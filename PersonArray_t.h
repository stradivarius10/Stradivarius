#include "Person_t.h"


class PersonArray_t
{
	public:
		~PersonArray_t();
		PersonArray_t(); //Defuault CTOR - capacity wil be the expand value 
		explicit PersonArray_t(const size_t capacity);  //explicit to prevent PersonArray_t a = 2 for instance.
		size_t get_num_of_elements() const;
		size_t get_capacity() const;
		void insert(const Person_t *person); //inserts a person_t * item to the array. Will expand the array with expand value if no place */
		Person_t *get_first_element() const; // returns NULL if array is empty
		Person_t * get_last_element() const; // returns NULL if array is empty
		Person_t * find(const Person_t &person) const; //find element with specific value. Returns NULL if no element found.
		Person_t * remove(const Person_t &person); // if more than one element has the same value, then removes only the first found
		void remove_delete(const Person_t &person); //if more than one element has the same value, then to remove all of them	
		void remove_all(); //all elements ( without deleting them , empty array)
		void remove_delete_all(); 
		int append(size_t index, const Person_t *person); //add a new element after  index in array	
		int prepend(size_t index,const Person_t *person); //add a new element before specific index in array
		bool is_empty() const; //returns True iff the array is empty. False otherwise
		void print_array() const;
		Person_t* get_element(size_t index) const; //get element by a given index

	private:
		const Person_t **array_pointer; // pointer to the array of Person_t *
		size_t num_of_elements; /* actual number of elements currently stored in the array*/
		size_t capacity; //how many elements can be stored in the array

		static const size_t expand_value; /* the value that we increase the array with each time it gets to it's fukk capacity*/

		//private:/* check*/
		PersonArray_t & operator= (const PersonArray_t &personArray); //private assignemnt operator to prevent copying the array.
		PersonArray_t(const PersonArray_t &personArray); //private copy contructor to prevent copying the array.

		//auxilliary functions
		void expand_capacity(); //expand the capacity by expan_value
		void shift_left(int index); // will shift all the items to the left form index towarads num_of_elements.
		void insert_at_index(size_t index, const Person_t *person); //will insert an item at index, and will shift right all items on the right
};
