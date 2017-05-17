#include "goverment_date.h"
C_goverment_date::C_goverment_date() {}
C_goverment_date::C_goverment_date(const C_goverment_date & goverment_date) {}
C_goverment_date& C_goverment_date::operator=(const C_goverment_date& goverment_date) {
	if (this == &goverment_date) return *this;
	if (*this == goverment_date) return *this;
	s_goverment_data = goverment_date.s_goverment_data;
	i_value_id = goverment_date.i_value_id;
	return *this;
}
bool C_goverment_date::operator==(const C_goverment_date& goverment_date) {
	if (s_goverment_data == goverment_date.s_goverment_data&&
		i_value_id == goverment_date.i_value_id) return true;
	return false;
}
bool C_goverment_date::operator!=(const C_goverment_date& goverment_date) {
	if (s_goverment_data != goverment_date.s_goverment_data&&
		i_value_id != goverment_date.i_value_id) return true;
	return false;
}
C_goverment_date::~C_goverment_date() {}
bool C_goverment_date::m_wchat_is() {
	if (this->s_goverment_data.m_size() >= 1 ||this->s_goverment_data!='\0')
		return true;
	return false;
}
void C_goverment_date::m_get_contens(N_striing &contens) { 
	this->s_goverment_data = m_is_there_contens(contens);
	i_value_id = m_id_value();
}
N_striing C_goverment_date::m_set_contens() { return this->s_goverment_data; }
N_striing C_goverment_date::m_is_there_contens(N_striing &Word) {
	int i,value=0;
	int X;
	for (i = 1; i < Word.m_size(); i++)
	{
		X = (int)Word[i] - 48 + 10 * ((int)Word[i - 1] - 48);
		switch (X)
		{
		case t_day:
			value++; break;
		case t_month:
			value++; break;
		case t_year:
			value++; break;
		default:
			break;
		}
	}
	if (value == 3) return Word;
	return "";
}
int C_goverment_date::m_id_value() {
	int i,j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		 data[0] = s_goverment_data[i - 1];
		data[1] = s_goverment_data[i];
		if (n_id_data == data)
		{
			for (j = i; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= 0 && s_goverment_data[j] <= 9)
				{
					str.m_push_back(s_goverment_data[j]);
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
int C_goverment_date::m_set_value_id() {
	return i_value_id;
}
C_day C_goverment_date::m_set_value_day() {
	C_day day;
	int i, j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		data[0] = s_goverment_data[i - 1];
		data[1] = s_goverment_data[i];
		if (n_day == data)
		{
			for (j = i; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= 0 && s_goverment_data[j] <= 9)
				{
					str.m_push_back(s_goverment_data[j]);
				}
				else {
					delete[] data;
					day.m_get_contens(str);
					return day;
				}
			}
		}
	}
	delete[] data;
	return day;
}; //przetestowac czy dziala
C_month C_goverment_date::m_set_value_month() {
	C_month month;
	int i, j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		data[0] = s_goverment_data[i - 1];
		data[1] = s_goverment_data[i];
		if (n_month == data)
		{
			for (j = i; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= 0 && s_goverment_data[j] <= 9)
				{
					str.m_push_back(s_goverment_data[j]);
				}
				else {
					delete[] data;
					month.m_get_contens(str);
					return month;
				}
			}
		}
	}
	delete[] data;
	return month;
}; //przetestowac czy dziala
C_year C_goverment_date::m_set_value_year() {
	C_year year;
	int i, j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		data[0] = s_goverment_data[i - 1];
		data[1] = s_goverment_data[i];
		if (n_year == data)
		{
			for (j = i; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= 0 && s_goverment_data[j] <= 9)
				{
					str.m_push_back(s_goverment_data[j]);
				}
				else {
					delete[] data;
					year.m_get_contens(str);
					return year;
				}
			}
		}
	}
	delete[] data;
	return year;
}; //przetestowac czy dziala