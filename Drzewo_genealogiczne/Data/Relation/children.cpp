#include "children.h"
C_children::C_children():C_relation() {}
C_children::C_children(const C_id &id) : C_relation() { ID_index = id; }
C_children::C_children(const C_children &children):C_relation(children) {
	if (this != &children) *this = children;
}
C_children& C_children::operator=(const C_children &children){
	if (this == &children) return *this;
	if (*this == children) return *this;
	ID_index = children.ID_index;
	ID_value = children.ID_value;
	return *this;
}
bool C_children::operator==(const C_children &children) {
	if (ID_index == children.ID_index && ID_value == children.ID_value) return true;
	return false;
}
bool C_children::operator!=(const C_children &children) {
	if (ID_index != children.ID_index && ID_value != children.ID_value) return true;
	return false;
}
C_children::~C_children() {}
void C_children::m_get_id(C_id &id) { ID_value = id; }
C_id C_children::m_set_id() { return ID_index; }


