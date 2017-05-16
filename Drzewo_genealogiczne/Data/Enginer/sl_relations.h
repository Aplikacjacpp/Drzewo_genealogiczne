/***************************************************************************************************************
*"sl_date.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_save_load"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_SL_RELATIONS
#define C_SL_RELATIONS
#include "save_load.h"
#include "../Databases/goverment_relation.h"
#include "../narzedzia/Vektor.h"
class C_sl_relations :public C_save_load
{
public:
	C_sl_relations(); //konstruktor bezparametrowy
	C_sl_relations(const C_sl_relations & sl_relations); //konstruktor kopiujacy
	C_sl_relations& operator=(const C_sl_relations& sl_relations); //operator przypisania
	bool operator==(const C_sl_relations& sl_relations); //operator porownania ==
	bool operator!=(const C_sl_relations& sl_relations); //operator porownania !=
	virtual ~C_sl_relations(); //wirtualny destruktor
	void m_load_file_relation(bool what); //czytanie z pliku
	virtual N_striing m_cypher_on(N_striing data); //odszyfrowywanie
	virtual N_striing m_cypher_off(N_striing data); //zaszyfrowywanie
private:
	N_vektor<C_goverment_relation> V_goverment_relation;
};
#endif // !C_SL_RELATIONS



