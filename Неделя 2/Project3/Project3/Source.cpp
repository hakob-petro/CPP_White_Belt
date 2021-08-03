#include <iostream>
#include <string> 
#include <vector>
using namespace std;

/*
void UpdateIfGreater(int first, int& second) {
	if (first > second)
		second = first;
}
*/

/*
void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto x : source) {
		destination.push_back(x);
	}
	source.clear();
}
*/

vector<int> Reversed(const vector<int>& v) {
	vector<int> x;
	for (int i = 0; i < v.size(); ++i) {
		x.push_back(v[v.size() - i -1]);
	}
	return x;
}

int main() {
	//vector<string> source = { "a", "b", "c" };
	//vector<string> destination = { "z" };
	//MoveStrings(source, destination);
	//cout << source[0] << endl;
	//cout << destination[2] << endl;
	return 0;
}