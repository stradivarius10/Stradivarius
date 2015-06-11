#ifndef PHONE_IMPL
#define PHONE_IMPL

#include "Observer.h"
#include "TC_t.h"
#include "iostream"
#include <string>

// this class is a part of the bridhe design pattern ( the impl field of the PhoneOwner class)

class PhoneOwner_implementation : public Observer
{

public:
	virtual void Update(Subject* ChngSubject) = 0;
	inline size_t  get_service_price(){ return service_price;}
	virtual string  who_am_i() = 0;

protected:
	TC_t * sbj;
	size_t service_price;

};




#endif