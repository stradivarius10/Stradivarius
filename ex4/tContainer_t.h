#ifndef TCONTAINER_T
#define TCONTAINER_T

//#define TEMPLATE_TEMPLALTE //we take this option as the default one

#include <vector>
#include <algorithm>
#include<iostream>


using namespace std;

#ifdef TEMPLATE_TEMPLATE
#define prefix_function  template<typename T, template <typename, typename> class CT> 
template <typename T, template <typename, typename> class CT > class tContainer_t


#else
#define prefix_function  template <typename T, typename CT > 

// forward decleration
//prefix_function ostream& operator<<(ostream& os, const tContainer_t<T, CT> & cont);
//should it be type name in here??????
template <typename T, typename CT > class tContainer_t


#endif

{


	// not asked but we added..
	prefix_function friend ostream& operator<<(ostream& os, const tContainer_t<T, CT> & cont);
	/*
	friend ostream& operator<<(ostream& os, const tContainer_t<T,CT> & cont)
	{
		const_iter_t it; /// const??????????????????

		for (it = cont.cont_m.begin(); it != cont.cont_m.end(); it++)
		{
			os << **it << endl;
		}
		return os;
	}
	*/


public:
	virtual ~tContainer_t();
	tContainer_t(); 


	 inline bool is_empty() const;
	 inline size_t get_size() const;
	 inline void insert(T * element);
	 inline T* get_first() const;
	 inline T* get_last() const;
	 T * find(const T & elem) const;
	 T * remove(const T & elem);
	 void remove_all();
	 void remove_and_delete(const T & elem);
	 void remove_delete_all();

	 



	 T * & operator[] (size_t index); //assign ????????????????????????
	 T * operator[] (size_t index) const; /////?????????

private:
	tContainer_t<T, CT>(const tContainer_t<T, CT>& container);// copy constructor

	/*The point of making an assignment operator virtual is to allow you from the benefit of being able to override it to copy more fields.*/
    tContainer_t<T, CT> &  operator=(const tContainer_t<T, CT> & container);


#ifdef TEMPLATE_TEMPLATE

	CT<T *,allocator<T *>> cont_m;
	typedef typename CT<T*,allocator<T *>>::const_iterator const_iter_t; // why??????????????????????
	typedef typename CT<T*,allocator<T *>>::iterator iter_t; // why??????????????????????
#else


	CT cont_m;
	typedef typename CT::iterator iter_t; // why??????????????????????
	typedef typename CT::const_iterator const_iter_t; // why??????????????????????
#endif

	///// type???????



};


prefix_function ostream&  operator<<(ostream& os, const tContainer_t<T, CT> & cont)
{
	tContainer_t<T, CT>::const_iter_t it; /// const??????????????????
	for (it = cont.cont_m.begin(); it != cont.cont_m.end(); it++)
	{
		os << **it << endl;
	}
	return os;
}


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
	cont_m.insert(cont_m.end(), element); //not catching the iterator
}


prefix_function T *  tContainer_t<T, CT>::get_first() const
{
	if (is_empty())
	{
		return nullptr; /// echecko!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
		return nullptr; /// echecko!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	else
	{
		return cont_m.back();
	}
}

prefix_function void  tContainer_t<T, CT>::remove_and_delete(const T & elem)
{

	T * elem_found = remove(elem);

	//ask!!!!!!!!!!!!!!!!!!
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
	//tContainer_t<T, CT>::iter_t it;

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



////////??????????????
prefix_function T *  tContainer_t<T, CT>::remove(const T & elem)
{
//	tContainer_t<T, CT>::iter_t it;

	/*
	//check it out!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (it = cont_m.begin(); it < cont_m.end(); it++)
	{
		// we assume the T class implenets  the == operator ..
		if ((*it) == T)
		{
			T* result = &(*it);// ???????????????????????????????
			cont_m.erase(it); //becuase it's a ponter then the destructor is not called!!!!!!!
			return  result;
		}

	}
	*/
	//// shichpul code????
	const_iter_t elem_found = find_if(cont_m.begin(), cont_m.end(), compare<T>(elem));

	if (elem_found != cont_m.end())
	{
		T * result = *elem_found;
		cont_m.erase(elem_found);  ///???????? check
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
	//tContainer_t<T, CT>::iter_t it;
	const_iter_t it; /// const??????????????????
	//it = cont_m.begin();
	//it++;
	//bool x = it < cont_m.end();
	for (it = cont_m.begin(); it != cont_m.end(); it++)
	{
		delete (*it);
	}

	remove_all(); //remove all elements but not destryong them.

}


prefix_function  T * &  tContainer_t<T, CT>::operator[] (size_t index)
{
	if (typeid(cont_m) == typeid(vector<T*>)) //vector has already implemented the [] operator so we can use it
	{
		return ((vector<T*> )cont_m)[index]; // ??????????? reference
	}

	else if (typeid(cont_m) == typeid(list<T*>))
	{
		//tContainer_t<T, CT>::iter_t it = cont_m.begin();
		const_iter_t it = cont_m.begin();
		advance(it, index);
		return *it;
		
	}
}



// shicpul code????????????????????
prefix_function T *   tContainer_t<T, CT>::operator[] (size_t index) const
{
	if (typeid(cont_m) == typeid(vector<T*>)) //vector has already implemented the [] operator so we can use it
	{
		return ((vector<T*>)cont_m)[index];
	}

	else if (typeid(cont_m) == typeid(list<T*>))
	{
		//tContainer_t<T, CT>::iter_t it = cont_m.begin();
		const_iter_t it = cont_m.begin();
		advance(it, index);
		return *it;

	}
}




// wil be used as the predicat for the find_if
//functor ==> not taught in class - saw it in stackoverflow.com/questions/13525361/can-you-pass-an-additional-parameter-to-a-predicate

template <class T> struct compare
{
	compare(T val) : first_val(val){}; //default constructor = used to retreive the first element to compare with

	bool operator()(T* second_val) const { return *second_val == first_val; } //we assume the T class has implemented the correct == operator


private:
	T first_val;
};






#endif


