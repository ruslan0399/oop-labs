#ifndef REMOVE_CRITERIA_ALL_HPP
#define REMOVE_CRITERIA_ALL_HPP

#include "remove_criteria.hpp"

template <class T> class RemoveCriteriaAll: public RemoveCriteria<T>
{
	public:
		RemoveCriteriaAll() {};
		virtual bool is_it(T *value) override { return true; }
};

#endif

