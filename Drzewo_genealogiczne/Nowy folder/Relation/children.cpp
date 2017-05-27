#include "children.h"
C_children::C_children():C_relation(n_children) {}
C_children::C_children(const C_id &id) : C_relation(n_children) { ID_index = id; }
C_children::C_children(const C_children &children):C_relation(children) {
	if (this != &children) *this = children;
}
C_children& C_children::operator=(const C_children &children){
	if (this == &children) return *this;
	if (*this == children) return *this;
	ID_index = children.ID_index;
	ID_value = children.ID_value;
	return *this;
}
bool C_children::operator==(const C_children &children) {
	if (ID_index == children.ID_index && ID_value == children.ID_value) return true;
	return false;
}
bool C_children::operator!=(const C_children &children) {
	if (ID_index != children.ID_index && ID_value != children.ID_value) return true;
	return false;
}
C_children::~C_children() {}
void C_children::m_get_id(C_id &id) { ID_value = id; }
C_id C_children::m_set_id() { return ID_index; }
int C_children::m_set_variable() { return t_children; }
void C_children::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}
void C_children::m_get_complete_content(N_striing Data) {
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
} //do przetestowania
N_striing C_children::m_get_contens() {
	return ID_value.m_set_contens();
}