#include "goverment_date.h"
C_goverment_date::C_goverment_date() {}
C_goverment_date::C_goverment_date(const C_goverment_date & goverment_date) {}
C_goverment_date& C_goverment_date::operator=(const C_goverment_date& goverment_date) {
	if (this == &goverment_date) return *this;
	if (*this == goverment_date) return *this;

	return *this;
}
bool C_goverment_date::operator==(const C_goverment_date& goverment_date) {
	if (true) return true;
	return false;
}
bool C_goverment_date::operator!=(const C_goverment_date& goverment_date) {
	if (true) return true;
	return false;
}
C_goverment_date::~C_goverment_date() {}
bool C_goverment_date::m_wchat_is() { if (this->s_goverment_data.m_size() >= 1 ||this->s_goverment_data!='\0') return true; return false; }
void C_goverment_date::m_get_contens(N_striing &contens) { this->s_goverment_data = m_is_there_contens(contens); }
N_striing C_goverment_date::m_set_contens() { return this->s_goverment_data; }
N_striing C_goverment_date::m_is_there_contens(N_striing &Word) {
	int i,value=0;
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