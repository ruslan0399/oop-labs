#ifndef STACK_ITEM_HPP
#define STACK_ITEM_HPP

#include <memory>
#include "figure.hpp"

class StackItem
{
	public:
		StackItem(const std::shared_ptr <Figure> &figure, int &num);
		friend std::ostream& operator<<(std::ostream &os, const StackItem &item);

		std::shared_ptr <StackItem> set_next(std::shared_ptr <StackItem> &next);
		std::shared_ptr <StackItem> get_next();
		std::shared_ptr <Figure> get_figure() const;

		virtual ~StackItem();
	private:
		std::shared_ptr <Figure> figure;
		std::shared_ptr <StackItem> next;
		int number;
};

#endif
