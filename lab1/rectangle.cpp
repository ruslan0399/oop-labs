#include "rectangle.hpp"

Rectangle::Rectangle() : Rectangle(0, 0) { std::cout << "Прямоугольник создан" << std::endl; }
Rectangle::Rectangle(size_t a, size_t b) : side_a(a), side_b(b) {}

Rectangle::Rectangle(std::istream &is)
{
	std::cout << "Введите стороны прямоугольника:" << std::endl;
	is >> side_a >> side_b;
}

Rectangle::Rectangle(const Rectangle &orig)
{
	side_a = orig.side_a;
	side_b = orig.side_b;
}

double Rectangle::Square() { return side_a * side_b; }
void Rectangle::Print() { std::cout << "a = " << side_a << ", b = " << side_b << std::endl; }

Rectangle::~Rectangle() { std::cout << "Прямоугольник удален" << std::endl; }
