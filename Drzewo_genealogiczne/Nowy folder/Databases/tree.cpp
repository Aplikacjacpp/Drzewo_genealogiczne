#include "tree.h"
C_tree::C_tree():C_element() {}
C_tree::C_tree(const C_human &human):C_element(human) {}
C_tree::C_tree(const C_tree &tree):C_element(tree) { if (this != &tree) *this = tree; }
C_tree& C_tree::operator=(const C_tree &tree) {
	if (this == &tree) return *this;
	if (*this == tree) return *this;
	V_human = tree.V_human;
	return *this;
}
bool C_tree::operator==(const C_tree &tree) {
	if (V_human == tree.V_human) return true;
	return false;
}
bool C_tree::operator!=(const C_tree &tree) {
	if (V_human != tree.V_human) return true;
	return false;
}
C_tree::~C_tree() {}
void C_tree::m_get_human(C_human& human) { V_human.m_push_back(human); }
void C_tree::m_update_human(int value, C_human &human) { V_human.m_erase(value); V_human.m_insert(value, human); }
void C_tree::m_delete_human(int value) { V_human.m_erase(value); }
C_human C_tree::m_set_human() { return V_human[0]; }
C_human C_tree::m_set_human(int value) { return V_human[value]; }
C_human C_tree::m_set_human_index() { return m_set_Human(); }