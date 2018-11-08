#ifndef STACK_ITEM_HPP
#define STACK_ITEM_HPP

#include <memory>
#include "figure.hpp"

template <class T> class StackItem
{
	public:
		StackItem(const std::shared_ptr <T> &figure);
		template <class A> friend std::ostream& operator<<(std::ostream &os, const StackItem<A> &item);

		std::shared_ptr <StackItem<T>> set_next(std::shared_ptr <StackItem<T>> &next);
		std::shared_ptr <StackItem<T>> get_next();
		std::shared_ptr <T> get_figure() const;

		virtual ~StackItem();
	private:
		std::shared_ptr <T> figure;
		std::shared_ptr <StackItem<T>> next;
};

#endif
