#ifndef DAY_CALENDAR
#define DAY_CALENDAR
#include "Meeting_t.h"
#include <string>
#include <iostream>
#include <vector>


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
	//DayCalendar_t; (); //Default will be just fine for us.	
	//bool operator==  will be providedp by the compiler

	void insert_meeting(const Meeting_t<T> * meeting); // can throw exception
	void remove_meeting(const T & start_time); //throws exception if not existed 
	Meeting_t<T> *find_meeting(const T & start_time) const; //returns null if not found

private:
	/* this function will tell us the index that the item should be inserted and thus
	the array will be sorted */
	size_t find_correct_insertion_location(Meeting_t<T> & meeting) const;
	vector<Meeting_t<T> *> meetings_arr_m;

};

template <class T>  virtual DayCalendar_t<T>:: ~DayCalendar_t()
{
	delete(& meeting_arr_m);
}



template <class T> void DayCalendar_t<T>::remove_meeting(const T & start_time)
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
}



template <class T> Meeting_t<T> * DayCalendar_t<T>::find_meeting(const T & start_time) const
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



template <class T> void DayCalendar_t<T>::insert_meeting(const Meeting_t<T> * meeting)
{
	size_t position;
	// already existed!
	if (find_meeting(meeting->get_start_time()) == NULL)
	{
		throw exception("Already existed (may be a time intersection as well)!");
	}

	position = find_correct_insertion_location(*meeting);
	meetings_arr_m.insert(position, meeting);

}

template <class T> size_t DayCalendar_t<T>::find_correct_insertion_location(Meeting_t<T> & meeting) const
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
