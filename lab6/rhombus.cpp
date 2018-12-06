#include "rhombus.hpp"

Rhombus::Rhombus() : Rhombus(0, 0) {}
Rhombus::Rhombus(size_t a, size_t h) : side_a(a), side_h(h) {}

Rhombus::Rhombus(const Rhombus &orig)
{
	side_a = orig.side_a;
	side_h = orig.side_h;
}

double Rhombus::Square() { return side_a * side_h; }

bool Rhombus::operator==(const Rhombus &right)
{
	return this->side_a == right.side_a && this->side_h == right.side_h;
}

Rhombus& Rhombus::operator++()
{
	side_a++;
	side_h++;

	return *this;
}

Rhombus& Rhombus::operator=(const Rhombus &right)
{
	if(this == &right) return *this;

	side_a = right.side_a;
	side_h = right.side_h;

	return *this;
}

Rhombus operator+(const Rhombus &left, const Rhombus &right)
{
	return Rhombus(left.side_a + right.side_a, left.side_h + right.side_h);
}

void Rhombus::print(std::ostream &os) const
{
	os << "Ромб: a = " << side_a << ", h = " << side_h;
}

std::istream& operator>>(std::istream &is, Rhombus &rhomb)
{
	std::cout << "Введите сторону и высоту ромба:" << std::endl;
	is >> rhomb.side_a >> rhomb.side_h;

	return is;
}

Rhombus::~Rhombus() {}
