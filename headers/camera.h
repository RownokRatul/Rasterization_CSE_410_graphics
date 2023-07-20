#ifndef _camera_header_
#define _camera_header_

#include <iostream>
using namespace std;

class Camera {
    
    public:

        double eyex, eyey, eyez;
        double lookx, looky, lookz;
        double upx, upy, upz;

        double fovY;
        double aspectRatio;
        double nearPlane;
        double farPlane;

};


#endif