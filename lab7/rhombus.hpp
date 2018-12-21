#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include <iostream>
#include "figure.hpp"

class Rhombus: public Figure
{
	public:
		Rhombus();
		Rhombus(size_t a, size_t h);
		Rhombus(const Rhombus &orig);

		double Square() override;

		bool operator==(const Rhombus &right);
		Rhombus& operator++();
		Rhombus& operator=(const Rhombus &right);
		friend Rhombus operator+(const Rhombus &left, const Rhombus &right);
	
		void print(std::ostream &os) const override;
		friend std::istream& operator>>(std::istream &is, Rhombus &rhomb);
		
		virtual ~Rhombus();
	private:
		size_t side_a, side_h;
};

#endif
