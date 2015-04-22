#ifndef DAY_CALENDAR
#define DAY_CALENDAR
#include "Meeting_t.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


template <class T> class DayCalendar_t
{
 friend ostream& operator<< (ostream& os, const DayCalendar_t<T> & m)
 {
	 cout << "The calendar is" << endl;
	 for (size_t i = 0; i < meetings_arr_m.size(); i++)
	 {
		 cout << *(meetings_arr_m.get(i)) << endl;
	 }
	 return os;
 }



public:
	virtual ~DayCalendar_t();
	//meetings_arr_m; (); //Default will be just fine for us.	
	//bool operator==  will be providedp by the compiler

	void insert_meeting(Meeting_t<T> * meeting);
	void remove_meeting(T & start_time);
	Meeting_t<T> *find_meeting(T & start_time) const; //returns null if not found

private:
	size_t find_correct_insertion_location(Meeting_t<T> & meeting);
	vector<Meeting_t<T> *> meetings_arr_m;

};

template <class T>  virtual DayCalendar_t<T>:: ~DayCalendar_t()
{
	delete(& meeting_arr_m);
}



template <class T> void DayCalendar_t<T>::remove_meeting(T & start_time)
{
	size_t i = 0;

	//  not existed!
	if (find_meeting(meeting->get_start_time()) == NULL)
	{
		throw exception("Nothing to remove!!!!!");
	}

	for (; i < meetings_arr_m.size(); i++)
	{
		if (meetings_arr_m.get(i)->get_start_time() == start_time)
		{
			meetings_arr_m.erase(i);
		}
	}
	return i;
}



template <class T> Meeting_t<T> * DayCalendar_t<T>::find_meeting(T & start_time) const
{
	for (int i = 0; i < meetings_arr_m.size(); i++)
	{
		if (meetings_arr_m.get(i)->get_start_time() == start_time)
		{
			return meetings_arr_m.get(i);
		}		
	}
	return NULL;
}



template <class T> void DayCalendar_t<T>::insert_meeting(Meeting_t<T> * meeting)
{
	size_t position;
	// already existed!
	if (find_meeting(meeting->get_start_time()) == NULL)
	{
		throw exception("Already existed bitch!");
	}
	position = find_correct_insertion_location(*meeting);
	meetings_arr_m.insert(position, meeting);

}

template <class T> size_t DayCalendar_t<T>::find_correct_insertion_location(Meeting_t<T> & meeting)
{
	size_t i = 0;
	for (; i < meetings_arr_m.size(); i++)
	{
		if (meeting > *(meetings_arr_m.get(i)))
		{
			return i;
		}
	}
	return i;
}







#endif
