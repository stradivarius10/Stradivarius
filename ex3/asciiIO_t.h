#ifndef ASCIIIO_T
#define ASCIIIO_T


#include "virtIO_t.h"

class asciiIO_t : public virtIO_t
{
public:

	virtual ~asciiIO_t(){}
	asciiIO_t(const string &path, const string & mode);

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
	asciiIO_t(const asciiIO_t &); //we don't suport copying
	asciiIO_t& operator=(const asciiIO_t&); //we don't suport copying
	//change status if it has problems... template so we can get the value witht he right type
	template <class T> void write_file_with_format(const string& format, const T& value);
	// in order to prevent code duplication! agreed and advised by YOSSI
	void read_file_with_format(const string& format, const void * x);
	

};




template <class T> void asciiIO_t::write_file_with_format(const string& format, const T& value)
{

	if (!is_file_initialized())
	{
		throw exception(" The file wasn't initialized ");
	}

	int result = fprintf(this->get_file(), format.c_str(), value);
	if (ferror(get_file()))
	{
		set_status(virtIO_t::bad_access_e);
		// YOSSI told in the forum to throw exception as well
		throw exception("Error:bad_access_e");
	}
	if (result < 1)
	{
		this->set_status(virtIO_t::writeErr_e);
		// YOSSI told in the forum to throw exception as well
		throw exception("Error:writeErr_e");
	}

	else
	{
		this->set_status(virtIO_t::ok_e);

	}
}


// inline implementation


// Please note: I've asked Yossi nd he told me I don't have to use Templeate functions here though I could..
// the read and write functions will throw exceptions and set the flag if needed!
inline virtIO_t& asciiIO_t::operator >> (char & c)
{
	read_file_with_format("%c", &c);
	return *this;
}

inline virtIO_t& asciiIO_t::operator<< (const char c)
{
	write_file_with_format("%c", c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator >> (unsigned char& c)
{
	read_file_with_format("%c", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (unsigned char c)
{
	write_file_with_format("%c", c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator >> (short& c)
{
	read_file_with_format("%hd", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (short c)
{
	write_file_with_format("%hd", c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator >> (unsigned short& c)
{
	read_file_with_format("%c", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (unsigned short c)
{
	write_file_with_format("%hu", c);
	return *this;
}



inline virtIO_t& asciiIO_t::operator >> (int& c)
{
	read_file_with_format("%d", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (int c)
{
	write_file_with_format("%d", c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator >> (unsigned int& c)
{
	read_file_with_format("%u", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (unsigned int c)
{
	write_file_with_format("%u", c);
	return *this;
}



inline virtIO_t& asciiIO_t::operator >> (long& c)
{
	read_file_with_format("%lu", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (long c)
{
	write_file_with_format("%lu", c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator >> (float& c)
{
	read_file_with_format("%f", &c);
	return *this;
}

inline virtIO_t& asciiIO_t::operator<< (float c)
{
	write_file_with_format("%f", c);
	return *this;
}

inline virtIO_t& asciiIO_t::operator >> (double& c)
{
	read_file_with_format("%lf", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (double c)
{
	write_file_with_format("%lf", c);
	return *this;
}

inline virtIO_t& asciiIO_t::operator >> (unsigned long &c)
{
	read_file_with_format("%lu", &c);
	return *this;
}


inline virtIO_t& asciiIO_t::operator<< (unsigned long c)
{
	write_file_with_format("%lu", c);
	return *this;
}














#endif
