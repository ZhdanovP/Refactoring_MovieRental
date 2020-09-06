#include "gtest/gtest.h"
#include "movie.hpp"
#include "rental.hpp"
#include "customer.hpp"
#include <iostream>
#include <memory>

TEST(MainMovieRentalTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(MainMovieRentalTest, NameFilmShouldBeCorrect)
{
	Movie *movie = new Movie(std::string("Rio2"), Movie::NEW_RELEASE);
	EXPECT_EQ(std::string("Rio2"), movie->getTitle()) << "Bad film name";
}

TEST(MainMovieRentalTest, TypeFilmShouldBeCorrect)
{
	Movie *movie = new Movie(std::string("Rio2"), Movie::NEW_RELEASE);	
	EXPECT_EQ(Movie::NEW_RELEASE, movie->getPriceCode()) << "incorrect type of film";
}

TEST(MainMovieRentalTest, RentalShouldBeCorrectMovie)
{
	std::shared_ptr<Movie> movie = std::make_shared<Movie>("Angry Birds", Movie::REGULAR);
	size_t daysRented = 20;
	Rental rental(movie, daysRented);
	EXPECT_EQ(*movie, *rental.getMovie());

}

TEST(MainMovieRentalTest, RentalShouldBeCorrectDayRented)
{
	std::shared_ptr<Movie> movie = std::make_shared<Movie>("Angry Birds", Movie::REGULAR);
	size_t daysRented = 20;
	Rental rental(movie, daysRented);
	EXPECT_EQ(daysRented, rental.getDaysRented());
}

TEST(MainMovieRentalTest, CustomerShouldBeCorrectName)
{
	Customer customer("Bug");
	EXPECT_EQ(std::string("Bug"), customer.getName());
}

TEST(LAB2, CustomerCreateCorrectStatement)
{
	Customer customer("Bug");

	std::shared_ptr<Movie> movie1 = std::make_shared<Movie>(std::string("Angry Birds"), Movie::CHILDREN);
	size_t daysRented1 = 2;
	std::shared_ptr<Rental> rental1 = std::make_shared<Rental>(movie1, daysRented1);
	customer.addRental(rental1);

	std::shared_ptr<Movie> movie2 = std::make_shared<Movie>(std::string("StarWar"), Movie::NEW_RELEASE);
	size_t daysRented2 = 10;
	std::shared_ptr<Rental> rental2 = std::make_shared<Rental>(movie2, daysRented2);
	customer.addRental(rental2);

	std::shared_ptr<Movie> movie3 = std::make_shared<Movie>(std::string("Hatico"), Movie::REGULAR);
	size_t daysRented3 = 4;
	std::shared_ptr<Rental> rental3 = std::make_shared<Rental>(movie3, daysRented3);
	customer.addRental(rental3);

	std::string expected = "Lease accounting for Bug:\n";
	expected += "\tAngry Birds\t15.000000\n";
	expected += "\tStarWar\t30.000000\n";
	expected += "\tHatico\t32.000000\n";
	expected += "The owed amount is 77.000000. You've earned 4 points for activity.";

	std::string actual = customer.statement();

	EXPECT_EQ(expected, actual);
}