#include <iostream>
#include <string>
#include "PhoneOwner.h"
#include "TC_t.h"

using namespace std;

static size_t getPrice()
{
	size_t price;
	string tmp;
	cout << "Enter price:" << endl;
	cin >> price;
	while (cin.fail())

	{
		cin.clear();
		cin >> tmp; //remove all the word and try again
		cout << "Some error occurred. Please try again." << endl;
		cin >> price;
	}

	return price;

}


int main()
{
	char c;
	size_t price;
	bool cont = true;
	TC_t * tc = TC_t::create_obj();
	PhoneOwner mobile_owner("Mobile", tc);
	PhoneOwner static_owner("Stationiary", tc);

	while (cont)
	{
		cout << "Press 1 to change service price" << endl
			<< "Press 2 to notify phones that they can update from old phones to new phones" << endl
			<< "Press 3 to get service price of tc" << endl
			<< "Press 4 to get service price of mobile" << endl
			<< "press 5 to get service price of static" << endl
			<< "press any other character to exit" << endl;
		cin >> c;
		try
		{
			switch (c)
			{
			case '1': price = getPrice();
				tc->change_service_price(price);
				break;
			case '2': tc->update_old_to_new();
				break;
			case '3': cout << "The service price of tc is: " << tc->get_service_price() << endl;
				break;
			case '4': cout << "The service price of mobile is: " << mobile_owner.get_service_price() << endl;
				break;
			case '5': cout << "The service price of static is: " << static_owner.get_service_price() << endl;
				break;

			default: cont=false;
			}
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
			TC_t::destroy();
		}
		catch (...)
		{
			cout << "Fatal error!" << endl;
			TC_t::destroy();
		}
	}
	TC_t::destroy();
	return 0;
}