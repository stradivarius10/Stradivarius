#include "cTime_t.h"


cTime_t::~cTime_t(){}

cTime_t::cTime_t()
{
	time_t 	time_of_date;
	struct tm* 	current_time;

	time_of_date = time(0);	// current time in seconds
	current_time = localtime(&time_of_date);

	hour_m = current_time->tm_hour;
	minutes_m = current_time->tm_min;
	seconds_m = current_time->tm_sec;

}

cTime_t::cTime_t(size_t hour, size_t minutes, size_t seconds) :hour_m(hour), minutes_m(minutes), seconds_m(seconds)
{
}

cTime_t::cTime_t(const cTime_t & time)
{
	hour_m = time.hour_m;
	minutes_m = time.minutes_m;
	seconds_m = time.seconds_m;
}

cTime_t & cTime_t::operator=(const cTime_t & time)
{
	if (this != &time)
	{
		hour_m = time.hour_m;
		minutes_m = time.minutes_m;
		seconds_m = time.seconds_m;
	}

	return *this;
}


void cTime_t::print(int format)
{
	if (format == 1)
	{
		cout << hour_m << ":" << minutes_m << ":" << seconds_m<< endl;
	}
	else if (format == 2)
	{
		string type = "";
		if (hour_m < 12)
		{
			type = "AM";
		}
		else
		{
			type = "PM";
		}
		cout << hour_m % 12 << ":" << minutes_m << ":" << seconds_m << " " << type<< endl;
	}
	else
	{
		throw exception("Format has to be 1 or 2");
	}
}



cTime_t cTime_t::operator+(const cTime_t & time)
{
	cTime_t result;

	result.seconds_m = time.seconds_m + this->seconds_m;
	if (!is_valid_seconds(result.seconds_m))
	{
		result.seconds_m -= 60;
		result.minutes_m += 1;
	}

	result.minutes_m = time.minutes_m + this->minutes_m;
	if (!is_valid_minutes(result.minutes_m))
	{
		result.minutes_m -= 60;
		result.hour_m += 1;
	}

	result.hour_m = time.hour_m  +this->hour_m;
	if (!is_valid_hour(result.hour_m))
	{
		result.hour_m -= 24;
		// letting the day attached know about the increase in the day..
		Notify();
	}
	return result;

}



