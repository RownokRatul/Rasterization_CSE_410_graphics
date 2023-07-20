#ifndef _triangle_header_
#define _triangle_header_

#include <iostream>

using namespace std;

class triangle {

    public:

        double p1x, p1y, p1z;
        double p2x, p2y, p2z;
        double p3x, p3y, p3z;


        void print() {
            cout << p1x << p1y << p1z << "\n";
            cout << p2x << p2y << p2z << "\n";
            cout << p3x << p3y << p3z << "\n";
        }

};


#endif