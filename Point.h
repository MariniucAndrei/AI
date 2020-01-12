#pragma once

#include <vector>
#include <time.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#define pi 3.1415926535
using namespace std;

class point {
public:
	vector<bool> V;
	int dim, p_code, bits;
	double value, left, right, left2, right2;
	point() {}
	point(int n, int code);
	point(point cpy, int poz);
	void reset();
	void copy(point);
	void createNeighbour(point cpy, int poz);
	void firstHC();
	void bestHC();
	void randomSA(point cpy);

	double decode(int k);
	void eval();
};