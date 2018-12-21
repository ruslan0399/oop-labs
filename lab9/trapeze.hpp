#ifndef TRAPEZE_HPP
#define TRAPEZE_HPP

#include <iostream>
#include "figure.hpp"

class Trapeze: public Figure
{
	public:
		Trapeze();
		Trapeze(size_t a, size_t b, size_t h);
		Trapeze(const Trapeze &orig);

		double Square() override;

		bool operator==(const Trapeze &right);
		Trapeze& operator++();
		Trapeze& operator=(const Trapeze &right);
		friend Trapeze operator+(const Trapeze &left, const Trapeze &right);
	
		void print(std::ostream &os) const override;
		friend std::istream& operator>>(std::istream &is, Trapeze &trap);

		virtual ~Trapeze();
	private:
		size_t side_a, side_b, side_h;
};

#endif
