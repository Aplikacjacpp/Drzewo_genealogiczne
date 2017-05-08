#include "element.h"
C_element::C_element() {}
C_element::C_element(const C_element &element) { if (this != &element) *this = element; }
C_element& C_element::operator=(const C_element &element) {
	if (this != &element) return *this;
	if (*this == element) return *this;
	V_children = element.V_children;
	V_parent = element.V_parent;
	V_sibling = element.V_sibling;
	return *this;
}
bool C_element::operator==(const C_element &element) {
	if (V_children == element.V_children&&V_parent==element.V_parent&&V_sibling==element.V_sibling) return true;
	return false;
}
bool C_element::operator!=(const C_element &element) {
	if (V_children != element.V_children&&V_parent != element.V_parent&&V_sibling != element.V_sibling) return true;
	return false;
}
C_element::~C_element() {}
C_element::C_element(const C_human& human) { Human = human; }
void C_element::m_get_children(C_children &children) { V_children.m_push_back(children); }
void C_element::m_get_parent(C_parent &parent) { V_parent.m_push_back(parent); }
void C_element::m_get_sibling(C_sibling &sibling) { V_sibling.m_push_back(sibling); }
void C_element::m_update_children(int value, C_children &children) { V_children.m_erase(value); V_children.m_insert(value, children); }
void C_element::m_update_parent(int value, C_parent &parent) { V_parent.m_erase(value); V_parent.m_insert(value, parent); }
void C_element::m_update_sibling(int value, C_sibling &sibling) { V_sibling.m_erase(value); V_sibling.m_insert(value, sibling); }
void C_element::m_update_human(const C_human &human) { Human = human; }
C_human C_element::m_set_Human() { return Human; }
C_children C_element::m_set_children() { return V_children[0]; }
C_parent C_element::m_set_parent() { return V_parent[0]; }
C_sibling C_element::m_set_sibling() { return V_sibling[0]; }
C_children C_element::m_set_children(int value) { return V_children[value]; }
C_parent C_element::m_set_parent(int value) { return V_parent[value]; }
C_sibling C_element::m_set_sibling(int value) { return V_sibling[value]; }
C_element& C_element::m_clean() { C_element E; return E; }
void C_element::m_clean_children() { V_children.m_close(); }
void C_element::m_clean_parent() { V_parent.m_close(); }
void C_element::m_clean_sibling() { V_sibling.m_close(); }
void C_element::m_delete_children() { V_children.m_pop_front(); }
void C_element::m_delete_parent() { V_parent.m_pop_front(); }
void C_element::m_delete_sibling() { V_sibling.m_pop_front(); }
void C_element::m_delete_children(int value) { V_children.m_erase(value); }
void C_element::m_delete_parent(int value) { V_parent.m_erase(value); }
void C_element::m_delete_sibling(int value) { V_sibling.m_erase(value); }

