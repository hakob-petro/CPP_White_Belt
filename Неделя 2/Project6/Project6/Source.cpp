#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
 
using namespace std;

int main() {
	int Q;
	cin >> Q;
	int N, i = 0, k = 1, l = 0;
	string stop;
	vector<string> stops;
	map<int, vector<string>> bus;

	while (i < Q)
	{
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> stop;
			stops.push_back(stop);
		}
		bus[k] = stops;
		if (k != 1) {
			for (int p = k - 1; p > 0; --p) {
				if (bus[p] == stops) {
					cout << "Already exists for " << p << endl;
					l = 1;
				}
			}
			if (l != 1) {
				cout << "New bus " << k << endl;
				++k;
			}
		}
		else {
			cout << "New bus " << k << endl;
			++k;
		}
		++i;
	}

	system("pause");
	return 0;
}	