#include "sibling.h"
C_sibling::C_sibling():C_relation(n_sibling) {}
C_sibling::C_sibling(const C_id &id) : C_relation(n_sibling) { ID_index = id; }
C_sibling::C_sibling(const C_sibling &sib):C_relation(sib) {
	if (this != &sib) *this = sib;
}
C_sibling& C_sibling::operator=(const C_sibling &sib) {
	if (this == &sib) return *this;
	if (*this == sib) return *this;
	ID_index = sib.ID_index;
	ID_value = sib.ID_value;
	return *this;
}
bool C_sibling::operator==(const C_sibling &sib) {
	if (ID_index == sib.ID_index && ID_value == sib.ID_value) return true;
	return false;
}
bool C_sibling::operator!=(const C_sibling &sib) {
	if (ID_index != sib.ID_index && ID_value != sib.ID_value) return true;
	return false;
}
C_sibling::~C_sibling() {}
void C_sibling::m_get_id(C_id &id) { ID_value = id; }
C_id C_sibling::m_set_id() { return ID_index; }

