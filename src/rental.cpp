#include "rental.hpp"

Rental::Rental(std::shared_ptr<Movie> movie, const size_t daysRented)
: m_movie(movie)
, m_daysRented(daysRented) {

}

Rental::~Rental(void) {

}

size_t Rental::getDaysRented(void) {
	return m_daysRented;
}

std::shared_ptr<Movie> Rental::getMovie(void) {
	return m_movie;
}