#ifndef MEETING
#define MEETING

#include <string>
#include <iostream>
using namespace std;

template <class T> class Meeting_t
{
	
public:
	virtual ~Meeting_t();
	Meeting_t(); // We said in class that we shouldn't throw excpetions in constructors and we rather use a init function after we create the object.
	Meeting_t<T>(const Meeting_t<T>& meeting); // copy constructor
	/* This function is initializing the objects and might throw expcetion. They "Way" of the big companies
	to overcome the throwing execptions in the constructor..*/
    void create(const T &start_time,const T &end_time,const string &subject); 


	/* return true if there is an intersection - according the the HW specs.We didn't make it virtual so 
	someone overides it and overides the HW sumbission guidline*/
	inline bool operator==(const Meeting_t<T> &meeting) const;

	Meeting_t<T> &  operator=(const Meeting_t<T> &meeting);

	inline bool operator<(const Meeting_t<T> &meeting) const;
	inline bool operator>(const Meeting_t<T> &meeting) const;

	inline T get_start_time() const; 
	inline T get_end_time() const;
	inline string get_subject() const;

	/* will print the object. We use it in order to achieve polymorphism of prints*/
	virtual void print() const;

private:
	T start_time_m;
	T end_time_m;
	string	subject_m;

};



template <class T>  Meeting_t<T>:: ~Meeting_t()
{
}

//We said in class that we shouldn't throw excpetions in constructors and we rather use a init function after we create the object.
template <class T>  Meeting_t<T>::Meeting_t(){} 


template <class T>  Meeting_t<T>::Meeting_t(const Meeting_t<T>& meeting)
{
	this->end_time_m = meeting.end_time_m;
	this->start_time_m = meeting.start_time_m;
	this->subject_m = meeting.subject_m;
} 



template <class T> void  Meeting_t<T>::create(const T &start_time, const T &end_time, const string &subject)
{
	if ((start_time >= end_time) || (start_time < 0) || (end_time >= 24))
	{
		throw exception("Illegal params");
	}
	start_time_m = start_time;
	end_time_m = end_time;
	subject_m = subject;
}

template <class T> T Meeting_t<T>::get_start_time() const
{
	return start_time_m;
}

template <class T> T Meeting_t<T>::get_end_time() const
{
	return end_time_m;
}

template <class T> string Meeting_t<T>::get_subject() const
{
	return subject_m;
}




template <class T> bool Meeting_t<T>::operator==(const Meeting_t<T> &meeting) const
{
	if ((this->start_time_m <= meeting.start_time_m && this->end_time_m > meeting.start_time_m)
		|| (meeting.start_time_m < this->start_time_m && meeting.end_time_m > this->start_time_m))
	{
		return true;
	}
	return false;
}



template <class T>  Meeting_t<T> & Meeting_t<T>::operator=(const Meeting_t<T> &meeting)
{
	// since we overided the == operator
	if (this != &meeting)
	{
		this->end_time_m = meeting.end_time_m;
		this->start_time_m = meeting.start_time_m;
		this->subject_m = meeting.subject_m;
	}

	return *this;
}


template <class T> void Meeting_t<T>::print() const
{
	cout << *this;
}

template <class T> bool Meeting_t<T>::operator<(const Meeting_t<T> &meeting) const
{
	return (this->start_time_m) < meeting.start_time_m;
}

template <class T> bool Meeting_t<T>::operator>(const Meeting_t<T> &meeting) const
{
	return (this->start_time_m) > meeting.start_time_m;
}

template <class T>  ostream& operator<< (ostream& os, const Meeting_t<T> & m)
{
	os << "start time is " << m.get_start_time() << endl
		<< "end time is " << m.get_end_time() << endl
		<< "subject is " << m.get_subject() << endl;
	return os;
}



#endif