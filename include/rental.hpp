#ifndef RENTAL_HPP
#define RENTAL_HPP

#include "movie.hpp"
#include <iostream>

class Rental
{
public:
	Rental(std::shared_ptr<Movie> movie, const size_t daysRented);

	~Rental(void);

	size_t getDaysRented(void);

	std::shared_ptr<Movie> getMovie(void);

private:
	std::shared_ptr<Movie> m_movie;
	size_t m_daysRented;
};

#endif