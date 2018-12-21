#ifndef STACK_HPP
#define STACK_HPP

#include "stack_item.hpp"
#include "iterator.hpp"
#include "remove_criteria.hpp"

template <class T, class T2> class Stack
{
	public:
		Stack();

		void push(std::shared_ptr <T> &&figure);
		std::shared_ptr <T> pop();
		bool empty();

		Iterator <StackItem<T>, T> begin();
		Iterator <StackItem<T>, T> end();

		void insert_subitem(T2 *value);
		void remove_subitem(RemoveCriteria<T2> *criteria);

		template <class A, class AA> friend std::ostream& operator<<(std::ostream &os, const Stack<A, AA> &stack);
		virtual ~Stack();
	private:
		std::shared_ptr <StackItem<T>> head;
};

#include "stack.cpp"
#endif
