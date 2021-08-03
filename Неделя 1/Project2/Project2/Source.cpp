#include <iostream>
#include <string>
using namespace std;

int main() {
	double N, A, B, X, Y;;
	cin >> N >> A >> B >> X >> Y;
	if (N > A && N <= B) {
		N = N - (N * X / 100);
		cout << N;
	}
	else if (N > B) {
		N = N - (N * Y / 100);
		cout << N;
	}
	else if (N <= A) {
		cout << N;
	}
	system("pause");
	return 0;
}