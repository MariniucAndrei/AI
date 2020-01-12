#pragma once

#include "Point.h"
#include "Nature.h"

class HillClimbing :public Nature
{
private:
	double Temperature;
	double MinTemperature;
	point vC, vBEST;

public:
	int Dim;
	int Code;
	int pbCode;
	HillClimbing() {}
	HillClimbing(int dim, int code, int pbCode);
	void SetTemperature(double temperature);
	void SetMinTemperature();
	void  InitializationNeighbours();
	double  ExecuteAlgoritm();
	double random();
};