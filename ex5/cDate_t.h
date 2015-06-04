#ifndef CDATE_T
#define CDATE_T

#include <time.h>
#include <string>
#include <iostream>
#include "Observer.h"
#include "cTime_t.h"
#include <iomanip>

using namespace std;


/* Yossi has asked to have a possiblity of inheritence of other langauges like chinese. I talked to him and he told me that I can assume that all times have day month and year
* He also told me that what I should do is use the data members as protected so any class who wants to inherit me, will be able to use them as we wants and also brought me an
* example form his real life. So that what I did. I also Used the Observer as we been taught in class and also got agreeement for that.
*/


class cDate_t : public Observer
{
public:
	virtual ~cDate_t();
	cDate_t(); //from current time
	cDate_t(size_t day, size_t month, size_t year); //throws exception is day month year combination is invalid. Yossi agreed!
	cDate_t(const cDate_t & date);

	/*The point of making an assignment operator virtual is to allow you from the benefit of being able to override it to copy more fields.*/
	virtual cDate_t & operator=(const cDate_t & date);

	virtual void setDayMonthYear(size_t day, size_t  month, size_t year);
    virtual void setDay(size_t day);  
	virtual void setMonth(size_t  month);
	virtual void setYear(size_t year);

	virtual size_t getDay() const;   
	virtual bool isYearLeap() const;
	virtual string getNameOfDay() const;
	virtual string getNameOfMonth() const;
	virtual size_t getDayOfYear() const;

	inline size_t getMonth() const;
	inline size_t getYear() const;
    inline size_t getDayOfMonth() const;

	virtual void  print(int format);// got apprvoce form Yossi to use it as paramater
	virtual void  Update(Subject* ChngSubject);
	virtual void  connect_with_time(cTime_t *);
	virtual void  disconnect_from_time(cTime_t *);

protected:
	virtual void  get_data(struct tm * timeinfo) const;
	virtual void  increase_date();
	virtual bool is_valid_day_month_year(size_t day, size_t month, size_t year);
	Subject* sbj;


	/* Yossi has asked to have a possiblity of inheritence of other langauges like chinese. I talked to him and he told me that I can assume that all times have day month and year
	* He also told me that what I should do is use the data members as protected so any class who wants to inherit me, will be able to use them as we wants and also brought me an
	* example form his real life. So that what I did. I also Used the Observer as we been taught in class and also got agreeement for that.
	*/
	size_t day_m;
	size_t month_m;
	size_t year_m;

};

//inline implementation


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



#endif
