#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "figure.hpp"

class Rectangle: public Figure
{
	public:
		Rectangle();
		Rectangle(size_t a, size_t b);
		Rectangle(const Rectangle &orig);

		double Square() override;

		bool operator==(const Rectangle &right);
		Rectangle& operator++();
		Rectangle& operator=(const Rectangle &right);
		friend Rectangle operator+(const Rectangle &left, const Rectangle &right);
	
		friend std::ostream& operator<<(std::ostream &os, const Rectangle &rect);
		friend std::istream& operator>>(std::istream &is, Rectangle &rect);

		virtual ~Rectangle();
	private:
		size_t side_a, side_b;
};

#endif
