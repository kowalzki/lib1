#pragma once
#include "ScientificLibraryHall.h"
#include "TList1Reliz.h"

class ScientificLibrary
{
	TList1Reliz<ScientificLibraryHall> hallsArr;

public:

	ScientificLibrary() {	}

	ScientificLibrary(const TList1Reliz<ScientificLibraryHall> hll) {
		this->hallsArr = hll;
	}

	ScientificLibrary(const ScientificLibraryHall* tmp, const int lgh) {
		this->hallsArr.initialization(tmp, lgh);
	}

	ScientificLibrary(const ScientificLibrary& tmp) {
		this->hallsArr = tmp.hallsArr;
	}

	bool add(const ScientificLibraryHall hll, const int index = -1) {
		return this->hallsArr.add(hll, index);
	}

	bool deleteInd(const int index = -1) {
		return this->hallsArr.deleteInd(index);
	}

	bool remakeHl(const ScientificLibraryHall hll, const int index = -1) {
		if (!this->deleteInd(index)) return false;
		if (!this->add(hll, index)) return false;
		return true;
	}

	ScientificBook& getBookInd(const int index) {
		int vatiableInd = index;
		for (int i = 0; i < this->hallsArr.getAmount(); i++) {
			if (vatiableInd > this->hallsArr[i].getAmount()) {
				vatiableInd -= this->hallsArr[i].getAmount();
			}
			else {
				return this->hallsArr[i].getBookInd(vatiableInd);
			}
		}
	}

	ScientificLibraryHall& getHallInd(const int index) {
		if (index >= this->hallsArr.getAmount()) {
			ScientificLibraryHall tmp;
			return tmp;
		}
		return this->hallsArr[index];
	}

	bool addBkInd(const ScientificBook newBk, const int index) {
		int variableInd = index;
		for (int i = 0; i < this->hallsArr.getAmount(); i++) {
			if (variableInd > this->hallsArr[i].getAmount()) {
				variableInd -= this->hallsArr[i].getAmount();
			}
			else {
				return this->hallsArr[i].addBk(newBk, index);
			}
		}
		return false;
	}

	bool deleteBk(const int index) {
		int variableInd = index;
		for (int i = 0; i < this->hallsArr.getAmount(); i++) {
			if (variableInd > this->hallsArr[i].getAmount()) {
				variableInd -= this->hallsArr[i].getAmount();
			}
			else {
				return this->hallsArr[i].deleteInd(variableInd);
			}
		}
		return false;
	}

	int getAOBooks() {
		int amount = 0;
		for (int i = 0; i < this->hallsArr.getAmount(); i++) {
			amount += this->hallsArr[i].getAmount();
		}
		return amount;
	}

	int getAOHalls() {
		this->hallsArr.getAmount();
	}

	ScientificBook getBestBook() {
		ScientificBook& bb = this->getBookInd(0);
		for (int i = 0; i < this->hallsArr.getAmount(); i++) {
			ScientificBook& tmp = this->hallsArr[i].getBestBook();
			if (bb.getPrice() < tmp.getPrice()) {
				bb = tmp;
			}
		}
		return bb;
	}

	void print() {
		for (int i = 0; i < this->hallsArr.getAmount(); i++) {
			std::cout << " Hall: " << this->hallsArr[i].getHName();
			this->hallsArr[i].print();
		}
		std::cout << "\n";
	}

	ScientificLibraryHall& operator[](const int index)
	{
		return this->hallsArr[index];
	}

	ScientificLibrary operator=(const ScientificLibrary& tmp)
	{
		if (this == &tmp) return *this;

		this->hallsArr = tmp.hallsArr;
		return *this;
	}

};