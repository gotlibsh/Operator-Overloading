#pragma once
#include <iosfwd>

class Fraction
{
public:
	//	Constructors
	Fraction(int numerator = 0, int denominator = 1);
	Fraction(double frac);
	//	Public Member Functions
	int getNumerator() const;
	int getDenominator() const;
	double getDecimalFraction() const;
	Fraction distToNextInt() const;
private:
	//	Private Data Members
	int m_numerator;
	int m_denominator;
};

//	Binary Operator
Fraction operator+(const Fraction & lhs, const Fraction & rhs);
Fraction operator-(const Fraction & lhs, const Fraction & rhs);
Fraction operator*(const Fraction & lhs, const Fraction & rhs);
Fraction operator/(const Fraction & lhs, const Fraction & rhs);

Fraction& operator+=(Fraction & lhs, const Fraction & rhs);
Fraction& operator-=(Fraction & lhs, const Fraction & rhs);
Fraction& operator*=(Fraction & lhs, const Fraction & rhs);
Fraction& operator/=(Fraction & lhs, const Fraction & rhs);

//	Unary Operator
Fraction operator-(const Fraction & frac);
Fraction operator++(Fraction & frac, int);
Fraction operator--(Fraction & frac, int);
Fraction& operator++(Fraction & frac);
Fraction& operator--(Fraction & frac);

//	Logic Operators
bool operator==(const Fraction & lhs, const Fraction & rhs);
bool operator!=(const Fraction & lhs, const Fraction & rhs);
bool operator<(const Fraction & lhs, const Fraction & rhs);
bool operator>(const Fraction & lhs, const Fraction & rhs);
bool operator<=(const Fraction & lhs, const Fraction & rhs);
bool operator>=(const Fraction & lhs, const Fraction & rhs);

//	Extraction Operator
std::ostream& operator<<(std::ostream& output, const Fraction & frac);