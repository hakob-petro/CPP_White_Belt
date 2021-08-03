#include <iostream>
#include <numeric>
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
	return {num1.Numerator()*num2.Denominator() + num2.Numerator()*num1.Denominator(), num1.Denominator()*num2.Denominator()};
}

Rational operator-(const Rational& num1, const Rational& num2) {
	return {num1.Numerator()*num2.Denominator() - num2.Numerator()*num1.Denominator(), num1.Denominator()*num2.Denominator()};
}

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
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
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}