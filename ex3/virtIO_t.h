#include <string>
#include <iostream>
using namespace std;
class virtIO_t
{
public:
	virtual ~virtIO_t();
	virtIO_t(); // default constructor
	virtIO_t(const string &path, const string & mode); 




	/* represents the status*/
	enum status_t
	{
		ok_e = 0x01,
		cant_open_file_e = 0x02,
		bad_access_e = 0x04,
		writeErr_e = 0x08,
		readErr_e = 0x10,

	};

	inline string get_path() const;
	inline string get_access() const;
	inline size_t get_length() const;
	inline status_t get_status() const;
	

	size_t read(void* buffer, size_t size, size_t count) ;

	size_t write(const void* buffer, size_t size, size_t count) ;


	void* operator>>(void* Buf);
	const void* operator<<(const void* Buf);
	void  operator,(int len);


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
	virtual virtIO_t& operator>>(float)= 0;
	virtual virtIO_t& operator<<(const float)= 0;
	virtual virtIO_t& operator>>(double) = 0;
	virtual virtIO_t& operator<<(const double) = 0;






protected:
	inline void set_length(size_t len);
	inline FILE * get_file();

private:
	size_t length_m;
	string mode_m;
	string path_m;
	status_t status_m;

	FILE * file;

	bool left; //true if we want opertor<<, false if we want opertor>>
    void *buff_pointer_read;
    const void *buff_pointer_write;

	virtIO_t(const virtIO_t &); //we don't suport copying

};


