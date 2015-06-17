#include "Mobile_phone.h"


void Mobile_phone::Update(Subject* ChngSubject)
{
	if (ChngSubject == sbj)
	{
		if (sbj->can_upgrade())
		{
			cout << who_am_i() << "  : " << "got a notify that I can be upgraded" << endl;
		}
		if (sbj->service_price_changed())
		{
			service_price = sbj->get_service_price();
			cout << who_am_i() <<"  : " << "price has changed. New price is " << service_price << endl;
		}
	}
}


Mobile_phone::Mobile_phone( TC_t *tc)
{
	sbj = tc;
	sbj->Attach(this);
}
Mobile_phone::~Mobile_phone()
{
	sbj->Detach(this);
}


string Mobile_phone::who_am_i() const
{
	return "Mobile";
}



Mobile_phone::Mobile_phone(const Mobile_phone &phone)
{
	service_price = phone.service_price;
	sbj = phone.sbj;
	sbj->Attach(this);
}

Mobile_phone & Mobile_phone::operator=(const Mobile_phone &phone)
{
	if (this != &phone)
	{
		service_price = phone.service_price;
		sbj = phone.sbj;
		sbj->Attach(this);
	}
	return *this;
}