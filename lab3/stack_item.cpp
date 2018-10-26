#include "stack_item.hpp"
#include "rectangle.hpp"
#include "trapeze.hpp"
#include "rhombus.hpp"

StackItem::StackItem(const std::shared_ptr <Figure> &figure, int &num)
{
	this->figure = figure;
	this->next = nullptr;
	this->number = num;
	std::cout << "Элемент стека создан" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const StackItem &item)
{
	if(item.number == 1)
	{
		std::shared_ptr <Rectangle> rect = std::dynamic_pointer_cast <Rectangle> (item.figure);
		os << *rect << std::endl;
	}
	
	else if(item.number == 2)
	{
		std::shared_ptr <Trapeze> trap = std::dynamic_pointer_cast <Trapeze> (item.figure);
		os << *trap << std::endl;
	}

	else if(item.number == 3)
	{
		std::shared_ptr <Rhombus> rhomb = std::dynamic_pointer_cast <Rhombus> (item.figure);
		os << *rhomb << std::endl;
	}

	return os;
}

std::shared_ptr <StackItem> StackItem::set_next(std::shared_ptr <StackItem> &next)
{
	std::shared_ptr <StackItem> old = this->next;
	this->next = next;
	return old;
}

std::shared_ptr <StackItem> StackItem::get_next() { return this->next; }
std::shared_ptr <Figure> StackItem::get_figure() const { return this->figure; }

StackItem::~StackItem() { std::cout << "Элемент стека удален" << std::endl; }
