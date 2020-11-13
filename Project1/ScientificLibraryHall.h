#pragma once
#include "ScientificBook.h"
#include "TList1Reliz.h"
#include <iostream>
#include <string>

class ScientificLibraryHall {

	TList1Reliz<ScientificBook> booksArr;
	std::string hallName;

public:

	ScientificLibraryHall() {
		this->hallName = "Not defined";
	}

	ScientificLibraryHall(const std::string nme, const TList1Reliz<ScientificBook> newhl) {
		this->hallName = nme;
		this->booksArr = newhl;
	}

	ScientificLibraryHall(const std::string nme, const ScientificBook* hll, const int lgh) {
		this->hallName = nme;
		this->booksArr.initialization(hll, lgh);
	}

	ScientificLibraryHall(const ScientificLibraryHall& tmp) {
		this->booksArr = tmp.booksArr;
		this->hallName = tmp.hallName;
	}

	void setHName(const std::string nme) {
		this->hallName = nme;
	}

	std::string getHName() {
		return this->hallName;
	}

	int getAmount() {
		return this->booksArr.getAmount();
	}

	float getFullPrice() {
		float fullpr = 0;
		for (int i = 0; i < this->booksArr.getAmount(); i++) {
			fullpr += this->booksArr[i].getPrice();
		}
		return fullpr;
	}

	ScientificBook& getBookInd(const int index) {
		if (index >= this->booksArr.getAmount() || index < 0) {
			ScientificBook tmp;
			return tmp;
		}
		return this->booksArr[index];
	}

	bool remakeBook(const ScientificBook newBk, const int index) {
		if (index < 0 || index >= this->booksArr.getAmount()) return false;
		this->booksArr[index] = newBk;
		return true;
	}

	bool addBk(const ScientificBook newBk, const int index = -1) {
		return this->booksArr.add(newBk, index);
	}

	bool deleteInd(const int index = -1) {
		return this->booksArr.deleteInd(index);
	}

	bool remakeBk(const ScientificBook newBk, const int index = -1) {
		if (!this->deleteInd(index)) return false;
		if (!this->addBk(newBk, index)) return false;
		return true;
	}

	ScientificBook& getBestBook() {
		if (!this->booksArr.getAmount()) {
			ScientificBook tmp;
			return tmp;
		}
		ScientificBook& bb = this->booksArr[0];
		for (int i = 0; i < this->booksArr.getAmount()) {
			if (bb.getPrice() < this->booksArr[i].getPrice()) {
				bb = this->booksArr[i];
			}
		}
		return bb;
	}

	void print() {
		std::cout << " Amount: " << this->booksArr.getAmount() << std::endl;
		for (int i = 0; i < this->booksArr.getAmount(); i++)
		{
			std::cout << std::left << "\tBook #" << std::setw(2) << i << "\tname: "
				<< this->booksArr[i].getName() << std::endl;
		}
		std::cout << std::endl;
	}

	ScientificBook& operator[](const int index)
	{
		return this->booksArr[index];
	}

	ScientificLibraryHall operator=(const ScientificLibraryHall& cpyHall)
	{
		if (this == &cpyHall)
		{
			return *this;
		}
		this->booksArr = cpyHall.booksArr;
		return *this;
	}

};