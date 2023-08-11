#include <iostream>
#include "headers/config.h"
#include "headers/modelTransformation.cpp"
using namespace std;

void translate() {
    double tx, ty, tz;
    cin >> tx >> ty >> tz;
    matrix T = translateMatrix(tx, ty, tz);
    model = matrixMultiply(model, T);
}

void triangle() {
    double p1x, p1y, p1z;
    double p2x, p2y, p2z;
    double p3x, p3y, p3z;
    cin >> p1x >> p1y >> p1z >> p2x >> p2y >> p2z >> p3x >> p3y >> p3z;
    matrix p1({p1x, p1y, p1z, 1});
    matrix p2({p2x, p2y, p2z, 1});
    matrix p3({p3x, p3y, p3z, 1});
    p1 = matrixMultiply(model, p1);
    p2 = matrixMultiply(model, p2);
    p3 = matrixMultiply(model, p3);
    Triangle t(p1, p2, p3);
    triangles.push_back(t);
    t.print();
}

void scale() {
    double sx, sy, sz;
    cin >> sx >> sy >> sz;
    matrix S = scaleMatrix(sx, sy, sz);
    model = matrixMultiply(model, S);
}

void rotate() {
    double angle, ax, ay, az;
    cin >> angle >> ax >> ay >> az;
    matrix R = rotationMatrix(angle, ax, ay, az);
    model = matrixMultiply(model, R);
}

void push() {
    st.push(model);
}

void pop() {
    model = st.top();
    st.pop();
}

void transformScene(matrix &t) {
    for(int i=0;i<triangles.size();i++) {
        triangles[i] = triangles[i].transform(t);
    }
    for(int i=0;i<triangles.size();i++) {
        triangles[i].print();
    }
}

void viewTransform() {
    freopen("stage2.txt", "w", stdout);
    matrix v = viewTransformationMatrix(camera);
    model = matrixMultiply(model, v);
    transformScene(model);
}

void projectTransform() {
    freopen("stage3.txt", "w", stdout);
    matrix proj = projectionMatrix(camera);
    transformScene(proj);
}