#include "goverment_personaly.h"
C_goverment_personaly::C_goverment_personaly() {}
C_goverment_personaly::C_goverment_personaly(const C_goverment_personaly & goverment_personaly) {}
C_goverment_personaly& C_goverment_personaly::operator=(const C_goverment_personaly& goverment_personaly) {
	if (this == &goverment_personaly) return *this;
	if (*this == goverment_personaly) return *this;
	s_goverment_personaly = goverment_personaly.s_goverment_personaly;
	return *this;
}
bool C_goverment_personaly::operator==(const C_goverment_personaly& goverment_personaly) {
	if (s_goverment_personaly == goverment_personaly.s_goverment_personaly) return true;
	return false;
}
bool C_goverment_personaly::operator!=(const C_goverment_personaly& goverment_personaly) {
	if (s_goverment_personaly != goverment_personaly.s_goverment_personaly) return true;
	return false;
}
C_goverment_personaly::~C_goverment_personaly() {}
bool C_goverment_personaly::m_wchat_is() { if (this->s_goverment_personaly.m_size() >= 1 || this->s_goverment_personaly != '\0') return true; return false; }
void C_goverment_personaly::m_get_contens(N_striing &contens) { this->s_goverment_personaly = m_is_there_contens(contens); }
N_striing C_goverment_personaly::m_set_contens() { return this->s_goverment_personaly; }
N_striing C_goverment_personaly::m_is_there_contens(N_striing &Word) {
	int i, value = 0;
	int X;
	for (i = 1; i < Word.m_size(); i++)
	{
		X = (int)Word[i] - 48 + 10 * ((int)Word[i - 1] - 48);
		switch (X)
		{
		case t_first_name:
			value++; break;
		case t_last_name:
			value++; break;
		case t_gender:
			value++; break;
		case t_id_data:
			value++; break;
		default:
			break;
		}
	}
	if (value == 4) return Word;
	return "\0";
}