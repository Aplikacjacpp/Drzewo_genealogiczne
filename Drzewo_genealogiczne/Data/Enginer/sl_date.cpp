#include "sl_date.h"
C_sl_date::C_sl_date():C_save_load() {}
C_sl_date::C_sl_date(const C_sl_date & sl_date):C_save_load(sl_date) {
	if (this != &sl_date) *this = sl_date;
}
C_sl_date& C_sl_date::operator=(const C_sl_date& sl_date) {
	if (this == &sl_date) return *this;
	if (*this == sl_date) return *this;
	V_goverment_date = sl_date.V_goverment_date;
	return *this;
}
bool C_sl_date::operator==(const C_sl_date& sl_date) {
	if (V_goverment_date==sl_date.V_goverment_date) return true;
	return false;
}
bool C_sl_date::operator!=(const C_sl_date& sl_date) {
	if (V_goverment_date != sl_date.V_goverment_date) return true;
	return false;
}
C_sl_date::~C_sl_date() {}
void C_sl_date::m_file_date(bool what) {
	N_striing s_data;
	int i,i_start, i_stop;
	if (what)
	{
		N_striing s_inline;
		C_goverment_date Gover;
		std::ifstream File;
		File.open(f_save_date);
		if (File.good())
		{
			do{
				s_inline.m_getline(File); //nie wiem czy bedzie dzialac
				if (s_inline == f_end_file) break;
				s_data += s_inline;
				s_inline.m_clear();
			} while (1);
			File.close();
		}
		s_data = m_cypher_on(s_data);
		i_start = 0;
		for (i = 0; i < s_data.m_size(); i++)
		{
			if (s_data[i] == '\n')
			{
				i_stop = i - 1;
				Gover.m_get_contens(s_data.m_cut(i_start, i_stop));
				V_goverment_date.m_push_back(Gover);
				i_start = i_stop;
			}
		}
	}
	else
	{
		s_data.m_clear();
		std::ofstream File;
		File.open(f_save_date);
		if (File.good())
		{
			for (i = 0; i < V_goverment_date.m_size(); i++)
			{
				s_data+=V_goverment_date[i].m_set_contens();
				s_data += "\n";
			}
			s_data = m_cypher_off(s_data);
			File << s_data;
			File << f_end_file;
			File.close();
		}
	}
} //czytanie z pliku
N_striing C_sl_date::m_cypher_on(N_striing data) { return data; }; //odszyfrowywanie
N_striing C_sl_date::m_cypher_off(N_striing data) { return data; }; //zaszyfrowywanie