#pragma once
#include "TList1Elem.h"
#include <cstdlib>
#include <iostream>

template<typename T>
class TList1Reliz {
	TList1Elem<T>* head;

private:
	TList1Elem<T>* getElemSCD(const int index) const {
		if (index < 0 || index >=this->getAmount()) return head;

		TList1Elem<T>* thisl = head->next;
		for (int i = 0; i < index; i++) {
			thisl = thisl->next;
		}
		return thisl;
	}

	void deleteAllSCD() {
		if (this->getAmount() == 0) return;

		if (this->getAmount() == 1) {
			delete this->head->next;
			this->head->next = this->head;
			this->head->prev = this->head;
			return;
		}

		TList1Elem<T>* thisel = this->head->next;
		TList1Elem<T>* nextel = thisel->next;

		while (thisel != head) {
			delete thisel;
			thisel = nextel;
			nextel = nextel->next;
		}
		this->head->next = this->head;
		this->head->prev = this->head;
	}

public: 
	bool ifEmpty() const {
		return (this->head == this->head->next && this->head == this->head->prev);
	}
	
	TList1Reliz() {
		this->head = new TList1Elem<T>;
	}

	TList1Reliz(const TList1Reliz& tmp) {
		this->initialization(tmp, false, true);
	}

	~TList1Reliz() {
		this->deleteAllSCD();
		delete this->head;
	}

	int getAmount() const {
		TList1Elem<T>* thisl = this->head->next;
		int lgh = 0;
		while (thisl != this->head) {
			thisl = thisl->next; lgh++;
		}
		return lgh;
	}

	bool add(const T newElem, const int index = -1)
	{
		int lgh = this->getAmount();
		int variableInd = index;

		if (variableInd == -1) variableInd = lgh;
		if (variableInd < 0 || variableInd > lgh) return false;

		TList1Elem<T>* prEl = this->getElemSCD(variableInd - 1);
		TList1Elem<T>* thsEl = new TList1Elem<T>(newElem, prEl, prEl->next);
		prEl->next = thsEl;
		prEl->next->next->prev = thsEl;

		return true;
	}

	bool remakeThis(const T newEl, const int index) {
		if (index < 0 || index >= this->getAmount()) return false;

		this->getElemSCD(index)->data = newEl;
		return true;
	}

	bool deleteInd(const int index = -1) {
		int lgh = this->getAmount();
		int variableInd = index;
		if (variableInd == -1) 	variableInd = lgh - 1;
		if (variableInd < 0 || variableInd >= lgh) return false;

		TList1Elem<T>* prEl = this->getElemSCD(variableInd - 1);
		TList1Elem<T>* thsEl = prEl->next;
		prEl->next = thsEl->next;
		thsEl->next->prev = prEl;
		delete thsEl;
		return true;
	}

	void initialization(const TList1Reliz& tmp, const bool fDelete = true, const bool fInitHdr = false) {
		if (fDelete) this->deleteAllSCD();
		if (fInitHdr) this->head = new TList1Elem<T>();
		int lgh = tmp.getAmount();
		if (lgh == 0) return;

		TList1Elem<T>* newHdr = tmp.head;
		TList1Elem<T>* thisHdr = this->head;

		if (lgh == 1) {
			thisHdr->next = newHdr->next;
			TList1Elem<T>* elem = new TList1Elem<T>(newHdr->next->data, thisHdr, thisHdr);
			elem->next = thisHdr;
			elem->prev = thisHdr;
			return;
		}

		TList1Elem<T>* newHdr1 = thisHdr;
		TList1Elem<T>* newHdr2 = newHdr->next;

		for (int i = 0; i < lgh; i++) {
			TList1Elem<T>* newEl = new TList1Elem<T>(newHdr2->data, newHdr1, newHdr1->next);
			newHdr1->next->prev = newEl;
			newHdr1->next = newEl;
			newHdr1 = newHdr1->next;
			newHdr2 = newHdr2->next;
		}
		newHdr1->next = thisHdr;
		return;
	}

	void initialization(const T* initArr, const int lgh) {
		this->deleteAllSCD();
		TList1Elem<T>* newPtr = this->head;
		for (int i = 0; i < lgh; i++) {
			newPtr->next = new TList1Elem<T>(initArr[i]);
			newPtr->next->prev = newPtr;
			newPtr = newPtr->next;
		}
		newPtr->next = this->head;
		this->head->prev = newPtr;
	}

	TList1Reliz operator=(const TList1Reliz<T>& tmp) {
		if (this == &tmp) return *this;
		this->initialization(tmp);
		return *this;
	}

	T& operator[](const int index) {
		if (!this->getAmount()) return this->head->data;
		TList1Elem<T>* thisel = this->head->next;
		for (int i = 0; i < index; i++) {
			thisel = thisel->next;
			if (thisel == head) thisel = thisel->next;
		}
		return thisel->data;
	}
};