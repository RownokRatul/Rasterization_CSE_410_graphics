#ifndef _triangle_header_
#define _triangle_header_

#include <iostream>
#include <iomanip>
#include <cstdio>
#include "matrix.h"

using namespace std;

class Triangle {

    public:

        double p1x, p1y, p1z;
        double p2x, p2y, p2z;
        double p3x, p3y, p3z;


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

};


#endif