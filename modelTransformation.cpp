#include "matrix.h"
using namespace std;


matrix RodriguesFormula(matrix a, matrix x, double theta) {
    matrix norm_a = normalize(a);
    matrix p1 = matrixMultiply(x, cos(theta));
    matrix p2 = matrixMultiply(norm_a, (1-cos(theta))*dot_product(norm_a, x));
    matrix p3 = matrixMultiply(cross_product(norm_a, x), sin(theta));
    matrix final = addMatrix(p3, addMatrix(p1, p2));
    return final;
}

matrix rotationMatrix(double angle, double ax, double ay, double az) {
    matrix a ({ax, ay, az, 1});
    a.print();
    matrix i({1, 0, 0, 1});
    matrix j({0, 1, 0, 1});
    matrix k({0, 0, 1, 1});
    i.print();
    matrix col1 = RodriguesFormula(a, i, angle);
    matrix col2 = RodriguesFormula(a, j, angle);
    matrix col3 = RodriguesFormula(a, k, angle);
    matrix rot(4, 4);
    rot.m[0][0] = col1.m[0][0];
    rot.m[1][0] = col1.m[1][0];
    rot.m[2][0] = col1.m[2][0];
    rot.m[0][1] = col2.m[0][0];
    rot.m[1][1] = col2.m[1][0];
    rot.m[2][1] = col2.m[2][0];
    rot.m[0][2] = col3.m[0][0];
    rot.m[1][2] = col3.m[1][0];
    rot.m[2][2] = col3.m[2][0];
    rot.m[3][3] = 1;
    rot.print();
    return rot;
}

matrix transformationMatrix(double tx, double ty, double tz) {
    matrix t(4, 4);
    t.m[0][0] = 1;
    t.m[1][1] = 1;
    t.m[2][2] = 1;
    t.m[3][3] = 1;
    t.m[3][0] = tx;
    t.m[3][1] = ty;
    t.m[3][2] = tz;
    return t;
}

matrix scaleMatrix(double sx, double sy, double sz) {
    matrix t(4, 4);
    t.m[0][0] = sx;
    t.m[1][1] = sy;
    t.m[2][2] = sz;
    t.m[3][3] = 1;
    return t;
}