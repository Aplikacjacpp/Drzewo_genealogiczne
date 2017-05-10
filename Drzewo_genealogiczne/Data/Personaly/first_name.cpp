#include "first_name.h"
C_first_name::C_first_name():C_data("$0"){
	s_data_first_name = "";
}
C_first_name::C_first_name(N_striing &first):C_data("$0") {
	s_data_first_name = m_is_there_contens(first);
}
C_first_name::C_first_name(const C_first_name &first_name):C_data(first_name) {
	if (this != &first_name) *this = first_name;
}
C_first_name& C_first_name::operator=(const C_first_name &first_name) {
	if (*this == first_name) return *this;
	s_data_first_name = first_name.s_data_first_name;
	return *this;
}
bool C_first_name::operator==(const C_first_name &first_name) {
	if (s_data_first_name == first_name.s_data_first_name) return true;
	return false;
}
bool C_first_name::operator!=(const C_first_name &first_name) {
	if (s_data_first_name != first_name.s_data_first_name) return true; 
	return false;
}

bool operator> (const C_first_name &first, const C_first_name &f1)
{
	return first > f1;
}

bool operator< (const C_first_name &first, const C_first_name &f1)
{
	return first < f1;
}

C_first_name::~C_first_name() {};
bool C_first_name::m_wchat_is() { if (this->s_data_first_name.m_size() >= 1) return true; return false; }
void C_first_name::m_get_contens(N_striing &contens) { this->s_data_first_name = m_is_there_contens(contens); }
N_striing C_first_name::m_set_contens() { return this->s_data_first_name; }
N_striing C_first_name::m_is_there_contens(N_striing &Word) {
	int y=0;
	do {
		if ((Word[y] >= 'A' && Word[y] <= 'Z') || (Word[y] >= 'a' && Word[y] <= 'z')) y++;
		else
			return "";
	} while (y != Word.m_size());
	return Word;
}

std::ostream& operator<<(std::ostream& is, C_first_name &first)
{
	is << "Imie: " << first.m_set_contens();
	return is;
}