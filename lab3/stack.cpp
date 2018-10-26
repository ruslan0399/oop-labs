#include "stack.hpp"

Stack::Stack() : head(nullptr) {}

void Stack::push(std::shared_ptr <Figure> &&figure, int &num)
{
	std::shared_ptr <StackItem> item(new StackItem(figure, num));
	item->set_next(head);
	head = item;
}

std::shared_ptr <Figure> Stack::pop()
{
	std::shared_ptr <Figure> result;
	if(head != nullptr)
	{
		std::cout << *head;
		result = head->get_figure();
		head = head->get_next();
	}

	return result;
}

std::ostream& operator<<(std::ostream &os, const Stack &stack)
{
	std::shared_ptr <StackItem> item = stack.head;
	while(item != nullptr)
	{
		os << *item;
		item = item->get_next();
	}

	return os;
}

bool Stack::empty() { return head == nullptr; }
Stack::~Stack() {}
