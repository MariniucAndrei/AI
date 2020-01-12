#include "HillClimbing.h"
#include "Point.h"

HillClimbing::HillClimbing(int dim, int code)
{
	this->Dim = dim;
	this->Code = code;
}
void HillClimbing::SetTemperature(double temperature)
{
	this->Temperature = temperature;
}
void HillClimbing::SetMinTemperature()
{
	this->MinTemperature = 0.00000001;
}
void HillClimbing::InitializationNeighbours()
{
	vC = point(Dim, Code);
	vBEST = point(Dim, Code);
}
double HillClimbing::random() {
	return rand() / RAND_MAX;
}
double HillClimbing::ExecuteAlgoritm()
{
	for (int t = 1; t <= this->Dim; t++) {
		bool local = false;
		point vN(vC, -1);
		while (!local) {

			if (this->Code == 1) vN.firstHC();
			else  vN.bestHC();

			if (vN.value < vC.value) {
				vC.copy(vN);
			}
			else
				local = true;
		}
		if (vBEST.value > vC.value) {
			vBEST.copy(vC);
		}
		return vC.value;
		vC.reset();
	}
	return vBEST.value;
}