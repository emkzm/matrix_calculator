#include <iostream>
#include "addition.h"
using namespace std;
#define nl cout<<endl

void print_v2d(vector<vector<int>> source)
{
    for (int i = 0; i < source.size(); i++)
    {
        for (int j = 0; j < source[i].size(); j++)
        {
            cout << source[i][j] << " ";
        }
        nl;
    }
    return;
}


int main()
{
    dvi vec1 = {
        {1, 2, 3},
        {4, 5, 6},
        
    };
    dvi vec2 = {
        {10, 11},
        {20, 21},
        {30, 31},
    };
    dvi vec3;

    // cout << "\tSUM ";
    // cout << (matrix_sum(vec1,vec2,vec3) ? "True" : "False") << endl;
    // print_v2d(vec3);

    // cout << "\tSUB ";
    // cout << (matrix_sub(vec1,vec2,vec3) ? "True" : "False") << endl;
    // print_v2d(vec3);

    // cout << "\tTransposed matrix 1 ";
    // cout << (transpose_matrix(vec2, vec3) ? "True" : "False") << endl;
    // print_v2d(vec3);

    cout << "\tMUL ";
    cout << (matrix_mul(vec1,vec2,vec3) ? "True" : "False") << endl;
    print_v2d(vec3);

    return 0;
}