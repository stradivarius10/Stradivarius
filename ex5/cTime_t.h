#ifndef CTIME_T
#define CTIME_T

#include <time.h>
#include <string>
#include <iostream>

using namespace std;

class cTime_t
{
public:
	virtual ~cTime_t();
	cTime_t(); //from current time
	cTime_t(size_t hour, size_t minutes, size_t seconds);
	cTime_t(const cTime_t & time);
	cTime_t & operator=(const cTime_t & time);
	inline void setHour(size_t hour);   // should we use & in here???
	inline void setMinutes(size_t  minutes);
	inline void setSeconds(size_t seconds);
	inline size_t getHour() const;   // should we use & in here???
	inline size_t getMinutes() const;
	inline size_t getSeconds() const;

	void print(int format); //format can be 1 or 2


private:
	size_t hour_m;
	size_t minutes_m;
	size_t seconds_m;
};


inline void cTime_t::setHour(size_t hour)
{
	hour_m = hour;
}


inline void cTime_t::setMinutes(size_t minutes)
{
	minutes_m = minutes;
}
inline void cTime_t::setSeconds(size_t seconds)
{
	seconds_m = seconds;
}


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


#endif
