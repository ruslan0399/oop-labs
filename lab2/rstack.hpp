#ifndef RSTACK_HPP
#define RSTACK_HPP

#include "rstack_item.hpp"

class RStack
{
	public:
		RStack();
		RStack(const RStack &orig);

		void push(Rectangle &&rect);
		Rectangle pop();
		bool empty();
		friend std::ostream& operator<<(std::ostream &os, const RStack &stack);
		virtual ~RStack();
	private:
		RStackItem *head;
};

#endif
