#include "PersonArray_t.h"

/* initiazling the static data member */
const size_t PersonArray_t::expand_value = 16;


PersonArray_t::PersonArray_t() : num_of_elements(0), capacity(expand_value)
{		
	array_pointer = new const Person_t *[expand_value];
}

PersonArray_t::PersonArray_t(const size_t capacity_size) : num_of_elements(0), capacity(capacity_size)
{
	array_pointer = new const Person_t *[capacity];
}


PersonArray_t::~PersonArray_t()
{
	// does it delete the elements themselves???
	/* removing the array elements*/
	/*
	for (size_t i = 0; i < num_of_elements; i++)
	{
		delete array_pointer[i];
	}
	*/
	// no need to remove the objects - we don't own them
	delete[] array_pointer;
	
}


/*
// denis what about your implementation??????? maybe we should delete this???
PersonArray_t::PersonArray_t(const PersonArray_t &personArray)
{
	array_pointer = new const Person_t *[personArray.capacity];
	capacity = personArray.capacity;
	num_of_elements = personArray.num_of_elements;

	 copying all the elements 
	for (size_t i = 0; i < num_of_elements; i++)
	{
		// what about fucking id????? 
		array_pointer[i] = personArray.array_pointer[i];
	}
}


PersonArray_t & PersonArray_t:: operator= (const PersonArray_t &personArray)
{

	if (this != &personArray)
	{ 
		////// maybe add af ucntion1!!~!!! code duplocation 
		delete[] array_pointer; /* check for complexity????????
		array_pointer = new const Person_t *[personArray.capacity];
		capacity = personArray.capacity;
		num_of_elements = personArray.num_of_elements;

		/* copying all the elements 
		for (size_t i = 0; i < num_of_elements; i++)
		{
			// what about fucking id????? 
			array_pointer[i] = personArray.array_pointer[i];
		}


	}
	return *this;

}
*/


size_t PersonArray_t::get_num_of_elements() const
{
	return num_of_elements;
}
size_t PersonArray_t::get_capacity() const
{
	return capacity;
}

bool PersonArray_t::is_empty() const
{
	return num_of_elements == 0;
}

void  PersonArray_t::insert( Person_t *person)
{  
	append(num_of_elements - 1, person);
}

Person_t * PersonArray_t::get_first_element() const
{
	if (is_empty())
		return NULL;

	return (Person_t *)array_pointer[0]; /*wtff???????? */
}
Person_t * PersonArray_t::get_last_element() const
{
	if (is_empty())
		return NULL;

	return  (Person_t *)array_pointer[num_of_elements - 1];/// wtf////
}
/* check the thing with comparsion!!!!*/
Person_t * PersonArray_t::find(const Person_t &person) const
{ 
	for (size_t i  = 0; i < num_of_elements; i++)
	{
		if (person == *array_pointer[i])
		{
			return (Person_t *)array_pointer[i]; //wtf
		}
	}
	return 0;
}


Person_t * PersonArray_t::remove(const Person_t &person)
{ /* fix in other places tosize)T*/
	Person_t *result = NULL;
	size_t i = 0;
	/*finding the index of the element*/
	for (; i < num_of_elements; i++)
	{
		if (person == *array_pointer[i])
		{
			 result = (Person_t *)array_pointer[i];
			 break;

		}
	}
	shift_left(i);

	num_of_elements--;
	return result;
}


void PersonArray_t::shift_left(int index)
{
	if (index < 0)
	{
		return;
	}
	/* removing it and moving the elements to the right place*/
	for (; index < (int)num_of_elements - 1; index++)
	{
		array_pointer[index] = array_pointer[index + 1];
	}
}

void PersonArray_t::remove_delete(const Person_t &person)
{ 
	size_t i = 0;
	/*finding the index of the element*/
	for (; i < num_of_elements; i++)
	{
		if (person == *array_pointer[i])
		{
			delete array_pointer[i];
			shift_left(i);
			num_of_elements--;
			i--;
		}
	}

}

void PersonArray_t::remove_all()
{
	num_of_elements = 0; // in this case the array is empty though items may be exists but will be treated as none exited.
}
void PersonArray_t::remove_delete_all()
{
	for (size_t i = 0; i < num_of_elements; i++)
	{
		delete array_pointer[i]; /* why deleting array won't call it????*/
	}
	remove_all(); // already took care for the deletion.
}


void PersonArray_t::expand_capacity()
{
    const Person_t ** temp = new const Person_t *[capacity + expand_value];
	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = array_pointer[i];
	}
	//liran - no need to call the delete of persons right? they are in use...
	//noooooooooooooooooooooo
	//delete[] array_pointer;
	array_pointer = temp;
	capacity += expand_value;
}

int PersonArray_t::append(int index,const Person_t *person)
{
	if (index >= (int)num_of_elements || index<-1)
		return 0;

	/* no place*/
	if (num_of_elements == capacity)
	{
		expand_capacity();
	}
	

	num_of_elements++;

	/* move the elements to the right in order to accumulate the new item*/
	for (size_t i = index + 1; i < num_of_elements; i++)
	{
		array_pointer[i+1] = array_pointer[i];

	}

	array_pointer[index + 1] = person;

	return 1;

}


int PersonArray_t::prepend(int index,const Person_t *person)
{
	if (index - 1 < 0) 
		return 0;
	 return append(index -2, person);
}


void PersonArray_t::print_array() const
{
	for (size_t i = 0; i < num_of_elements; i++)
	{
		cout << *array_pointer[i] << endl;
	}
}

Person_t* PersonArray_t::get_element(int index) const
{
	if (index < 0 || (size_t)index >= num_of_elements) //error in index
		return NULL;
	return (Person_t*)array_pointer[index];
}