#include "virtIO_t.h"

class binIO_t : public virtIO_t
{
public:
	virtual ~binIO_t();
	binIO_t(const string &path, const string & mode);


	virtual virtIO_t& operator>>(char) = 0;
	virtual virtIO_t& operator<<(const char) = 0;
	virtual virtIO_t& operator>>(unsigned char) = 0;
	virtual virtIO_t& operator<<(const unsigned char) = 0;
	virtual virtIO_t& operator>>(short) = 0;
	virtual virtIO_t& operator<<(const short) = 0;
	virtual virtIO_t& operator>>(unsigned short) = 0;
	virtual virtIO_t& operator<<(const unsigned short) = 0;
	virtual virtIO_t& operator>>(int) = 0;
	virtual virtIO_t& operator<<(const int) = 0;
	virtual virtIO_t& operator>>(unsigned int) = 0;
	virtual virtIO_t& operator<<(const unsigned int) = 0;
	virtual virtIO_t& operator>>(long) = 0;
	virtual virtIO_t& operator<<(const long) = 0;
	virtual virtIO_t& operator>>(unsigned long) = 0;
	virtual virtIO_t& operator<<(const unsigned long) = 0;
	virtual virtIO_t& operator>>(float) = 0;
	virtual virtIO_t& operator<<(const float) = 0;
	virtual virtIO_t& operator>>(double) = 0;
	virtual virtIO_t& operator<<(const double) = 0;


protected:
	inline void set_length(size_t len);

private:
	binIO_t(const binIO_t &); //we don't suport copying

};


