#ifndef STATIONIARY_PHONE
#define STATIONIARY_PHONE

#include "PhoneOwner_implementation.h"
                                 
class Stationiary_phone : public PhoneOwner_implementation
{
public:
	Stationiary_phone(TC_t *tc);
	virtual ~Stationiary_phone();

	Stationiary_phone(const Stationiary_phone &phone);
	Stationiary_phone & operator=(const Stationiary_phone &phone);

	virtual void	Update(Subject* ChngSubject);
	virtual string  who_am_i() const;
};

#endif
