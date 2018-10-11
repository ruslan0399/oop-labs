#include "rstack_item.hpp"

RStackItem::RStackItem(const Rectangle &rect)
{
	this->rectangle = rect;
	this->next = nullptr;
	std::cout << "Элемент стека создан" << std::endl;
}

RStackItem::RStackItem(const RStackItem &orig)
{
	this->rectangle = orig.rectangle;
	this->next = orig.next;
	std::cout << "Элемент стека скопирован" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const RStackItem &item)
{
	std::cout << item.rectangle << std::endl;
	return os;
}

RStackItem *RStackItem::set_next(RStackItem *next)
{
	RStackItem *old = this->next;
	this->next = next;
	return old;
}

RStackItem *RStackItem::get_next() { return this->next; }
Rectangle RStackItem::get_rectangle() const { return this->rectangle; }

RStackItem::~RStackItem()
{
	std::cout << "Элемент стека удален" << std::endl;
	delete next;
}
