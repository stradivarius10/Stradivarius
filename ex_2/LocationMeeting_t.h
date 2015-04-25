#ifndef LOCATION_MEETING
#define LOCATION_MEETING

#include "Meeting_t.h"

template <class T> class LocationMeeting_t:public Meeting_t<T>
{
public:
	virtual ~LocationMeeting_t();
	LocationMeeting_t(); // We said in class that we shouldn't throw excpetions in constructors and we rather use a init function after we create the object.
	LocationMeeting_t(const LocationMeeting_t<T>& meeting); // copy constructor
	/* This function is initializing the objects and might throw expcetion. They "Way" of the big companies
	to overcome the throwing execptions in the constructor..*/
	void create(const T &start_time, const T &end_time, const string &subject,const string location); 

	LocationMeeting_t<T> &  operator=(const  LocationMeeting_t<T> &meeting);
	inline string get_location() const;

	/* will print the object. We use it in order to achieve polymorphism of prints*/
	virtual ostream& print(ostream& os) const;


private:
	string location_m; 


};

template <class T>  LocationMeeting_t<T>:: ~LocationMeeting_t(){}

template <class T>   LocationMeeting_t<T>::LocationMeeting_t(){} //default constructor we will use create instead


template <class T> void   LocationMeeting_t<T>::create(const T &start_time, const T &end_time, const string &subject, const string location)
{
	Meeting_t<T>::create(start_time, end_time, subject);
	location_m = location;
}


template <class T>  LocationMeeting_t<T>::LocationMeeting_t(const LocationMeeting_t<T>& meeting)
{
	this->end_time_m = meeting.end_time_m;
	this->start_time_m = meeting.start_time_m;
	this->subject_m = meeting.subject_m;
	this->location_m = meeting.location_m;
}

template <class T> string LocationMeeting_t<T>::get_location() const
{
	return location_m;
}

template <class T> ostream& LocationMeeting_t<T>::print(ostream& os) const
{
	Meeting_t<T>::print(os) << "location is " << location_m << endl;
	return os;
}


template <class T>  LocationMeeting_t<T> & LocationMeeting_t<T>::operator=(const LocationMeeting_t<T> &meeting)
{
	// since we overided the == operator
	if (&this != &meeting)
	{
		this->end_time_m = meeting.end_time_m;
		this->start_time_m = meeting.start_time_m;
		this->subject_m = meeting.subject_m;
		this->location_m = metting.LocationMeeting_t
	}

	return *this;
}



#endif
