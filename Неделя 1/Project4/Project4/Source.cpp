#include <iostream>
#include <string>
using namespace std;

int main() {
	int j = 0, s = 0;
	string noun;
	cin >> noun;
 	for (int i = 0; i <= noun.size(); ++i) {
		if (noun[i] == 'f')
		{
			j += 1;
		}
		if (noun[i] == 'f' && j == 2) {
			cout << i;
		}
	}
	if (j == 0) {
		cout << -2;
	}
	if (j == 1) {
		cout << -1;
	}
	/*if (j >= 2) {
		cout << s;
	}*/
	system("pause");
	return 0;
}