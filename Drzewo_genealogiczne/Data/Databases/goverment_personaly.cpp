#include "goverment_personaly.h"
C_goverment_personaly::C_goverment_personaly() {}
C_goverment_personaly::C_goverment_personaly(const C_goverment_personaly & goverment_personaly) {}
C_goverment_personaly& C_goverment_personaly::operator=(const C_goverment_personaly& goverment_personaly) {
	if (this == &goverment_personaly) return *this;
	if (*this == goverment_personaly) return *this;
	s_goverment_personaly = goverment_personaly.s_goverment_personaly;
	i_value_id = goverment_personaly.i_value_id;
	return *this;
}
bool C_goverment_personaly::operator==(const C_goverment_personaly& goverment_personaly) {
	if (s_goverment_personaly == goverment_personaly.s_goverment_personaly&&
		i_value_id == goverment_personaly.i_value_id) return true;
	return false;
}
bool C_goverment_personaly::operator!=(const C_goverment_personaly& goverment_personaly) {
	if (s_goverment_personaly != goverment_personaly.s_goverment_personaly&&
		i_value_id != goverment_personaly.i_value_id) return true;
	return false;
}
C_goverment_personaly::~C_goverment_personaly() {}
bool C_goverment_personaly::m_wchat_is() { 
	if (this->s_goverment_personaly.m_size() >= 1 || this->s_goverment_personaly != '\0')
		return true;
	return false; 
}
void C_goverment_personaly::m_get_contens(N_striing &contens) { 
	this->s_goverment_personaly = m_is_there_contens(contens);
	i_value_id = m_id_value();
}
N_striing C_goverment_personaly::m_set_contens(void) { return s_goverment_personaly; }
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
	return "";
}
int C_goverment_personaly::m_id_value() {
	int i,j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_personaly.m_size(); i++) {
		 data[0] = s_goverment_personaly[i - 1];
		data[1] = s_goverment_personaly[i];
		if (n_id_data == data)
		{
			for (j = i; j < s_goverment_personaly.m_size(); j++)
			{
				if (s_goverment_personaly[j] >= 0 && s_goverment_personaly[j] <= 9)
				{
					str.m_push_back(s_goverment_personaly[j]);
				}
				else {
					delete[] data;
					return str.m_atoi(0, str.m_size() - 1);
				}
			}
		}
	}
	delete[] data;
	return 0;
} //trzeba przetestowac!!
int C_goverment_personaly::m_set_value_id(){
	return i_value_id;
}
C_first_name C_goverment_personaly::m_set_value_first_name() {
	C_first_name First;
	int i, j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_personaly.m_size(); i++) {
		data[0] = s_goverment_personaly[i - 1];
		data[1] = s_goverment_personaly[i];
		if (n_first_name == data)
		{
			for (j = i; j < s_goverment_personaly.m_size(); j++)
			{
				if (!(s_goverment_personaly[j+1] >= 0&&s_goverment_personaly[j+1] <=9))
				{
					str.m_push_back(s_goverment_personaly[j]);
				}
				else {
					delete[] data;
					First.m_get_contens(str);
					return First;
				}
			}
		}
	}
	delete[] data;
	return First;
} //przetestowac czy dziala
C_last_name C_goverment_personaly::m_set_value_last_name() {
	C_last_name Last;
	int i, j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_personaly.m_size(); i++) {
		data[0] = s_goverment_personaly[i - 1];
		data[1] = s_goverment_personaly[i];
		if (n_last_name == data)
		{
			for (j = i; j < s_goverment_personaly.m_size(); j++)
			{
				if (!(s_goverment_personaly[j + 1] >= 0 && s_goverment_personaly[j + 1] <= 9))
				{
					str.m_push_back(s_goverment_personaly[j]);
				}
				else {
					delete[] data;
					Last.m_get_contens(str);
					return Last;
				}
			}
		}
	}
	delete[] data;
	return Last;
} //przetestowac czy dziala
C_gender C_goverment_personaly::m_set_value_gender() {
	C_gender Gender;
	int i, j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_personaly.m_size(); i++) {
		data[0] = s_goverment_personaly[i - 1];
		data[1] = s_goverment_personaly[i];
		if (n_gender == data)
		{
			for (j = i; j < s_goverment_personaly.m_size(); j++)
			{
				if (!(s_goverment_personaly[j + 1] >= 0 && s_goverment_personaly[j + 1] <= 9))
				{
					str.m_push_back(s_goverment_personaly[j]);
				}
				else {
					delete[] data;
					Gender.m_get_contens(str);
					return Gender;
				}
			}
		}
	}
	delete[] data;
	return Gender;
} //przetestowac czy dziala