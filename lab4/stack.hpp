#ifndef STACK_HPP
#define STACK_HPP

#include "stack_item.hpp"

template <class T> class Stack
{
	public:
		Stack();

		void push(std::shared_ptr <T> &&figure);
		std::shared_ptr <T> pop();
		bool empty();
		template <class A> friend std::ostream& operator<<(std::ostream &os, const Stack<A> &stack);
		virtual ~Stack();
	private:
		std::shared_ptr <StackItem<T>> head;
};

#endif
