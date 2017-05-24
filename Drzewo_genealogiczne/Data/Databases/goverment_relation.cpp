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
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_id_relation)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
					return str.m_atoi(0, str.m_size() - 1);
				}
			}
		}
	return 0;
} //trzeba przetestowac!!
int C_goverment_relation::m_set_value_id() {
	return i_value_id;
}
N_vektor<C_children> C_goverment_relation::m_set_value_children() {
	N_vektor<C_children> Vektor;
	C_children children;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_children)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
					C_id Id, Id_value;
					Id.m_get_contens(i_value_id);
					Id_value.m_get_contens(str.m_atoi(0, str.m_size()));
					children.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(children);
					i = j;
					break;
				}
			}
		}
	return Vektor;
} //do przetestowania
N_vektor<C_parent> C_goverment_relation::m_set_value_parent() {
	N_vektor<C_parent> Vektor;
	C_parent parent;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_parent)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
					C_id Id, Id_value;
					Id.m_get_contens(i_value_id);
					Id_value.m_get_contens(str.m_atoi(0, str.m_size()));
					parent.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(parent);
					i = j;
					break;
				}
			}
		}
	return Vektor;
}; //do przetestowania
N_vektor<C_grandchildren> C_goverment_relation::m_set_value_grandchildren() {
	N_vektor<C_grandchildren> Vektor;
	C_grandchildren grandchildren;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_grandchildren)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
						C_id Id, Id_value;
						Id.m_get_contens(i_value_id);
						Id_value.m_get_contens(str.m_atoi(0, str.m_size()));
					grandchildren.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(grandchildren);
					i = j;
					break;
				}
			}
		}
	return Vektor;
}; //do przetestowania
N_vektor<C_grandparents> C_goverment_relation::m_set_value_grandparents() {
	N_vektor<C_grandparents> Vektor;
	C_grandparents grandparent;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_grandparent)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
				C_id Id, Id_value;
				Id.m_get_contens(i_value_id);
				Id_value.m_get_contens(str.m_atoi(0, str.m_size()));
				grandparent.m_get_complete_content(Id, Id_value);
				Vektor.m_push_back(grandparent);
				i = j;
				break;
			}
		}
	}
	return Vektor;
} //do przetestowania
N_vektor<C_sibling> C_goverment_relation::m_set_value_sibling() {
	N_vektor<C_sibling> Vektor;
	C_sibling sibling;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_sibling)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
						C_id Id, Id_value;
						Id.m_get_contens(i_value_id);
						Id_value.m_get_contens(str.m_atoi(0, str.m_size()));
					sibling.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(sibling);
					i = j;
					break;
				}
			}
		}
	return Vektor;
}//do przetestowania
N_vektor<C_partner> C_goverment_relation::m_set_value_patner() {
	N_vektor<C_partner> Vektor;
	C_partner sibling;
	int i, j;
	N_striing str,relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_partner)
		{
			for (j = i+1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
					C_id Id, Id_value;
					Id.m_get_contens(i_value_id);
					Id_value.m_get_contens(str.m_atoi(0, str.m_size()));
					sibling.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(sibling);
					i = j;
					break;
			}
		}
	}
	return Vektor;
}
//wyszukuje i zwraca wartosc dla sibling