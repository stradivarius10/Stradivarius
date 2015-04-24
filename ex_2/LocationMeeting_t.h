#ifndef LOCATION_MEETING
#define LOCATION_MEETING

#include "Meeting_t.h"

template <class T> class LocationMeeting_t:public Meeting_t<T>
{
public:
	virtual ~LocationMeeting_t();
	LocationMeeting_t(); 
	LocationMeeting_t<T>(const LocationMeeting_t& meeting); // copy constructor
	void create(const T &start_time, const T &end_time, const string &subject,const string location); //should we throw exception

	LocationMeeting_t &  operator=(const  LocationMeeting_t &meeting);
	inline string get_location() const;

	/*
protected:
	virtual ostream& meeting_out(ostream& os) const;
	*/

private:
	string location_m; 


};

template <class T>  LocationMeeting_t<T>:: ~LocationMeeting_t()
{
	
}




template <class T>   LocationMeeting_t<T>::LocationMeeting_t(){} //default constructor we wil use init instead


template <class T> void   LocationMeeting_t<T>::create(const T &start_time, const T &end_time, const string &subject, const string location)
{
	Meeting_t<T>::create(start_time, end_time, subject);
	location_m = location;
}


template <class T>  LocationMeeting_t<T>::LocationMeeting_t(const LocationMeeting_t& meeting)
{
	this->end_time_m = meeting.end_time_m;
	this->start_time_m = meeting.start_time_m;
	this->subject_m = meeting.subject_m;
	this->location_m = meeting.location_m;
}



template <class T> ostream& operator<< (ostream& os, const LocationMeeting_t<T> & m)
{
	//return m.meeting_out(os);
	os << "start time is " << m.get_start_time() << endl
		<< "end time is " << m.get_end_time() << endl
		<< "subject is " << m.get_subject() << endl;
	<< "location is " << m.get_location() << endl;
	return os;
}

template <class T> string LocationMeeting_t<T>::get_location() const
{
	return location_m;
}


template <class T>  LocationMeeting_t<T> & LocationMeeting_t<T>::operator=(const LocationMeeting_t &meeting)
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




/*
template <class T> ostream& LocationMeeting_t<T>::meeting_out(ostream& os) const
{
	Meeting_t<T>::meeting_out(os) << "The location is " << location_m << endl;
	return os;
}

*/
#endif
