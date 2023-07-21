#ifndef _matrix_header_
#define _matrix_header_

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;


class matrix {

    public:

        vector<vector<double> > m;
        int row_dim;
        int col_dim;


        matrix () {
            row_dim = 0;
            col_dim = 0;
        }

        matrix(int dim) {
            row_dim = col_dim = dim;
            vector<vector<double> > temp(dim, vector<double>(dim, 0));
            m = temp;
        }

        matrix(int r_dim, int c_dim) {
            row_dim = r_dim;
            col_dim = c_dim;
            vector<vector<double> > temp(r_dim, vector<double>(c_dim, 0));
            m = temp;
        }

        matrix(vector<double> v) {
            row_dim = v.size();
            col_dim = 1;
            vector<vector<double> > temp(row_dim);
            for(int i=0;i<row_dim;i++) {
                temp[i].push_back(v[i]);
            }
            m = temp;
        }

        void print() {
            cout << "-------------\n";
            for(int i=0;i<row_dim;i++) {
                for(int j=0;j<col_dim;j++) {
                    cout << m[i][j] << " ";
                }
                cout << "\n";
            } 
            cout << "-------------\n";
        }

};


matrix matrixMultiply(matrix x, matrix y) {
    if(x.col_dim != y.row_dim) {
        cout << "Matrix multiplication: Dimension Error!\n";
        return matrix(0, 0);
    }
    matrix res(x.row_dim, y.col_dim);
    for(int i=0;i<y.col_dim;i++) {
        for(int j=0;j<x.row_dim;j++) {
            for(int k=0;k<x.col_dim;k++) {
                res.m[j][i] += x.m[j][k] * y.m[k][i];
            }
        }
    }
    return res;
}

matrix matrixMultiply(matrix x, double c) {
    matrix res(x.row_dim, x.col_dim);
    for(int i=0;i<x.row_dim;i++) {
        for(int j=0;j<x.col_dim;j++) {
            res.m[i][j] = c*x.m[i][j];
        }
    }
    return res;
}


matrix homogenousNormalize(matrix k) {
    matrix normalized(k.row_dim, k.col_dim);
    double w = k.m[k.row_dim-1][k.col_dim-1];
    for(int i=0;i<k.row_dim;i++) {
        for (int j=0;j<k.col_dim;j++) {
            normalized.m[i][j] = k.m[i][j]/w;
        }
    }
    return normalized;
}


matrix normalize(matrix k) {
    matrix wNormalized = homogenousNormalize(k);
    double t = sqrt(k.m[0][0]*k.m[0][0] + k.m[1][0]*k.m[1][0] + k.m[2][0]*k.m[2][0]);
    for(int i=0;i<k.row_dim-1;i++) {
        wNormalized.m[i][0] /= t;
    }
    return wNormalized;
}

matrix cross_product(matrix a, matrix b) {
    matrix c(4, 1);
    c.m[0][0] = a.m[1][0]*b.m[2][0] - a.m[2][0]*b.m[1][0];
    c.m[1][0] = -a.m[0][0]*b.m[2][0] + a.m[2][0]*b.m[0][0];
    c.m[2][0] = a.m[0][0]*b.m[1][0] - a.m[1][0]*b.m[0][0];
    c.m[3][0] = 1;
    return c;
}

matrix addMatrix(matrix a, matrix b) {
    if(a.col_dim != b.col_dim && a.row_dim != b.row_dim) {
        cout << "add matrix: dimension error!" << "\n";
        return matrix(0, 0);
    }
    matrix c(a.row_dim, a.col_dim);
    for(int i=0;i<a.row_dim;i++) {
        for(int j=0;j<a.col_dim;j++) {
            c.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }
    return c;
}

double dot_product(matrix a, matrix b) {
    return a.m[0][0]*b.m[0][0] + a.m[1][0]*b.m[1][0] + a.m[2][0]*b.m[2][0];
}


#endif 