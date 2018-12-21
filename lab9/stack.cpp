template <class T> Stack<T>::Stack() : head(nullptr) {}

template <class T> void Stack<T>::push(std::shared_ptr <T> &&figure)
{
	std::shared_ptr <StackItem<T>> item(new StackItem<T>(figure));
	item->set_next(head);
	head = item;
}

template <class T> std::shared_ptr<T> Stack<T>::pop()
{
	std::shared_ptr <T> result;
	if(head != nullptr)
	{
		result = head->get_figure();
		head = head->get_next();
	}

	return result;
}

template <class T> std::shared_ptr<T> Stack<T>::pop_last()
{
	std::shared_ptr <T> result;
	if(head != nullptr)
	{
		std::shared_ptr<StackItem<T>> elem = head;
		std::shared_ptr<StackItem<T>> prev = nullptr;

		while(elem->get_next() != nullptr)
		{
			prev = elem;
			elem = elem->get_next();
		}

		if(prev != nullptr)
		{
			prev->set_next(nullptr);
			result = elem->get_figure();
		}

		else
		{
			result = elem->get_figure();
			head = nullptr;
		}
	}

	return result;
}

template <class T> Iterator<StackItem<T>, T> Stack<T>::begin()
{
	return Iterator<StackItem<T>, T>(head);
}

template <class T> Iterator<StackItem<T>, T> Stack<T>::end()
{
	return Iterator<StackItem<T>, T>(nullptr);
}

template <class T> std::ostream& operator<<(std::ostream &os, const Stack<T> &stack)
{
	std::shared_ptr <StackItem<T>> item = stack.head;
	while(item != nullptr)
	{
		os << *item << std::endl;
		item = item->get_next();
	}

	return os;
}

template <class T> size_t Stack<T>::size()
{
	size_t res = 0;
	for(auto i = this->begin(); i != this->end(); ++i) ++res;
	return res;
}

template <class T> bool Stack<T>::empty() { return head == nullptr; }
template <class T> Stack<T>::~Stack() {}
