#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <class node, class T>
class Iterator
{
	public:
		Iterator(std::shared_ptr<node> n): node_ptr{n} {}

		std::shared_ptr<T> operator*()
		{
			return node_ptr->get_figure();
		}

		std::shared_ptr<T> operator->()
		{
			return node_ptr->get_figure();
		}

		void operator++()
		{
			node_ptr = node_ptr->get_next();
		}

		Iterator operator++(int)
		{
			Iterator iter(*this);
			++(*this);
			return iter;
		}

		bool operator==(Iterator const &iter)
		{
			return node_ptr == iter.node_ptr;
		}

		bool operator!=(Iterator const &iter)
		{
			return !(*this == iter);
		}

	private:
		std::shared_ptr<node> node_ptr;
};

#endif
