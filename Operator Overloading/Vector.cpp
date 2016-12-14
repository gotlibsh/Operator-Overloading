#include "Vector.h"
#include <ostream>
#include <cmath>

Vector::Vector(size_t size, const Fraction & frac)
	:m_dataStructure(size, frac)
{}

Vector::Vector(size_t size, const Fraction * arr)
	:m_dataStructure(size, arr)
{}

DataStructure Vector::getDataStructure() const
{
	return m_dataStructure;
}

const Fraction& Vector::operator[](const int i) const
{
	return m_dataStructure[i];
}

Fraction& Vector::operator[](const int i)
{
	return m_dataStructure[i];
}

Vector operator+(const Vector & lhs, const Vector & rhs)
{
	size_t l_size = lhs.getDataStructure().size();
	size_t r_size = rhs.getDataStructure().size();
	Vector temp(l_size);

	for (int i = 0; i < l_size; i++)
	{
		if (i < r_size)
			temp[i] = lhs[i] + rhs[i];
		else
			temp[i] = lhs[i];
	}

	return temp;
}

Vector operator-(const Vector & lhs, const Vector & rhs)
{

	size_t l_size = lhs.getDataStructure().size();
	size_t r_size = rhs.getDataStructure().size();
	Vector temp(l_size);

	for (int i = 0; i < l_size; i++)
	{
		if (i < r_size)
			temp[i] = lhs[i] - rhs[i];
		else
			temp[i] = lhs[i];
	}

	return temp;
}

Vector operator*(const Vector & lhs, const Vector & rhs)
{
	size_t l_size = lhs.getDataStructure().size();
	size_t r_size = rhs.getDataStructure().size();
	Vector temp(fmax(l_size, r_size));

	for (int i = 0; i < l_size; i++)
	{
		if (i < r_size)
			temp[i] = lhs[i] * rhs[i];
		else
			temp[i] = Fraction(0, 1);
	}

	return temp;
}


Vector operator*(const Fraction & scalar, Vector & rhs)
{
	size_t size = rhs.getDataStructure().size();
	Vector temp(size);

	for (int i = 0; i < size; i++)
	{
		temp[i] = rhs[i] * scalar;
	}

	return temp;
}

Vector operator*(Vector & lhs, const Fraction & scalar)
{
	return (scalar * lhs);
}

Vector & operator+=(Vector & lhs, const Vector & rhs)
{
	lhs = lhs + rhs;

	return lhs;
}

Vector & operator-=(Vector & lhs, const Vector & rhs)
{
	lhs = lhs - rhs;

	return lhs;
}

Vector & operator*=(Vector & lhs, const Vector & rhs)
{
	lhs = lhs * rhs;

	return lhs;
}

std::ostream & operator<<(std::ostream & output, const Vector & v)
{
	size_t size = v.getDataStructure().size();

	for (int i = 0; i < size; i++)
	{
		output << v[i] << " ";
	}

	return output;
}
