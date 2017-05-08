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
class C_sl_personalys :
	public C_save_load
{
public:
	C_sl_personalys();
	C_sl_personalys(const C_sl_personalys & sl_personalys);
	C_sl_personalys& operator=(const C_sl_personalys& sl_personalys);
	bool operator==(const C_sl_personalys& sl_personalys);
	bool operator!=(const C_sl_personalys& sl_personalys);
	virtual ~C_sl_personalys();
};
#endif // !C_SL_PERSOLALYS_H


