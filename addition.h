#pragma once
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
#define mtx_type double
typedef std::vector<std::vector<mtx_type>> mtx;
typedef std::vector<mtx_type> vec;

bool matrix_sum(mtx m1, mtx m2, mtx& destination)
{
	if (m1.size() != m2.size()) return false;
	if (m1[0].size() != m2[0].size()) return false;
	destination.resize(m1.size());
	for (int i = 0; i < m1.size(); i++) 
	{
		destination[i].resize(m1[i].size());
		for (int j = 0; j < m1[i].size(); j++)
		{
			destination[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return true;
}

bool matrix_sub(mtx m1, mtx m2, mtx& destination)
{
	if (m1.size() != m2.size()) return false;
	if (m1[0].size() != m2[0].size()) return false;
	destination.resize(m1.size());
	for (int i = 0; i < m1.size(); i++)
	{
		destination[i].resize(m1[i].size());
		for (int j = 0; j < m1[i].size(); j++)
		{
			destination[i][j] = m1[i][j] - m2[i][j];
		}
	}
	return true;
}
bool matrix_mul(mtx m1, mtx m2, mtx& destination)
{
	if (m1[0].size() != m2.size()) return false;
	destination.resize(m1.size());
	for (int i = 0; i < m1.size(); i++)
	{
		destination[i].resize(m2[0].size());
		for (int j = 0; j < m2[0].size(); j++)
		{
			mtx_type sum = 0;
			for (int k = 0; k < m1[0].size(); k++)
			{
				sum += m1[i][k] * m2[k][j];
			}
			destination[i][j] =  sum;
		}
	}
	return true;
}

bool matrix_mul_n(mtx source, int n, mtx& destination)
{
	for (int i = 0; i < source.size(); i++)
	{
		destination[i].resize(source[i].size());
		for (int j = 0; j < source[i].size(); j++)
		{
			destination[i][j] = source[i][j] * n;
		}
	}
	return true;
}

bool matrix_transpose(mtx source, mtx& destination)
{
	destination.resize(source[0].size());
	for (int i = 0; i < source[0].size(); i++)
	{
		destination[i].resize(source.size());
		for (int j = 0; j < source.size(); j++)
		{
			destination[i][j] = source[j][i];
		}
	}
	return true;
}

int matrix_rank(mtx A)
{
	const double EPS = 1E-9;
    int n = A.size();
    int m = A[0].size();

    int rank = 0;
    std::vector<bool> row_selected(n, false);
    for (int i = 0; i < m; i++)
	{
        int j;
        for (j = 0; j < n; j++)
		{
            if (!row_selected[j] && abs(A[j][i]) > EPS)
			{
                break;
			}
        }

        if (j != n)
		{
            rank++;
            row_selected[j] = true;
            for (int p = i + 1; p < m; ++p)
			{
                A[j][p] /= A[j][i];
			}
            for (int k = 0; k < n; k++)
			{
                if (k != j && abs(A[k][i]) > EPS)
				{
                    for (int p = i + 1; p < m; p++)
					{
                        A[k][p] -= A[j][p] * A[k][i];
					}
                }
            }
        }
    }
    return rank;
}

bool vector_sum(vec v1, vec v2, vec& destination)
{
	if (v1.size() != v2.size()) return false;
	for (int i=0; i < v1.size(); i++) 
	{
		destination[i] = v1[i] + v2[i];
	}
	return true;
}
// скалярное произведение векторов
mtx_type vector_dot(vec v1, vec v2)
{
	if (v1.size() != v2.size()) return 0;
	mtx_type sum = 0;
	for (int i=0; i < v1.size(); i++) 
	{
		sum += v1[i] * v2[i];
	}
	return sum;
}
// векторное произведение векторов
bool vector_cross(vec v1, vec v2, vec& destination)
{
	if (v1.size() != v2.size()) return false;
	return true;
}