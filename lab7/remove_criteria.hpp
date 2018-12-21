#ifndef REMOVE_CRITERIA_HPP
#define REMOVE_CRITERIA_HPP

template <class T> class RemoveCriteria
{
	public:
		virtual bool is_it(T *value) = 0;
};

#endif

