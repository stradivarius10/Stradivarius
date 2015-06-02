#ifndef OBSERVER
#define OBSERVER

#include <vector>
using namespace std;
class Subject;

class Observer {
public:
	virtual			~Observer() {}
	virtual void	Update(Subject* ChngSubject) = 0;
protected:
	Observer() {}
	Subject* sbj;
};


class Subject {
public:
	virtual ~Subject() {}

	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual void Notify();
protected:
	Subject() {}
private:
	vector<Observer*> m_observers;
};



#endif
