#ifndef REMOVE_CRITERIA_BY_VALUE_HPP
#define REMOVE_CRITERIA_BY_VALUE_HPP

#include "remove_criteria.hpp"

template <class T> class RemoveCriteriaByValue: public RemoveCriteria<T>
{
	public:
		RemoveCriteriaByValue(double value): m_value(value) {};
		virtual bool is_it(T *value) override { return m_value >= value->Square(); }

	private:
		double m_value;
};

#endif

