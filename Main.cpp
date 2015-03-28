
#include "PersonArray_t.h"

using namespace std;

//====================================================

static Person_t getValue() {
	//shachar change
	//Person_t i;
	string name;
	int age;
	cout << "\nEnter the name of the person:" << endl;
	cin >> name;
	cout << "\nEnter the age of person: (Age has to be in 0-120 range)" << endl;
	cin >> age;
	Person_t i(name, age);
//	cin >> i;
	return i;
}

//====================================================

static Person_t* getPtr() {
	/*
	Person_t* ip = new Person_t;
	cout << "\nEnter name and age of person:" << endl;
	cin >> *ip;
	return ip;
	*/
	string name;
	int age;
	//cout << "\nEnter name and age of person:" << endl;
	//cin >> name >> age;
	cout << "\nEnter the name of the person:" << endl;
	cin >> name;
	cout << "\nEnter the age of person: (Age has to be in 0-120 range)" << endl;
	cin >>  age;
	if (age > 120 || age < 0)
	{
		cout << "Age has to be in 0-120 range. Exiting" << endl;
		cin.clear();
		return NULL;
	}
	Person_t* ip = new Person_t(name, age);
	//	cin >> i;
	return ip;
}

//====================================================

static int get_index()
{
	int index;
	cout << "\nEnter index:" << endl;
	cin >> index;
	return index;
}

//====================================================

int main() {
	PersonArray_t arr;
	Person_t *ip;
	Person_t value("example",3);
	int index;
	char c;

	bool cont = true;

	while (cont) {
		cout << endl
			<< "Press n to see the number of elements" << endl
			<< "Press c to see the capacity" << endl
			<< "press f to get the first element in array" << endl
			<< "press l to get the last element in array" << endl
			<< "Press b to find an element in array" << endl
			<< "Press e to see if array is empty" << endl
			<< "Press i to insert new person at the and of array" << endl
			<< "Press r to remove a person from array" << endl
			<< "Press R to remove all elements from array" << endl
			<< "Press d to remove and delete person from array" << endl
			<< "Press D to remove and delete all elements from array" << endl
			<< "press a to append a new person after a given index" << endl
			<< "press p to prepend a new person before a given index" << endl
			<< "press t to print the array" << endl
			<< "press any other character to exit" << endl;

		
		cin >> c;

		switch (c) {
		case 'n':  cout << "The number of elements is: " << arr.get_num_of_elements() << endl;
			break;
		case 'c':  cout << "The capacity is: " << arr.get_capacity() << endl;
			break;
		case 'f':
			if (arr.is_empty())
				cout << "Array is empty" << endl;
			else
				cout << *arr.get_first_element() << endl;
			break;
		case 'l':
			if (arr.is_empty())
				cout << "Array is empty" << endl;
			else
				cout << *arr.get_last_element() << endl;
			break;
		case 'b': value = getValue();
			ip = arr.find(value);
			if (ip != NULL)
				cout << "element was found:" << endl << *ip << endl;
			else
				cout << "element was not found" << endl;
			break;
		case 'e':  cout << (arr.is_empty() ? "Empty" : "Not empty") << endl;
			break;
		case 'i':  ip = getPtr();
			if (!ip)
				return -1;
			arr.insert(ip);
			break;
		case 'r':  value = getValue();
			arr.remove(value);
			break;
		case 'R':  arr.remove_all();
			break;
		case 'd': value = getValue();
			arr.remove_delete(value);
			break;
		case 'D': arr.remove_delete_all();
			break;
		case 'a':  ip = getPtr();
			if (!ip)
				return -1;
			index = get_index();
			if (!arr.append(index, ip))
				cout << "some error has occured. Please make sure you entered correct params" << endl;
			break;
		case 'p':  ip = getPtr();
			if (!ip)
				return -1;
			index = get_index();
			if (!arr.prepend(index, ip))
				cout << "some error has occured .Please make sure you entered correct params" << endl;
			break;
		case 't': 
			arr.print_array();
			break;
		
		default: cont = false; break;

		}
	}
	//freeing memory
	arr.remove_delete_all();
	return 0;
}