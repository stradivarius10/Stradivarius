#include "Stationiary_phone.h"

void	Stationiary_phone::Update(Subject* ChngSubject)
{
	if (ChngSubject == sbj)
	{
		if (sbj->service_price_changed())
		{
			service_price = sbj->get_service_price();
			cout << who_am_i() << "  : "  << "price has changed. New price is " << service_price << endl;
		}
	}
}


Stationiary_phone::Stationiary_phone(TC_t *tc)
{
	sbj = tc;
	sbj->Attach(this);
}
Stationiary_phone::~Stationiary_phone()
{
	sbj->Detach(this);
}


string Stationiary_phone::who_am_i()
{
	return "Stationiary";
}


Stationiary_phone::Stationiary_phone(const Stationiary_phone &phone)
{
	service_price = phone.service_price;
	sbj = phone.sbj;
	sbj->Attach(this);
}
Stationiary_phone & Stationiary_phone::operator=(const Stationiary_phone &phone)
{
	if (this != &phone)
	{
		service_price = phone.service_price;
		sbj = phone.sbj;
		sbj->Attach(this);
	}

	return *this;

}