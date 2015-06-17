#ifndef MOBILE_PHONE
#define MOBILE_PHONE

#include "PhoneOwner_implementation.h"

using namespace std;


class Mobile_phone : public PhoneOwner_implementation
{

public:
	Mobile_phone(TC_t *tc);
	virtual ~Mobile_phone();

	Mobile_phone(const Mobile_phone &phone);
	Mobile_phone & operator=(const Mobile_phone &phone);
	virtual void	Update(Subject* ChngSubject);
	virtual string  who_am_i() const;


};

#endif
