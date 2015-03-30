#include "PersonArray_t.h"

/* initiazling the static data member */
const size_t PersonArray_t::m_expand_value = 4;


PersonArray_t::PersonArray_t() : m_num_of_elements(0), m_capacity(m_expand_value)
{		
	m_array_pointer = new const Person_t *[m_expand_value];
}

PersonArray_t::PersonArray_t(const size_t capacity_size) : m_num_of_elements(0), m_capacity(capacity_size)
{
	m_array_pointer = new const Person_t *[m_capacity];
}


PersonArray_t::~PersonArray_t()
{
	// no need to remove the objects - we don't own them
	delete[] m_array_pointer;
	
}

size_t PersonArray_t::get_num_of_elements() const
{
	return m_num_of_elements;
}
size_t PersonArray_t::get_capacity() const
{
	return m_capacity;
}

bool PersonArray_t::is_empty() const
{
	return m_num_of_elements == 0;
}

void  PersonArray_t::insert(const Person_t *person)
{  
	insert_at_index(m_num_of_elements, person);
}

Person_t * PersonArray_t::get_first_element() const
{
	if (is_empty())
		return NULL;

	return (Person_t *)m_array_pointer[0]; 
}
Person_t * PersonArray_t::get_last_element() const
{
	if (is_empty())
		return NULL;

	return  (Person_t *)m_array_pointer[m_num_of_elements - 1];
}

Person_t * PersonArray_t::find(const Person_t &person) const
{ 
	for (size_t i = 0; i < m_num_of_elements; i++)
	{
		if (person == *m_array_pointer[i])
		{
			return (Person_t *)m_array_pointer[i]; 
		}
	}
	return 0;
}


Person_t * PersonArray_t::remove(const Person_t &person)
{ 
	Person_t *result = NULL;
	size_t i = 0;
	/*finding the index of the element*/
	for (; i < m_num_of_elements; i++)
	{
		if (person == *m_array_pointer[i])
		{
			result = (Person_t *)m_array_pointer[i];
			 break;

		}
	}
	shift_left(i);

	m_num_of_elements--;
	return result;
}


void PersonArray_t::shift_left(int index)
{
	if (index < 0)
	{
		return;
	}
	/* removing it and moving the elements to the right place*/
	for (; index < (int)m_num_of_elements - 1; index++)
	{
		m_array_pointer[index] = m_array_pointer[index + 1];
	}
}

void PersonArray_t::remove_delete(const Person_t &person)
{ 
	/*finding the index of the element*/
	for (size_t i = 0; i < m_num_of_elements; i++)
	{
		if (person == *m_array_pointer[i])
		{
			delete m_array_pointer[i];
			shift_left(i);
			m_num_of_elements--;
			i--;
		}
	}

}

void PersonArray_t::remove_all()
{
	m_num_of_elements = 0; // in this case the array is empty though items may be exists but will be treated as none exited.
}

void PersonArray_t::remove_delete_all()
{
	for (size_t i = 0; i < m_num_of_elements; i++)
	{
		delete m_array_pointer[i]; 
	}
	remove_all(); // already took care for the deletion.
}


void PersonArray_t::expand_capacity()
{
	const Person_t ** temp = new const Person_t *[m_capacity + m_expand_value];
	for (size_t i = 0; i < m_capacity; i++)
	{
		temp[i] = m_array_pointer[i];
	}
	m_array_pointer = temp;
	m_capacity += m_expand_value;
}

int PersonArray_t::append(const size_t index,const Person_t *person)
{
	if (index >=m_num_of_elements)
		return 0;

	insert_at_index(index + 1, person);
	return 1;

}


int PersonArray_t::prepend(const size_t index,const Person_t *person)
{
	if (index == 0 || index > m_num_of_elements) 
		return 0;
	insert_at_index(index -1, person);
	return 1;
}


void PersonArray_t::print_array() const
{
	for (size_t i = 0; i < m_num_of_elements; i++)
	{
		cout << *m_array_pointer[i] << endl;
	}
}

Person_t* PersonArray_t::get_element(const size_t index) const
{
	if (index >= m_num_of_elements) //error in index
		return NULL;
	return (Person_t*)m_array_pointer[index];
}


void PersonArray_t::insert_at_index(const size_t index, const Person_t *person)
{

	/* no place*/
	if (m_num_of_elements == m_capacity)
	{
		expand_capacity();
	}

	/* move the elements to the right in order to accumulate the new item*/
	for (size_t i = m_num_of_elements; i > index; i--)
	{
		m_array_pointer[i] = m_array_pointer[i - 1];

	}

	m_array_pointer[index] = person;

	m_num_of_elements++;

}
