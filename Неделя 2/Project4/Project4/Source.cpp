#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int main() {
	int N, i = 0, mid = 0, k = 0;
	vector<int> temp;
	vector<int> result;

	//cout << "Enter N = ";
	cin >> N;
	//cout << "Enter vector's items" << endl;
	while (i < N)
	{
		int x;
		cin >> x;
		temp.push_back(x);
		i++;
		mid = mid + x;
	}
	mid = mid / (temp.size()); 

	for (int j = 0; j < temp.size(); ++j) {
		if (temp[j] > mid) {
			result.insert(result.end(), j);
			k++;
		}
	}

	cout << k << endl;
	for (auto y : result)
		cout << y << " ";

	system("pause");
	return 0;
}