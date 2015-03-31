#include <string>
#include <iostream>
using namespace std;
class Person_t
{
	public:
		~Person_t();
		Person_t(const string &name, int age); //CTOR - returns a person with a name, and age and a unique ID
		Person_t(const Person_t& person);
		Person_t & operator= (const Person_t &person);  //note that ID is UNIQUE and won't be copied - approved by the teacher
		bool operator==(const Person_t &person) const; // Based on teacher agreement - the == wil be done
		// based on age + name, thats in order to allow the find and remove of persons in the interactive test by the user
		// (which doesn't have the object in hand..)

		size_t get_id() const;
		int get_age() const;
		string get_name() const;

		void set_age(int age);
		void set_name(string name);
		
		
	private:
		const size_t m_id;		// Unique for each Person_t object 
		string		m_name;	
		int		m_age;
		static size_t m_globID;	// Stores the current max global id.
};



istream& operator>> (istream& is, Person_t& p);
ostream& operator<< (ostream& os, const Person_t & p);

