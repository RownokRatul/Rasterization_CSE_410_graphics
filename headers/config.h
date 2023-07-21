#ifndef _config_header_
#define _config_header_

#include "matrix.h"
#include "triangle.h"
#include "camera.h"
#include <stack>
using namespace std;


matrix model;
vector<Triangle> triangles;
stack<matrix> st;
Camera camera;


#endif