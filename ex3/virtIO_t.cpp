#include "virtIO_t.h"


virtIO_t::virtIO_t(const string &path, const string & mode) :buff_pointer_write(NULL), buff_pointer_read(NULL)
{

	open(path, mode);

}

virtIO_t::virtIO_t():buff_pointer_write(NULL), buff_pointer_read(NULL)
{
}



size_t virtIO_t::get_length() const
{
	fseek(file, 0, SEEK_END); 
	size_t result = ftell(file);
	// rewind..
	fseek(file, 0, SEEK_CUR);  

	return result;
}



virtIO_t::status_t virtIO_t::open(const string &path, const string & mode)
{
	this->mode_m = mode;
	this->path_m = path;


	// was not initialized
	file = fopen(path_m.c_str(), mode_m.c_str());
	if (!file)
	{
			status_m = cant_open_file_e; 
			//no exception - the use has to check the status!
	}
	else
	{
		status_m = ok_e;
		this->is_initialized = true;
	}
	return status_m;
}


size_t virtIO_t::read(void* buffer, size_t size, size_t count)
{

	if (!is_file_initialized())
	{
		throw exception(" The file wasn't initialized ");
	}
	int read_n = fread(buffer, size, count, file);

	if (read_n != count)
	{
		set_status(writeErr_e);
	}
	else if (ferror(file))
	{
		set_status(bad_access_e);
	}
	else
	{
		status_m = ok_e;
	}

	return read_n;

}


size_t virtIO_t::write(const void* buffer, size_t size, size_t count)
{
	if (!is_file_initialized())
	{
		throw exception(" The file wasn't initialized ");
	}

	int write_n = fwrite(buffer, size, count, file);
	if (write_n != count)
	{
		set_status(writeErr_e);
	}
	else if (ferror(file))
	{
		set_status(bad_access_e);
	}
	else
 	{
		status_m = ok_e;
	}

	return write_n;
}



void  virtIO_t::operator,(int len)
{
	if (buff_pointer_write == NULL || buff_pointer_read == NULL)
	{
		throw exception(" NO use of << or >> was occrued before calling to the , operator");
	}
	if (input)
	{
		write(buff_pointer_write,1, len);
		// we dont' need to remember it..
		buff_pointer_write = NULL;

	}
	else
	{
		read(buff_pointer_read, 1, len);
		buff_pointer_read = NULL;
	}
}

virtIO_t:: ~virtIO_t()
{
	if (is_file_initialized())
		fclose(file); /* don't care about the reuslt! we destyoyed the object!!!*/
}