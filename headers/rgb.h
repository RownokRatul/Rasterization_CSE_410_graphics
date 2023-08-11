#ifndef _rgb_header_
#define _rgb_header_

#include <iostream>
using namespace std;

class rgb {

    public:

        int r;
        int g;
        int b;

        rgb() {
            r = g = b = 0;
        }

        rgb(int p, int q, int s) {
            r = p;
            g = q;
            b = s;
        }

        void print() {
            cout << "(" << r << " " << g << " " << b << ")" << endl;
        }

};

#endif