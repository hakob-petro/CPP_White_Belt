#include <iostream>
#include <string>
using namespace std;

int main() {
	int j = 0, p = 0;
	string noun;
	cin >> noun;
	for (int i = 0; i <= noun.size(); ++i) {
		if (noun[i] = 'f' && j > 0) {
			j++;
			break;
			cout << p;
		} else if (noun[i] = 'f' && j == 0) {
			p = i;
			j = j + 1;
		}
	}
	if (p = 0)
		cout << -2;
	else if ( j = 1)
		cout << -1;
	system("pause");
	return 0;
}