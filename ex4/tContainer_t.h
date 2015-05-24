#ifndef TCONTAINER_T
#define TCONTAINER_T

#include <vector>
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include "Comparator.h"


using namespace std;

#ifdef TEMPLATE_TEMPLATE
#define PREFIX_TEMPLATE  template<class T, template <typename, typename> class CT> 

#else
#define PREFIX_TEMPLATE  template <class T, class CT > 

#endif

	PREFIX_TEMPLATE	class tContainer_t {
public:
	 ~tContainer_t();// YOSSI told us in the forum that we should not support inheritence and agreed that the destructor would be not virtual to prevent such case
	 tContainer_t();  

	 // - return true/false according to is container is  empty or not
	 inline bool is_empty() const;
	 // return number of elements in array
	 inline size_t get_size() const;
	 //- insert a new element in the end of array
	 inline void insert(T * element);
	 //return first element in container
	 inline T* get_first() const;
	 //return last  element in container
	 inline T* get_last() const;
	 //- find specific element by value
	 inline T * find(const T & elem) const;
	 //remove specific element and returns pointer to it 
	 inline T * remove(const T & elem);
	 // all elements ( without deleting them )
	 inline void remove_all();
	 //- remove and delete specific element
	 inline void remove_and_delete(const T & elem);
	 //- remove and delete all elements 
	 inline void remove_delete_all();

	 

	 inline T * & operator[] ( size_t index); //assign  - throws excpetion if out of bound
	 inline T * operator[] (size_t index) const; // retrieve  -throws excpetion if out of bound

private:
	tContainer_t<T, CT>(const tContainer_t<T, CT>& container);// not allowing copy
    tContainer_t<T, CT> &  operator=(const tContainer_t<T, CT> & container);// not allowing copy


	// not asked but we added so it can be easy to debug and added functionality of printing to the test..
	PREFIX_TEMPLATE friend ostream& operator<<(ostream& os, const tContainer_t<T, CT> & cont);


#ifdef TEMPLATE_TEMPLATE

	CT<T *,allocator<T *>> cont_m;
	typedef typename CT<T*,allocator<T *>>::const_iterator const_iter_t;
	typedef typename CT<T*,allocator<T *>>::iterator iter_t;
#else

	CT cont_m;
	typedef typename CT::iterator iter_t; 
	typedef typename CT::const_iterator const_iter_t;
#endif

};


PREFIX_TEMPLATE  tContainer_t<T, CT>:: ~tContainer_t(){}

PREFIX_TEMPLATE  tContainer_t<T, CT>::tContainer_t(){}

PREFIX_TEMPLATE inline bool  tContainer_t<T, CT>::is_empty() const
{
	return cont_m.empty();
}

PREFIX_TEMPLATE inline size_t  tContainer_t<T, CT>::get_size() const
{
	return cont_m.size();
}

PREFIX_TEMPLATE inline void  tContainer_t<T, CT>::insert(T * element)
{
	cont_m.push_back(element);
}


PREFIX_TEMPLATE inline T *  tContainer_t<T, CT>::get_first() const
{
	if (is_empty())
	{
		return nullptr; //Agreed by YOSSI.
	
	}
	else
	{
		return cont_m.front();
	}
}

PREFIX_TEMPLATE inline T *  tContainer_t<T, CT>::get_last() const
{
	if (is_empty())
	{
		return nullptr; //Agreed by YOSSI.
	}
	else
	{
		return cont_m.back();
	}
}

PREFIX_TEMPLATE inline void  tContainer_t<T, CT>::remove_and_delete(const T & elem)
{

	T * elem_found = remove(elem);

	if (elem_found == 0)
	{
		throw exception("No such element was found"); //agreed by YOSSI in the forum!
	}
	else
	{
		delete elem_found; 
	}

}


PREFIX_TEMPLATE inline T *  tContainer_t<T, CT>::find(const T & elem) const
{
	const_iter_t elem_found = find_if(cont_m.begin(), cont_m.end(), comparator<T>(elem));

	if (elem_found != cont_m.end())
	{
		return *elem_found;
	}
	else
	{
		return 0;
	}
}


PREFIX_TEMPLATE inline T *  tContainer_t<T, CT>::remove(const T & elem)
{

	const_iter_t elem_found = find_if(cont_m.begin(), cont_m.end(), comparator<T>(elem));
	if (elem_found != cont_m.end())
	{
		T * result = *elem_found;
		cont_m.erase(elem_found); 
		return result;
	}
	else
	{
		return 0;
	}
	
}

PREFIX_TEMPLATE inline void  tContainer_t<T, CT>::remove_all()
{
	cont_m.clear();
}


PREFIX_TEMPLATE inline void  tContainer_t<T, CT>::remove_delete_all()
{

	iter_t it; 
	for (it = cont_m.begin(); it != cont_m.end(); it++)
	{
		delete (*it);
	}

	remove_all(); //remove all elements but not destryong them (we have already destroyed them..).

}


PREFIX_TEMPLATE inline  T * &  tContainer_t<T, CT>::operator[] (size_t index)
{
	if (index >= cont_m.size())
	{
		throw exception("Index is out of bound!");
	}

	if (typeid(cont_m) == typeid(vector<T*>)) //vector has already implemented the [] operator so we can use it
	{
		vector<T*, allocator<T*>> *temp = (vector<T*, allocator<T*>> *)(&cont_m);
		return  (*temp)[index]; 
	}
	else
	{
		iter_t it = cont_m.begin();
		advance(it, index);
		return *it;
		
	}
}



PREFIX_TEMPLATE inline  T *   tContainer_t<T, CT>::operator[] (size_t index) const
{
	if (index >= cont_m.size())
	{
		throw exception("Index is out of bound!");
	}

	if (typeid(cont_m) == typeid(vector<T*>)) //vector has already implemented the [] operator so we can use it
	{
		vector<T*, allocator<T*>> *temp = (vector<T*, allocator<T*>> *)(&cont_m);
		return  (*temp)[index]; 
	}
	else //list - YOSSI told us that there only 2 options - list or vector!
	{
		const_iter_t it = cont_m.begin();
		advance(it, index);
		return *it;

	}
}



PREFIX_TEMPLATE ostream&  operator<<(ostream& os, const tContainer_t<T, CT> & cont)
{
	tContainer_t<T, CT>::const_iter_t it;
	for (it = cont.cont_m.begin(); it != cont.cont_m.end(); it++)
	{
		os << **it << endl ;
	}
	return os;
}









#endif


