#pragma once
#include <cstdlib>

template<typename T>
class TList1Elem
{
private:
	T data;
	TList1Elem* next;

	TList1Elem() { this->next = this; }

	TList1Elem(T newEl) {
		this->data = newEl;
	}

	TList1Elem(T newEl, TList1Elem* nextEl) {
		this->data = newEl;
		this->next = nextEl;
	}

	TList1Elem(const TList1Elem& T) {
		this->data = T.data;
		this->next = T.next;
	}
	friend TList1Reliz;
};