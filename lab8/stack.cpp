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

template <class T> void Stack<T>::sort()
{
	if(size() > 1)
	{
		std::shared_ptr<T> middle = pop();
		Stack<T> left, right;

		while(!empty())
		{
			std::shared_ptr<T> item = pop();
			if(item->Square() < middle->Square()) left.push(std::move(item));
			else right.push(std::move(item));
		}

		left.sort();
		right.sort();

		while(!left.empty()) push(left.pop_last());
		push(std::move(middle));
		while(!right.empty()) push(right.pop_last());
	}
}

template <class T> void Stack<T>::parallel_sort()
{
	if(size() > 1)
	{
		std::shared_ptr<T> middle = pop_last();
		Stack<T> left, right;

		while(!empty())
		{
			std::shared_ptr<T> item = pop_last();
			if(item->Square() < middle->Square()) left.push(std::move(item));
			else right.push(std::move(item));
		}

		std::future<void> left_res = left.sort_in_background();
		std::future<void> right_res = right.sort_in_background();

		left_res.get();
		while(!left.empty()) push(left.pop_last());
		push(std::move(middle));
		right_res.get();
		while(!right.empty()) push(right.pop_last());
	}
}

template <class T> std::future<void> Stack<T>::sort_in_background()
{
	std::packaged_task<void(void)> task(std::bind(std::mem_fn(&Stack<T>::parallel_sort), this));
	std::future<void> res(task.get_future());
	std::thread th(std::move(task));
	th.detach();
	return res;
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
