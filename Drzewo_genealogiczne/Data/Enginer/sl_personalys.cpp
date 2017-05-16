#include "sl_personalys.h"
C_sl_personalys::C_sl_personalys() {}
C_sl_personalys::C_sl_personalys(const C_sl_personalys & sl_personalys) {}
C_sl_personalys& C_sl_personalys::operator=(const C_sl_personalys& sl_personalys) {
	if (this == &sl_personalys) return *this;
	if (*this == sl_personalys) return *this;
	V_goverment_personaly = sl_personalys.V_goverment_personaly;
	return *this;
}
bool C_sl_personalys::operator==(const C_sl_personalys& sl_personalys) {
	if (V_goverment_personaly == sl_personalys.V_goverment_personaly) return true;
	return false;
}
bool C_sl_personalys::operator!=(const C_sl_personalys& sl_personalys) {
	if (V_goverment_personaly != sl_personalys.V_goverment_personaly) return true;
	return false;
}
C_sl_personalys::~C_sl_personalys() {}
void C_sl_personalys::m_load_file_personaly(bool what) {
	N_striing s_data;
	int i_multiple, i, i_start, i_stop;
	if (what)
	{
		C_goverment_personaly Gover;
		std::ifstream File;
		File.open(f_save_data);
		if (File.good())
		{
			File >> i_multiple;
			for (i = 0; i < i_multiple; i++)
			{
				s_data += s_data.m_getline(File); //nie wiem czy bedzie dzialac
			}
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
				V_goverment_personaly.m_push_back(Gover);
				i_start = i_stop;
			}
		}
	}
	else
	{
		s_data.m_clear();
		std::ofstream File;
		File.open(f_save_data);
		if (File.good())
		{
			File << V_goverment_personaly.m_size();
			for (i = 0; i < V_goverment_personaly.m_size(); i++)
			{
				s_data += V_goverment_personaly[i].m_set_contens();
			}
			s_data = m_cypher_off(s_data);
			File << s_data;
			File.close();
		}
	}
}
N_striing C_sl_personalys::m_cypher_on(N_striing data) { return data; }; //odszyfrowywanie
N_striing C_sl_personalys::m_cypher_off(N_striing data) { return data; }; //zaszyfrowywanie