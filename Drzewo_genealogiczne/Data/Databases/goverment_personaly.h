/***************************************************************************************************************
*"goverment_personaly.h"
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
****************************************************************************************************************/
#ifndef GOVERMENT_PERSONALY_H
#define GOVERMENT_PERSONALY_H
#include "goverment.h"
class C_goverment_personaly :
	public C_goverment
{
public:
	C_goverment_personaly();
	C_goverment_personaly(const C_goverment_personaly & goverment_personaly);
	C_goverment_personaly& operator=(const C_goverment_personaly& goverment_personaly);
	bool operator==(const C_goverment_personaly& goverment_personaly);
	bool operator!=(const C_goverment_personaly& goverment_personaly);
	virtual ~C_goverment_personaly();
};
#endif // !GOVERMENT_PERSONALY_H



