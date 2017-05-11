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
	C_sl_relations();
	C_sl_relations(const C_sl_relations & sl_relations);
	C_sl_relations& operator=(const C_sl_relations& sl_relations);
	bool operator==(const C_sl_relations& sl_relations);
	bool operator!=(const C_sl_relations& sl_relations);
	virtual ~C_sl_relations();
private:
	N_vektor<C_goverment_relation> V_goverment_relation;
};
#endif // !C_SL_RELATIONS



