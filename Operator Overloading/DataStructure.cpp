#include "DataStructure.h"
#include <algorithm>

DataStructure::DataStructure(size_t size, const Fraction & frac)
{
	if (size == 0)
	{
		m_size = 0;
		m_ptr = nullptr;
	}
	else
	{
		m_size = size;
		m_ptr = new Fraction[m_size];

		for (int i = 0; i < m_size; i++)
		{
			m_ptr[i] = frac;
		}
	}
}

DataStructure::DataStructure(size_t size, const Fraction * arr)
{
	initialize(arr, size);
}

//	Copy c-tor
DataStructure::DataStructure(const DataStructure & other)
{
	initialize(other.m_ptr, other.m_size);
}

//	Assignment operator
DataStructure & DataStructure::operator=(const DataStructure & other)
{
	DataStructure temp = other;
	temp.swap((*this));

	return (*this);
}

const Fraction& DataStructure::operator[](const int i) const
{
	return m_ptr[i];
}

Fraction& DataStructure::operator[](const int i)
{
	return m_ptr[i];
}

size_t DataStructure::size() const
{
	return m_size;
}

DataStructure::~DataStructure()
{
	delete[] m_ptr;
}

void DataStructure::initialize(const Fraction * arr, size_t size)
{
	m_size = size;

	if (size == 0)
	{
		m_ptr = nullptr;
	}
	else
	{	
		m_ptr = new Fraction[m_size];

		for (int i = 0; i < m_size; i++)
		{
			m_ptr[i] = arr[i];
		}
	}
}

void DataStructure::swap(DataStructure & other)
{
	using std::swap;
	swap(m_ptr, other.m_ptr);
	swap(m_size, other.m_size);
}

DataStructure operator+(const DataStructure & lhs, const DataStructure & rhs)
{
	size_t size = lhs.size() + rhs.size();
	DataStructure temp(size);
	int i;

	for (i = 0; i < lhs.size(); i++)
	{
		temp[i] = lhs[i];
	}
	for (i = 0; i < rhs.size(); i++)
	{
		temp[i + lhs.size()] = rhs[i];
	}

	return temp;
}

DataStructure & operator+=(DataStructure & lhs, const DataStructure & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const DataStructure & lhs, const DataStructure & rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}

	for (int i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

bool operator!=(const DataStructure & lhs, const DataStructure & rhs)
{
	return !(lhs == rhs);
}
