#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include <iostream>
#include "figure.hpp"

class Rhombus: public Figure
{
	public:
		Rhombus();
		Rhombus(std::istream &is);
		Rhombus(size_t a, size_t h);
		Rhombus(const Rhombus &orig);

		double Square() override;
		void Print() override;

		virtual ~Rhombus();
	private:
		size_t side_a, side_h;
};

#endif
