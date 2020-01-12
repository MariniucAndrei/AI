#include "SimulatedAnnelling.h"
#include "Point.h"

SimulatedAnnelling::SimulatedAnnelling(int dim, int code, int pbCode)
{
	this->Dim = dim;
	this->Code = code;
	this->pbCode = pbCode;
	this->numberOfExecutions = 0;
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
	int no=0;
	if (this->pbCode == 3) {
		for (int i = 1; i <= 20; i++) //numarul de iteratii
		{

			while (Temperature > MinTemperature) {
				int condition = 2 * this->Dim;
				no++;
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
			if (vBEST.value < 20) {
				break;
			}
		}
	}
	else if (this->pbCode == 6) {
		for (int i = 1; i <= 20; i++) //numarul de iteratii
		{

			while (Temperature > MinTemperature) {
				int condition = 2 * this->Dim;
				while (condition) {
					no++;
					point vN(vC, -1);
					vN.randomSA(vC);
					point vHC(vC, -1);
					vHC.firstHC();
					if (vHC.value < vN.value) {
						vN.copy(vHC);
					}
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
			if (vBEST.value < 20) {
				break;
			}
		}
	}
	else if (this->pbCode == 7) {
		for (int i = 1; i <= 20; i++) //numarul de iteratii
		{

			while (Temperature > MinTemperature) {
				int condition = 2 * this->Dim;
				while (condition) {
					no++;
					point vHC(vC, -1);
					vHC.bestHC();
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
			if (vBEST.value < 20) {
				break;
			}
		}
	}
	
	this->numberOfExecutions = no;
	cout <<"S-au executat "<<this->numberOfExecutions <<" functii de evaluare"<< endl;
	return vBEST.value;
}