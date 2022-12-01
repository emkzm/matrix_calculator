#pragma once
#include <vector>
#include <iostream>
#define dvi vector<vector<int>>
#define vi vector<int>
using std::vector;
using std::cout;
using std::endl;

bool matrix_sum(dvi m1, dvi m2, dvi& destination)
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

bool matrix_sub(dvi m1, dvi m2, dvi& destination)
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
bool matrix_mul(dvi m1, dvi m2, dvi& destination)
{
	if (m1.size() != m2[0].size()) return false;
	destination.resize(m1.size());
	// for (int i = 0; i < m1.size(); i++)
	// {
	// 	int sum = 0;
	// 	destination[i].resize(m1.size());
	// 	for (int j = 0; j < m1[i].size(); j++)
	// 	{
	// 		sum += m1[i][j] + m2[j][i];
	// 	}
	// 	a.push_back(sum);
	// }
	if (m1[0].size() != m2.size()) return false;
	destination.resize(//C = []
	for i in range(len(A)):
		C += [[]]
		for j in range(len(B[0])):
			s = 0
			for k in range(w):
				s += A[i][k] * B[k][j]
			C[i] += [s]
	return C

	return true;
}

bool mul_matrix_to_n(dvi mtx, int n, dvi& destination);
bool mul_matrix_to_vector(dvi mtx, vi vec, dvi& destination);
bool transpose_matrix(dvi source, dvi& destination)
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
bool rank_matrix(const dvi& source);
bool vector_sum(vi v1, vi v2, vi& destination);
bool vector_scal_sub(vi v1, vi v2, vi& destination);
bool vector_vec_mul(vi v1, vi v2, vi& destination);