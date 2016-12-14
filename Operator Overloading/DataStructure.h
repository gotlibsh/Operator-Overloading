#pragma once
#include "Fraction.h"

class DataStructure
{
public:
	//	Constructors
	DataStructure(size_t size = 0, const Fraction & frac = Fraction{});
	DataStructure(size_t size, const Fraction * arr);
	DataStructure(const DataStructure & other);
	
	//	Destructor
	~DataStructure();

	//	Operators
	DataStructure& operator=(const DataStructure & other);
	const Fraction& operator[](const int i) const;
	Fraction& operator[](const int i);

	//	Public Member Functions
	size_t size() const;
private:
	void initialize(const Fraction * arr, size_t size);
	void swap(DataStructure & other);
	Fraction *m_ptr;
	size_t m_size;
};

//	Binary Operators
DataStructure operator+(const DataStructure & lhs, const DataStructure & rhs);
DataStructure& operator+=(DataStructure & lhs, const DataStructure & rhs);
bool operator==(const DataStructure & lhs, const DataStructure & rhs);
bool operator!=(const DataStructure & lhs, const DataStructure & rhs);