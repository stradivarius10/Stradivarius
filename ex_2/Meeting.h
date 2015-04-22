#include <string>
using namespace std;
class Person_t
{
public:
	~Person_t();
	Person_t();
	Person_t(string m_name, int m_age);
	Person_t & operator= (const Person_t &person);
	bool operator==(const Person_t &person) const;


private:
	const size_t 	m_id;		// Unique for each Person_t object
	string		m_name;	// use C++ class 'string', see #include <string>
	int		m_age;
	static size_t m_globID;	// used to calculate m_id
};
