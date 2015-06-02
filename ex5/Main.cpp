#include <iostream>
#include <string>
#include "cDate_t.h"
#include "cTime_t.h"

using namespace std;

static size_t getSize_t(const string & msg)
{
	size_t value;

	string tmp;

	cout << msg << endl;

	cin >> value;

	while (cin.fail())
	{
		cin.clear();
		cin >> tmp; //remove all the word and try again
		cout << "Some error occurred. Please try again. " + msg << endl;
		cin >> value;
	}

	return value;
}

static int getFormat()
{
	return getSize_t("Enter format");
}

static size_t getDay()
{
	return getSize_t("Enter day");
}

static size_t getMonth()
{
	return getSize_t("Enter month");
}

static size_t getYear()
{
	return getSize_t("Enter year");
}

static size_t getHour()
{
	return getSize_t("Enter hour");
}

static size_t getMinutes()
{
	return getSize_t("Enter minutes");
}

static size_t getSeconds()
{
	return getSize_t("Enter seconds");
}

static void initDate(cDate_t & date)
{
	date.setDay(getDay());
	date.setMonth(getMonth());
	date.setYear(getYear());
}

static void initTime(cTime_t & time)
{
	time.setHour(getHour());
	time.setMinutes(getMinutes());
	time.setSeconds(getSeconds());
}

static void handleDate(cDate_t & date)
{
	char c;

	cout << "Press 1 to set day" << endl
		<< "Press 2 to set month" << endl
		<< "Press 3 to set year" << endl
		<< "Press 4 to get day of week" << endl
		<< "Press 5 to get month" << endl
		<< "Press 6 to get year" << endl
		<< "Press 7 to get day of year" << endl
		<< "Press 8 to get day of month" << endl
		<< "press 9 to check if year is leap" << endl
		<< "press n to get name of day" << endl
		<< "press m to get name of month" << endl
		<< "press p to print date" << endl
		<< "press any other character to return previous menu" << endl;

	cin >> c;


	try{

		switch (c)
		{
		case '1':
			date.setDay(getDay());
			break;

		case '2':
			date.setMonth(getMonth());
			break;

		case '3':
			date.setYear(getYear());
			break;

		case '4':
			cout << date.getDay() << endl;
			break;

		case '5':
			cout << date.getMonth() << endl;
			break;

		case '6':
			cout << date.getYear() << endl;
			break;

		case '7':
			cout << date.getDayOfYear() << endl;
			break;

		case '8':
			cout << date.getDayOfMonth() << endl;
			break;

		case '9':
			if (date.isYearLeap())
			{
				cout << "The year is leap" << endl;
			}
			else
			{
				cout << "The year is not leap" << endl;
			}
			break;

		case 'n':
			cout << date.getNameOfDay() << endl;
			break;

		case 'm':
			cout << date.getNameOfMonth() << endl;
			break;

		case 'p':
			date.print(getFormat());
			break;

		default: break;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

static void handleTime(cTime_t & time)
{
	char c;
	cTime_t time2;
	cout << "Press 1 to set hour" << endl
		<< "Press 2 to set minutes" << endl
		<< "Press 3 to set seconds" << endl
		<< "Press 4 to get hour" << endl
		<< "Press 5 to get minutes" << endl
		<< "Press 6 to get seconds" << endl
		<< "press p to print time" << endl
		<< "Press + to add another time to this time" <<endl
		<< "press any other character to return previous menu" << endl;

	cin >> c;

	try
	{
		switch (c)
		{
		case '1':
			time.setHour(getHour());
			break;

		case '2':
			time.setMinutes(getMinutes());
			break;

		case '3':
			time.setSeconds(getSeconds());
			break;

		case '4':
			cout << time.getHour() << endl;
			break;

		case '5':
			cout << time.getMinutes() << endl;
			break;

		case '6':
			cout << time.getSeconds() << endl;
			break;

		case 'p':
			time.print(getFormat());
			break;

		case '+':
			initTime(time2);
			time = time + time2;
			time.print(1);
			break;

		default: break;
		}
	}

	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	

}

int main()
{
	char c;

	cDate_t date;
	cTime_t time;

	cout << "Press d to initialize default time, or press x to initialize your time. press any other key to exit." << endl;
	cin >> c;

	try
	{
		switch (c)
		{
		case 'd':

			break;

		case 'x':
			initTime(time);
			break;
		default: return 0;
		}

		cout << "Press d to initialize default date, or press x to initialize your date. press any other key to exit." << endl;
		cin >> c;

		switch (c)
		{
		case 'd':

			break;

		case 'x':
			initDate(date);
			break;
		default: return 0;
		}

		date.connect_with_time(&time);

		while (true)
		{
			cout << "Press t to handle time" << endl
				<< "Press d to handle date" << endl
				<< "Press any other key to exit" << endl;
			cin >> c;

			switch (c)
			{
			case 't':
				handleTime(time);
				break;

			case 'd':
				handleDate(date);
				break;
			default: return 0;
			}
		}
	}

	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}


	return 0;
}
