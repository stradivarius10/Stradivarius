#ifndef CDATE_T
#define CDATE_T

#include <time.h>
#include <string>
#include <iostream>

using namespace std;

class cDate_t
{
public:
	virtual ~cDate_t();
	cDate_t(); //from current time
	cDate_t(size_t day, size_t month, size_t year);
	cDate_t(const cDate_t & time);
	cDate_t & operator=(const cDate_t & date);
	inline void setDay(size_t day);   // should we use & in here???
	inline void setMonth(size_t  month);
	inline void setYear(size_t year);
	inline size_t getDay() const;   // should we use & in here???
	inline size_t getMonth() const;
	inline size_t getYear() const;
	inline size_t getDayOfYear() const;
	inline size_t getDayOfMonth() const;
	inline bool isYearLeap() const;
	inline string getNameOfDay() const;
	inline string getNameOfMonth() const;

	void print(int format); //format can be 1, 2 or 3

private:
	size_t day_m;
	size_t month_m;
	size_t year_m;
};


inline void cDate_t::setDay(size_t day)
{
	day_m = day;
}


inline void cDate_t::setMonth(size_t month)
{
	month_m = month;
}
inline void cDate_t::setYear(size_t year)
{
	year_m = year;
}


inline size_t cDate_t::getDay() const
{
	return day_m;
}
inline size_t cDate_t::getMonth() const
{
	return month_m;
}
inline size_t cDate_t::getYear() const
{
	return year_m;
}


#endif
