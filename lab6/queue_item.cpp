template <class T> QueueItem<T>::QueueItem(const std::shared_ptr <T> &figure)
{
	this->figure = figure;
	this->next = nullptr;
}

template <class T> std::ostream& operator<<(std::ostream &os, const QueueItem<T> &item)
{
	os << *item.figure;
	return os;
}

template <class T> std::shared_ptr <QueueItem<T>> QueueItem<T>::set_next(std::shared_ptr <QueueItem<T>> &next)
{
	std::shared_ptr <QueueItem<T>> old = this->next;
	this->next = next;
	return old;
}

template <class T> std::shared_ptr <QueueItem<T>> QueueItem<T>::get_next() { return this->next; }
template <class T> std::shared_ptr <T> QueueItem<T>::get_figure() const { return this->figure; }

template <class T> QueueItem<T>::~QueueItem() {}
