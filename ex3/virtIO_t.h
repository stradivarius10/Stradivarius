#ifndef VIRTIO_H
#define VIRTIO_H

#include <string>
#include <iostream>
using namespace std;
class virtIO_t
{
public:

	/* represents the status*/
	enum status_t
	{
		ok_e ,cant_open_file_e,bad_access_e, writeErr_e ,readErr_e 
	};

	virtual ~virtIO_t();
	virtIO_t(); // default constructor

	// the file won't be open till the user cas the open function
	virtIO_t(const string &path, const string & mode); 


	// if a defutl constructor is used, then you must call open before using the other members function (except dtor)
	status_t open(const string &path, const string & mode);

	inline string get_path() const;
	inline string get_access() const;
	inline status_t get_status() const;


	//returns the length of the file and also updates the field
	size_t get_length();
	

	inline size_t read(void* buffer, size_t size, size_t count) ;

	inline size_t write(const void* buffer, size_t size, size_t count) ;

	//get the position - ftell
	inline long get_position() const;
	// fseek
	inline bool set_position(int pos);

	// set the right buffer. , will do the actual operation
	virtual virtIO_t& operator>>(void* Buf);
	virtual virtIO_t& operator<<(const void* Buf);

	void  operator,(int len);


	virtual virtIO_t& operator>>(char &c) = 0;
	virtual virtIO_t& operator<<(char c) = 0;
	virtual virtIO_t& operator>>(unsigned char &c) = 0;
	virtual virtIO_t& operator<<( unsigned char c) = 0;
	virtual virtIO_t& operator>>(short &c) = 0;
	virtual virtIO_t& operator<<( short c) = 0;
	virtual virtIO_t& operator>>(unsigned short &c) = 0;
	virtual virtIO_t& operator<<( unsigned short c) = 0;
	virtual virtIO_t& operator>>(int &c) = 0;
	virtual virtIO_t& operator<<( int c) = 0;
	virtual virtIO_t& operator>>(unsigned int &c) = 0;
	virtual virtIO_t& operator<<( unsigned int c) = 0;
	virtual virtIO_t& operator>>(long &c) = 0;
	virtual virtIO_t& operator<<( long c) = 0;
	virtual virtIO_t& operator>>(unsigned long &c) = 0;
	virtual virtIO_t& operator<<( unsigned long c) = 0;
	virtual virtIO_t& operator>>(float &c) = 0;
	virtual virtIO_t& operator<<( float c) = 0;
	virtual virtIO_t& operator>>(double &c) = 0;
	virtual virtIO_t& operator<<( double c) = 0;






protected:
	inline void set_length(size_t len);
	inline FILE * get_file();
	inline bool is_file_initialized();
	inline void set_status(status_t status);

private:
	size_t length_m;
	string mode_m;
	string path_m;
	status_t status_m;

	//represents the the file has succeffuly been opened
	bool is_initialized;

	FILE * file; //the "real" file..

	bool input; //true if we want opertor<<, false if we want opertor>>
    void *buff_pointer_read;
    const void *buff_pointer_write;

	virtIO_t(const virtIO_t &); //we don't suport copying
	virtIO_t& operator=(const virtIO_t &); //we don't suport copying

};


inline void virtIO_t::set_status(status_t status)
{
	status_m = status;
}


inline string virtIO_t::get_path() const
{
	return path_m;
}


inline string virtIO_t::get_access() const
{
	return mode_m;
}



inline virtIO_t::status_t virtIO_t::get_status() const
{
	return status_m;
}

inline void virtIO_t::set_length(size_t len)
{
	length_m = len;
}

inline FILE * virtIO_t::get_file()
{
	return file;
}


inline bool virtIO_t::is_file_initialized()
{
	return is_initialized;
}


inline long virtIO_t::get_position() const
{
	return ftell(file);
}



inline bool virtIO_t::set_position(int pos)
{
	int result  =  fseek( this->file, pos, SEEK_SET) == 0;
	return result == 0;

}


inline virtIO_t& virtIO_t::operator>>(void* buf)
{
	input = false;
	buff_pointer_read = buf;

	return *this;
}

inline virtIO_t& virtIO_t::operator<<(const void* buf)
{
	input = true;
	buff_pointer_write = buf;

	return *this;
}

#endif
