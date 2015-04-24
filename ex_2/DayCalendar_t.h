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
	 for (size_t i = 0; i < m.get_array().size(); i++)
	 {
		 cout << *(m.get_array()[i]) << endl;
	 }
	 return os;
 }



public:
	virtual ~DayCalendar_t();// default is fine

	//DayCalendar_t(); //Default will be just fine for us.	
	//bool operator==  will be providedp by the compiler

	void insert_meeting( Meeting_t<T> * meeting); // can throw exception
	void remove_meeting(const T & start_time); //throws exception if not existed 
	Meeting_t<T> *find_meeting(const T & start_time) const; //returns null if not found
	virtual void remove_all(); // destroy all elements

	vector<Meeting_t<T> *> get_array() const;
private:
	/* this function will tell us the index that the item should be inserted and thus
	the array will be sorted */
	bool is_meeting_exists(const Meeting_t<T> & meeting) const;
	size_t find_correct_insertion_location(Meeting_t<T> & meeting) const;
	vector<Meeting_t<T> *> meetings_arr_m;

};



template <class T> vector<Meeting_t<T> *>  DayCalendar_t<T>::get_array() const
{
	return meetings_arr_m;
}

template <class T>  DayCalendar_t<T>:: ~DayCalendar_t()
{
	meetings_arr_m.clear();
}




template <class T> void DayCalendar_t<T>::remove_meeting(const T & start_time)
{
	size_t i = 0;

	//  not existed!
	if (find_meeting(start_time) == NULL)
	{
		throw ("Nothing to remove!!!!!");
	}

	for (; i < meetings_arr_m.size(); i++)
	{
		if (meetings_arr_m[i]->get_start_time() == start_time)
		{
			vector<Meeting_t<T>*>::iterator it = meetings_arr_m.begin() + i;
			meetings_arr_m.erase(it);

		}
	}
}



template <class T> Meeting_t<T> * DayCalendar_t<T>::find_meeting(const T & start_time) const
{
	for (size_t i = 0; i < meetings_arr_m.size(); i++)
	{
		if (meetings_arr_m[i]->get_start_time() == start_time)
		{
			return meetings_arr_m[i];
		}		
	}
	return NULL;
}

template <class T> void DayCalendar_t<T>::remove_all()
{
	/*
	for (int i = 0; i < meetings_arr_m.size(); i++)
	{
		delete meetings_arr_m.get(i);
	}
	*/
	meetings_arr_m.clear();


}


template <class T> void DayCalendar_t<T>::insert_meeting(Meeting_t<T> * meeting)
{
	size_t position;
	// already existed!
	if (is_meeting_exists(*meeting))
	{
		throw ("Already existed (may be a time intersection as well)!");
	}

	position = find_correct_insertion_location(*meeting);

	vector<Meeting_t<T>*>::iterator it = meetings_arr_m.begin() + position;
	meetings_arr_m.insert(it, meeting);

}

template <class T> size_t DayCalendar_t<T>::find_correct_insertion_location(Meeting_t<T> & meeting) const
{
	size_t i = 0;
	for (; i < meetings_arr_m.size(); i++)
	{
		if (meeting < *(meetings_arr_m[i]))
		{
			return i;
		}
	}
	return i;
}

template <class T> bool DayCalendar_t<T>::is_meeting_exists(const Meeting_t<T> & meeting) const
{
	size_t i = 0;
	for (; i < meetings_arr_m.size(); i++)
	{
		if (meeting == *(meetings_arr_m[i]))
		{
			return true;
		}
	}
	return false;
}







#endif
