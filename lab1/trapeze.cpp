#include "trapeze.hpp"

Trapeze::Trapeze() : Trapeze(0, 0, 0) { std::cout << "Трапеция создана" << std::endl; }
Trapeze::Trapeze(size_t a, size_t b, size_t h) : side_a(a), side_b(b), side_h(h) {}

Trapeze::Trapeze(std::istream &is)
{
	std::cout << "Введите основания и высоту трапеции:" << std::endl;
	is >> side_a >> side_b >> side_h;
}

Trapeze::Trapeze(const Trapeze &orig)
{
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_h = orig.side_h;
}

double Trapeze::Square() { return (side_a + side_b) * side_h / 2.; }
void Trapeze::Print() { std::cout << "a = " << side_a << ", b = " << side_b << ", h = " << side_h << std::endl; }

Trapeze::~Trapeze() { std::cout << "Трапеция удалена" << std::endl; }
