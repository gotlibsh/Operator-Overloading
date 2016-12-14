#pragma once
#include "DataStructure.h"
#include <iosfwd>

class Vector
{
public:
	//	Constructors
	Vector(size_t size = 0, const Fraction & frac = Fraction());
	Vector(size_t size, const Fraction * arr);
	DataStructure getDataStructure() const;
	//	Operators
	const Fraction& operator[](const int i) const;
	Fraction& operator[](const int i);
private:
	//	Private Data Members
	DataStructure m_dataStructure;
};

//	Binary Operators
Vector operator+(const Vector & lhs, const Vector & rhs);
Vector operator-(const Vector & lhs, const Vector & rhs);
Vector operator*(const Vector & lhs, const Vector & rhs);
Vector operator*(const Fraction & scalar, Vector & rhs);
Vector operator*(Vector & lhs, const Fraction & scalar);
Vector& operator+=(Vector & lhs, const Vector & rhs);
Vector& operator-=(Vector & lhs, const Vector & rhs);
Vector& operator*=(Vector & lhs, const Vector & rhs);
std::ostream& operator<<(std::ostream & output, const Vector & v);