#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include "matrix.h"
#include "modelTransformation.cpp"
#include "headers/camera.h"
#include "headers/triangle.h"

using namespace std;

#define degToRadian(x) x*M_PI/180.0

Camera camera;

void test() {
    vector<double> t = {1, 2, 3};
    matrix c({1, 2, 3});
    c.print();
    rotationMatrix(degToRadian(90.0), 0.0, 1.0, 0.0);
}

void parseCommand() {
    freopen("scene.txt", "r", stdin);
    cin >> camera.eyex >> camera.eyey >> camera.eyez;
    cin >> camera.lookx >> camera.looky >> camera.lookz;
    cin >> camera.upx >> camera.upy >> camera.upz;
    cin >> camera.fovY >> camera.aspectRatio >> camera.nearPlane >> camera. farPlane;

    string cmd;
    while(true) {
        cin >> cmd;
        if(cmd == "triangle") {

        }
        else if(cmd == "translate") {

        }
        else if(cmd == "scale") {

        }
        else if(cmd == "rotate") {

        }
        else if(cmd == "push") {

        }
        else if(cmd == "pop") {

        }
        else if(cmd == "end") {
            
        }
    }
}

int main() {
    parseCommand();

    return 0;
}