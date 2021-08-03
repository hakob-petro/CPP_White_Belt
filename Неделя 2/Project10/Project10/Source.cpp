#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int q, day, dump =0, month = 0;
	string command, task;
	vector<int> result_sizes, months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> result_dumps(1000), tasks(31);
	cin >> q;
	for(int i = 0; i < q; ++i)
	{
		cin >> command;
		if (command == "ADD") {
			cin >> day;
			cin >> task;
			tasks[day-1].push_back(task);
		}

		else if (command == "DUMP") {
			cin >> day;
			int size;
			size = tasks[day - 1].size();
			result_sizes.push_back(size);
			for (int j = 0; j < size; ++j) {
				result_dumps[dump].push_back(tasks[day - 1][j]);
			}
			dump++;
		}
		else {
			if (month != 11) {
				if (months[month] <= months[month + 1]) {
					tasks.resize(months[month + 1]);
				}
				else {
					vector<string> diff_tasks;
					for (int k = months[month + 1]; k < months[month]; ++k) {
						for (auto l : tasks[k])
							diff_tasks.push_back(l);
					}
					tasks.resize(months[month + 1]);
					for (auto job : diff_tasks)
						tasks[months[month + 1] - 1].push_back(job);
				}
			}
			else
				tasks.resize(months[0]);
			month++;
			if (month == 12) {
				month == 0;
			}
			tasks.resize(months[month]);
		}
	}

	for (int p = 0; p < result_sizes.size(); p++) {
		cout << result_sizes[p] << " ";
		for (int u = 0; u < result_dumps[p].size(); ++u)
			cout << result_dumps[p][u] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}