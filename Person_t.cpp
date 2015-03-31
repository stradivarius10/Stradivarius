#include "Person_t.h"

/* initiazling the static data member */
 size_t Person_t::m_globID = 0;

 Person_t::	~Person_t(){}
 
 Person_t::Person_t(const string &name, int age): m_id(++m_globID), m_name(name), m_age(age)
 {
	 //already took care of advancing the m_globID
 }

 Person_t::Person_t(const Person_t& person) : m_id(++m_globID), m_name(person.m_name), m_age(person.m_age)
 {
	 //already took care of advancing the m_globID
 }

 Person_t & Person_t:: operator= (const Person_t &person)
 {
	 if( this != &person)
	 {
		 m_name = person.m_name;
		 m_age = person.m_age;
		 // unique id cann't be assign - UNIQUE 
	 }
	 return *this;
 }

 bool Person_t::operator==(const Person_t &person) const
{
	return (person.m_age == m_age) && (person.m_name == m_name);
}

 size_t Person_t::get_id() const
 {
	 return m_id;
 }

 int Person_t::get_age() const
 {
	 return m_age;
 }

 string Person_t::get_name() const
 {
	 return m_name;
 }


 void Person_t::set_age(int age)
 {
	 m_age = age;
 }

 void Person_t::set_name(string name)
 {
	 m_name = name;
 }
 
 
 
 istream& operator>> (istream& is, Person_t& p) {
	 string name;
	 int age;

	 is >> name >> age;
	 p.set_name(name);
	 p.set_age(age);
	 
	 return is;
 }
 
 

 ostream& operator<< (ostream& os, const Person_t & p) {
	 os << "Id: " << p.get_id()
		 << ", Name: " << p.get_name()
		 << ", Age: " << p.get_age();
	 return os;
 }