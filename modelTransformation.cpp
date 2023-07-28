#include "headers/matrix.h"
using namespace std;

#define degToRadian(x) x*M_PI/180.0


matrix RodriguesFormula(matrix x, matrix a, double theta) {
    // matrix norm_a = normalize(a);
    matrix p1 = matrixMultiply(x, cos(theta));
    // p1.print();
    matrix p2 = matrixMultiply(a, (1-cos(theta))*dot_product(a, x));
    // p2.print();
    matrix p3 = matrixMultiply(cross_product(a, x), sin(theta));
    // p3.print();
    matrix final = addMatrix(p3, addMatrix(p1, p2));
    // final.print();
    // final = homogenousNormalize(final);
    return final;
}

matrix rotationMatrix(double angle, double ax, double ay, double az) {
    // cout << angle << " " << ax << " " << ay << " " << az << endl;
    double angle_radian = degToRadian(angle);
    // cout << angle_radian << endl;
    matrix a ({ax, ay, az, 1});
    a = normalize(a);
    // a.print();
    matrix i({1, 0, 0, 1});
    matrix j({0, 1, 0, 1});
    matrix k({0, 0, 1, 1});
    matrix col1 = RodriguesFormula(i, a, angle_radian);
    // col1.print();
    matrix col2 = RodriguesFormula(j, a, angle_radian);
    // col2.print();
    matrix col3 = RodriguesFormula(k, a, angle_radian);
    // col3.print();
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
    // rot.print();
    return rot;
}

matrix translateMatrix(double tx, double ty, double tz) {
    matrix t(4, 4);
    t.m[0][0] = 1;
    t.m[1][1] = 1;
    t.m[2][2] = 1;
    t.m[3][3] = 1;
    t.m[0][3] = tx;
    t.m[1][3] = ty;
    t.m[2][3] = tz;
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

matrix loadIdentityMatrix() {
    matrix id(4, 4);
    for(int i=0;i<4;i++) {
        id.m[i][i] = 1;
    }
    return id;
}

matrix viewTransformationMatrix(Camera &cam) {
    matrix l({cam.lookx-cam.eyex, cam.looky-cam.eyey, cam.lookz-cam.eyez, 1});
    matrix up({cam.upx, cam.upy, cam.upz, 1});
    l = normalize(l);
    matrix r = normalize(cross_product(l, up));
    matrix u = cross_product(r, l);

    matrix T(4, 4);
    for(int i=0;i<4;i++) {
        T.m[i][i] = 1;
    }
    T.m[0][3] = -cam.eyex;
    T.m[1][3] = -cam.eyey;
    T.m[2][3] = -cam.eyez;

    matrix R(4, 4);
    R.m[0][0] = r.m[0][0];
    R.m[0][1] = r.m[1][0];
    R.m[0][2] = r.m[2][0];
    R.m[1][0] = u.m[0][0];
    R.m[1][1] = u.m[1][0];
    R.m[1][2] = u.m[2][0];
    R.m[2][0] = -l.m[0][0];
    R.m[2][1] = -l.m[1][0];
    R.m[2][2] = -l.m[2][0];
    R.m[3][3] = 1;
    return matrixMultiply(R, T);
}

matrix projectionMatrix(Camera &cam) {
    double fovX = cam.aspectRatio * cam.fovY;
    double t = cam.nearPlane * tan(degToRadian(cam.fovY/2));
    double r = cam.nearPlane * tan(degToRadian(fovX/2));
    matrix proj(4, 4);
    proj.m[0][0] = cam.nearPlane/r;
    proj.m[1][1] = cam.nearPlane/t;
    proj.m[2][2] = -(cam.farPlane+cam.nearPlane)/(cam.farPlane-cam.nearPlane);
    proj.m[2][3] = (-2.0*cam.farPlane*cam.nearPlane)/(cam.farPlane-cam.nearPlane);
    proj.m[3][2] = -1.0;
    return proj;
}