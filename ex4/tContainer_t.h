#ifndef TCONTAINER_T
#define TCONTAINER_T

#include <vector>
#include <algorithm>
#include <iostream>
#include <typeinfo>


using namespace std;

#ifdef TEMPLATE_TEMPLATE
#define prefix_function  template<class T, template <typename, typename> class CT> 
template <class T, template <typename, typename> class CT > class tContainer_t


#else
#define prefix_function  template <class T, class CT > 

template <class T, class CT > class tContainer_t


#endif

{


public:
	 ~tContainer_t();// YOSSI told us in the forum that we should not support inheritence and agreed that the destructor would be not virtual to prevent such case
	 tContainer_t();  

	 // - return true/false according to is container is  empty or not
	 inline bool is_empty() const;
	 // return number of elements in array
	 inline size_t get_size() const;
	 //- insert a new element in the end of array
	 inline void insert(T * element); // ????????????????????????????????? name
	 //return first element in container
	 inline T* get_first() const;
	 //return last  element in container
	 inline T* get_last() const;
	 //- find specific element by value
	 T * find(const T & elem) const;
	 //remove specific element and returns pointer to it 
	 T * remove(const T & elem);
	 // all elements ( without deleting them )
	 void remove_all();
	 //- remove and delete specific element 
	 void remove_and_delete(const T & elem);
	 //- remove and delete all elements 
	 void remove_delete_all();

	 

	 T * & operator[] ( size_t index); //assign  - throws excpetion if out of bound
	 T * operator[] (size_t index) const; // retrieve  -throws excpetion if out of bound

private:
	tContainer_t<T, CT>(const tContainer_t<T, CT>& container);// not allowing copy
    tContainer_t<T, CT> &  operator=(const tContainer_t<T, CT> & container);// not allowing copy


	// not asked but we added so it can be easy to debug and added functionality of printing to the test..
	prefix_function friend ostream& operator<<(ostream& os, const tContainer_t<T, CT> & cont);


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


prefix_function  tContainer_t<T, CT>:: ~tContainer_t(){}

prefix_function  tContainer_t<T, CT>::tContainer_t(){}

prefix_function bool  tContainer_t<T, CT>::is_empty() const
{
	return cont_m.empty();
}

prefix_function size_t  tContainer_t<T, CT>::get_size() const
{
	return cont_m.size();
}

prefix_function void  tContainer_t<T, CT>::insert(T * element)
{
	//cont_m.insert(cont_m.end(), element); //not catching the iterator
	cont_m.push_back(element);
}


prefix_function T *  tContainer_t<T, CT>::get_first() const
{
	if (is_empty())
	{
		return nullptr; //cehck itttttttttt
		// in [] check and throw exception!!!
	}
	else
	{
		return cont_m.front();
	}
}

prefix_function T *  tContainer_t<T, CT>::get_last() const
{
	if (is_empty())
	{
		return nullptr;
	}
	else
	{
		return cont_m.back();
	}
}

prefix_function void  tContainer_t<T, CT>::remove_and_delete(const T & elem)
{

	T * elem_found = remove(elem);

	if (elem_found == 0)
	{
		throw exception("No such element was found");
	}
	else
	{
		delete elem_found; 
	}

}


prefix_function T *  tContainer_t<T, CT>::find(const T & elem) const
{
	const_iter_t elem_found = find_if(cont_m.begin(), cont_m.end(), compare<T>(elem));

	if (elem_found != cont_m.end())
	{
		return *elem_found;
	}
	else
	{
		return 0;
	}
}


prefix_function T *  tContainer_t<T, CT>::remove(const T & elem)
{

	iter_t elem_found = find_if(cont_m.begin(), cont_m.end(), compare<T>(elem));
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

prefix_function void  tContainer_t<T, CT>::remove_all()
{
	cont_m.clear();
}


prefix_function void  tContainer_t<T, CT>::remove_delete_all()
{

	iter_t it; 
	for (it = cont_m.begin(); it != cont_m.end(); it++)
	{
		delete (*it);
	}

	remove_all(); //remove all elements but not destryong them (we have already destroyed them..).

}


prefix_function  T * &  tContainer_t<T, CT>::operator[] ( size_t index)
{
	if (index >= cont_m.size())
	{
		throw exception("Index is out of bound!");
	}

	if (typeid(cont_m) == typeid(vector<T*>)) //vector has already implemented the [] operator so we can use it
	{
		//vector<T*, allocator<T*>> *temp = reinterpret_cast <vector<T*, allocator<T*>> * >(&cont_m);
		vector<T*, allocator<T*>> *temp = (vector<T*, allocator<T*>> *)(&cont_m);
		return  (*temp)[index]; 
	}
	//else if (typeid(cont_m) == typeid(list<T*>))
	else
	{
		//tContainer_t<T, CT>::iter_t it = cont_m.begin();
		iter_t it = cont_m.begin();
		advance(it, index);
		return *it;
		
	}
	//return NULL;
}



prefix_function  T *   tContainer_t<T, CT>::operator[] ( size_t index) const
{
	if (index >= cont_m.size())
	{
		throw exception("Index is out of bound!");
	}

	if (typeid(cont_m) == typeid(vector<T*>)) //vector has already implemented the [] operator so we can use it
	{
	//	vector<T*, allocator<T*>> *temp = reinterpret_cast <vector<T*, allocator<T*>> * >(&cont_m);
		vector<T*, allocator<T*>> *temp = (vector<T*, allocator<T*>> *)(&cont_m);
		return  (*temp)[index]; // ??????????? reference
	}
	//else if (typeid(cont_m) == typeid(list<T*>))
	else //list - YOSSI told us that there only 2 options - list or vector!
	{
		//tContainer_t<T, CT>::iter_t it = cont_m.begin();
		const_iter_t it = cont_m.begin();
		advance(it, index);
		return *it;

	}
}



prefix_function ostream&  operator<<(ostream& os, const tContainer_t<T, CT> & cont)
{
	tContainer_t<T, CT>::const_iter_t it;
	for (it = cont.cont_m.begin(); it != cont.cont_m.end(); it++)
	{
		os << **it << endl ;
	}
	return os;
}





// wil be used as the predicat for the find_if
//functor ==> not taught in class - saw it in stackoverflow.com/questions/13525361/can-you-pass-an-additional-parameter-to-a-predicate

template <class T> struct compare
{
	compare(const T &val) : first_val(val){}; //default constructor = used to retreive the first element to compare with

	bool operator()(const T* second_val) const { return *second_val == first_val; } //we assume the T class has implemented the correct == operator


private:
	const T &first_val;
};






#endif


