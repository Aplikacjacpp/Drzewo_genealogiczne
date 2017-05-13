#include "grandparents.h"
C_grandparents::C_grandparents():C_relation(n_grandparent) {}
C_grandparents::C_grandparents(const C_grandparents & grandparents):C_relation() {}
C_grandparents& C_grandparents::operator=(const C_grandparents& grandparents) {
	if (this == &grandparents) return *this;
	if (*this == grandparents) return *this;
	ID_index = grandparents.ID_index;
	ID_value = grandparents.ID_value;
	return *this;
}
bool C_grandparents::operator==(const C_grandparents& grandparents) {
	if (ID_index == grandparents.ID_index&&ID_value == grandparents.ID_value) return true;
	return false;
}
bool C_grandparents::operator!=(const C_grandparents& grandparents) {
	if (ID_index != grandparents.ID_index&&ID_value != grandparents.ID_value) return true;
	return false;
}
C_grandparents::~C_grandparents() {}
void C_grandparents::m_get_id(C_id &id) { ID_value = id; }
C_id C_grandparents::m_set_id() { return ID_index; }
int C_grandparents::m_set_variable() { return t_grandparent; }