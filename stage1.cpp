#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include "headers/config.h"
#include "cmdParser.cpp"

using namespace std;

#define degToRadian(x) x*M_PI/180.0


void test() {
    vector<double> t = {1, 2, 3};
    matrix c({1, 2, 3});
    c.print();
    rotationMatrix(degToRadian(90.0), 0.0, 1.0, 0.0);
}

void parseCommand() { 
    model = loadIdentityMatrix();
    freopen("scene.txt", "r", stdin);
    cin >> camera.eyex >> camera.eyey >> camera.eyez;
    cin >> camera.lookx >> camera.looky >> camera.lookz;
    cin >> camera.upx >> camera.upy >> camera.upz;
    cin >> camera.fovY >> camera.aspectRatio >> camera.nearPlane >> camera. farPlane;

    string cmd;
    while(true) {
        cin >> cmd;
        if(cmd == "triangle") {
            triangle();
        }
        else if(cmd == "translate") {
            translate();
        }
        else if(cmd == "scale") {
            scale();
        }
        else if(cmd == "rotate") {
            rotate();
        }
        else if(cmd == "push") {
            push();
        }
        else if(cmd == "pop") {
            pop();
        }
        else if(cmd == "end") {
            exit(0);
        }
        else {
            exit(1);
        }
    }
}

int main() {
    parseCommand();
    return 0;
}