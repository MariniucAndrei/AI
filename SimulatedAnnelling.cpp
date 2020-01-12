#include "SimulatedAnnelling.h"
#include "Point.h"

SimulatedAnnelling::SimulatedAnnelling(int dim, int code)
{
	this->Dim = dim;
	this->Code = code;
}
void SimulatedAnnelling::SetTemperature(double temperature)
{
	this->Temperature = temperature;
}
void SimulatedAnnelling::SetMinTemperature()
{
	this->MinTemperature = 0.00000001;
}
void SimulatedAnnelling::InitializationNeighbours()
{
	vC = point(Dim, Code);
	vBEST = point(Dim, Code);
}
double SimulatedAnnelling::random() {
	return rand() / RAND_MAX;
}
double SimulatedAnnelling::ExecuteAlgoritm()
{
	for (int i = 1; i <= 20; i++) //numarul de iteratii
	{

		while (Temperature > MinTemperature) {
			int condition = 2 * this->Dim;
			while (condition) {
				point vN(vC, -1);
				vN.randomSA(vC);
				if (vN.value < vC.value) {
					vC.copy(vN);
				}
				else if (random() < exp((vC.value - vN.value) / Temperature)) {
					vC.copy(vN);
				}
				condition--;
			}
			Temperature = Temperature * (0.9 - Temperature / 100);
		}
		if (vC.value < vBEST.value)
			vBEST.copy(vC);

		return vBEST.value;
	}
}