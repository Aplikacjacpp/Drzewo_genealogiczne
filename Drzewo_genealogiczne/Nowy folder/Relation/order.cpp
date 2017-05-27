#include "order.h"
C_order::C_order() :C_relation(n_parent) {}
C_order::C_order(C_id &id) : C_relation(n_parent) { ID_index = id; }
C_order::C_order(const C_id &id) : C_relation(n_parent) { ID_index = id; }
C_order::C_order(const C_order &parent) : C_relation(parent) {
	if (this != &parent) *this = parent;
}
C_order& C_order::operator=(const C_order &parent) {
	if (this == &parent) return *this;
	if (*this == parent) return *this;
	ID_index = parent.ID_index;
	ID_value = parent.ID_value;
	return *this;
}
bool C_order::operator==(const C_order &parent) {
	if (ID_index == parent.ID_index && ID_value == parent.ID_value) return true;
	return false;
}
bool C_order::operator!=(const C_order &parent) {
	if (ID_index != parent.ID_index && ID_value != parent.ID_value) return true;
	return false;
}
C_order::~C_order() {}
void C_order::m_get_id(C_id &id) { ID_value = id; }
C_id C_order::m_set_id() { return ID_index; }
int C_order::m_set_variable() { return t_parent; }
void C_order::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}
void C_order::m_get_complete_content(N_striing Data) {
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
}
void  C_order::m_set_sOrd(N_striing sOrdm)
{
	sOrd = sOrdm; //o taka metode chodzi?
}
//do przetestowania