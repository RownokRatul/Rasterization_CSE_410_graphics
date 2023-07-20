#include <iostream>
#include <vector>
#include <stack>
#include "matrix.h"
using namespace std;


matrix rotationMatrix(double angle, double ax, double ay, double az) {
    matrix a (4 ,1);
    a.m[0][0] = ax;
    a.m[0][1] = ay;
    a.m[0][2] = az;
    a.m[0][0] = 1;
    matrix i
    matrix c1 = RodriguesFormula(a, )
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




int main() {
    matrix test(4, 4);
    test.print();
    return 0;
}