#include "sibling.h"
C_sibling::C_sibling():C_relation(n_sibling) {}
C_sibling::C_sibling(const C_id &id) : C_relation(n_sibling) { ID_index = id; }
C_sibling::C_sibling(const C_sibling &sib):C_relation(sib) {
	if (this != &sib) *this = sib;
}
C_sibling& C_sibling::operator=(const C_sibling &sib) {
	if (this == &sib) return *this;
	if (*this == sib) return *this;
	ID_index = sib.ID_index;
	ID_value = sib.ID_value;
	return *this;
}
bool C_sibling::operator==(const C_sibling &sib) {
	if (ID_index == sib.ID_index && ID_value == sib.ID_value) return true;
	return false;
}
bool C_sibling::operator!=(const C_sibling &sib) {
	if (ID_index != sib.ID_index && ID_value != sib.ID_value) return true;
	return false;
}
C_sibling::~C_sibling() {}
void C_sibling::m_get_id(C_id &id) { ID_value = id; }
C_id C_sibling::m_set_id() { return ID_index; }
int C_sibling::m_set_variable() { return t_sibling; }
void C_sibling::m_get_complete_content(N_striing Data) {
	int i, j;
	bool what = false;
	C_id Id(n_id_personaly);
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < Data.m_size(); i++) {
		data[0] = Data[i - 1];
		data[1] = Data[i];
		if (n_id_personaly == data)
		{
			for (j = i; j < Data.m_size(); j++)
			{
				if (Data[j] >= 0 && Data[j] <= 9)
				{
					str.m_push_back(Data[j]);
				}
				else {
					delete[] data;
					Id.m_get_contens(str);
					if (what)
					{
						ID_value = Id;
						return;
					}
					else
					{
						ID_index = Id;
						what = true;
						break;
					}
				}
			}
		}
	}
	delete[] data;
	return;
}//do przetestowania
void C_sibling::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}