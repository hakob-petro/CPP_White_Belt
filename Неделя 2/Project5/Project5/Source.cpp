#include <iostream>
#include <string>
using namespace std;

int main()
{
	string base_str = ",, 11, 2222 , 33333,44, ";   // �������� ������
	string delim = " ";   // ������ ��� ������ �����������
	size_t pos = 0;
	size_t base_str_size = base_str.size();
	size_t delim_size = delim.size();
	string temp;
	while (pos < base_str_size) {
		temp = temp.assign(base_str, pos, base_str.find(delim, pos) - pos);
		if (temp.size() > 0)  // �������� �� ������ ������ ��� �������������
			cout << temp << endl;
		pos += temp.size() + delim_size;
	}
	system("pause");
	return 0;
}