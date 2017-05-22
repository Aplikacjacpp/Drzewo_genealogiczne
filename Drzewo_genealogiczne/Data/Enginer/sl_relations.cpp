#include "sl_relations.h"
C_sl_relations::C_sl_relations():C_save_load() {}
C_sl_relations::C_sl_relations(const C_sl_relations & sl_relations):C_save_load(sl_relations) {
	if (this != &sl_relations) *this = sl_relations;
}
C_sl_relations& C_sl_relations::operator=(const C_sl_relations& sl_relations) {
	if (this == &sl_relations) return *this;
	if (*this == sl_relations) return *this;
	V_goverment_relation = sl_relations.V_goverment_relation;
	return *this;
}
bool C_sl_relations::operator==(const C_sl_relations& sl_relations) {
	if (V_goverment_relation == sl_relations.V_goverment_relation) return true;
	return false;
}
bool C_sl_relations::operator!=(const C_sl_relations& sl_relations) {
	if (V_goverment_relation != sl_relations.V_goverment_relation) return true;
	return false;
}
C_sl_relations::~C_sl_relations() {}
void C_sl_relations::m_load_file_relation(bool what) {
	N_striing s_data,s_inline;
	int i_multiple, i, i_start, i_stop;
	if (what)
	{
		C_goverment_relation Gover;
		std::ifstream File;
		File.open(f_save_relation);
		if (File.good())
		{
			do {
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
			if (s_data[i] == '>')
			{
				i_stop = i;
				N_striing s_help_data = s_data.m_cut(i_start, i_stop);
				s_help_data += '>';
				Gover.m_get_contens(s_help_data);
				V_goverment_relation.m_push_back(Gover);
				i_start = i_stop+1;
			}
		}
	}
	else
	{
		s_data.m_clear();
		std::ofstream File;
		File.open(f_save_relation);
		if (File.good())
		{
			for (i = 0; i < V_goverment_relation.m_size(); i++)
			{
				s_data += V_goverment_relation[i].m_set_contens();
			}
			s_data = m_cypher_off(s_data);
			File << s_data;
			File << f_end_file;
			File.close();
		}
	}
}
N_striing C_sl_relations::m_cypher_on(N_striing data) { return data; }; //odszyfrowywanie
N_striing C_sl_relations::m_cypher_off(N_striing data) { return data; }; //zaszyfrowywanie