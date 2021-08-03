#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");
	int number;
	double N, M;
	input >> N;
	input >> M;
	//cout << fixed << setprecision(3);
	cout << right;
	while (N !=0) {
		for (int i = M; i > 0; i--) {
			input >> number;
			input.ignore(1);
			cout << setw(10) << number;
		}
		cout << endl;
		N--;
	}
	system("pause");
	return 0;
}