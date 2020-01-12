#pragma once

#include "Point.h"
#include "Nature.h"

class SimulatedAnnelling :public Nature
{
private:
	double Temperature;
	double MinTemperature;
	point vC, vBEST;

public:
	int numberOfExecutions;
	int Dim;
	int Code;
	int pbCode;
	SimulatedAnnelling() {}
	SimulatedAnnelling(int dim, int code, int pbCode);
	void SetTemperature(double temperature);
	void SetMinTemperature();
	void  InitializationNeighbours();
	double  ExecuteAlgoritm();
	double random();
};