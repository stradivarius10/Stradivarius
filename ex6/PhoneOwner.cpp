#include "PhoneOwner.h"


void PhoneOwner::Update(Subject* ChngSubject)
{
	impl->Update(ChngSubject);
}

size_t  PhoneOwner::get_service_price()
{
	return impl->get_service_price();
}

PhoneOwner::PhoneOwner(const string &impl_str, TC_t *tc)
{
	impl = Phone_factory::Create(impl_str, tc);
}


string PhoneOwner::who_am_i()
{
	return impl->who_am_i();
}

