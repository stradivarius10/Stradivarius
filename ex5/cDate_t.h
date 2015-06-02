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
	cDate_t(const cDate_t & date);
	cDate_t & operator=(const cDate_t & date);

	inline void setDay(size_t day);   // should we use & in here???
	inline void setMonth(size_t  month);
	inline void setYear(size_t year);
	size_t getDay() const;   // should we use & in here???
	inline size_t getMonth() const;
	inline size_t getYear() const;
    size_t getDayOfYear() const;
    inline size_t getDayOfMonth() const;
	inline bool isYearLeap() const;
    string getNameOfDay() const;
    string getNameOfMonth() const;

	void print(int format); //format can be 1, 2 or 3

protected:
	void  get_data(struct tm * timeinfo) const;

private:
	size_t day_m;
	size_t month_m;
	size_t year_m;

	inline static bool is_valid_day_month_year(size_t day, size_t month, size_t year); //ask!!!!!!!!!!!!!!!!!!!!


};

//inline implementation

inline void cDate_t::setDay(size_t day)
{
	if (is_valid_day_month_year(day, month_m, year_m))
	{
		day_m = day;
	}
	else
	{
		throw exception("invalid day month and year combination");
	}

}


inline void cDate_t::setMonth(size_t month)
{
	if (is_valid_day_month_year(day_m, month, year_m))
	{
		month_m = month;
	}
	else
	{
		throw exception("invalid day month and year combination");
	}

}
inline void cDate_t::setYear(size_t year)
{
	if (is_valid_day_month_year(day_m, month_m, year))
	{
		year_m = year;
	}
	else
	{
		throw exception("invalid day month and year combination");
	}

}


inline size_t cDate_t::getMonth() const
{
	return month_m;
}
inline size_t cDate_t::getYear() const
{
	return year_m;
}

inline size_t cDate_t::getDayOfMonth() const
{
	return day_m;
}
inline bool cDate_t::isYearLeap() const
{
	return ( (year_m % 4) == 0) && ( (year_m % 400) == 0);
}

inline bool cDate_t::is_valid_day_month_year(size_t day, size_t month, size_t year)
{
	if (day > 31)
	{
		return false;
	}
	if (month < 1 || month >12)
	{
		return false;
	}
	if (year < 1900) // YOSSI AGREED IN THE FORUM
	{
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		return false;
	}
	if (month == 2)
	{
		if (day > 29)
			return false;
		if (!(((year % 4) == 0) && ((year % 400) == 0)) && (day == 29)) //  only not in leap year day 29 is valid
			return false; 
	}
	
	return true;

}



#endif
