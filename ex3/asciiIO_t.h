#ifndef ASCIIIO_T
#define ASCIIIO_T


#include "virtIO_t.h"

class asciiIO_t : public virtIO_t
{
public:
	virtual ~asciiIO_t();
	asciiIO_t(const string &path, const string & mode);

	virtual virtIO_t& operator>>(void* Buf);
	virtual virtIO_t& operator<<(const void* Buf);


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
	asciiIO_t(const asciiIO_t &); //we don't suport copying
	asciiIO_t& operator=(const asciiIO_t&); //we don't suport copying

};






#endif
