#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int q;
	set<string> words;
	string word;
	cin >> q;
	while (q != 0) {
		cin >> word;
		words.insert(word);
		q--;
	}
	cout << words.size();
	system("pause");
	return 0;
}
