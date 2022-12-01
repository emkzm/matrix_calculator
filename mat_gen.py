from math import sin, cos
from fractions import Fraction
import random
rand = random.randint

def mtx_print(m, br=True):
	ln = max(map(lambda x: len(str(x)), sum(m, [])))
	s = ''
	for i in range(len(m)):
		if br:
			s += '['
		for j in range(len(m[i])):
			v = str(m[i][j])
			if v[0] != '-':
				v = ' ' + v
			s += v.ljust(ln, ' ') + ' '
		if br:
			s += ']'
		s += '\n'
	print(s)

def mtx_transpose(m):
	n = []
	for j in range(len(m[0])):
		n += [[0] * len(m)]
	for i in range(len(m)):
		for j in range(len(m[i])):
			n[j][i] = m[i][j]
	return n

def mtx_identity(s, v=1):
	n = []
	for i in range(s):
		n += [[]]
		for j in range(s):
			n[i] += [v if (i==j) else 0]
	return n

def mtx_minor(m, y, x):
	x -= 1
	y -= 1
	n = []
	for i in range(len(m)):
		if i != y:
			n += [[]]
			for j in range(len(m[i])):
				if j != x:
					n[len(n)-1] += [m[i][j]]
	return n

def mtx_det(m):
	h = len(m)
	if h != len(m[0]):
		return None
	if h == 2:
		return m[0][0]*m[1][1] - m[1][0]*m[0][1]
	else:
		s = 0
		for j in range(h):
			sgn = 1 - 2 * (j%2)
			s += sgn * m[0][j] * mtx_det(mtx_minor(m, 1, j+1))
		return s

def mtx_adjugate(m):
	n = []
	for i in range(len(m)):
		n += [[]]
		for j in range(len(m[i])):
			sgn = 1 - 2 * ((i+j) % 2)
			n[i] += [sgn * mtx_det(mtx_minor(m, i+1, j+1))]
	return mtx_transpose(n)

def mtx_smul(m, s):
	for i in range(len(m)):
		for j in range(len(m[i])):
			m[i][j] *= s
	return m

def mtx_add(A, B):
	C = []
	for i in range(len(A)):
		C += [[]]
		for j in range(len(B)):
			pass

def mtx_mul(A, B):
	w = len(A[0])
	if w != len(B):
		return None
	C = []
	for i in range(len(A)):
		C += [[]]
		for j in range(len(B[0])):
			s = 0
			for k in range(w):
				s += A[i][k] * B[k][j]
			C[i] += [s]
	return C

def mtx_div(A, B):
	return mtx_mul(A, mtx_inverse(B))

def mtx_inverse(m):
	return mtx_smul(mtx_adjugate(m), 1 / mtx_det(m))

def mtx_gen(h, w, _min, _max, seed = -1):
	m = []
	if seed != -1:
		state = random.getstate()
		random.seed(seed)
	for i in range(h):
		m += [[0] * w]
		for j in range(w):
			m[i][j] = Fraction(rand(_min, _max))
	if seed != -1:
		random.setstate(state)
	return m

"""
I = [
	[1, 2, 3],
	[4, 5, 6]
]
J = [
	[10, 11],
	[20, 21],
	[30, 31]
]
"""
I = [
	[0x3, 0x4, 0x2],
]
J = [
	[13, 9, 7, 15],
	[8, 7, 4, 6],
	[6, 4, 0, 3],
]
mtx_print(I, False)
mtx_print(J, False)
mtx_print(mtx_mul(I, J), False)
input()
