template <class T> Queue<T>::Queue() : head(nullptr), tail(nullptr) {}

template <class T> void Queue<T>::push(std::shared_ptr <T> &&figure)
{
	std::shared_ptr <QueueItem<T>> item(new QueueItem<T>(figure));

	if(head == nullptr) head = item;
	else tail->set_next(item);
	tail = item;
}

template <class T> std::shared_ptr<T> Queue<T>::pop()
{
	std::shared_ptr <T> result;
	if(head != nullptr)
	{
		result = head->get_figure();
		head = head->get_next();
	}

	return result;
}

template <class T> Iterator<QueueItem<T>, T> Queue<T>::begin()
{
	return Iterator<QueueItem<T>, T>(head);
}

template <class T> Iterator<QueueItem<T>, T> Queue<T>::end()
{
	return Iterator<QueueItem<T>, T>(nullptr);
}

template <class T> std::ostream& operator<<(std::ostream &os, const Queue<T> &queue)
{
	std::shared_ptr <QueueItem<T>> item = queue.head;
	while(item != nullptr)
	{
		os << *item << std::endl;
		item = item->get_next();
	}

	return os;
}

template <class T> size_t Queue<T>::size()
{
	size_t res = 0;
	for(auto i = this->begin(); i != this->end(); ++i) ++res;
	return res;
}

template <class T> bool Queue<T>::empty() { return head == nullptr; }
template <class T> Queue<T>::~Queue() {}
