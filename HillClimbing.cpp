#include "HillClimbing.h"
#include "Point.h"

HillClimbing::HillClimbing(int dim, int code, int pbCode)
{
	this->Dim = dim;
	this->Code = code;
	this->pbCode = pbCode;
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
	int no = 0;
	for (int t = 1; t <= this->Dim; t++) {
		bool local = false;
		point vN(vC, -1);
		while (!local) {
			no++;

			if (this->pbCode == 1) vN.firstHC();
			else if (this->pbCode == 2) {
				vN.bestHC();
			}
			else if (this->pbCode == 4) {
				vN.firstHC();
				point vSA(vC, -1);

				while (Temperature > MinTemperature) {
					int condition = 2 * this->Dim;
					while (condition) {
						point vSAj(vC, -1);
						vSAj.randomSA(vC);
						if (vSAj.value < vC.value) {
							vC.copy(vSAj);
							vSA.copy(vSAj);
						}
						else if (random() < exp((vC.value - vSAj.value) / Temperature)) {
							vC.copy(vSAj);
							vSA.copy(vSAj);
						}
						condition--;
					}
					Temperature = Temperature * (0.9 - Temperature / 100);


					if (vN.value > vSA.value) {
						vC.copy(vN);
					}
					if (vC.value < 20) {
						break;
					}
				}
			}
			else if (this->pbCode == 5) {
				vN.bestHC();
				point vSA(vC, -1);
					while (Temperature > MinTemperature) {
						int condition = 2 * this->Dim;
						while (condition) {
							point vSAj(vC, -1);
							vSAj.randomSA(vC);
							if (vSAj.value < vC.value) {
								vC.copy(vSAj);
								vSA.copy(vSAj);
							}
							else if (random() < exp((vC.value - vSAj.value) / Temperature)) {
								vC.copy(vSAj);
								vSA.copy(vSAj);
							}
							condition--;
						}
						Temperature = Temperature * (0.9 - Temperature / 100);
					}
				if (vN.value > vSA.value) {
					vC.copy(vN);
				}
				if (vC.value < 20) {
					break;
				}
			}

			if (vN.value < vC.value) {
				vC.copy(vN);
			}
			else
				local = true;
		}
		if (vBEST.value > vC.value) {
			vBEST.copy(vC);
		}
		if (vC.value < 20) {
			break;
		}
		/*return vC.value;
		vC.reset();*/
	}
	cout << "S-au executat " << no << " functii de evaluare" << endl;
	return vBEST.value;
}