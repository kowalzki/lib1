#pragma once
#include <iomanip>
#include <iostream>
#include <string>

class ScientificBook {
	std::string author;
	std::string name;
	float price;
	int year;
	int rating;

public:
	ScientificBook() {
		this->author = "Not defined";
		this->name = "Not defined";
		this->price = 0;
		this->year = 0;
		this->rating = 0;
	}

	ScientificBook(std::string athr, std::string nme, float prce, int yr, int rate)	{
		this->author = athr;
		this->name = nme;
		this->price = prce;
		this->year = yr;
		this->rating = rate;
	}

	ScientificBook(const std::string athr, const int yr) :ScientificBook()	{
		this->author = athr;
		this->year = yr;
	}

	void fullIn(const ScientificBook newbk) {
		this->author = newbk.author;
		this->name = newbk.name;
		this->price = newbk.price;
		this->year = newbk.year;
		this->rating = newbk.rating;
	}

	void set_author(const std::string athr) {
		this->author = athr;
		return;
	}

	void set_name(const std::string newnm) {
		this->name = newnm; return;
	}

	void set_cost(const float nwPrc) {
		this->price = nwPrc; return;
	}

	void set_yearPost(const int yr) {
		this->year = yr; return;
	}

	void set_rating(const int rate) {
		this->rating = rate; return;
	}

	std::string getAuthor() {
		return this->author;
	}

	std::string getName()	{
		return this->name;
	}

	float getPrice() {
		return this->price;
	}

	int getYear()	{
		return this->year;
	}

	int getRating() {
		return this->rating;
	}

	void print() const {
		std::cout
			<< " Name: " << this->name << std::endl
			<< " Author: " << this->author << std::endl
			<< " Cost: " << this->price << std::endl
			<< " Year post: " << this->year << std::endl
			<< " Rating: " << this->rating << std::endl
			<< std::endl;
	}
};