#include "goverment_relation.h"
C_goverment_relation::C_goverment_relation() {}
C_goverment_relation::C_goverment_relation(const C_goverment_relation & goverment_relation) {}
C_goverment_relation& C_goverment_relation::operator=(const C_goverment_relation& goverment_relation) {
	if (this == &goverment_relation) return *this;
	if (*this == goverment_relation) return *this;
	s_goverment_relation = goverment_relation.s_goverment_relation;
	return *this;
}
bool C_goverment_relation::operator==(const C_goverment_relation& goverment_relation) {
	if (s_goverment_relation == goverment_relation.s_goverment_relation) return true;
	return false;
}
bool C_goverment_relation::operator!=(const C_goverment_relation& goverment_relation) {
	if (s_goverment_relation != goverment_relation.s_goverment_relation) return true;
	return false;
}
C_goverment_relation::~C_goverment_relation() {}
bool C_goverment_relation::m_wchat_is() { if (this->s_goverment_relation.m_size() >= 1 || this->s_goverment_relation != '\0') return true; return false; }
void C_goverment_relation::m_get_contens(N_striing &contens) { this->s_goverment_relation = m_is_there_contens(contens); }
N_striing C_goverment_relation::m_set_contens() { return this->s_goverment_relation; }
N_striing C_goverment_relation::m_is_there_contens(N_striing &Word) {
	int i, value = 0,X;
	for (i = 0; i < Word.m_size(); i++)
	{
		X = (int)Word[i] - 48 + 10 * ((int)Word[i - 1] - 48);
		switch (X)
		{
		case t_children:
			value++; break;
		case t_grandchildren:
			value++; break;
		case t_grandparent:
			value++; break;
		case t_parent:
			value++; break;
		case t_sibling:
			value++; break;
		default:
			break;
		}
	}
	if (value == 5) return Word;
	return "";
}
int C_goverment_relation::m_id_value() {
	int i, j;
	N_striing str;
	char *relation = new char[2];
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation[0] = s_goverment_relation[i - 1];
		relation[1] = s_goverment_relation[i];
		if (n_id_relation == relation)
		{
			for (j = i; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= 0 && s_goverment_relation[j] <= 9){
					str.m_push_back(s_goverment_relation[j]);
				}
				else {
					delete[] relation;
					return str.m_atoi(0, str.m_size() - 1);
				}
			}
		}
	}
	delete[] relation;
	return 0;
} //trzeba przetestowac!!
int C_goverment_relation::m_set_value_id() {
	return i_value_id;
}
C_children C_goverment_relation::m_set_value_children() {
	C_children children;
	int i, j;
	N_striing str;
	char *relation = new char[2];
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation[0] = s_goverment_relation[i - 1];
		relation[1] = s_goverment_relation[i];
		if (n_children == relation)
		{
			for (j = i; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= 0 && s_goverment_relation[j] <= 9) {
					str.m_push_back(s_goverment_relation[j]);
				}
				else {
					delete[] relation;
				/*	C_id Id(n_id_relation);
					Id.m_get_contens(i_value_id)
					children.m_get_id(str); */ //do zrobienia!!
					return children;
				}
			}
		}
	}
	delete[] relation;
	return children;
} //do przetestowania
C_parent C_goverment_relation::m_set_value_parent() {
	C_parent parent;
	int i, j;
	N_striing str;
	char *relation = new char[2];
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation[0] = s_goverment_relation[i - 1];
		relation[1] = s_goverment_relation[i];
		if (n_parent == relation)
		{
			for (j = i; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= 0 && s_goverment_relation[j] <= 9) {
					str.m_push_back(s_goverment_relation[j]);
				}
				else {
					delete[] relation;
					/*	C_id Id(n_id_relation);
					Id.m_get_contens(i_value_id)
					parent.m_get_id(str); */ //do zrobienia!!
					return parent;
				}
			}
		}
	}
	delete[] relation;
	return parent;
}; //do przetestowania
C_grandchildren C_goverment_relation::m_set_value_grandchildren() {
	C_grandchildren grandchildren;
	int i, j;
	N_striing str;
	char *relation = new char[2];
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation[0] = s_goverment_relation[i - 1];
		relation[1] = s_goverment_relation[i];
		if (n_grandchildren == relation)
		{
			for (j = i; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= 0 && s_goverment_relation[j] <= 9) {
					str.m_push_back(s_goverment_relation[j]);
				}
				else {
					delete[] relation;
					/*	C_id Id(n_id_relation);
					Id.m_get_contens(i_value_id)
					grandchildren.m_get_id(str); */ //do zrobienia!!
					return grandchildren;
				}
			}
		}
	}
	delete[] relation;
	return grandchildren;
}; //do przetestowania
C_grandparents C_goverment_relation::m_set_value_grandparents() {
	C_grandparents grandparent;
	int i, j;
	N_striing str;
	char *relation = new char[2];
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation[0] = s_goverment_relation[i - 1];
		relation[1] = s_goverment_relation[i];
		if (n_grandparent == relation)
		{
			for (j = i; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= 0 && s_goverment_relation[j] <= 9) {
					str.m_push_back(s_goverment_relation[j]);
				}
				else {
					delete[] relation;
					/*	C_id Id(n_id_relation);
					Id.m_get_contens(i_value_id)
					grandparent.m_get_id(str); */ //do zrobienia!!
					return grandparent;
				}
			}
		}
	}
	delete[] relation;
	return grandparent;
} //do przetestowania
C_sibling C_goverment_relation::m_set_value_sibling() {
	C_sibling sibling;
	int i, j;
	N_striing str;
	char *relation = new char[2];
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation[0] = s_goverment_relation[i - 1];
		relation[1] = s_goverment_relation[i];
		if (n_sibling == relation)
		{
			for (j = i; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= 0 && s_goverment_relation[j] <= 9) {
					str.m_push_back(s_goverment_relation[j]);
				}
				else {
					delete[] relation;
					/*	C_id Id(n_id_relation);
					Id.m_get_contens(i_value_id)
					sibling.m_get_id(str); */ //do zrobienia!!
					return sibling;
				}
			}
		}
	}
	delete[] relation;
	return sibling;
}//do przetestowania