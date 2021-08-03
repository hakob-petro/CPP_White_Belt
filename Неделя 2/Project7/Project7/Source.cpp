#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> queue, worry, worry_sizes;
	string command;
	int i = 0, number_of_commands, number, size_queue;
	
	cin >> number_of_commands;

	while (i < number_of_commands) {
		size_queue = queue.size();
		cin >> command;

		if (command != "WORRY_COUNT") {
			cin >> number;
			if (command == "COME" && number >= 0) {
				for (int j = size_queue; j < size_queue + number; ++j)
					queue.push_back(j);
			}
			else if (command == "COME" && number < 0) {
				for (int j = size_queue; j > size_queue + number; --j) {
					int m = worry.size();
					if (m != 0 && worry[m - 1] == queue[j - 1]) {
						worry.pop_back();
						queue.pop_back();
					}
					else queue.pop_back();
				}
			}

			if (command == "WORRY") {
				worry.push_back(number);
				sort(worry.begin(), worry.end());
			}

			if (command == "QUIET") {
				int p = worry.size();
				for (int i = 0; i < p; i++) {
					if (worry[i] == number) {
						worry.erase(worry.begin() + i);
					}
				}
			}
		}
		else worry_sizes.push_back(worry.size());
		++i;
	}

	int l = worry_sizes.size();
	for (int k = 0; k < l; ++k) {
		cout << worry_sizes[k] << endl;
	}

	system("pause");
	return 0;
}