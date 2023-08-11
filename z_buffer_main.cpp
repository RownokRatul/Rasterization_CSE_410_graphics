#include <iostream>
#include <string>
#include "headers/z_buffer_util.h"
#include "headers/bitmap_image.hpp"
#include "headers/triangle.h"

using namespace std;

vector<Triangle> tr;

void print_triangles() {
    for(Triangle each : tr) {
        each.print();
    }
}

void read_data() {
    freopen("stage3.txt", "r", stdin);
    string line;
    double temp;
    while(cin >> temp) {
        vector<double> p;
        p.push_back(temp);
        for(int i=0;i<8;i++) {
            cin >> temp;
            p.push_back(temp);
        }
        tr.push_back(Triangle(p));
    }
    // print_triangles();
}

void init_buffers() {

}

void apply_z_buffer() {

}

void save() {

}

void free_memory() {

}

int main() {
    read_data();
}