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
#ifndef C_SL_PERSONALYS_H
#define C_SL_PERSONALYS_H
#include "save_load.h"
#include "../Databases/goverment_personaly.h"
#include "../narzedzia/Vektor.h"
class C_sl_personalys :
	public C_save_load
{
public:
	C_sl_personalys(); //konstruktor bezparametrowy
	C_sl_personalys(const C_sl_personalys & sl_personalys); // kostruktor kopiujacy
	C_sl_personalys& operator=(const C_sl_personalys& sl_personalys); //operator przypisania
	bool operator==(const C_sl_personalys& sl_personalys); //operator porownania ==
	bool operator!=(const C_sl_personalys& sl_personalys); //operator porownania !=
	virtual ~C_sl_personalys(); //destruktor virtualny
	void m_load_file_personaly(bool what); //czytanie z pliku
	virtual N_striing m_cypher_on(N_striing data); //odszyfrowywanie
	virtual N_striing m_cypher_off(N_striing data); //zaszyfrowywanie
private:
	N_vektor<C_goverment_personaly> V_goverment_personaly;
};
#endif // !C_SL_PERSOLALYS_H



