#include "rstack.hpp"

RStack::RStack() : head(nullptr) {}
RStack::RStack(const RStack &orig) { head = orig.head; }

void RStack::push(Rectangle &&rect)
{
	RStackItem *item = new RStackItem(rect);
	item->set_next(head);
	head = item;
}

Rectangle RStack::pop()
{
	Rectangle rect;
	if(head != nullptr)
	{
		RStackItem *old_head = head;
		head = head->get_next();
		rect = old_head->get_rectangle();
		old_head->set_next(nullptr);
		delete old_head;
	}

	return rect;
}

std::ostream& operator<<(std::ostream &os, const RStack &stack)
{
	RStackItem *item = stack.head;
	while(item != nullptr)
	{
		os << *item;
		item = item->get_next();
	}

	return os;
}

bool RStack::empty() { return head == nullptr; }
RStack::~RStack() { delete head; }
