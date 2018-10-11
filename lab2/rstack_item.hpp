#ifndef RSTACKITEM_HPP
#define RSTACKITEM_HPP

#include "rectangle.hpp"

class RStackItem
{
	public:
		RStackItem(const Rectangle &rect);
		RStackItem(const RStackItem &orig);
		friend std::ostream& operator<<(std::ostream &os, const RStackItem &item);

		RStackItem *set_next(RStackItem *next);
		RStackItem *get_next();
		Rectangle get_rectangle() const;

		virtual ~RStackItem();
	private:
		Rectangle rectangle;
		RStackItem *next;
};

#endif
