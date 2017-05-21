#include "enginer.h"
C_enginer::C_enginer() :C_sl_date(), C_sl_personalys(), C_sl_relations() { m_load_files(); }
C_enginer::C_enginer(const C_enginer &enginer) : C_sl_date(enginer), C_sl_personalys(enginer), C_sl_relations(enginer) { if (this != &enginer) *this = enginer; }
C_enginer& C_enginer::operator=(const C_enginer &enginer) {
	if (this == &enginer) return *this;
	if (*this == enginer) return *this;
	V_tree = enginer.V_tree;
	i_index = enginer.i_index;
	return *this;
}
bool C_enginer::operator==(const C_enginer &enginer) {
	if (V_tree == enginer.V_tree&&i_index==enginer.i_index) return true;
	return false;
}
bool C_enginer::operator!=(const C_enginer &enginer) {
	if (V_tree != enginer.V_tree&&i_index!=enginer.i_index) return true;
	return false;
}
int C_enginer::m_set_index() { return i_index; }
void C_enginer::m_get_index(int value) { i_index = value; }
C_enginer::~C_enginer() {}
int C_enginer::i_index = NULL;
void C_enginer::m_file_init(bool b_what) {
	if (b_what)
	{
		std::ifstream file;
		file.open(f_init_file);
		if (file.good())
		{
			int value;
			file >> value;
			m_get_index(value);
			file.close();
		}
	}
	else
	{
		std::ofstream File;
		File.open(f_init_file);
		if (File.good())
		{
			File << m_set_index();
			File.close();
		}
	}
}
void C_enginer::m_load_files() {
	m_printer(1);
	m_file_init(true);
	m_file_date(true);
	m_load_file_personaly(true);
	m_load_file_relation(true);
}
void C_enginer::m_save_files() {
	m_printer(2);
	m_file_init(false);
	m_file_date(false);
	m_load_file_personaly(false);
	m_load_file_relation(false);
}
void C_enginer::m_new_human(C_human human) {
	m_add_new_personaly(++i_index,human.m_set_first_name(),human.m_set_V_last_name(),human.m_set_gender());
	//std::cout<<"w silniku"<< human.m_set_Vdate()[0].m_set_DD_MM_YYYY()<<"\n";
	m_get_new_date(i_index, human.m_set_Vdate());
}
void C_enginer::m_printer(int i) {
	switch (i)
	{
	case 1:
	{
		//system("cls");
		std::cout << "Wczytywanie danych...\n";
		break; 
	}
	case 2:
	{
	//	system("cls");
		std::cout << "Zapisywanie danych..\n";
		break;
	}
	default:
		break;
	}
}