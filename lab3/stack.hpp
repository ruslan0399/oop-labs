#ifndef STACK_HPP
#define STACK_HPP

#include "stack_item.hpp"

class Stack
{
	public:
		Stack();

		void push(std::shared_ptr <Figure> &&figure, int &num);
		std::shared_ptr <Figure> pop();
		bool empty();
		friend std::ostream& operator<<(std::ostream &os, const Stack &stack);
		virtual ~Stack();
	private:
		std::shared_ptr <StackItem> head;
};

#endif
