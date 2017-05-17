#include "grandparents.h"
C_grandparents::C_grandparents():C_relation(n_grandparent) {}
C_grandparents::C_grandparents(const C_grandparents & grandparents):C_relation() {}
C_grandparents& C_grandparents::operator=(const C_grandparents& grandparents) {
	if (this == &grandparents) return *this;
	if (*this == grandparents) return *this;
	ID_index = grandparents.ID_index;
	ID_value = grandparents.ID_value;
	return *this;
}
bool C_grandparents::operator==(const C_grandparents& grandparents) {
	if (ID_index == grandparents.ID_index&&ID_value == grandparents.ID_value) return true;
	return false;
}
bool C_grandparents::operator!=(const C_grandparents& grandparents) {
	if (ID_index != grandparents.ID_index&&ID_value != grandparents.ID_value) return true;
	return false;
}
C_grandparents::~C_grandparents() {}
void C_grandparents::m_get_id(C_id &id) { ID_value = id; }
C_id C_grandparents::m_set_id() { return ID_index; }
int C_grandparents::m_set_variable() { return t_grandparent; }
void C_grandparents::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}
void C_grandparents::m_get_complete_content(N_striing Data) {
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