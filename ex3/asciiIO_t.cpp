#include "asciiIO_t.h"


asciiIO_t::asciiIO_t(const string &path, const string & mode) :virtIO_t(path, mode)  {}


void asciiIO_t::read_file_with_format(const string& format,  const void * x)
{
	int result = fscanf(this->get_file(), format.c_str(), x);
	if (ferror(get_file()))
	{
		set_status(virtIO_t::bad_access_e);
	}
	if (result < 1)
	{
		this->set_status(virtIO_t::writeErr_e);
	}
	else
	{
		this->set_status(virtIO_t::ok_e);

	}

}
