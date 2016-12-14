#include "Fraction.h"
#include "Utilities.h"
#include <ostream>
#include <cmath>

//+-----------------------------------------------------+
//|						Constructors					|
//+-----------------------------------------------------+

/*
*	Assigns the numerator & denominator given 2 integers, uses 0 as default.
*/
Fraction::Fraction(int numerator, int denominator)
{
	if (numerator == 0 || denominator == 0)
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	else
	{
		int temp = gcd(abs(numerator), abs(denominator));

		m_numerator = numerator / temp;
		m_denominator = denominator / temp;

		if (m_denominator < 0)
		{
			if (m_numerator < 0)
			{
				m_numerator = abs(m_numerator);
				m_denominator = abs(m_denominator);
			}
			else
			{
				m_numerator = -m_numerator;
				m_denominator = abs(m_denominator);
			}
		}
	}
}

/*
*	Assigns numerator & denominator given a decimal number.
*/
Fraction::Fraction(double frac)
	:Fraction(frac * 1000, 1000)
{}

//+-----------------------------------------------------+
//|				Public Member Functions					|
//+-----------------------------------------------------+

/*
*	Returns the numerator of the fraction.
*/
int Fraction::getNumerator() const
{
	return m_numerator;
}

/*
*	Returns the denominator of the fraction.
*/
int Fraction::getDenominator() const
{
	return m_denominator;
}

/* 
*	Returns the fraction as a decimal number.
*/
double Fraction::getDecimalFraction() const
{
	return (double)m_numerator / m_denominator;
}

/*
*	Returns the fraction needed to complete the current fraction to the next integer.
*/
Fraction Fraction::distToNextInt() const
{
	int numerator = m_denominator - (m_numerator % m_denominator);

	//	Takes care of a negative number.
	numerator -= (m_numerator < 0) ? m_denominator : 0;

	return Fraction(numerator, m_denominator);
}

//+-----------------------------------------------------+
//|					Public Functions					|
//+-----------------------------------------------------+

/*
*	Returns the sum: lhs + rhs
*/
Fraction operator+(const Fraction & lhs, const Fraction & rhs)
{
	int numerator = (lhs.getNumerator() * rhs.getDenominator()) + 
					(rhs.getNumerator() * lhs.getDenominator());
	int denominator = lhs.getDenominator() * rhs.getDenominator();

	return Fraction(numerator, denominator);
}

/*
*	Returns the subtraction: lhs - rhs
*/
Fraction operator-(const Fraction & lhs, const Fraction & rhs)
{
	return lhs + (-rhs);
}

/*
*	Returns the multiplying: lhs * rhs
*/
Fraction operator*(const Fraction & lhs, const Fraction & rhs)
{
	int numerator = lhs.getNumerator() * rhs.getNumerator();
	int denominator = lhs.getDenominator() * rhs.getDenominator();

	return Fraction(numerator, denominator);
}

/*
*	Returns the division: lhs / rhs
*/
Fraction operator/(const Fraction & lhs, const Fraction & rhs)
{
	return lhs * Fraction(rhs.getDenominator(), rhs.getNumerator());
}

/*
*	Returns a reference of (lhs + rhs) after adding rhs to lhs.
*/
Fraction & operator+=(Fraction & lhs, const Fraction & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

/*
*	Returns a reference of (lhs - rhs) after subtracting rhs from lhs.
*/
Fraction & operator-=(Fraction & lhs, const Fraction & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

/*
*	Returns a reference to (lhs * rhs) after multiplying lhs by rhs.
*/
Fraction & operator*=(Fraction & lhs, const Fraction & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

/*
*	Returns a reference to (lhs / rhs) after dividing lhs by rhs.
*/
Fraction & operator/=(Fraction & lhs, const Fraction & rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

/*
*	Returns the fraction multiplied by (-1).
*/
Fraction operator-(const Fraction & frac)
{
	return Fraction(-frac.getNumerator(), frac.getDenominator());
}

/*
*	Returns the fraction as is and adds 1 to it (postfix).
*/
Fraction operator++(Fraction & frac, int)
{
	++frac;
	return (frac - Fraction(1, 1));
}

/*
*	Returns the fraction as is and subtracts 1 of it (postfix).
*/
Fraction operator--(Fraction & frac, int)
{ 
	--frac;
	return frac + Fraction(1, 1);
}

/*
*	Returns the fraction after adding 1 to it (prefix).
*/
Fraction & operator++(Fraction & frac)
{
	frac += Fraction(1, 1);
	return frac;
}

/*
*	Returns the fraction after subtracting 1 of it (prefix).
*/
Fraction & operator--(Fraction & frac)
{
	frac -= Fraction(1, 1);
	return frac;
}

/*
*	Returns whether the 2 fractions are equal or not.
*/
bool operator==(const Fraction & lhs, const Fraction & rhs)
{
	return (lhs.getNumerator() == rhs.getNumerator()) &&
		(lhs.getDenominator() == rhs.getDenominator());
}

/*
*	Returns whether the 2 fractions are different from each other or not.
*/
bool operator!=(const Fraction & lhs, const Fraction & rhs)
{
	return !(lhs == rhs);
}

/*
*	Returns whether the left-side fraction is less than the right one or not.
*/
bool operator<(const Fraction & lhs, const Fraction & rhs)
{
	Fraction r_min_l = rhs - lhs;

	return (r_min_l.getNumerator() > 0);
}

/*
*	Returns whether the left-side fraction is greater than the right one or not.
*/
bool operator>(const Fraction & lhs, const Fraction & rhs)
{
	return !(lhs <= rhs);
}

/*
*	Returns whether the left-side fraction is less than or equal to the right one or not.
*/
bool operator<=(const Fraction & lhs, const Fraction & rhs)
{
	return (lhs < rhs) || (lhs == rhs);
}

/*
*	Returns whether the left-side fraction is greater than or equal to the right one or not.
*/
bool operator>=(const Fraction & lhs, const Fraction & rhs)
{
	return !(lhs < rhs);
}

/*
*	Returns a reference to an ostream object after outputting the fraction.
*/
std::ostream & operator<<(std::ostream & output, const Fraction & frac)
{
	output << frac.getNumerator() << '/' << frac.getDenominator();

	return output;
}
