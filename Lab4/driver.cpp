#include<iostream>
#include<cstdlib>
#include"lists.h"
using namespace std;

template<class E>
size_t length(List<E> *list)
{
	list->moveToStart();
	size_t size = 0;
	while (list->next())
	{
		size++;
	}
	return size;
}

int pass = 0, fail = 0;

template<class E>
bool test(List<E> *list, size_t target)
{
	if (length(list) == target)
	{
		cout<< "Passed" <<endl;
		pass++;
		return true;
	}
	else
	{
		cout << "Failed. Incorrect size" << endl;
		fail++;
		return false;
	}
}

template<class E>
void test2(List<E> *list, size_t ActiveTarget, size_t FreeTarget)
{
	if (list->numActive() != ActiveTarget || list->numFree() != FreeTarget)
	{
		fail++;
	}
	else
	{
		pass++;
	}
	cout << "Active: " << list->numActive() << " out of " << ActiveTarget << endl;
	cout << "Free: " << list->numFree() << " out of " << FreeTarget << endl;
}


int main()
{
	List<int>* list = new LinkedList<int>();

	for (int i = 0; i < 20; i++)
	{
		list->append(i);
		list->append(i);
	}
	test(list, 40);
	test2(list, 42, 0);
	list->clear();
	if (test(list, 0))
	{
		cout << "cleared" << endl;
	}
	test2(list, 2, 40);

	cout << "Pass: " << pass << "  Failed: " << fail << endl;
	system("PAUSE");
	return 0;
}
