#ifndef TC_T
#define TC_T

#include "Observer.h"
#include "Subject.h"

// this class represents the telephone company. It implements the singleton design pattern becuase we want one instance of it at most.
// this class also implements the subject from the observer deisgn pattern
class TC_t : public Subject
{
public:
	static void destroy();
	static TC_t * create_obj();
	virtual void change_service_price(size_t price);
	virtual void update_old_to_new();
	inline bool can_upgrade() const{ return can_upgrade_m; }
	inline bool service_price_changed() const{ return service_price_changed_m; }
	inline size_t get_service_price() const{ return service_price; }

protected:
	virtual ~TC_t();

private:
	TC_t();
	TC_t( const TC_t & t); // not allow copy
	void operator=(const TC_t &); // not allow copy

	static TC_t *sng_ptr;
	size_t service_price;
	bool service_price_changed_m;
	bool can_upgrade_m;

};


#endif
