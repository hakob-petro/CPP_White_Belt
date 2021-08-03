#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<string> a(3);
	for (int i = 0; i <= 2; ++i) {
		cin >> a[i];
	}
	sort(begin(a), end(a));
	cout << a[0];
	system("pause");
	return 0;
}