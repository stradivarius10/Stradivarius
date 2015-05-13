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


	// if a problem occurs the status will be set with the relevant error code
	void open();

	inline string get_path() const;
	inline string get_access() const;
	inline size_t get_length() const;
	inline status_t get_status() const;
	

	size_t read(void* buffer, size_t size, size_t count) ;

	size_t write(const void* buffer, size_t size, size_t count) ;


	virtual virtIO_t& operator>>(void* Buf);
	virtual virtIO_t& operator<<(const void* Buf);

	void  operator,(int len);


	virtual virtIO_t& operator>>(char &c) = 0;
	virtual virtIO_t& operator<<(const char &c) = 0;
	virtual virtIO_t& operator>>(unsigned char &c) = 0;
	virtual virtIO_t& operator<<(const unsigned char &c) = 0;
	virtual virtIO_t& operator>>(short &c) = 0;
	virtual virtIO_t& operator<<(const short &c) = 0;
	virtual virtIO_t& operator>>(unsigned short &c) = 0;
	virtual virtIO_t& operator<<(const unsigned short &c) = 0;
	virtual virtIO_t& operator>>(int &c) = 0;
	virtual virtIO_t& operator<<(const int &c) = 0;
	virtual virtIO_t& operator>>(unsigned int &c) = 0;
	virtual virtIO_t& operator<<(const unsigned int &c) = 0;
	virtual virtIO_t& operator>>(long &c) = 0;
	virtual virtIO_t& operator<<(const long &c) = 0;
	virtual virtIO_t& operator>>(unsigned long &c) = 0;
	virtual virtIO_t& operator<<(const unsigned long &c) = 0;
	virtual virtIO_t& operator>>(float &c) = 0;
	virtual virtIO_t& operator<<(const float &c) = 0;
	virtual virtIO_t& operator>>(double &c) = 0;
	virtual virtIO_t& operator<<(const double &c) = 0;






protected:
	inline void set_length(size_t len);
	inline FILE * get_file();

private:
	size_t length_m;
	string mode_m;
	string path_m;
	status_t status_m;

	FILE * file; //the "real" file..

	bool left; //true if we want opertor<<, false if we want opertor>>
    void *buff_pointer_read;
    const void *buff_pointer_write;

	virtIO_t(const virtIO_t &); //we don't suport copying
	virtIO_t& operator=(const virtIO_t &); //we don't suport copying

};



inline string virtIO_t::get_path() const
{
	return path_m;
}


inline string virtIO_t::get_access() const
{
	return mode_m;
}

inline size_t virtIO_t::get_length() const
{
	return length_m;
}

inline virtIO_t::status_t virtIO_t::get_status() const
{
	return status_m;
}

inline void virtIO_t::set_length(size_t len)
{
	length_m = len;
}

FILE * virtIO_t::get_file()
{
	return file;
}







#endif
