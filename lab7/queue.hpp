#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "queue_item.hpp"
#include "iterator.hpp"

template <class T> class Queue 
{
	public:
		Queue();

		void push(std::shared_ptr <T> &&figure);
		std::shared_ptr <T> pop();
		size_t size();
		bool empty();

		Iterator <QueueItem<T>, T> begin();
		Iterator <QueueItem<T>, T> end();

		template <class A> friend std::ostream& operator<<(std::ostream &os, const Queue<A> &queue);
		virtual ~Queue();
	private:
		std::shared_ptr <QueueItem<T>> head, tail;
};

#include "queue.cpp"
#endif
