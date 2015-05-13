#include "virtIO_t.h"


virtIO_t::virtIO_t(const string &path, const string & mode): mode_m(mode), path_m( path)
{


	file = fopen(path.c_str(),mode.c_str());
	if (!file)
	{
		switch (errno)
		{
			case EACCES:
				status_m = bad_access_e;  /////ask denis the king
				break;
			default:
				status_m = cant_open_file_e;
		}
	
		//throw exception("could not opene the file bitch (agreed by Yossi)");
	}
	else
	{
		status_m = ok_e;

		//update the length

		fseek(file, 0, SEEK_END);  ///ask in the forum
		length_m = ftell(file);
		// rewind..
		fseek(file, 0, SEEK_CUR);  ///ask in the forum
	}

	

}


size_t virtIO_t::read(void* buffer, size_t size, size_t count)
{
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


virtIO_t& virtIO_t::operator>>(void* buf)
{
	left = false;
	buff_pointer_read = buf;
}

virtIO_t& virtIO_t::operator<<(const void* buf)
{
	left = true;
	buff_pointer_write = buf;
}

void  virtIO_t::operator,(int len)
{
	if (!left)
	{
		write(buff_pointer_write, /* checkkkkkkkkkkkkkk */sizeof(char), len);
	}
	else
	{
		read(buff_pointer_read, /* checkkkkkkkkkkkkkk */sizeof(char), len);
	}
}

virtIO_t:: ~virtIO_t()
{
	fclose(file); /* don't care about the reuslt! we destyoyed the object!!!*/
}