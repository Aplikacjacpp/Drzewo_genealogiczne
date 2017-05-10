#include "last_name.h"

C_last_name::C_last_name():C_data(n_last_name){
	s_data_last_name = "";
}
C_last_name::C_last_name(N_striing &last):C_data(n_last_name) {
	s_data_last_name = m_is_there_contens(last);
}
C_last_name::C_last_name(const C_last_name &last_name):C_data(last_name) {
	if (this != &last_name) *this = last_name;
}
C_last_name& C_last_name::operator=(const C_last_name &last_name) {
	if (*this == last_name) return *this;
	s_data_last_name = last_name.s_data_last_name;
	return *this;
}
bool C_last_name::operator==(const C_last_name &last_name) {
	if (s_data_last_name == last_name.s_data_last_name) return true;
	return false;
}
bool C_last_name::operator!=(const C_last_name &last_name) {
	if (s_data_last_name != last_name.s_data_last_name) return true;
	return false;
}


bool operator> (const C_last_name &last, const C_last_name &l1)
{
	return last > l1;
}

bool operator< (const C_last_name &last, const C_last_name &l1)
{
	return last < l1;
}

C_last_name::~C_last_name() {}
bool C_last_name::m_wchat_is() { if (this->s_data_last_name.m_size() >= 1) return true; return false; }
void C_last_name::m_get_contens(N_striing &contens) { this->s_data_last_name = m_is_there_contens(contens); }
N_striing C_last_name::m_set_contens() { return this->s_data_last_name; }
N_striing C_last_name::m_is_there_contens(N_striing &Word) { 
	int y = 0;
	setlocale(LC_ALL, "");
	char TCh[18] = {'¹', 'æ', 'ê', '³', 'ñ', 'ó', 'œ', 'Ÿ', '¿', '¥', 'Æ', 'Ê', '£', 'Ñ', 'Ó', 'Œ', '', '¯' };
	do {
		if ((Word[y] >= 'A' && Word[y] <= 'Z') || (Word[y] >= 'a' && Word[y] <= 'z') || (Word[y] >= TCh[0] && Word[y] <= TCh[18])) y++;
		else
			return "";
	} while (y != Word.m_size());
	return Word;
}


std::ostream& operator<<(std::ostream& is, C_last_name &last)
{
	is << "Nazwisko: " << last.m_set_contens();
	return is;
}