#ifndef STACK_HPP
#define STACK_HPP

#include "stack_item.hpp"
#include "iterator.hpp"

template <class T> class Stack
{
	public:
		Stack();

		void push(std::shared_ptr <T> &&figure);
		std::shared_ptr <T> pop();
		std::shared_ptr <T> pop_last();
		size_t size();
		bool empty();

		Iterator <StackItem<T>, T> begin();
		Iterator <StackItem<T>, T> end();

		template <class A> friend std::ostream& operator<<(std::ostream &os, const Stack<A> &stack);
		virtual ~Stack();
	private:
		std::shared_ptr <StackItem<T>> head;
};

#include "stack.cpp"
#endif
