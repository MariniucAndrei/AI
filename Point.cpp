#include "Point.h"

point::point(int n, int code) {
	p_code = code;
	bits = 8;
	dim = n;
	if (code == 1 || code == 3) {
		left = -5.12;
		right = 5.12;
	}
	else if (code == 2) {
		left = -500;
		right = 500;
	}
	else if (code == 4) {
		left = -3; right = 3;
		left2 = -2; right2 = 2;
		dim = 2;
	}

	for (int i = 0; i < bits * dim; i++) {
		V.push_back(rand() % 2);
	}
	eval();
}

point::point(point cpy, int poz) {
	left = cpy.left;
	right = cpy.right;
	left2 = cpy.left2;
	right2 = cpy.right2;
	p_code = cpy.p_code;
	bits = cpy.bits;
	createNeighbour(cpy, poz);
}

void point::reset() {
	for (int i = 0; i < bits * dim; i++) {
		V[i] = rand() % 2;
	}
	eval();
}

void point::copy(point cpy) {
	*this = cpy;
}

void point::createNeighbour(point cpy, int poz) {
	dim = cpy.dim;
	V = cpy.V;
	if (poz >= 0)
		V[poz] = 1 - V[poz];
	eval();
}

void point::firstHC() {
	for (int i = 0; i < bits * dim; i++) {
		point cpy(*(this), i);
		if (cpy.value < this->value) {
			copy(cpy);
			break;
		}
	}
}

void point::bestHC() {
	point result(*this, -1);
	for (int i = 0; i < bits * dim; i++) {
		point cpy(*this, i);
		if (cpy.value < result.value) {
			result.copy(cpy);
		}
	}
	copy(result);
}

void point::randomSA(point cpy) {
	int rez = bits * dim;
	int nr = rand() % rez;
	createNeighbour(cpy, nr);
}

int power(int p) {
	int rez = 1;
	while (p) {
		rez *= 2;
		p--;
	}
	return rez;
}

double point::decode(int k) {
	double result = 0;
	for (int i = k; i < k + bits; i++) {
		result += power(i - k) * V[i];
	}
	return result / power(bits);
}

void point::eval() {
	if (p_code == 1 || p_code == 2)
		value = 0;
	else if (p_code == 3) {
		value = 10 * dim;
	}
	if (p_code <= 3) {
		for (int i = 0; i < dim; i++) {
			double xi = left + decode(i * bits) * (right - left);
			if (p_code == 1)
				value += xi * xi;
			else if (p_code == 2)
				value += (-xi * sin(sqrt(abs(xi))));
			else if (p_code == 3) {
				value += (xi * xi - 10 * cos(2 * pi * xi));
			}
		}
	}
	else {
		double x1 = left + decode(bits * 0) * (right - left);
		double x2 = left2 + decode(bits * 1) * (right2 - left2);
		value = (4 - 2.1 * x1 * x1 + x1 * x1 * x1 * x1 / 3) * x1 * x1 + x1 * x2 + (-4 + 4 * x2 * x2) * x2 * x2;
	}
}