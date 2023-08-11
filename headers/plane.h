#ifndef _plane_header_
#define _plane_header_

#include <iostream>
#include <cmath>

using namespace std;

class Plane {

    public:

        // ax + by + cz = d
        double a;
        double b;
        double c;
        double d;

        Plane(double x, double y, double z, double w) {
            a = x;
            b = y;
            c = z;
            d = w;
        }

        double find_z(double x, double y) {
            return (d-a*x-b*y)/c;
        }

        void print() {
            cout << a << " " << b << " " << c << " " << d << endl;
        }

};

#endif