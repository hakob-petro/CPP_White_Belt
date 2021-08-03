#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*map<char, int> BuildCharCounters(const string & word) {
	map<char, int>  letters;
	for (int w = 0; w < word.size(); ++w) {
		++letters[word[w]];
	}
	return letters;
}


int main() {
	int N, i = 0;
	string word_1, word_2;
	vector<string> result;
	cin >> N;

	while (i < N) {
		int indikator = 0;
		cin >> word_1;
		cin >> word_2;
		map<char, int> letters_1 = BuildCharCounters(word_1);
		map<char, int> letters_2 = BuildCharCounters(word_2);
		if (letters_1.size() == letters_2.size() ) {
			for (int k = 0; k < word_1.size(); ++k) {
				if (letters_1[word_1[k]] == letters_2[word_1[k]]) {
					++indikator;
				}
			}	
			if (indikator == (word_1.size())) {
				result.push_back("YES");
			}
			else {
				result.push_back("NO");
			}
		} 
		else {
			result.push_back("NO");
		}

		++i;
	}

	for (int j = 0; j < result.size(); ++j) {
		cout << result[j] << endl;
	}

	system("pause");
	return 0;
}*/			

int main() {
	int q;
	cin >> q;

	map<string, string> country_to_capital;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "CHANGE_CAPITAL") {

			string country, new_capital;
			cin >> country >> new_capital;
			if (country_to_capital.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}
			else {
				const string& old_capital = country_to_capital[country];
				if (old_capital == new_capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else {
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
				}
			}
			country_to_capital[country] = new_capital;

		}
		else if (operation_code == "RENAME") {

			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] <<
					" has been renamed to " << new_country_name << endl;
				country_to_capital[new_country_name] = country_to_capital[old_country_name];
				country_to_capital.erase(old_country_name);
			}

		}
		else if (operation_code == "ABOUT") {

			string country;
			cin >> country;
			if (country_to_capital.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
			}

		}
		else if (operation_code == "DUMP") {

			if (country_to_capital.empty()) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (const auto& country_item : country_to_capital) {
					cout << country_item.first << "/" << country_item.second << " ";
				}
				cout << endl;
			}

		}

	}

	return 0;
}
