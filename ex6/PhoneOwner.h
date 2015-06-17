#ifndef PHONE_OWNER
#define PHONE_OWNER

#include "Observer.h"
#include "PhoneOwner_implementation.h"
#include "PhoneFactory.h"


// This class implements the bridge design pattern
class PhoneOwner : public Observer
{

public:
	~PhoneOwner(){};
	PhoneOwner(const string &impl, TC_t *tc);

	virtual void	Update(Subject* ChngSubject);
	virtual size_t  get_service_price() const;
	virtual string  who_am_i() const ; //agreed by yossi in order to prevent double vector in the observer design pattern.

private:
	PhoneOwner_implementation * impl;

};






#endif
