#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <iostream>

class Movie
{
public:
	enum PriceCodeType
	{
	   CHILDREN,
	   REGULAR,
	   NEW_RELEASE
	};

	Movie(std::string title, size_t priceCode);

	int getPriceCode(void);

	void setPriceCode(int priceCode);

	std::string getTitle();

	bool operator==(const Movie& m) const {
		return m_title == m.m_title && m_priceCode == m.m_priceCode;
	}

private:
	std::string m_title;
	size_t m_priceCode;
};


#endif