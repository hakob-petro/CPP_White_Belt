#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int Factorial(int x){
	int s = 1;
	if (x < 0){
		return 1;
	}
	else{
		for (int i = 1; i <= x; ++i) {
			s *= i;
		}
		return s;
	}
}

int main() {
	int a; // z;
	cin >> a;
	//z = Factorial(a);
	cout << Factorial(a) << endl;
	system("pause");
	return 0;
}