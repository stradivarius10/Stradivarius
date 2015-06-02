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
	cTime_t(size_t hour, size_t minutes, size_t seconds); // problem of checking!!!!!!!!!!!!!!!!!
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

	inline static bool is_valid_hour(size_t hour); //ask!!!!!!!!!!!!!!!!!!!!
	inline static bool is_valid_minutes(size_t minutes); //ask!!!!!!!!!!!!!!!!!!!!
	inline static bool is_valid_seconds(size_t seconds); //ask!!!!!!!!!!!!!!!!!!!!
};



// inline implementation

inline void cTime_t::setHour(size_t hour)
{
	if (is_valid_hour(hour))
	{
		hour_m = hour;
	}
	else
	{
		throw exception("Invalid hour. Hour has to be 0-23");
	}
}


inline void cTime_t::setMinutes(size_t minutes)
{
	if (is_valid_minutes(minutes))
	{
		minutes_m = minutes;
	}
	else
	{
		throw exception("Invalid minutes. Hour has to be 0-59");
	}
}
inline void cTime_t::setSeconds(size_t seconds)
{
	if (is_valid_seconds(seconds))
	{
		seconds_m = seconds;
	}
	else
	{
		throw exception("Invalid seconds. Hour has to be 0-59");
	}

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
