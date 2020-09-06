#include "customer.hpp"

std::string Customer::statement()
{
	double totalAmount = 0;
	std::string result;
	int frequentRenterPoints = 0;
	std::vector<std::shared_ptr<Rental>>::iterator rentals = m_rentals.begin();

	result = "Lease accounting for " + getName() + ":\n";

	while(rentals != m_rentals.end())
	{
		double thisAmount = 0;
		std::shared_ptr<Rental> each = *rentals;

		// Determine the amount for each line
		switch(each->getMovie()->getPriceCode())
		{
		case Movie::REGULAR:
			thisAmount+=2;
			if(each->getDaysRented() > 2)
				thisAmount+=(each->getDaysRented()- 2) * 15;
			break;
		case Movie::NEW_RELEASE:
			thisAmount += each->getDaysRented() * 3;
		    break;
		case Movie::CHILDREN:
			thisAmount+=15;
			if(each->getDaysRented() > 3)
				thisAmount += (each->getDaysRented() -3)*15;
			break;
		}
		// add points for active tenant
		frequentRenterPoints++;
		// bonus for renting new items for two days
		if(each->getMovie()->getPriceCode() == Movie::NEW_RELEASE && each->getDaysRented() > 1)
			frequentRenterPoints++;

		// show result for this rental
		result += "\t" + each->getMovie()->getTitle() + "\t" + std::to_string(thisAmount) + "\n";
		totalAmount+=thisAmount;
		rentals++;
	}

	// add footer
	result += "The owed amount is " + std::to_string(totalAmount) + ". ";
	result += "You've earned " + std::to_string(frequentRenterPoints) + " points for activity.";

	return result;
}