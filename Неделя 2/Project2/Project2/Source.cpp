#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/*bool IsPalindrom(string word)
*{
*	int len = word.length();
*	for (int i = 0; i < len / 2; ++i)
*	{
*		if (word[i] != word[len - i - 1])
*		{
*			return false;
*		}
*	}
*	return true;
}*/

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;
	for (int j = 0; j < words.size(); ++j) {
		int x = 0;
		string w;
		int len = words[j].size();
		w = words[j];
		for (int i = 0; i < len / 2; ++i) {
			if (w[i] != w[len - i - 1]) {
				x = 1;
				break;
			}
		}
		if (x == 0 && len >= minLength)
			result.insert(result.end(), w);
	}
	return result;
}

int main(){
	/*vector<string> a;
	*cin >> a;
	*std::istream >> std::a;
	*int b;
	*cin >> b;
	cout >> PalindromFilter(a, b);
	*/return 0;
}