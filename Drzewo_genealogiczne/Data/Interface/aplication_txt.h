/***************************************************************************************************************
*"aplication_txt.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_aplication"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef APLICATION_TXT_H
#define APLICATION_TXT_H
#include "aplication.h"
class C_aplication_txt :
	public C_aplication
{
public:
	C_aplication_txt();
	C_aplication_txt(const C_aplication_txt & aplication_txt);
	C_aplication_txt& operator=(const C_aplication_txt& aplication_txt);
	bool operator==(const C_aplication_txt& aplication_txt);
	bool operator!=(const C_aplication_txt& aplication_txt);
	virtual ~C_aplication_txt();
};
#endif // !APLICATION_TXT_H



