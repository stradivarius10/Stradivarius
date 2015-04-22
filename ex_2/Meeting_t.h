#ifndef MEETING
#define MEETING

#include <string>
#include <iostream>
using namespace std;
template <class T> class Meeting_t
{
	
	friend ostream& operator<< (ostream& os, const Meeting_t<T> & m)
	{
		
		cout << "start time is " << m.get_start_time() << endl
			<< "end time is " << m.get_end_time() << endl
			<< "subject is " << m.get_subject() << endl;
		return os;
		
	}

public:
	virtual ~Meeting_t();
	Meeting_t(); //CTOR - returns a person with a name, and age and a unique ID
    void create(T start_time, T end_time, string subject); //should we throw exception
	bool operator==(const Meeting_t &meeting) const; 
	bool operator<(const Meeting_t &meeting) const;
	bool operator>(const Meeting_t &meeting) const;



	T get_start_time() const; //inline???
	T get_end_time() const;
	string get_subject() const;


private:
	T start_time_m;
	T end_time_m;
	string	subject_m;
};


template <class T>  Meeting_t<T>:: ~Meeting_t()
{
	//delete(&start_time_m);
	//delete(&end_time_m);
	//delete(&subject_m); /// wtf???????
}


template <class T>  Meeting_t<T>::Meeting_t(){} //default constructor we wil use init instead


template <class T> void  Meeting_t<T>::create(T start_time, T end_time, string subject)
{
	if ((start_time > end_time) || (start_time < 0) || (start_time >= 24))
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

template <class T> bool Meeting_t<T>::operator==(const Meeting_t &meeting) const
{
	if ((this->start_time_m <= meeting.start_time_m && this->end_time_m >= meeting.start_time_m)
		|| (meeting.start_time_m <= this->start_time_m && meeting.end_time_m >= this->start_time_m))
		return true;
	return false;
}

template <class T> bool Meeting_t<T>::operator<(const Meeting_t &meeting) const
{
	return this->start_time_m < meeting.start_time_m;
}

template <class T> bool Meeting_t<T>::operator>(const Meeting_t &meeting) const
{
	return this->start_time_m > meeting.start_time_m;
}

//istream& operator>> (istream& is, Meeting_t <T> & m);
//stream& operator<< (ostream& os, const Meeting_t <T> & m);


#endif