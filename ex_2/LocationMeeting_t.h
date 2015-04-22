#ifndef LOCATION_MEETING
#define LOCATION_MEETING

#include "Meeting_t.h"

template <class T> class LocationMeeting_t:public Meeting_t<T>
{
public:
	virtual ~LocationMeeting_t();
	LocationMeeting_t(); //CTOR - returns a person with a name, and age and a unique ID
	void create(T start_time, T end_time, string subject, string location); //should we throw exception
	//bool operator==(const Meeting_t &meeting) const;

//	T get_start_time() const; //inline???
//	T get_end_time() const;
//	string get_subject() const;
	string get_location() const;



private:
	string location_m; 
};

template <class T>  virtual LocationMeeting_t<T>:: ~LocationMeeting_t()
{
	delete(&location_m); /// wtf???????
}




template <class T>   LocationMeeting_t<T>::LocationMeeting_t(){} //default constructor we wil use init instead


template <class T> void   LocationMeeting_t<T>::create(T start_time, T end_time, string subject, string location)
{
	create(start_time, end_time, subject);
	location_m = location;
}

template <class T> string LocationMeeting_t<T>::get_location() const
{
	return location_m;
}

//istream& operator>> (istream& is, Meeting_t <T> & m);
//stream& operator<< (ostream& os, const Meeting_t <T> & m);



#endif
