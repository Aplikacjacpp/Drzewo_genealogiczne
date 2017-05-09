#include "goverment_relation.h"
C_goverment_relation::C_goverment_relation() {}
C_goverment_relation::C_goverment_relation(const C_goverment_relation & goverment_relation) {}
C_goverment_relation& C_goverment_relation::operator=(const C_goverment_relation& goverment_relation) {
	if (this == &goverment_relation) return *this;
	if (*this == goverment_relation) return *this;

	return *this;
}
bool C_goverment_relation::operator==(const C_goverment_relation& goverment_relation) {
	if (true) return true;
	return false;
}
bool C_goverment_relation::operator!=(const C_goverment_relation& goverment_relation) {
	if (true) return true;
	return false;
}
C_goverment_relation::~C_goverment_relation() {}
bool C_goverment_relation::m_wchat_is() { if (this->s_goverment_relation.m_size() >= 1 || this->s_goverment_relation != '\0') return true; return false; }
void C_goverment_relation::m_get_contens(N_striing &contens) { this->s_goverment_relation = m_is_there_contens(contens); }
N_striing C_goverment_relation::m_set_contens() { return this->s_goverment_relation; }
N_striing C_goverment_relation::m_is_there_contens(N_striing &Word) {
	int i, value = 0;
	for (i = 0; i < Word.m_size(); i++)
	{
		switch (Word[i])
		{
		case '$':
			value++; break;
		case '&':
			value++; break;
		case '!':
			value++; break;
		default:
			break;
		}
	}
	if (value == 3) return Word;
	return "\0";
}