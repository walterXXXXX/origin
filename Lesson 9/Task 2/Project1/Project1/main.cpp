#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	void simplifyingFraction() {
		int count;
		if (numerator_ < denominator_) count = numerator_ / 2; else count = denominator_ / 2;
		for (int i = 2; i <= count; i++) {
			if (numerator_ % i == 0 && denominator_ % i == 0) {
				numerator_ /= i;
				denominator_ /= i;
				simplifyingFraction();
				break;
			}
		}
		return;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	int getNumerator() { return numerator_; }
	int getDenominator() { return denominator_; }
	void setNumerator(int numerator) { numerator_ = numerator; }
	void setDenominator(int denominator) { denominator_ = denominator; }

	Fraction operator+(Fraction& other) {
		Fraction fr(1, 1);
		if (denominator_ == other.denominator_) {
			fr.setNumerator(numerator_ + other.getNumerator()); 
			fr.setDenominator(denominator_);
		}
		else {
			fr.setNumerator(numerator_ * other.getDenominator() + denominator_ * other.getNumerator());
			fr.setDenominator(denominator_ * other.getDenominator());
		}
		fr.simplifyingFraction();
		return fr;
	}
	Fraction operator-(Fraction& other) {
		Fraction fr(1, 1);
		if (denominator_ == other.denominator_) {
			fr.setNumerator(numerator_ - other.getNumerator());
			fr.setDenominator(denominator_);
		}
		else {
			fr.setNumerator(numerator_ * other.getDenominator() - denominator_ * other.getNumerator());
			fr.setDenominator(denominator_ * other.getDenominator());
		}
		fr.simplifyingFraction();
		return fr;
	}
	Fraction operator*(Fraction& other) {
		Fraction fr(1, 1);
		fr.setNumerator(numerator_ * other.getNumerator());
		fr.setDenominator(denominator_ * other.getDenominator());
		fr.simplifyingFraction();
		return fr;
	}
	Fraction operator/(Fraction& other) {
		Fraction fr(1, 1);
		fr.setNumerator(numerator_ * other.getDenominator());
		fr.setDenominator(denominator_ * other.getNumerator());
		fr.simplifyingFraction();
		return fr;
	}
	// префикс
	Fraction& operator++() {
		numerator_ += denominator_;
		simplifyingFraction();
		return *this;
	}
	Fraction& operator--() {
		numerator_ -= denominator_;
		simplifyingFraction();
		return *this;
	}
	//постфикс
	Fraction operator++(int) {
		Fraction temp = *this;
		++(*this);
		simplifyingFraction();
		return temp;
	}
	Fraction operator--(int) {
		Fraction temp = *this;
		--(*this);
		simplifyingFraction();
		return temp;
	}
};

std::ostream& operator<<(std::ostream& stream, Fraction fr) {
	stream << fr.getNumerator() << "/" << fr.getDenominator();
	return stream;
}

int main()
{
	setlocale(LC_ALL, "");

	int num{ 1 }, den{ 1 };
	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> num;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> den;
	Fraction f1(num, den);

	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> num;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> den;
	Fraction f2(num, den);

	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
	std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;

	std::cout << "++" << f1 << " * " << f2 << " = ";
	std::cout << ++f1 * f2 << std::endl;
	std::cout << "«начение дроби 1 = " << f1 << std::endl;

	std::cout << f1 << "-- * " << f2 << " = " << f1-- * f2 << std::endl;
	std::cout << "«начение дроби 1 = " << f1 << std::endl;

	return 0;
}