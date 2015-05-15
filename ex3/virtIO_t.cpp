#include "virtIO_t.h"


virtIO_t::virtIO_t(const string &path, const string & mode)
{

	open(path, mode);

}


size_t virtIO_t::get_length()
{
	fseek(file, 0, SEEK_END); 
	length_m = ftell(file);
	// rewind..
	fseek(file, 0, SEEK_CUR);  

	return length_m;
}






virtIO_t::status_t virtIO_t::open(const string &path, const string & mode)
{
	this->mode_m = mode;
	this->path_m = path;


	// was not initialized
	file = fopen(path_m.c_str(), mode_m.c_str());
	if (!file)
	{
			status_m = cant_open_file_e; ///maybe more?
		//throw exception("could not opene the file bitch (agreed by Yossi)");
	}
	else
	{
		status_m = ok_e;
		this->is_initialized = true;

		//update the length

		fseek(file, 0, SEEK_END);  ///ask in the forum
		length_m = ftell(file);
		// rewind..
		fseek(file, 0, SEEK_CUR);  ///ask in the forum
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

	if ( read_n !=  count)
	{
		status_m = readErr_e;
	}
	else
	{
		status_m = ok_e;
	}

	return read_n;

}


size_t virtIO_t::write(const void* buffer, size_t size, size_t count)
{

	int write_n = fwrite(buffer, size, count, file);
	int old_length = get_length();
	set_length(old_length + write_n);
	if (write_n != count)
	{
		status_m = writeErr_e;
	}
	else
	{
		status_m = ok_e;
	}

	return write_n;
}



void  virtIO_t::operator,(int len)
{
	// check if the buffer was set!!!!

	if (input)
	{
		write(buff_pointer_write,1, len);
		// we dont' need to remember it..
		buff_pointer_write = 0;

	}
	else
	{
		read(buff_pointer_read, 1, len);
		buff_pointer_read = 0;
	}




}

virtIO_t:: ~virtIO_t()
{
	if (is_file_initialized())
		fclose(file); /* don't care about the reuslt! we destyoyed the object!!!*/
}