#include <iostream>
#include "addition.h"
using namespace std;
#define nl cout << endl

void print_mtx(mtx source)
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
    mtx mtx1 = {
        {1, 2},
        {3, 4}
        
    };
    mtx mtx2 = {
        {1, 2},
        {3, 4}
    };
    mtx vec3;

    cout << "\tSUM ";
    cout << (matrix_sum(mtx1,mtx2,vec3) ? "True" : "False") << endl;
    print_mtx(vec3);

    // cout << "\tSUB ";
    // cout << (matrix_sub(mtx1,mtx2,vec3) ? "True" : "False") << endl;
    // print_mtx(vec3);

    // cout << "\tTransposed matrix 1 ";
    // cout << (matrix_transpose(mtx2, vec3) ? "True" : "False") << endl;
    // print_mtx(vec3);

    // cout << "\tMUL ";
    // cout << (matrix_mul(mtx1,mtx2,vec3) ? "True" : "False") << endl;
    // print_mtx(vec3);

    // cout << "\tRANK = ";
    // cout << matrix_rank(mtx2) << endl;
    // print_mtx(mtx2);


    return 0;
}