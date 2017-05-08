/***************************************************************************************************************
*"goverment_date.h"
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
#ifndef GOVERMENT_DATE_H
#define GOVERMENT_DATE_H
#include "goverment.h"
class C_goverment_date :
	public C_goverment
{
public:
	C_goverment_date();
	C_goverment_date(const C_goverment_date & goverment_date);
	C_goverment_date& operator=(const C_goverment_date& goverment_date);
	bool operator==(const C_goverment_date& goverment_date);
	bool operator!=(const C_goverment_date& goverment_date);
	virtual ~C_goverment_date();
};
#endif // !GOVERMENT_DATE_H



