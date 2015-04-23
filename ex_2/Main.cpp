#include "LocationMeeting_t.h"
#include "DayCalendar_t.h"
#include "Meeting_t.h"


static float get_start_time()
{
	float start_time;
	cout << "Enter the start time:" << endl;
	cin >> start_time;
	return start_time;
}

static float get_end_time()
{
	float end_time;
	cout << "Enter the end time:" << endl;
	cin >> end_time;
	return end_time;
}

static string getSubject()
{
	string subject;
	cout << "Enter the subject:" << endl;
	cin >> subject;
	return subject;
}

static Meeting_t<int>* getMeeting_int()
{
	int start_time, end_time;
	string subject;

	start_time = (int)get_start_time();
	end_time = (int)get_end_time();
	subject = getSubject();

	Meeting_t<int> *meeting = new Meeting_t<int>();
	meeting->create(start_time, end_time, subject);
	return meeting;
}

static Meeting_t<float>* getMeeting_float()
{
	float start_time, end_time;
	string subject;

	start_time = get_start_time();
	end_time = get_end_time();
	subject = getSubject();

	Meeting_t<float> *meeting = new Meeting_t<float>();
	meeting->create(start_time, end_time, subject);
	return meeting;
}

static void test_int()
{
	DayCalendar_t<int> day;
	Meeting_t<int> * meeting;

	char c;

	float start_time;

	bool cont = true;

	while (cont) {
		cout << "Press f to find a meeting in day" << endl
			<< "Press i to insert a new meeting" << endl
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
		case 'i':  meeting = getMeeting_int();
			day.insert_meeting(meeting);
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

static void test_float()
{
	DayCalendar_t<float> day;
	Meeting_t<float> * meeting;

	char c;

	float start_time;

	bool cont = true;

	while (cont) {
		cout << "Press f to find a meeting in day" << endl
			<< "Press i to insert a new meeting" << endl
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
		case 'i':  meeting = getMeeting_float();
			day.insert_meeting(meeting);
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

int main() {
	char c;

	cout << "Press i or f to choose int or float (type of time). Press any other key to exit" << endl;
	cin >> c;
	switch (c)
	{
	case 'i': test_int(); break;
	case 'f': test_float(); break;
	default:
		return 0;
	}

	return 0;
}