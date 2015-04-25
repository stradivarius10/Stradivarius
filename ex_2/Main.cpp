#include "LocationMeeting_t.h"
#include "DayCalendar_t.h"
#include "Meeting_t.h"


template<class T> static T get_start_time()
{
	T start_time = -1;
	string tmp;
	while ((start_time < 0) || (start_time > 24))
	{
		cout << "Enter the start time (has to be 0-24):" << endl;
		cin >> start_time;

		while (cin.fail())
		{
			cout << "The time has to be number. Please try again:" << endl;
			cin.clear();
			cin >> tmp; //remove all the word and try again
			cin >> start_time;
		}
	}

	return start_time;
}

template<class T> static T get_end_time(T start_time)
{
	T end_time = -1;
	string tmp;
	while ((end_time < 0) || (end_time > 24) || (end_time <= start_time))
	{
		cout << "Enter the end time (has to be 0-24 and larger than start time):" << endl;

		cin >> end_time;

		while (cin.fail())
		{
			cout << "The time has to be number. Please try again:" << endl;
			cin.clear();
			cin >> tmp; //remove all the word and try again
			cin >> end_time;
		}
	}
	return end_time;
}

static string getSubject()
{
	string subject;
	cout << "Enter the subject:" << endl;
	cin >> subject;
	return subject;
}

static string getLocation()
{
	string location;
	cout << "Enter the location:" << endl;
	cin >> location;
	return location;
}

template<class T> static Meeting_t<T>* getMeeting(bool with_location)
{
	T start_time, end_time;
	string subject, location;
	Meeting_t<T> *meeting;

	start_time = get_start_time<T>();
	end_time = get_end_time<T>(start_time);
	subject = getSubject();
	if (with_location)
	{
		location = getLocation();
		meeting = new LocationMeeting_t<T>();
		((LocationMeeting_t<T>*)meeting)->create(start_time, end_time, subject, location);
	}

	else
	{
		meeting = new Meeting_t<T>();
		meeting->create(start_time, end_time, subject);
	}

	return meeting;
}

template<class T> static void test()
{
	DayCalendar_t<T> day;
	Meeting_t<T> * meeting;

	char c;

	T start_time;

	bool cont = true;

	try
	{

		while (cont) {
			cout << "Press f to find a meeting in day" << endl
				<< "Press i to insert a new meeting" << endl
				<< "Press j to insert a new meeting with location" << endl
				<< "Press r to remove a meeting" << endl
				<< "press p to print the day calendar" << endl
				<< "press any other character to exit" << endl;


			cin >> c;

			switch (c) {

			case 'f': start_time = get_start_time<T>();

				meeting = day.find_meeting(start_time);
				if (meeting == NULL)
				{
					cout << "Meeting is not exist" << endl;
				}
				else
				{
					//cout << *meeting << endl;
					(*meeting).print();
				}
				break;
			case 'i': meeting = getMeeting<T>(false);
				try
				{
					day.insert_meeting(meeting);
				}
				catch (exception &e)
				{
					cout << e.what() << endl;
					//freeing memory
					delete meeting;
				}
				break;
			case 'j': meeting = getMeeting<T>(true);
				try
				{
					day.insert_meeting(meeting);
				}
				catch (exception &e)
				{
					cout << e.what() << endl;
					//freeing memory
					delete meeting;
				}
				break;
			case 'r':  start_time = get_start_time<T>();
				day.remove_meeting(start_time);
				break;

			case 'p':  cout << day << endl;
				break;
			default: cont = false; break;

			}
		}
		//freeing memory
		day.remove_all();
	}
	//catch any exception
	catch (...)
	{
		cout << "Some error was occured. Fatal error!" << endl;
		//freeing memory
		day.remove_all();
	}
}

int main() {
	char c;
	bool finish = false;
	while (!finish)
	{
		cout << "Press i or f to choose int or float (type of time). Press any other key to exit" << endl;
		cin >> c;

		switch (c)
		{
			case 'i':
			{
				test<int>();
				finish = true;
				break;
			}
			case 'f':
			{
				test<float>();
				finish = true;
				break;
			}

		}
	}
	return 0;
}

