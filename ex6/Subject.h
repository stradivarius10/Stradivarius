#ifndef SUBJECT
#define SUBJECT
#include <vector>
#include <string>
#include "Observer.h"

using namespace std;

/* This code is a copy of the code we saw in class. YOSSI approved to use it as is!*/
class Subject {
public:
	virtual ~Subject() {}

	virtual void Detach(Observer*);
	virtual void Attach(Observer*);
	virtual void Notify(string who);

protected:
	Subject() {}
private:
	vector<Observer*> m_observers;
};

#endif


