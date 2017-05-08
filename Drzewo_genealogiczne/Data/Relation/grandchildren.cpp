#include "grandchildren.h"
C_grandchildren::C_grandchildren() {}
C_grandchildren::C_grandchildren(const C_grandchildren & grandchildren) {}
C_grandchildren& C_grandchildren::operator=(const C_grandchildren& grandchildren) {
	if (this == &grandchildren) return *this;
	if (*this == grandchildren) return *this;

	return *this;
}
bool C_grandchildren::operator==(const C_grandchildren& grandchildren) {
	if (true) return true;
	return false;
}
bool C_grandchildren::operator!=(const C_grandchildren& grandchildren) {
	if (true) return true;
	return false;
}
C_grandchildren::~C_grandchildren() {}