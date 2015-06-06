#ifndef CTIME_T
#define CTIME_T

#include <time.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "Observer.h"

using namespace std;

class cTime_t :public Subject
{
public:
	virtual ~cTime_t();
	cTime_t(); //from current time
	cTime_t(size_t hour, size_t minutes, size_t seconds);  //throws exception is day month year combination is invalid. Yossi agreed!
	cTime_t(const cTime_t & time);
	/*The point of making an assignment operator virtual is to allow you from the benefit of being able to override it to copy more fields.*/
	virtual cTime_t & operator=(const cTime_t & time);

	virtual void setHour(size_t hour);  
	virtual void setMinutes(size_t  minutes);
	virtual void setSeconds(size_t seconds);
	inline size_t getHour() const;  
	inline size_t getMinutes() const;
	inline size_t getSeconds() const;

	virtual void print(int format); // got approve form Yossi to use it as paramater

	// will notify the observers if the time exceeded a day.
	//Yossi wrote in the forum that we need to overwrite + operator and not +=.
	cTime_t operator+(const cTime_t & time);

protected:
	// got approve from Yossi to use them as static
	inline static bool is_valid_hour(size_t hour);
	inline static bool is_valid_minutes(size_t minutes);
	inline static bool is_valid_seconds(size_t seconds);


private:
	size_t hour_m;
	size_t minutes_m;
	size_t seconds_m;

};



// inline implementation

inline size_t cTime_t::getHour() const
{
	return hour_m;
}
inline size_t cTime_t::getMinutes() const
{
	return minutes_m;
}
inline size_t cTime_t::getSeconds() const
{
	return seconds_m;
}

inline bool cTime_t::is_valid_hour(size_t hour)
{
	return (hour < 24 && hour >= 0);
}
inline bool cTime_t::is_valid_minutes(size_t minutes)
{
	return (minutes < 60 && minutes >= 0);
}
inline bool cTime_t::is_valid_seconds(size_t seconds)
{
	return (seconds < 60 && seconds >= 0);
}


#endif
