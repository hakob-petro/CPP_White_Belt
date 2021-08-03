#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		data[year].fn = first_name;
		if (year < minyear) {
			minyear = year;
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		data[year].ln = last_name;
		if (year < minyear) {
			minyear = year;
		}
	}

	string GetFullName(int year, bool history = false) {
		// получить имя и фамилию по состоянию на конец года year
		int i = 0, j = 0, cnt = 0, firsthist = 0, secondhist = 0;
		string firstsave, secondsave;
		while(data[year - i].fn.empty() && (year - i)>= minyear){
			i++;
		}
		if (data[year - i].fn.empty()) {
			cnt++;
		}
		else {
			result = data[year - i].fn;
			firstsave = data[year - i].fn;
			if (history == true) {
				for (int k = year - i - 1; k > minyear; --k) {
					if (!data[k].fn.empty() && firsthist == 0 && data[k].fn != data[year-i].fn && data[k].fn != firstsave) {
						result += " (" + data[k].fn;
						firsthist++;
						firstsave = data[k].fn;
					}
					else if(!data[k].fn.empty() && firsthist != 0 && data[k].fn != data[year - i].fn && data[k].fn != firstsave){
						result += ", " + data[k].fn;
						firstsave = data[k].fn;
					}
				}
				if (firsthist != 0) {
					result += ")";
				}

			}
		}

		while (data[year - j].ln.empty() && (year - j) >= minyear) {
			j++;
		}
		if (data[year - j].ln.empty()) {
			if (cnt == 0) {
				result += " with unknown last name";
			}
			else {
				result = "Incognito";
			}
			cnt++;
		}
		else {
			if (cnt == 1) {
				result = data[year - j].ln;
				secondsave = data[year - j].ln;
				if (history == true) {
					for (int k = year - j - 1; k > minyear; --k) {
						if (!data[k].ln.empty() && secondhist == 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
							result += " (" + data[k].ln;
							secondhist++;
							secondsave = data[k].ln;
						}
						else if (!data[k].ln.empty() && secondhist != 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
							result += ", " + data[k].ln;
							secondsave = data[k].ln;
						}
					}
					if (secondhist != 0) {
						result += ")";
					}
				}
				result += " with unknown first name";
			}
			else {
				result += " " + data[year - j].ln;
				if (history == true) {
					for (int k = year - j - 1; k > minyear; --k) {
						if (!data[k].ln.empty() && secondhist == 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
							result += " (" + data[k].ln;
							secondhist++;
							secondsave = data[k].ln;
						}
						else if (!data[k].ln.empty() && secondhist != 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
							result += ", " + data[k].ln;
							secondsave = data[k].ln;
						}
					}
					if (secondhist != 0) {
						result += ")";
					}
				}
			}
		}
		
			
		return result;
	}

	string GetFullNameWithHistory(int year) {
		// получить все имена и фамилии по состоянию на конец года year
		return GetFullName(year, true);
	}

private:
	// приватные поля
	struct FirstLast{
		string fn;
		string ln;
	};
	int minyear;
	string result;
	map<int, FirstLast> data;
};

//Without history

/* 
int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}


	system("pause");
	return 0;
}
*/

//With history

//1 test

int main() {
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;

	system("pause");
	return 0;
}


//2 test

// int main() {
// 	Person person;

// 	person.ChangeFirstName(1965, "Polina");
// 	person.ChangeLastName(1967, "Sergeeva");
// 	for (int year : {1900, 1965, 1990}) {
// 		cout << person.GetFullNameWithHistory(year) << endl;
// 	}

// 	person.ChangeFirstName(1970, "Appolinaria");
// 	for (int year : {1969, 1970}) {
// 		cout << person.GetFullNameWithHistory(year) << endl;
// 	}

// 	person.ChangeLastName(1968, "Volkova");
// 	for (int year : {1969, 1970}) {
// 		cout << person.GetFullNameWithHistory(year) << endl;
// 	}

// 	person.ChangeFirstName(1990, "Polina");
// 	person.ChangeLastName(1990, "Volkova-Sergeeva");
// 	cout << person.GetFullNameWithHistory(1990) << endl;

// 	person.ChangeFirstName(1966, "Pauline");
// 	cout << person.GetFullNameWithHistory(1966) << endl;

// 	person.ChangeLastName(1960, "Sergeeva");
// 	for (int year : {1960, 1967}) {
// 		cout << person.GetFullNameWithHistory(year) << endl;
// 	}

// 	person.ChangeLastName(1961, "Ivanova");
// 	cout << person.GetFullNameWithHistory(1967) << endl;

// 	system("pause");
// 	return 0;
// }



// 3 test
// int main() {
// 	Person person;

// 	person.ChangeFirstName(1965, "Polina");
// 	person.ChangeFirstName(1965, "Appolinaria");

// 	person.ChangeLastName(1965, "Sergeeva");
// 	person.ChangeLastName(1965, "Volkova");
// 	person.ChangeLastName(1965, "Volkova-Sergeeva");

// 	for (int year : {1964, 1965, 1966}) {
// 		cout << person.GetFullNameWithHistory(year) << endl;
// 	}


// 	system("pause");
// 	return 0;
// }
