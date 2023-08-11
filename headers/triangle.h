#ifndef _triangle_header_
#define _triangle_header_

#include <iostream>
#include <iomanip>
#include <cstdio>
#include "matrix.h"
#include "plane.h"
#include "rgb.h"

using namespace std;

class Triangle {

    public:

        double p1x, p1y, p1z;
        double p2x, p2y, p2z;
        double p3x, p3y, p3z;

        rgb color;

        Triangle(double ax, double ay, double az,
                double bx, double by, double bz,
                double cx, double cy, double cz) {
            p1x = ax;
            p1y = ay;
            p1z = az;
            p2x = bx;
            p2y = by;
            p2z = bz;
            p3x = cx;
            p3y = cy;
            p3z = cz;
            color = rgb(255, 255, 255);
        }

        Triangle(vector<double> v) {
            p1x = v[0];
            p1y = v[1];
            p1z = v[2];
            p2x = v[3];
            p2y = v[4];
            p2z = v[5];
            p3x = v[6];
            p3y = v[7];
            p3z = v[8];
            color = rgb(255, 255, 255);
        }

        Triangle(matrix p1, matrix p2, matrix p3) {
            p1x = p1.m[0][0];
            p1y = p1.m[1][0];
            p1z = p1.m[2][0];

            p2x = p2.m[0][0];
            p2y = p2.m[1][0];
            p2z = p2.m[2][0];

            p3x = p3.m[0][0];
            p3y = p3.m[1][0];
            p3z = p3.m[2][0];

            color = rgb(255, 255, 255);
        }

        void print() {
            printf("%.7lf %.7lf %.7lf\n", p1x, p1y, p1z);
            printf("%.7lf %.7lf %.7lf\n", p2x, p2y, p2z);
            printf("%.7lf %.7lf %.7lf\n\n", p3x, p3y, p3z);
        }

        Triangle transform(matrix &model) {
            matrix p1({p1x, p1y, p1z, 1});
            matrix p2({p2x, p2y, p2z, 1});
            matrix p3({p3x, p3y, p3z, 1});
            matrix p1_prime = homogenousNormalize(matrixMultiply(model, p1));
            matrix p2_prime = homogenousNormalize(matrixMultiply(model, p2));
            matrix p3_prime = homogenousNormalize(matrixMultiply(model, p3));
            return Triangle(p1_prime, p2_prime, p3_prime);
        }

        Plane get_equation() {
            matrix r({p1x-p2x, p1y-p2y, p1z-p2z, 1});
            matrix s({p1x-p3x, p1y-p3y, p1z-p3z, 1});
            matrix n = cross_product(r, s);
            n = normalize(n);
            double a = n.m[0][0];
            double b = n.m[1][0];
            double c = n.m[2][0];
            Plane p(a, b, c, a*p1x+b*p1y+c*p1z);
            return p;
        }

};


#endif