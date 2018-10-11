#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "figure.hpp"

class Rectangle: public Figure
{
	public:
		Rectangle();
		Rectangle(std::istream &is);
		Rectangle(size_t a, size_t b);
		Rectangle(const Rectangle &orig);

		double Square() override;
		void Print() override;

		virtual ~Rectangle();
	private:
		size_t side_a, side_b;
};

#endif
