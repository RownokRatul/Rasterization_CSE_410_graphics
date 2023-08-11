#ifndef _zbuffer_util_header
#define _zbuffer_util_header

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

static unsigned long int g_seed = 1;

inline int random_z() {
    g_seed = (214013 * g_seed + 2531011);
    return (g_seed >> 16) & 0x7FFF;
}


#endif