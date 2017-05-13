#include "parent.h"
C_parent::C_parent():C_relation(n_parent){}
C_parent::C_parent(C_id &id) : C_relation(n_parent) { ID_index = id; }
C_parent::C_parent(const C_id &id) : C_relation(n_parent) { ID_index = id; }
C_parent::C_parent(const C_parent &parent):C_relation(parent) {
	if (this != &parent) *this = parent;
}
C_parent& C_parent::operator=(const C_parent &parent) {
	if (this == &parent) return *this;
	if (*this == parent) return *this;
	ID_index = parent.ID_index;
	ID_value = parent.ID_value;
	return *this;
}
bool C_parent::operator==(const C_parent &parent) {
	if (ID_index == parent.ID_index && ID_value == parent.ID_value) return true;
	return false;
}
bool C_parent::operator!=(const C_parent &parent) {
	if (ID_index != parent.ID_index && ID_value != parent.ID_value) return true;
	return false;
}
C_parent::~C_parent(){}
void C_parent::m_get_id(C_id &id) { ID_value = id; }
C_id C_parent::m_set_id() { return ID_index; }
int C_parent::m_set_variable() { return t_parent; }