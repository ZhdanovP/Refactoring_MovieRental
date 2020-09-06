#include "movie.hpp"

Movie::Movie(std::string title, size_t priceCode) {
	m_title = title;
	m_priceCode = priceCode;
}

int Movie::getPriceCode(void) {
	return m_priceCode;
}

void Movie::setPriceCode(int priceCode) {
	m_priceCode = priceCode;
}

std::string Movie::getTitle() {
	return m_title;
}