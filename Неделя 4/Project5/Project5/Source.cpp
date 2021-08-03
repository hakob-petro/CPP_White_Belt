#include <iostream>
#include <numeric>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		if (numerator == 0) {
			p = numerator;
			q = 1;
		}
		else if (denominator == 0) {
			throw invalid_argument("LOL, denomiator is zero!");
		}
		else {
			del = gcd(numerator, denominator);
			if (del != 0) {
				p = numerator / del;
				q = denominator / del;
			}
			else {
				p = numerator;
				q = denominator;
			}
			if (numerator < 0) {
				if (denominator < 0) {
					p = -p;
					q = -q;
				}
			}
			else if (numerator > 0) {
				if (denominator < 0) {
					p = -p;
					q = -q;
				}
			}
		}

	}

	int Numerator() const {
		return p;
	}

	int Denominator() const {
		return q;
	}

private:
	int p, q, del;
};

bool operator==(const Rational& num1, const Rational& num2) {
	if (num1.Numerator() == num2.Numerator() && num1.Denominator() == num2.Denominator())
		return 1;
	else
		return 0;
}

Rational operator+(const Rational& num1, const Rational& num2) {
	return { num1.Numerator()*num2.Denominator() + num2.Numerator()*num1.Denominator(), num1.Denominator()*num2.Denominator() };
}

Rational operator-(const Rational& num1, const Rational& num2) {
	return { num1.Numerator()*num2.Denominator() - num2.Numerator()*num1.Denominator(), num1.Denominator()*num2.Denominator() };
}

Rational operator*(const Rational& num1, const Rational& num2) {
	return { num1.Numerator()*num2.Numerator(), num1.Denominator()*num2.Denominator() };
}

Rational operator/(const Rational& num1, const Rational& num2) {
	if (num2.Numerator() == 0)
		throw domain_error("LOL, divisor is zero!");
	return { num1.Numerator()*num2.Denominator(), num1.Denominator()*num2.Numerator() };
}

ostream& operator<<(ostream& stream, const Rational& num) {
	stream << num.Numerator() << '/' << num.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& num) {
	int numerator, denominator;
	char operation;
	if (stream >> numerator) {
		stream >> operation;
		if(operation == '/')
			if(stream >> denominator)
				num = { numerator, denominator };
	}
	return stream;
}

bool operator<(const Rational& num1, const Rational& num2) {
	if (num1.Numerator()*num2.Denominator() - num2.Numerator()*num1.Denominator() < 0)
		return 1;
	else
		return 0;
}

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			system("pause");
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			system("pause");
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			system("pause");
			return 3;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			system("pause");
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			system("pause");
			return 2;
		}
	}

	{
		istringstream input("");
		Rational r;
		bool correct = !(input >> r);
		if (!correct) {
			cout << "Read from empty stream works incorrectly" << endl;
			system("pause");
			return 3;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			system("pause");
			return 4;
		}
		
		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			system("pause");
			return 5;
		}
	}

	{
		istringstream input1("1*2"), input2("1/"), input3("/4");
		Rational r1, r2, r3;
		input1 >> r1;
		input2 >> r2;
		input3 >> r3;
		bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
		if (!correct) {
			cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
				<< r1 << " " << r2 << " " << r3 << endl;
			system("pause");
			return 6;
		}
	}

	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			system("pause");
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			system("pause");
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			system("pause");
			return 3;
		}
	}

	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}
	
	cout << "OK" << endl;
	system("pause");
	return 0;
}