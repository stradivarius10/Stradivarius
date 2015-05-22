#include <iostream>

#define TEMPLATE_TEMPLATE //this is the default
#include "tContainer_t.h"
#include <vector>
#include <list>
#include <string>



using namespace std;

template<class T> static T* get_elem_ptr()
{
	T* elem = new T;
	string tmp;
	cout << "enter a value" << endl;
	cin >> *elem;
	while (cin.fail())
	{
		cout << "Some error occured. Please try again:" << endl;
		cin.clear();
		cin >> tmp; //remove all the word and try again
		cin >> *elem;
	}
	return elem;
}
#ifdef TEMPLATE_TEMPLATE
template<typename T, template <typename, typename> class CT> static void test()
#else
template<typename T, typename CT> static void test()
#endif

{
	char c;
	tContainer_t<T, CT> cont;
	T* elem = nullptr;
	T* elem_from_cont = nullptr;
	bool cont_flag = true;
	while (cont_flag) {
		cout << "Press f to find an element" << endl
			<< "Press e to check if container is empty" << endl
			<< "Press s to get the size of the container" << endl
			<< "Press i to insert a new element" << endl
			<< "Press r to remove a value from cont without delete" << endl
			<< "Press d to remove a value from cont with delete" << endl
			<< "Press R to remove all values from cont without delete" << endl
			<< "Press D to remove all values from cont with delete" << endl
			<< "press a to get the first element" << endl
			<< "press b to get the last element" << endl
			<< "press p to print all elements" << endl
			<< "press any other character to exit" << endl;


		cin >> c;

		switch (c) {

		case 'a':
			elem = cont.get_first();
			if (elem == 0)
			{
				cout << "container is empty" << endl;
			}
			else
			{
				cout << *cont.get_first() << endl;
			}
			break;
		case 'b':
			elem = cont.get_last();
			if (elem == 0)
			{
				cout << "container is empty" << endl;
			}
			else
			{
				cout << *cont.get_first() << endl;
			}
			break;
		case 'e':
			if (cont.is_empty())
			{
				cout << "Container is empty" << endl;
			}
			else
			{
				cout << "Container is not empty" << endl;
			}
			break;
		case 's':
			cout << cont.get_size() << endl;
			break;
		case 'R':
			cont.remove_all();
			break;
		case 'D':
			cont.remove_delete_all();
			break;
		case 'i':
			elem = get_elem_ptr<T>();
			cont.insert(elem);
			break;
		case 'r':
			elem = get_elem_ptr<T>();
			elem_from_cont = cont.remove(*elem);
			if (elem_from_cont == 0)
			{
				cout << "Element is not in container" << endl;
			}
			else
			{
				cout << "Element is in container" << endl;
			}
			delete elem;
			delete elem_from_cont;
			break;
		case 'd':
			elem = get_elem_ptr<T>();
			cont.remove_and_delete(*elem);
			delete elem;
			break;
		case 'f':
			elem = get_elem_ptr<T>();
			elem_from_cont = cont.find(*elem);
			if (elem_from_cont == 0)
			{
				cout << "Element is not in container" << endl;
			}
			else
			{
				cout << "Element is in container" << endl;
			}
			delete elem;
			break;
		case 'p':
			cout << cont << endl;
			break;
		default: cont_flag = false; break;

		}
	}

	cont.remove_delete_all();
	//freeing memory
	//delete cont;
}

int main()
{
	char c;
	bool finish = false;
	while (!finish)
	{
		cout << "Press v or l to choose vector or list (elements are of type int) :" << endl;
		cin >> c;

		switch (c)
		{
		case 'v':
		{
			#ifdef TEMPLATE_TEMPLATE
				test<int, vector>();
			#else
				test<int, vector<int*>>();
			#endif


			finish = true;
			break;
		}
		case 'l':
		{
			#ifdef TEMPLATE_TEMPLATE
			test<int, list>();
			#else
			test<int, list<int*>>();
			#endif

			finish = true;
			break;
		}

		}
	}
	return 0;
}
