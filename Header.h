#pragma once
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

template <class T = int>
class Deque
{
private:
	struct Element
	{
		T data;
		Element* next;
		Element* prev;
		Element(T dataA) : data(dataA), next(nullptr), prev(nullptr) {}
	};
	Element* front{ nullptr };
	Element* rear{ nullptr };
	unsigned size{ 0 };
	void clone(const Deque& q);
	void erase();

public:
	Deque() = default;
	Deque(const Deque&);
	~Deque();
	void pushBack(T a);
	void pushFront(T a);
	bool popBack();
	bool popFront();
	T& getTop();
	T& getBack();
	unsigned getSize() const;
	Deque& operator = (const Deque& q);
	void outBegin(ostream& os) const;
	void outEnd(ostream& os) const;

};

template <class T>
void Deque<T>::pushBack(T a)
{
	Element* tmp = new Element(a);
	if (size > 0)
	{
		rear->next = tmp;
		tmp->prev = rear;
	}
	else
	{
		front = tmp;
	}
	rear = tmp;
	size++;
}

template <class T>
void Deque<T>::pushFront(T a)
{
	Element* tmp = new Element(a);
	if (size > 0)
	{
		tmp->next = front;
		front->prev = tmp;
	}
	else
	{
		rear = tmp;
	}
	front = tmp;
	size++;
}

template <class T>
bool Deque<T>::popFront()
{
	if (!size)
	{
		return false;
	}
	Element* tmp = front;
	front = front->next;
	delete tmp;
	size--;
	if (!size)
	{
		rear = nullptr;
	}
	return true;
}

template <class T>
bool Deque<T>::popBack()
{
	if (!size)
	{
		return false;
	}
	Element* tmp = rear;
	delete tmp;
	size--;
	if (!size)
	{
		front = nullptr;
	}
	return true;
}

template <class T>
Deque<T>::~Deque()
{
	erase();
}
template <typename T>
T& Deque<T>::getTop()
{
	return front->data;
}


template <typename T>
T& Deque<T>::getBack()
{
	return rear->data;
}

template<class  T>
unsigned Deque<T>::getSize() const
{
	return size;
}

template<class  T>
Deque<T>& Deque<T>::operator=(const Deque<T>& q)
{
	if (this != &q)
	{
		erase();
		clone(q);
	}
	return *this;
}

template<class  T>
void Deque<T>::outBegin(ostream& os) const
{
	Element* tmp = front;
	for (unsigned i = 0; i < size; i++)
	{
		os << (*tmp).data << ' ';
		tmp = tmp->next;
	}
}

template<class  T>
void Deque<T>::outEnd(ostream& os) const
{
	Element* tmp = rear;
	for (unsigned i = 0; i < size; i++)
	{
		os << (*tmp).data << ' ';
		tmp = tmp->prev;
	}
}

template<class  T>
Deque<T>::Deque(const Deque<T>& q)
{
	clone(q);
}

template<class  T>
inline void Deque<T>::clone(const Deque<T> &q)
{
	Element* tmp = q.front;
	for (int i = 0; i < q.size; i++)
	{
		pushBack(tmp->data);
		tmp = tmp->next;
	}
}

template<class  T>
void Deque<T>::erase()
{
	while (popBack());
	size = 0;
}



typedef const char * Cc_t;
template <>
inline Deque <Cc_t>::Element::Element(Cc_t dataA) :next(NULL), prev(NULL)
{
	data = new char[strlen(dataA) + 1];
	strcpy((char*)data, dataA);
}

template <>
inline bool Deque<Cc_t>::popBack()
{
	if (!size)
	{
		return false;
	}
	Element* tmp = rear;
	rear = rear->prev;
	delete[] tmp->data;
	delete tmp;
	--size;
	if (!size)
	{
		rear = nullptr;
		front = nullptr;
	}
	return true;
}

template<>
inline bool Deque<Cc_t>::popFront()
{
	if (size == 0) {
		return false;
	}
	Element* tmp = front;
	front = front->next;
	delete[] tmp->data;
	delete tmp;
	size--;
	if (!size)
	{
		rear = nullptr;
		front = nullptr;
	}
	return true;
}