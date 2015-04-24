#include "LocationMeeting_t.h"
#include "DayCalendar_t.h"
#include "Meeting_t.h"


static float get_start_time()
{
	float start_time = -1.0;
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

static float get_end_time(float start_time)
{
	float end_time = -1.0;
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

static Meeting_t<int>* getMeeting_int(bool with_location)
{
	int start_time, end_time;
	string subject, location;
	Meeting_t<int> *meeting;

	start_time = (int)get_start_time();
	end_time = (int)get_end_time((float)start_time);
	subject = getSubject();
	if (with_location)
	{
		location = getLocation();
		meeting = new LocationMeeting_t<int>();
		((LocationMeeting_t<int>*)meeting)->create(start_time, end_time, subject, location);
	}

	else
	{
		meeting = new Meeting_t<int>();
		meeting->create(start_time, end_time, subject);
	}

	return meeting;
}

static Meeting_t<float>* getMeeting_float(bool with_location)
{
	float start_time, end_time;
	string subject, location;
	Meeting_t<float> *meeting;

	start_time = get_start_time();
	end_time = get_end_time(start_time);
	subject = getSubject();
	if (with_location)
	{
		location = getLocation();
		meeting = new LocationMeeting_t<float>();
		((LocationMeeting_t<float>*)meeting)->create(start_time, end_time, subject, location);
	}

	else
	{
		meeting = new Meeting_t<float>();
		meeting->create(start_time, end_time, subject);
	}

	return meeting;
}

static void test_int()
{
	DayCalendar_t<int> day;
	Meeting_t<int> * meeting;

	char c;

	float start_time;

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

			case 'f': start_time = get_start_time();

				meeting = day.find_meeting((int)start_time);
				if (meeting == NULL)
				{
					cout << "Meeting is not exist" << endl;
				}
				else
					cout << *meeting << endl;
				break;
			case 'i': meeting = getMeeting_int(false);
				try
				{
					day.insert_meeting(meeting);
				}
				catch (exception &e)
				//catch (char const * error)
				{
					cout << e.what() << endl;
					//cout << error << endl;
					//freeing memory
					delete meeting;
				}
				break;
			case 'j': meeting = getMeeting_int(true);
				try
				{
					day.insert_meeting(meeting);
				}
				catch (exception &e)
					//catch (char const * error)
				{
					cout << e.what() << endl;
					//cout << error << endl;
					//freeing memory
					delete meeting;
				}
				break;
			case 'r':  start_time = get_start_time();
				day.remove_meeting((int)start_time);
				break;

			case 'p':  cout << day << endl;
				break;
			default: cont = false; break;

			}
		}
		//freeing memory
		day.remove_all();
	}
	//catch (exception e)
	catch (char const * error)
	{
		cout << error << endl;
		//freeing memory
		day.remove_all();
	}
}

static void test_float()
{
	DayCalendar_t<float> day;
	Meeting_t<float> * meeting;

	char c;

	float start_time;

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

			case 'f': start_time = get_start_time();

				meeting = day.find_meeting(start_time);
				if (meeting == NULL)
				{
					cout << "Meeting is not exist" << endl;
				}
				else
					cout << *meeting << endl;
				break;
			case 'i':  meeting = getMeeting_float(false);
				try
				{
					day.insert_meeting(meeting);
				}
				catch (exception &e)
					//catch (char const * error)
				{
					cout << e.what() << endl;
					//cout << error << endl;
					//freeing memory
					delete meeting;
				}
				break;
			case 'j':  meeting = getMeeting_float(true);
				try
				{
					day.insert_meeting(meeting);
				}
				catch (exception &e)
					//catch (char const * error)
				{
					cout << e.what() << endl;
					//cout << error << endl;
					//freeing memory
					delete meeting;
				}
				break;
			case 'r':  start_time = get_start_time();
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
	catch (char const * error)
	{
		cout << error << endl;
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
				test_int();
				finish = true;
				break;
			}
			case 'f':
			{
				test_float();
				finish = true;
				break;
			}

		}
	}
	return 0;
}

