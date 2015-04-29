#ifndef DAY_CALENDAR
#define DAY_CALENDAR
#include "Meeting_t.h"
#include <string>
#include <iostream>
#include <vector>

template <class T> class DayCalendar_t
{
public:
	virtual ~DayCalendar_t();

	DayCalendar_t();  
	DayCalendar_t(const DayCalendar_t<T>& meeting); // copy constructor

	virtual void insert_meeting( Meeting_t<T> * meeting); // can throw exception. virtual so in a case that someone is
	// overiding in order to let's say record the meeting somewhere else,  he can do it.
	virtual void remove_meeting(const T & start_time); //throws exception if not existed 
	virtual Meeting_t<T> *find_meeting(const T & start_time) const; //returns null if not found
	virtual bool operator==(const DayCalendar_t<T> &meeting) const;
	/*The point of making an assignment operator virtual is to allow you from the benefit of being able to override it to copy more fields.*/
	virtual DayCalendar_t<T> &  operator=(const DayCalendar_t<T> &meeting); //copy constructor. In case we want to have the same calendar for a different day
	virtual void remove_all(); // destroy all elements - if the user wishes!

protected:
	// we decided to make it protected in case a derived class wants to use it. For example, cloud may want an access to batch of meeting at once
	vector<Meeting_t<T> *> meetings_arr_m;


private:
	/* this function will tell us the index that the item should be inserted and thus
	the array will be sorted */
	bool is_meeting_exists(const Meeting_t<T> & meeting) const;
	size_t find_correct_insertion_location(Meeting_t<T> & meeting) const;


	friend ostream& operator<< (ostream& os, const DayCalendar_t<T> & m)
	{
		cout << "The calendar is" << endl;
		for (size_t i = 0; i < m.meetings_arr_m.size(); i++)
		{
			cout << *(m.meetings_arr_m[i]) << endl;
		}
		return os;
	}
};

template <class T>  DayCalendar_t<T>::DayCalendar_t(){}

template <class T>  DayCalendar_t<T>:: ~DayCalendar_t()
{
	meetings_arr_m.clear();
}


template <class T> bool DayCalendar_t<T>::operator==(const DayCalendar_t<T> &calendar_other) const
{
	return meetings_arr_m == calendar_other.meetings_arr_m;
}


template <class T>  DayCalendar_t<T> & DayCalendar_t<T>::operator=(const DayCalendar_t<T> &calendar)
{
	if (this != &calendar)
	{
		this->meetings_arr_m = calendar.meetings_arr_m;
	}

	return *this;
}


template <class T>  DayCalendar_t<T>::DayCalendar_t(const DayCalendar_t<T>& meeting)
{
	this->meetings_arr_m = meeting.meetings_arr_m;
}


template <class T> void DayCalendar_t<T>::remove_meeting(const T & start_time)
{
	size_t i = 0;

	//  not existed!
	if (find_meeting(start_time) == NULL)
	{
		throw exception("Nothing to remove!!!!!");
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
	/* Please note that accrrding to the teacher, complexity is NOT important*/
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
	
	for (size_t i = 0; i < meetings_arr_m.size(); i++)
	{
		delete meetings_arr_m[i];
	}
	
	meetings_arr_m.clear();


}


template <class T> void DayCalendar_t<T>::insert_meeting(Meeting_t<T> * meeting)
{
	size_t position;
	// already existed!
	if (is_meeting_exists(*meeting))
	{
		throw exception("Already existed (may be a time intersection as well)!");
	}

	position = find_correct_insertion_location(*meeting);

	vector<Meeting_t<T>*>::iterator it = meetings_arr_m.begin() + position;
	meetings_arr_m.insert(it, meeting);

}

template <class T> size_t DayCalendar_t<T>::find_correct_insertion_location(Meeting_t<T> & meeting) const
{
	size_t i = 0;
	/* Please note that accrrding to the teacher, complexity is NOT important*/
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
	/* Please note that accrrding to the teacher, complexity is NOT important*/
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
