#include "goverment_relation.h"
C_goverment_relation::C_goverment_relation() {}
C_goverment_relation::C_goverment_relation(const C_goverment_relation & goverment_relation) {}
C_goverment_relation& C_goverment_relation::operator=(const C_goverment_relation& goverment_relation) {
	if (this == &goverment_relation) return *this;
	if (*this == goverment_relation) return *this;
	s_goverment_relation = goverment_relation.s_goverment_relation;
	return *this;
}
bool C_goverment_relation::operator==(const C_goverment_relation& goverment_relation) {
	if (s_goverment_relation == goverment_relation.s_goverment_relation) return true;
	return false;
}
bool C_goverment_relation::operator!=(const C_goverment_relation& goverment_relation) {
	if (s_goverment_relation != goverment_relation.s_goverment_relation) return true;
	return false;
}
C_goverment_relation::~C_goverment_relation() {}
bool C_goverment_relation::m_wchat_is() { if (this->s_goverment_relation.m_size() >= 1 || this->s_goverment_relation != '\0') return true; return false; }
void C_goverment_relation::m_get_contens(N_striing &contens) { this->s_goverment_relation = m_is_there_contens(contens); }
N_striing C_goverment_relation::m_set_contens() { return this->s_goverment_relation; }
N_striing C_goverment_relation::m_is_there_contens(N_striing &Word) {
	int i, value = 0,X;
	for (i = 0; i < Word.m_size(); i++)
	{
		X = (int)Word[i] - 48 + 10 * ((int)Word[i - 1] - 48);
		switch (X)
		{
		case t_children:
			value++; break;
		case t_grandchildren:
			value++; break;
		case t_grandparent:
			value++; break;
		case t_parent:
			value++; break;
		case t_sibling:
			value++; break;
		default:
			break;
		}
	}
	if (value == 5) return Word;
	return "";
}
int C_goverment_relation::m_id_value() {
	int i, j;
	N_striing str;
	char *relation = new char[2];
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation[0] = s_goverment_relation[i - 1];
		relation[1] = s_goverment_relation[i];
		if (n_id_relation == relation)
		{
			for (j = i; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= 0 && s_goverment_relation[j] <= 9){
					str.m_push_back(s_goverment_relation[j]);
				}
				else {
					delete[] relation;
					return str.m_atoi(0, str.m_size() - 1);
				}
			}
		}
	}
	delete[] relation;
	return 0;
} //trzeba przetestowac!!
int C_goverment_relation::m_set_value_id() {
	return i_value_id;
}