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
	HillClimbing() {}
	HillClimbing(int dim, int code);
	void SetTemperature(double temperature);
	void SetMinTemperature();
	void  InitializationNeighbours();
	double  ExecuteAlgoritm();
	double random();
};