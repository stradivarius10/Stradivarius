#include "LocationMeeting_t.h"
#include "DayCalendar_t.h"
#include "Meeting_t.h"


int main(char **argv, int argc)
{
	Meeting_t<int> x;
	x.create(1, 2, "templates is amazing!!!!!!!");
	cout << x;




}