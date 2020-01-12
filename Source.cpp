#include "Point.h"
#include "HillClimbing.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <stdlib.h>
#include "SimulatedAnnelling.h"

using namespace std;
int maxIT, n, p_code, a_code;

void init() {
	system("CLS");
	cout << fixed;
	maxIT = 30;
	cout << "Problema pe care vrem sa o rezolvam:\n";
	cout << "1. De Jong 1" << endl;
	cout << "2. Schwefel 7" << endl;
	cout << "3. Rastrigin" << endl;
	cout << "4. Six-hump camel back\n" << endl;
	cin >> p_code;
	system("CLS");

	cout << "Alege algoritmul folosit pentru a rezolva problema" << endl;
	cout << "1. Hill Climbing - First Improvement" << endl;
	cout << "2. Hill Climbing - Best Improvement" << endl;
	cout << "3. Simulated Annealing\n" << endl;
	cout << "4. Hill Climbing - First Improvement + Simulated Annealing" << endl;
	cout << "5. Hill Climbing - Best Improvement + Simulated Annealing" << endl;
	cout << "6. Simulated Annealing + Hill Climbin - First Improvment" << endl;
	cout << "7. Simulated Annealing + Hill Climbin - Best Improvment" << endl;

	cin >> a_code;
	system("CLS");

	if (p_code <= 3) {
		cout << "Dimensiunea: ";
		cin >> n;
	}
	system("CLS");

	srand(time(NULL));
}

double random() {
	return rand() / RAND_MAX;
}

//void hillClimbing() {
//	point vC(n, p_code), vBest(vC, -1);
//	for (int t = 1; t <= maxIT; t++) {
//		bool local = false;
//		point vN(vC, -1);
//		while (!local) {
//
//			if (a_code == 1) vN.firstHC();
//			else  vN.bestHC();
//
//			if (vN.value < vC.value) {
//				vC.copy(vN);
//			}
//			else
//				local = true;
//		}
//		if (vBest.value > vC.value) {
//			vBest.copy(vC);
//		}
//		cout << "Iteratia " << t << ": " << vC.value << endl;
//		vC.reset();
//	}
//	cout << endl << "Minim obtinut:" << vBest.value;
//}

//void simulatedAnnealing() {
//	double maxim = -10000000;
//	point vC(n, p_code), vBest(n, p_code);
//	for (int i = 1; i <= maxIT; i++) {
//		double T = 5;
//		while (T > 0.00000001) {
//			int condition = 2 * n;
//			while (condition) {
//				point vN(vC, -1);
//				vN.randomSA(vC);
//				if (vN.value < vC.value) {
//					vC.copy(vN);
//				}
//				else if (random() < exp((vC.value - vN.value) / T)) {
//					vC.copy(vN);
//				}
//				condition--;
//			}
//			T = T * (0.9 - T / 100);
//		}
//		if (vC.value < vBest.value)
//			vBest.copy(vC);
//		cout << "Iteratia " << i << ": " << vC.value << endl;
//		vC.reset();
//	}
//	cout << endl << "Minim obtinut:" << vBest.value;
//}
//double HCFirstSA() {
//	HillClimbing deal = HillClimbing(n, 1);
//	cout << "Introduceti temperatura:";
//	int temp;
//	cin >> temp;
//	deal.SetTemperature(temp);
//	deal.InitializationNeighbours();
//	deal.SetMinTemperature();
//}
int main() {
	char quit = 'y';
	while (quit != 'n' && quit != 'N') {
		init();
		if (a_code <= 2 || a_code == 4 || a_code == 5)
		{
			HillClimbing deal = HillClimbing(n,p_code, a_code);
			cout << "Introduceti temperatura:";
			int temp;
			cin >> temp;
			deal.SetTemperature(temp);
			deal.InitializationNeighbours();
			deal.SetMinTemperature();
			cout << "Minim obtinut " << deal.ExecuteAlgoritm();
		}
		else if(a_code == 3 || a_code == 6 || a_code == 7)
		{
			SimulatedAnnelling Anne = SimulatedAnnelling(n, p_code,a_code);
			cout << "Introduceti temperatura:";
			int temp;
			cin >> temp;
			Anne.SetTemperature(temp);
			Anne.InitializationNeighbours();
			Anne.SetMinTemperature();
			cout << "Minim obtinut " << Anne.ExecuteAlgoritm()<<" "<< Anne.numberOfExecutions;
		}
		cout << "\n\nContinue? Y/N:";
		cin >> quit;
	}
	return 0;
}
