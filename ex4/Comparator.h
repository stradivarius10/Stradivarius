#ifndef COMPARATOR_T
#define COMPARATOR_T
// wil be used as the predicat for the find_if
//functor ==> not taught in class - saw it in stackoverflow.com/questions/13525361/can-you-pass-an-additional-parameter-to-a-predicate
// references were used in order to support not copybale objects as well :)
template <class T> struct comparator
{
	comparator(const T &val) : first_val(val){}; //default constructor = used to retreive the first element to compare with

	bool operator()(const T* second_val) const { return *second_val == first_val; } //we assume the T class has implemented the correct == operator


private:
	const T &first_val; 
};

#endif

