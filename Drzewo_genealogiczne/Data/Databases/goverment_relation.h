/***************************************************************************************************************
*"goverment_relation.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klascie C_goverment"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1     09.05.2017  Pure Virtual Methods Added										  Mateusz Marchelewicz
*1.2	 14.05.2017  Adding new mothods												  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef GOVERMENT_RELATION_H
#define GOVERMENT_RELATION_H
#include "goverment.h"
class C_goverment_relation :
	public C_goverment
{
public:
	C_goverment_relation();
	C_goverment_relation(const C_goverment_relation & goverment_relation);
	C_goverment_relation& operator=(const C_goverment_relation& goverment_relation);
	bool operator==(const C_goverment_relation& goverment_relation);
	bool operator!=(const C_goverment_relation& goverment_relation);
	virtual ~C_goverment_relation();
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual N_striing m_set_contens();
	int C_goverment_relation::m_set_value_id();
private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	N_striing s_goverment_relation;
	int m_id_value();
	int i_value_id;
};
#endif // !GOVERMENT_RELATION_H


//doxygen 
