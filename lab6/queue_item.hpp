#ifndef QUEUE_ITEM_HPP
#define QUEUE_ITEM_HPP

#include <memory>

template <class T> class QueueItem
{
	public:
		QueueItem(const std::shared_ptr <T> &figure);
		template <class A> friend std::ostream& operator<<(std::ostream &os, const QueueItem<A> &item);

		std::shared_ptr <QueueItem<T>> set_next(std::shared_ptr <QueueItem<T>> &next);
		std::shared_ptr <QueueItem<T>> get_next();
		std::shared_ptr <T> get_figure() const;

		virtual ~QueueItem();
	
	private:
		std::shared_ptr <T> figure;
		std::shared_ptr <QueueItem<T>> next;
};

#include "queue_item.cpp"
#endif
