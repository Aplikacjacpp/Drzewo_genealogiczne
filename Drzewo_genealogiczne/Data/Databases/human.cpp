#include "human.h"
C_human::C_human() {}
C_human::C_human(C_id &id) { Id = id; }
C_human::C_human(const C_human &human) { if (this != &human) *this = human; }
C_human& C_human::operator=(const C_human &human) {
	if (this == &human) return *this;
	if (*this == human) return *this;
	V_date = human.V_date;
	Id = human.Id;
	First = human.First;
	V_last = human.V_last;
	Gender = human.Gender;
	return *this;
}
bool C_human::operator==(const C_human &human) {
	if (V_date == human.V_date && Id == human.Id && First == human.First && V_last == human.V_last) return true;
	return false;
}
bool C_human::operator!=(const C_human &human) {
	if (V_date == human.V_date && Id == human.Id && First == human.First && V_last == human.V_last) return false;
	return true;
}
C_human::~C_human() {}
void C_human::m_get_first_name(C_first_name &f_name) { First = f_name; }
void C_human::m_get_first_name(N_striing &f_name) { C_first_name F(f_name); First = F; }
void C_human::m_get_last_name(C_last_name &l_name) { V_last.m_push_back(l_name); }
void C_human::m_get_last_name(N_striing &l_name) { C_last_name L(l_name); V_last.m_push_back(L); }
void C_human::m_get_gender(C_gender &gender) { Gender = gender; }
void C_human::m_get_gender(N_striing &gender) { C_gender G(gender); Gender = G; }
void C_human::m_get_gender(bool gender) 
{
	N_striing G;
	G.m_itoa((int)gender);
	Gender.m_get_contens(G);
}
void C_human::m_shift_id(N_striing &id) { C_id I(id); Id = I; }
void C_human::m_shift_id(int id) { C_id I(id); Id = I; }
void C_human::m_shift_id(C_id &id) { Id = id; }
void C_human::m_get_date(C_date& date) { V_date.m_push_back(date); }
void C_human::m_delete_first_name() { N_striing data = ""; First.m_get_contens(data); }
void C_human::m_delete_last_name(int value) { V_last.m_erase(value); }
void C_human::m_delete_last_name() { V_last.m_pop_front(); }
void C_human::m_delete_gender() { N_striing data = ""; Gender.m_get_contens(data);}
void C_human::m_delete_date(int value) { V_date.m_erase(value); }
void C_human::m_delete_date() { V_date.m_pop_front(); }
void C_human::m_update_date(int value, C_date& date) { V_date.m_insert(value, date); }
void C_human::m_update_last_name(int value, C_last_name& l_name) { V_last.m_insert(value, l_name); }
void C_human::m_update_last_name(int value, N_striing& l_name) { C_last_name L(l_name); V_last.m_insert(value, L); }
C_human& C_human::m_clear() { C_human H(m_set_id()); return H; }
C_human& C_human::m_clear_date() { V_date.m_close(); return *this; }
C_human& C_human::m_clear_last_name() { V_last.m_close(); return *this; }
C_first_name C_human::m_set_first_name() { return First; }
C_last_name C_human::m_set_last_name() { return V_last[0]; }
C_last_name C_human::m_set_last_name(int value) { return V_last[value]; }
C_gender C_human::m_set_gender() { return Gender; }
C_id C_human::m_set_id() { return Id; }
C_date C_human::m_set_date(int value) { return V_date[value]; }
C_date C_human::m_set_date() { return V_date[0]; }