#include "binIO_t.h"


binIO_t::binIO_t(const string &path, const string & mode) :
virtIO_t::virtIO_t(path, mode)  ///check in the forum about the b!!!!!!!!!!!!!
{

}



virtIO_t& binIO_t::operator >> (char c) //what should we return in here????
{
	write((char *)&c, sizeof(char), 1);
}
virtual virtIO_t& operator<<(const char) = 0;
