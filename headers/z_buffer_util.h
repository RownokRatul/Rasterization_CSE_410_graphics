#ifndef _zbuffer_util_header
#define _zbuffer_util_header

#include<iostream>
#include<cmath>
#include<vector>
#include "triangle.h"

using namespace std;

static unsigned long int g_seed = 1;

inline int random_z() {
    g_seed = (214013 * g_seed + 2531011);
    return (g_seed >> 16) & 0x7FFF;
}

double triangle_area2d(Triangle t) {
    return abs(0.5*(t.p1x*(t.p2y-t.p3y) + t.p3x*(t.p1y-t.p2y) + t.p2x*(t.p3y-t.p1y)));
}

bool check_point_inside_triangle(Triangle t, double x, double y) {
    double epsilon = 0.00001;
    double area = triangle_area2d(t);
    double a1 = triangle_area2d(Triangle(t.p1x, t.p1y, t.p1z, t.p2x, t.p2y, t.p2z, x, y, 0.0));
    double a2 = triangle_area2d(Triangle(t.p1x, t.p1y, t.p1z, t.p3x, t.p3y, t.p3z, x, y, 0.0));
    double a3 = triangle_area2d(Triangle(t.p3x, t.p3y, t.p3z, t.p2x, t.p2y, t.p2z, x, y, 0.0));
    return abs(a1+a2+a3-area) < epsilon;
}

double find_max(double a, double b, double c) {
    if(a > b) {
        if(a > c) {
            return a;
        }
        return c;
    }
    else {
        if(b > c) {
            return b;
        }
        return c;
    }
}

double find_min(double a, double b, double c) {
    return find_max(-a, -b, -c);
}

#endif