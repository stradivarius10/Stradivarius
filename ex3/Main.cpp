#include "binIO_t.h"
#include "virtIO_t.h"
#include "asciiIO_t.h"


static string get_path()
{
	string path;
	cout << "Enter the path of your file:" << endl;
	cin >> path;
	return path;
}

static string get_mode()
{
	string mode;
	cout << "Enter the mode of your file:" << endl;
	cin >> mode;
	return mode;
}

static int get_num_of_bytes()
{
	int num_of_bytes;
	cout << "Enter number of bytes to read/write:" << endl;
	cin >> num_of_bytes;
	return num_of_bytes;
}

static void write_data(virtIO_t * file)
{
	char x;
	char c;
	unsigned char uc;
	short s;
	unsigned short us;
	unsigned int ui;
	unsigned long ul;
	int i;
	long l;
	float f;
	double d;

	string str;

	cout
		<< "Press c to write char" << endl
		<< "Press d to write unsigned char" << endl
		<< "press s to write short" << endl
		<< "press t to write unsigned short" << endl
		<< "press i to write int" << endl
		<< "press j to write unsigned int" << endl
		<< "press l to write long" << endl
		<< "press m to write unsigned long" << endl
		<< "press f to write float" << endl
		<< "press g to write double" << endl
		<< "press z to write string" << endl
		<< "press any other character to exit" << endl;

	cin >> x;
	try
	{
		switch (x)
		{
		case 'c':
		{
		cout << "Enter char" << endl;
		cin >> c;
		*file << c;
		}
			break;
		case 'd':
		{
	
			cout << "Enter unsigned char" << endl;
			cin >> uc;
			*file << uc;
		}
			break;
		case 's':
		{
			
			cout << "Enter short" << endl;
			cin >> s;
			*file << s;
		}
			break;
		case 't':
		{
			cout << "Enter unsigned short" << endl;
			cin >> us;
			*file << us;
		}

			break;
		case 'i':
			cout << "Enter int" << endl;
			cin >> i;
			*file << i;
			break;
		case 'j':
		{
			cout << "Enter unsigned int" << endl;
			cin >> ui;
			*file << ui;
		}
			break;
		case 'l':
		{

			cout << "Enter long" << endl;
			cin >> l;
			*file << l;
		}
			break;
		case 'm':
		{

			cout << "Enter unsigned long" << endl;
			cin >> ul;
			*file << ul;
		}
			break;
		case 'f':
		{

			cout << "Enter float" << endl;
			cin >> f;
			*file << f;
		}
			break;
		case 'g':
		{
			cout << "Enter double" << endl;
			cin >> d;
			*file << d;
		}
			break;
		case 'z':
			cout << "Enter string" << endl;
			cin >> str;
			*file << str.c_str(), (int)str.length();
			break;
		default: break;
		}

	}
	catch (exception &e)
	{
		string err_msg(e.what());
		cout << err_msg + ". Check status!" << endl;
	}
}

static void read_data(virtIO_t * file)
{
	char x;
	char c;
	unsigned char uc;
	short s;
	unsigned short us;
	unsigned int ui;
	unsigned long ul;
	int i;
	long l;
	float f;
	double d;
	int num_of_bytes;



	char * buffer = NULL;

	cout
		<< "Press c to read char" << endl
		<< "Press d to read unsigned char" << endl
		<< "press s to read short" << endl
		<< "press t to read unsigned short" << endl
		<< "press i to read int" << endl
		<< "press j to read unsigned int" << endl
		<< "press l to read long" << endl
		<< "press m to read unsigned long" << endl
		<< "press f to read float" << endl
		<< "press g to read double" << endl
		<< "press z to read string" << endl
		<< "press any other character to exit" << endl;

	cin >> x;

	try
	{
		switch (x)
		{
		case 'c':
			*file >> c;
			cout << c << endl;
			break;
		case 'd':
			*file >> uc;
			cout << uc << endl;
		
			break;
		case 's':
		
			*file >> s;
			cout << s << endl;
		
			break;
		case 't':
		
			*file >> us;
			cout << us << endl;
			break;
		case 'i':
			*file >> i;
			cout << i << endl;
			break;
		case 'j':
			*file >> ui;
			cout << ui<< endl;
			break;
		case 'l':
			*file >> l;
			cout << l << endl;
			break;
		case 'm':
			*file >> ul;
			cout << ul << endl;
			break;
		case 'f':
			*file >> f;
			cout << f << endl;
			break;
		case 'g':
			*file >> d;
			cout << d << endl;
			break;
		case 'z':
		    num_of_bytes = get_num_of_bytes();
			buffer = new char[num_of_bytes + 1];
			*file >> buffer, num_of_bytes;
			buffer[num_of_bytes] = '\0';
			cout << buffer << endl;
			delete buffer;
			break;
		default: break;
		}
	}
	catch (exception &e)
	{
		string err_msg(e.what());
		cout << err_msg+". Check status!" << endl;
		delete buffer;
	}
}

static void test(char file_type)
{
	virtIO_t * file = NULL;
	string path, mode;
	char c;
	long position;
	int status;

	path = get_path();
	mode = get_mode();

	if (file_type == 'a')
	{
		file = new asciiIO_t(path, mode);
	}

	else if (file_type == 'b')
	{
		file = new binIO_t(path, mode);
	}

	if (file->get_status() != virtIO_t::ok_e)
	{
		cout << "Error in openning the file. Check status!" << endl;
	}

	bool cont = true;

	try
	{
		while (cont) {
			cout<<endl
				<< "Press w to write new data to the file" << endl
				<< "Press r to read data from the file" << endl
				<< "press p to get the path of the file" << endl
				<< "press a to get the access of the file" << endl
				<< "press l to get the length of the file" << endl
				<< "press s to get the status of the file" << endl
				<< "Press x to get the position in the file"<<endl
				<< "Press y to set the position in the file" << endl
				<< "Press f to flush the file" << endl
				<< "press any other character to exit" << endl;


			cin >> c;

			switch (c) {
			case 'p':cout << file->get_path(); break;
			case 'a':cout << file->get_access(); break;
			case 'l':cout << file->get_length(); break;
			case 's':
				status = file->get_status();
				switch (status)
				{
				case virtIO_t::ok_e:
					cout << "Ok" << endl;
					break;
				case virtIO_t::bad_access_e:
					cout << "Bad access" << endl;
					break;
				case virtIO_t::cant_open_file_e:
					cout << "Cannot open file" << endl;
					break;
				case virtIO_t::readErr_e:
					cout << "Read error" << endl;
					break;
				case virtIO_t::writeErr_e:
					cout << "Write error" << endl;
					break;
				default:
					break;
				}
				break;
			case 'r':read_data(file); break;
			case 'w':write_data(file); break;
			case 'x':cout << file->get_position(); break;
			case 'y':cout << "Enter long:";
				cin >> position;
				if (!file->set_position(position))	//error setting the position
					cout << "Error! cannot set the position!" << endl;
				break;
			case 'f':
				if (!file->flush())
					cout << "Error in flush. Check status!" << endl;
				break;

			default: cont = false; break;

			}
		}
		//freeing memory
		delete file;
	}

	catch (exception &e)
	{
		string err_msg(e.what());
		cout << err_msg + ". Check status!" << endl;
		delete file;
	}
	//catch any exception
	catch (...)
	{
		cout << "Some error was occured. Fatal error!. Check also the status!" << endl;
		//freeing memory
		delete file;
	}
}

int main() {
	char c;

	cout << "Press a or b to choose ascii or binary (type of file). Press any other key to exit" << endl;
	cin >> c;

	if (c == 'a' || c == 'b')
	{
		test(c);
	}

	return 0;
}
