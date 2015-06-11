#ifndef OBSERVER
#define OBSERVER


/* This code is a copy of the code we saw in class. YOSSI approved to use it as is!*/
#include <string>

using namespace std;
class Subject;

class Observer {
public:
	virtual			~Observer() {}
	virtual void	Update(Subject* ChngSubject) = 0;
	virtual string  who_am_i() = 0;
protected:
	Observer() {}

	//////// check with denis
};


#endif
