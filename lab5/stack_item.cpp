template <class T> StackItem<T>::StackItem(const std::shared_ptr <T> &figure)
{
	this->figure = figure;
	this->next = nullptr;
	std::cout << "Элемент стека создан" << std::endl;
}

template <class T> std::ostream& operator<<(std::ostream &os, const StackItem<T> &item)
{
	os << *item.figure;
	return os;
}

template <class T> std::shared_ptr <StackItem<T>> StackItem<T>::set_next(std::shared_ptr <StackItem<T>> &next)
{
	std::shared_ptr <StackItem<T>> old = this->next;
	this->next = next;
	return old;
}

template <class T> std::shared_ptr <StackItem<T>> StackItem<T>::get_next() { return this->next; }
template <class T> std::shared_ptr <T> StackItem<T>::get_figure() const { return this->figure; }

template <class T> StackItem<T>::~StackItem() { std::cout << "Элемент стека удален" << std::endl; }
