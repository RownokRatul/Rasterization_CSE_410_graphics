#include <iostream>
#include <cstdio>
#include "headers/z_buffer_util.h"
#include "headers/bitmap_image.hpp"
#include "headers/triangle.h"
#include "headers/rgb.h"

using namespace std;


vector<Triangle> tr;

int screen_height;
int screen_width;
double dx;
double dy;
double right_limit;
double left_limit;
double top_limit;
double bottom_limit;
double top_most_y;
double bottom_most_y;
double left_most_x;
double right_most_x;
double z_max;
double z_front_limit;
double scale_width;
double scale_height;

vector<vector<double> > z_buffer;
vector<vector<rgb> > frame_buffer;
bitmap_image *img;


void print_triangles() {
    for(Triangle each : tr) {
        each.print();
    }
}

void print_buffers() {
    freopen("z_buffer.txt", "w", stdout);
    int sz = z_buffer.size();
    for(int i=sz-1; i>=0; i--) {
        for(double x : z_buffer[i]) {
            if(x != z_max) {
                printf("%.6lf\t", x);
            }
        }
        printf("\n");
    }
}

void read_data() {
    // cout << " Called read data\n";
    freopen("stage3.txt", "r", stdin);
    double temp;
    while(cin >> temp) {
        vector<double> p;
        p.push_back(temp);
        for(int i=0;i<8;i++) {
            cin >> temp;
            p.push_back(temp);
        }
        tr.push_back(Triangle(p));
        int r = random_z() % 256;
        int g = random_z() % 256;
        int b = random_z() % 256;
        tr.back().color = rgb(r, g, b);
    }
    cin.clear();
    freopen("config.txt", "r", stdin);
    cin >> screen_width >> screen_height;
    // cout << screen_width << screen_height << endl;
    // print_triangles();
}

void init_vars() {
    // cout << " Called init vars\n";
    right_limit = 1;
    left_limit = -1;
    top_limit = 1;
    bottom_limit = -1;
    dx = (right_limit - left_limit) / screen_width;
    dy = (top_limit - bottom_limit) / screen_height;
    top_most_y = top_limit - (dy/2);
    bottom_most_y = bottom_limit + (dy/2);
    left_most_x = left_limit + (dx/2);
    right_most_x = right_limit - (dx/2);
    z_max = 1.0;
    z_front_limit = -1.0;
    scale_width = screen_width/(right_limit - left_limit);
    scale_height = screen_height/(top_limit - bottom_limit);
}

void init_buffers() {
    // cout << " Called init buf\n";
    init_vars();
    for(int i=0;i<screen_width;i++) {
        z_buffer.push_back(vector<double> (screen_height, z_max));
        // frame_buffer.push_back(vector<rgb> (screen_height, rgb(0, 0, 0)));
    }
    // print_buffers();
    img = new bitmap_image(screen_width, screen_height);
}

void apply_z_buffer() {
    // cout << " Called z_buffer\n";
    for(Triangle t : tr) {
        double max_y = find_max(t.p1y, t.p2y, t.p3y);
        double min_y = find_min(t.p1y, t.p2y, t.p3y);
        double max_x = find_max(t.p1x, t.p2x, t.p3x);
        double min_x = find_min(t.p1x, t.p2x, t.p3x);
        // clipping
        if (max_y > top_most_y) {
            max_y = top_most_y;
        }
        if (min_y < bottom_most_y) {
            min_y = bottom_most_y;
        }
        if (max_x > right_most_x) {
            max_x = right_most_x;
        }
        if (min_x < left_most_x) {
            min_x = left_most_x;
        }
        //z_buffer update
        // t.print();
        // cout << max_x << " " << min_x << " " << max_y << " " << min_y << endl;
        int dbg = 1;
        for(double y=min_y; y<=max_y; y+=dy) {
            for(double x=min_x; x<=max_x; x+=dx) {
                if(check_point_inside_triangle(t, x, y)) {
                    // cout << "Found an inside point\n";
                    Plane plane = t.get_equation();
                    double z_val = plane.find_z(x, y);
                    int pixel_x = round(x*scale_width + (screen_width/2.0));
                    int pixel_y = round(-y*scale_height + (screen_height/2.0));
                    if(z_val < z_buffer[pixel_x][pixel_y] && z_val > z_front_limit) {
                        // cout << z_buffer[pixel_x][pixel_y] << " " << z_val << "\n";
                        z_buffer[pixel_x][pixel_y] = z_val;
                        // frame_buffer[pixel_x][pixel_y] = t.color;
                        img->set_pixel(pixel_x, pixel_y, t.color.r, t.color.g, t.color.b);
                    }
                }
            }
        }
    }
}

void save() {
    print_buffers();
    img->save_image("out.bmp");
}

void free_memory() {
    delete img;
}

int main() {
    read_data();
    init_buffers();
    apply_z_buffer();
    save();
    free_memory();
}