#include "grandchildren.h"
C_grandchildren::C_grandchildren():C_relation(n_grandchildren) {}
C_grandchildren::C_grandchildren(const C_grandchildren & grandchildren):C_relation() {}
C_grandchildren& C_grandchildren::operator=(const C_grandchildren& grandchildren) {
	if (this == &grandchildren) return *this;
	if (*this == grandchildren) return *this;
	ID_index = grandchildren.ID_index;
	ID_value = grandchildren.ID_value;
	return *this;
}
bool C_grandchildren::operator==(const C_grandchildren& grandchildren) {
	if (ID_index == grandchildren.ID_index&&ID_value == grandchildren.ID_value) return true;
	return false;
}
bool C_grandchildren::operator!=(const C_grandchildren& grandchildren) {
	if (ID_index == grandchildren.ID_index&&ID_value != grandchildren.ID_value) return true;
	return false;
}
C_grandchildren::~C_grandchildren() {}
void C_grandchildren::m_get_id(C_id &id) { ID_value = id; }
C_id C_grandchildren::m_set_id() { return ID_index; }
int C_grandchildren::m_set_variable() { return t_grandchildren; }