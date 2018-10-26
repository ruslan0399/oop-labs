#include "rectangle.hpp"

Rectangle::Rectangle() : Rectangle(0, 0) {} 
Rectangle::Rectangle(size_t a, size_t b) : side_a(a), side_b(b) {}

Rectangle::Rectangle(const Rectangle &orig)
{
	side_a = orig.side_a;
	side_b = orig.side_b;
}

double Rectangle::Square() { return side_a * side_b; }

bool Rectangle::operator==(const Rectangle &right)
{
	return this->side_a == right.side_a && this->side_b == right.side_b;
}

Rectangle& Rectangle::operator++()
{
	side_a++;
	side_b++;

	return *this;
}

Rectangle& Rectangle::operator=(const Rectangle &right)
{
	if(this == &right) return *this;

	side_a = right.side_a;
	side_b = right.side_b;

	return *this;
}

Rectangle operator+(const Rectangle &left, const Rectangle &right)
{
	return Rectangle(left.side_a + right.side_a, left.side_b + right.side_b);
}

std::ostream& operator<<(std::ostream &os, const Rectangle &rect)
{
	os << "a = " << rect.side_a << ", b = " << rect.side_b;
	return os;
}

std::istream& operator>>(std::istream &is, Rectangle &rect)
{
	std::cout << "Введите стороны прямоугольника:" << std::endl;
	is >> rect.side_a >> rect.side_b;

	return is;
}

Rectangle::~Rectangle() {}
