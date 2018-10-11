#ifndef TRAPEZE_HPP
#define TRAPEZE_HPP

#include <iostream>
#include "figure.hpp"

class Trapeze: public Figure
{
	public:
		Trapeze();
		Trapeze(std::istream &is);
		Trapeze(size_t a, size_t b, size_t h);
		Trapeze(const Trapeze &orig);

		double Square() override;
		void Print() override;

		virtual ~Trapeze();
	private:
		size_t side_a, side_b, side_h;
};

#endif
