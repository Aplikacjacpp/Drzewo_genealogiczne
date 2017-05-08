/***************************************************************************************************************
*"enginer.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_tree reprezentuje silnik aplikacji"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     01.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#include "../Databases/tree.h"
#include "sl_date.h"
#include "sl_personalys.h"
#include "sl_relations.h"
class C_enginer :virtual public C_tree, C_sl_date, C_sl_personalys, C_sl_relations
{
public:
	C_enginer();
	C_enginer(const C_enginer &enginer);
	C_enginer& operator=(const C_enginer &enginer);
//	bool operator==(const C_enginer &enginer);
	//~C_enginer();
	virtual ~C_enginer();
};

