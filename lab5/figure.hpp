#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>

class Figure
{
	public:
		virtual void print(std::ostream &os) const = 0;
		friend std::ostream &operator<<(std::ostream &os, const Figure &figure)
		{
			figure.print(os);
			return os;
		}

		virtual double Square() = 0;
		virtual ~Figure() {};
};

#endif
