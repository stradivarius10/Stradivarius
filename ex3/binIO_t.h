#ifndef BINIO_T
#define BINIO_T


#include "virtIO_t.h"

class binIO_t : public virtIO_t
{
public:
	// base is suffice
	virtual ~binIO_t(){}

	binIO_t();
	binIO_t(const string &path, const string & mode);


	// since we are implementing other << we don't want to hide these
	using virtIO_t::operator<<;
	using virtIO_t::operator>>;

	virtual virtIO_t& operator>>(char &c);
	virtual virtIO_t& operator<<(char c);
	virtual virtIO_t& operator>>(unsigned char &c);
	virtual virtIO_t& operator<<(unsigned char c);
	virtual virtIO_t& operator>>(short &c);
	virtual virtIO_t& operator<<(short c);
	virtual virtIO_t& operator>>(unsigned short &c);
	virtual virtIO_t& operator<<(unsigned short c);
	virtual virtIO_t& operator>>(int &c);
	virtual virtIO_t& operator<<(int c);
	virtual virtIO_t& operator>>(unsigned int &c);
	virtual virtIO_t& operator<<(unsigned int c);
	virtual virtIO_t& operator>>(long &c);
	virtual virtIO_t& operator<<(long c);
	virtual virtIO_t& operator>>(unsigned long &c);
	virtual virtIO_t& operator<<(unsigned long c);
	virtual virtIO_t& operator>>(float &c);
	virtual virtIO_t& operator<<(float c);
	virtual virtIO_t& operator>>(double &c);
	virtual virtIO_t& operator<<(double c);


private:
	binIO_t(const binIO_t &); //we don't suport copying
	binIO_t& operator=(const binIO_t &); //we don't suport copying

};


// inline implementation

// Please note: I've asked Yossi nd he told me I don't have to use Templeate functions here though I could..
// the read and write functions will throw exceptions and set the flag if needed!
inline virtIO_t& binIO_t::operator >> (char & c ) 
{
	read(&c, sizeof(char), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (const char c) 
{
	write(&c, sizeof(char), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator >> (unsigned char& c)
{
	read(&c, sizeof(char), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (unsigned char c) 
{
	write(&c, sizeof(char), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator >> (short& c) 
{
	read(&c, sizeof(short), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (short c) 
{
	write(&c, sizeof(short), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator >> (unsigned short& c) 
{
	read(&c, sizeof(short), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (unsigned short c) 
{
	write(&c, sizeof(short), 1);
	return *this;
}



inline virtIO_t& binIO_t::operator >> (int& c) 
{
	read(&c, sizeof(int), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (int c) 
{
	write(&c, sizeof(int), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator >> (unsigned int& c) 
{
	read(&c, sizeof(int), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (unsigned int c) 
{
	write(&c, sizeof(int), 1);
	return *this;
}



inline virtIO_t& binIO_t::operator >> (long& c) 
{
	read(&c, sizeof(long), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (long c) 
{
	write(&c, sizeof(long), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator >> (float& c) 
{
	read(&c, sizeof(long), 1);
	return *this;
}

inline virtIO_t& binIO_t::operator<< (float c)
{
	write(&c, sizeof(char), 1);
	return *this;
}

inline virtIO_t& binIO_t::operator >> (double& c)
{
	read(&c, sizeof(double), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (double c)
{
	write(&c, sizeof(double), 1);
	return *this;
}

inline virtIO_t& binIO_t::operator >> (unsigned long &c)
{
	read(&c, sizeof(long), 1);
	return *this;
}


inline virtIO_t& binIO_t::operator<< (unsigned long c)
{
	write(&c, sizeof(long), 1);
	return *this;
}










#endif
