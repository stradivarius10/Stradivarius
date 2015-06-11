#include "TC_t.h"



TC_t* TC_t::sng_ptr = 0;  // initializing the static data memeber..

TC_t::TC_t(){}
TC_t::~TC_t(){}

TC_t * TC_t::create_obj()
{
	if (sng_ptr == 0)
	{
		sng_ptr = new TC_t();
	}
	return sng_ptr;
}


void TC_t::destroy()
{
	delete sng_ptr;
	sng_ptr = 0;
}

void TC_t::change_service_price(size_t price)
{
	service_price = price;
	service_price_changed_m = true;

	// notify all users

	Notify("Mobile");
	Notify("Stationiary");
	service_price_changed_m = false;

}

void TC_t::update_old_to_new()
{
	can_upgrade_m = true;
	Notify("Mobile");
	can_upgrade_m = false;
}