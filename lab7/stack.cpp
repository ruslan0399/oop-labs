template <class T, class T2> Stack<T, T2>::Stack() : head(nullptr) {}

template <class T, class T2> void Stack<T, T2>::push(std::shared_ptr <T> &&figure)
{
	std::shared_ptr <StackItem<T>> item(new StackItem<T>(figure));
	item->set_next(head);
	head = item;
}

template <class T, class T2> std::shared_ptr<T> Stack<T, T2>::pop()
{
	std::shared_ptr <T> result;
	if(head != nullptr)
	{
		result = head->get_figure();
		head = head->get_next();
	}

	return result;
}

template <class T, class T2> Iterator<StackItem<T>, T> Stack<T, T2>::begin()
{
	return Iterator<StackItem<T>, T>(head);
}

template <class T, class T2> Iterator<StackItem<T>, T> Stack<T, T2>::end()
{
	return Iterator<StackItem<T>, T>(nullptr);
}

template <class T, class T2> void Stack<T, T2>::insert_subitem(T2 *value)
{
	bool inserted = false;
	if(head != nullptr)
	{
		for(auto i: *this)
		{
			if(i->size() < 5)
			{
				i->push(std::shared_ptr<T2>(value));
				inserted = true;
			}
		}
	}

	if(!inserted)
	{
		T *item = new T;
		item->push(std::shared_ptr<T2>(value));
		this->push(std::shared_ptr<T>(item));
	}
	std::cout << "Элемент добавлен" << std::endl;
}

template <class T, class T2> void Stack<T, T2>::remove_subitem(RemoveCriteria<T2> *criteria)
{
	for(auto i: *this)
	{
		T copy;
		while(!i->empty())
		{
			std::shared_ptr<T2> value = i->pop();
			if(!criteria->is_it(&*value))
				copy.push(std::move(value));
			else std::cout << "Удален: " << *value << std::endl;
		}

		while(!copy.empty())
			i->push(copy.pop());
	}
}

template <class T, class T2> std::ostream& operator<<(std::ostream &os, const Stack<T, T2> &stack)
{
	std::shared_ptr <StackItem<T>> item = stack.head;
	while(item != nullptr)
	{
		os << *item << std::endl;
		item = item->get_next();
	}

	return os;
}

template <class T, class T2> bool Stack<T, T2>::empty() { return head == nullptr; }
template <class T, class T2> Stack<T, T2>::~Stack() {}
