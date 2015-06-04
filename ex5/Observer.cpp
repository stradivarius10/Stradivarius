#include "Observer.h"

/* This code is a copy of the code we saw in class. YOSSI approved to use it as is!*/

//================================================================================
// Subject Implemenation
//================================================================================

void Subject::Attach(Observer* ob) {
	m_observers.push_back(ob);
}

void Subject::Detach(Observer* ob) {
	size_t i = 0;
	for (i = 0; i < m_observers.size(); i++)
	{
		if (m_observers[i] == ob) break;
	}

	if (i != m_observers.size())
	{
		m_observers.erase(m_observers.begin() + i);
	}

}

void Subject::Notify() {
	for (size_t i = 0; i < m_observers.size(); i++)
		(m_observers[i])->Update(this);
}
