/***************************************************************************************************************
*"save_load.h"
*
*
*
*
*
*CONTENTS:
* "Klasa bazowa dla innych klas do wczytywania"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_SAVE_LOAD_H
#define C_SAVE_LOAD_H
class C_save_load
{
public:
	C_save_load();
	C_save_load(const C_save_load & save_load);
	C_save_load& operator=(const C_save_load& save_load);
	bool operator==(const C_save_load& save_load);
	bool operator!=(const C_save_load& save_load);
	virtual ~C_save_load();
};
#endif // !C_SAVE_LOAD_H



