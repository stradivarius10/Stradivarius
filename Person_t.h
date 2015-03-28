#include <string>
#include <iostream>
using namespace std;
class Person_t
{
	public:
		~Person_t();
		//Person_t(); 
		Person_t(const string &name,const int age);
		Person_t(const Person_t& person);
		Person_t & operator= (const Person_t &person);  
		bool operator==(const Person_t &person) const;  
		size_t get_id() const;
		int get_age() const;
		string get_name() const;

		
		// shachar - We don't need setters. Think about the situation in which the user calls the set name
		// then there wil be a memory leak! 
		void set_age(int age);
		void set_name(string name);
		


		
	private:
		const size_t m_id;		// Unique for each Person_t object 
		string		m_name;	
		int		m_age;
		static size_t m_globID;	// used to calculate m_id. Stores the current max global id.
};



istream& operator>> (istream& is, Person_t& p);
ostream& operator<< (ostream& os, const Person_t & p);

