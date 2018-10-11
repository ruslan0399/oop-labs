#include "rhombus.hpp"

Rhombus::Rhombus() : Rhombus(0, 0) { std::cout << "Ромб создан" << std::endl; }
Rhombus::Rhombus(size_t a, size_t h) : side_a(a), side_h(h) {}

Rhombus::Rhombus(std::istream &is)
{
	std::cout << "Введите основание и высоту ромба:" << std::endl;
	is >> side_a >> side_h;
}

Rhombus::Rhombus(const Rhombus &orig)
{
	side_a = orig.side_a;
	side_h = orig.side_h;
}

double Rhombus::Square() { return side_a * side_h; }
void Rhombus::Print() { std::cout << "a = " << side_a << ", h = " << side_h << std::endl; }

Rhombus::~Rhombus() { std::cout << "Ромб удален" << std::endl; }
