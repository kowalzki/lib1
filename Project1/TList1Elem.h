#pragma once
#include <cstdlib>

template<typename T>
class TList1Elem
{
private:
	T data;
	TList1Elem* next;
	TList1Elem* prev;

	TList1Elem() { 
		this->next = this; 
		this->prev = this; 
	}

	TList1Elem(T newEl) {
		this->data = newEl;
	}

	TList1Elem(T newEl, TList1Elem* prevEl, TList1Elem* nextEl) {
		this->data = newEl;
		this->next = nextEl;
		this->prev = prevEl;
	}

	TList1Elem(const TList1Elem& T) {
		this->data = T.data;
		this->next = T.next;
		this->prev = T.prev;
	}
	template<typename T>
		friend class TList1Reliz;
};