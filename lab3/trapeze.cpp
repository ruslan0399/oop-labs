#include "trapeze.hpp"

Trapeze::Trapeze() : Trapeze(0, 0, 0) {}
Trapeze::Trapeze(size_t a, size_t b, size_t h) : side_a(a), side_b(b), side_h(h) {}

Trapeze::Trapeze(const Trapeze &orig)
{
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_h = orig.side_h;
}

double Trapeze::Square() { return (side_a + side_b) * side_h / 2.; }

bool Trapeze::operator==(const Trapeze &right)
{
	return this->side_a == right.side_a && this->side_b == right.side_b && this->side_h == right.side_h;
}

Trapeze& Trapeze::operator++()
{
	side_a++;
	side_b++;
	side_h++;

	return *this;
}

Trapeze& Trapeze::operator=(const Trapeze &right)
{
	if(this == &right) return *this;

	side_a = right.side_a;
	side_b = right.side_b;
	side_h = right.side_h;

	return *this;
}

Trapeze operator+(const Trapeze &left, const Trapeze &right)
{
	return Trapeze(left.side_a + right.side_a, left.side_b + right.side_b, left.side_h + right.side_h);
}

std::ostream& operator<<(std::ostream &os, const Trapeze &trap)
{
	os << "a = " << trap.side_a << ", b = " << trap.side_b << ", h = " << trap.side_h;
	return os;
}

std::istream& operator>>(std::istream &is, Trapeze &trap)
{
	std::cout << "Введите основания и высоту трапеции:" << std::endl;
	is >> trap.side_a >> trap.side_b >> trap.side_h;

	return is;
}

Trapeze::~Trapeze() {}
