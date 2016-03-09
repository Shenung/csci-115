#ifndef LISTS_H
#define LISTS_H
#include<cstdlib>
#include "List.h"

template<typename E>
class Link
{
private:
	E value;
	Link<E>* next;

	static Link<E>* FreeList;
	static int numFreeNode;
	static int numActiveNode;
public:
	Link();

	void* operator new(size_t size);
	void operator delete(void* node);

	const E& getVal() const;
	Link<E>* getNext() const;
	int getActive() const;
	int getFree() const;
	void setVal(const E& newVal);
	void setNext(Link<E>* newNext);
};

template<typename E>
class LinkedList : public List < E >
{
private:
	Link<E> *head;
	Link<E> *tail;
	Link<E> *current;
public:
	LinkedList();
	virtual ~LinkedList();

	virtual void clear();
	virtual void prepend(const E& item);
	virtual void append(const E& item);
	virtual void moveToStart();
	virtual bool next();
	virtual const E& getValue() const;
	virtual int numActive();
	virtual int numFree();
};

template<typename E>
Link<E>::Link() : next(NULL)
{}

template<typename E>
int Link<E>::numFreeNode = 0;

template<typename E>
int Link<E>::numActiveNode = 0;

template<typename E>
Link<E>* Link<E>::FreeList = NULL;

template<typename E>
LinkedList<E>::LinkedList() : head(new Link<E>), tail(new Link<E>), current(tail)
{
	head->setNext(tail);
}

template<typename E>
LinkedList<E>::~LinkedList()
{
	clear();
	delete tail;
	delete head;
}

template<typename E>
void* Link<E>::operator new(size_t size)
{
	if (numFreeNode > 0)
	{
		Link<E> *newNode = FreeList;
		FreeList = newNode->getNext();
		--numFreeNode;
		return newNode;
	}
	else
	{
		++numActiveNode;
		return malloc(size);
	}

}

template<typename E>
void Link<E>::operator delete(void* node)
{
	Link<E> *link = static_cast<Link<E>*>(node);
	link->setNext(FreeList);
	FreeList = link;
	--numActiveNode;
	++numFreeNode;
}

template<typename E>
int Link<E> ::getActive() const
{
	return numActiveNode;
}

template<typename E>
int Link<E> ::getFree() const
{
	return numFreeNode;
}

template<typename E>
const E& Link<E>::getVal() const
{
	return value;
}

template<typename E>
Link<E>* Link<E>::getNext() const
{
	return next;
}

template<typename E>
const E& LinkedList<E>::getValue() const
{
	return current->getVal();
}

template<typename E>
void Link<E>::setVal(const E& newVal)
{
	value = newVal;
}

template<typename E>
void Link<E>::setNext(Link<E> *newNext)
{
	next = newNext;
}

template<typename E>
void LinkedList<E> ::clear()
{
	Link<E> *currNode = head->getNext();
	while (currNode != tail)
	{
		Link<E> *saved = currNode;
		currNode = currNode->getNext();
		delete saved;
	}
	head->setNext(tail);
}

template<typename E>
void LinkedList<E> ::prepend(const E& item)
{
	Link<E> *newNode;
	newNode = new Link<E>;

	newNode->setVal(item);
	newNode->setNext(head->getNext());
	head->setNext(newNode);
}

template<typename E>
void LinkedList<E> ::append(const E& item)
{
	Link<E> *newNode;
	newNode = new Link<E>;

	newNode->setNext(NULL);
	tail->setNext(newNode);
	tail->setVal(item);
	tail = newNode;
}

template<typename E>
int LinkedList < E > ::numActive()
{
	return head->getActive();
}

template<typename E>
int LinkedList < E > ::numFree()
{
	return head->getFree();
}

template<typename E>
void LinkedList<E> ::moveToStart()
{
	current = head->getNext();
}

template<typename E>
bool LinkedList < E > ::next()
{
	if (current == tail)
	{
		return false;
	}
	else
	{
		current = current->getNext();
		return true;
	}
}

#endif
