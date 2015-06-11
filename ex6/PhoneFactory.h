#ifndef PHONE_FACTORY
#define PHONE_FACTORY

#include "Stationiary_phone.h"
#include "Mobile_phone.h"


//the name says it all... factory desgin pattern..
class Phone_factory {

public:

	static PhoneOwner_implementation * Create(const string& Impl, TC_t *tc)
	{
		PhoneOwner_implementation * phone = 0;
		if (Impl == "Stationiary")
		{
			phone = new Stationiary_phone(tc);
		}
		if (Impl == "Mobile")
		{
			phone = new Mobile_phone(tc);
		}
		return phone;
	}

private:

	Phone_factory();
	~Phone_factory();

};




#endif
