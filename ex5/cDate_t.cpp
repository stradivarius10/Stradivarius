#include "cDate_t.h"
#include <iomanip>

cDate_t::~cDate_t()
{
	if (sbj != nullptr)
	{
		sbj->Detach(this);
	}
}

cDate_t::cDate_t()
{
	time_t 	time_of_date;
	struct tm* 	current_time;

	time_of_date = time(0);	// current time in seconds
	current_time = localtime(&time_of_date);

	day_m = current_time->tm_mday;
	month_m = current_time->tm_mon + 1;
	year_m = current_time->tm_year + 1900;

}



cDate_t::cDate_t(size_t day, size_t month, size_t year) :day_m(day), month_m(month), year_m(year), sbj(nullptr){}


cDate_t::cDate_t(const cDate_t & date)
{
	day_m = date.day_m;
	month_m = date.month_m;
	year_m = date.year_m;
	sbj = date.sbj;
}

cDate_t & cDate_t::operator=(const cDate_t & date)
{

	if (this != &date)
	{
		day_m = date.day_m;
		month_m = date.month_m;
		year_m = date.year_m;
		sbj = date.sbj;
	}

	return *this;

}




size_t cDate_t::getDay() const
{

	struct tm timeinfo;

	get_data(&timeinfo);

	return timeinfo.tm_wday + 1;

}

void  cDate_t::get_data(struct tm * timeinfo) const
{
	struct tm * temp;

	time_t rawtime;

	time(&rawtime);
	temp = localtime(&rawtime);
	*timeinfo = *temp;
	timeinfo->tm_year = year_m - 1900;
	timeinfo->tm_mon = month_m - 1;
	timeinfo->tm_mday = day_m;

	/* call mktime: timeinfo->tm_wday will be set */
	mktime(timeinfo);
}

size_t cDate_t::getDayOfYear() const
{
	struct tm  timeinfo;
	get_data(&timeinfo);

	return timeinfo.tm_yday + 1;
}


string cDate_t::getNameOfDay() const
{

	static const string days_rep[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return days_rep[getDay() - 1];

}

string cDate_t::getNameOfMonth() const
{

	static const string month_rep[] = { "January", "February", "March", "April", "May", "June","July", "August", 
		"September", "October", "November","December"};
	return month_rep[month_m - 1];

}

void cDate_t::print(int format) //format can be 1, 2 or 3
{
	if (format == 1)
	{
		/*
		if (day_m < 10)
		{
			cout << "0";
		}
		cout << day_m << "/" << getNameOfMonth() << "/" << year_m <<  endl;
		*/
		cout << setw(2)<< setfill('0') <<day_m << "/" << getNameOfMonth() << "/" << year_m << endl;
	}
	else if (format == 2)
	{
		/*
		if (day_m < 10)
		{
			cout << "0";
		}
		cout << day_m << "/";
		if (month_m < 10)
		{
			cout << "0";
		}
		cout << month_m << "/" << year_m << "            European" << endl;
		*/
		cout << setw(2) << setfill('0') << day_m << "/" <<  setw(2)<< month_m << "/" << year_m << "            European" << endl;
	}
	else if (format == 3)
	{
		/*
		if (month_m < 10)
		{
			cout << "0";
		}
		cout << month_m << "/";
		if (day_m < 10)
		{
			cout << "0";
		}
		*/
		cout << setw(2) << setfill('0') << month_m << "/" << setw(2) << day_m << "/" << year_m << "            American" << endl;
	}
	else
	{
		throw exception("Format has to be 1 or 2");

	}

}

void  cDate_t::connect_with_time(Subject * time_t)  //should we check it's time???
{
	sbj = time_t;
	sbj->Attach(this);
}


void cDate_t::Update(Subject* theChangedSubject)
{
	if (theChangedSubject == sbj)
	{
		if (is_valid_day_month_year(day_m + 1, month_m, year_m)) //valid date..
		{
			day_m++;
		}
		else //we need to increase month and maybe the year..
		{
			if (month_m == 12)
			{
				year_m++;
				month_m = 1;
			}
			else
			{

				month_m++;
				day_m++;
			}

		}
	}
}


bool cDate_t::is_valid_day_month_year(size_t day, size_t month, size_t year)
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
