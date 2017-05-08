#include "grandparents.h"
C_grandparents::C_grandparents() {}
C_grandparents::C_grandparents(const C_grandparents & grandparents) {}
C_grandparents& C_grandparents::operator=(const C_grandparents& grandparents) {
	if (this == &grandparents) return *this;
	if (*this == grandparents) return *this;

	return *this;
}
bool C_grandparents::operator==(const C_grandparents& grandparents) {
	if (true) return true;
	return false;
}
bool C_grandparents::operator!=(const C_grandparents& grandparents) {
	if (true) return true;
	return false;
}
C_grandparents::~C_grandparents() {}
