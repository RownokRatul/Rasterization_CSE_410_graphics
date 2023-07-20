#ifndef _VECTOR_HEADER_
#define _VECTOR_HEADER_

#include<iostream>
#include<cstdio>
#include<cmath>
#include "matrix.h"

using namespace std;

point3d cross_product(point3d a, point3d b) {
    point3d c;
    c.x = a.y*b.z - a.z*b.y;
    c.y = -a.x*b.z + a.z*b.x;
    c.z = a.x*b.y - a.y*b.x;
    return c;
}

double dot_product(point3d a, point3d b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

point3d addVector(point3d a, point3d b) {
    return point3d(a.x+b.x, a.y+b.y, a.z+b.z);
}

point3d Rodrigues_formula(point3d v, point3d k, double theta) {
    point3d v_rot;
    point3d normalized_k = normalize(k);
    point3d p1 = scaleVector(v, cos(theta));
    point3d p2 = scaleVector(cross_product(normalized_k, v), sin(theta));
    point3d p3 = scaleVector(normalized_k, dot_product(normalized_k, v)*(1-cos(theta)));
    v_rot = addVector(p1, p2);
    v_rot = addVector(v_rot, p3);
    return v_rot;
}

#endif