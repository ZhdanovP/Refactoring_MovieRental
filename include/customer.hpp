#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <iostream>
#include <vector>
#include "rental.hpp"

class Customer
{
public:
	Customer(std::string name)
	: m_name(name) { }

	~Customer(void) { }

	void addRental(std::shared_ptr<Rental> rental)
	{
		m_rentals.push_back(rental);
	}

	std::string getName(void)
	{
		return m_name;
	}

	std::string statement();

private:
 std::string m_name;
 std::vector<std::shared_ptr<Rental> > m_rentals;
};

#endif
