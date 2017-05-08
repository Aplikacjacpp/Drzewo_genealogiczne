/***************************************************************************************************************
*"goverment.h"
*
*
*
*
*
*CONTENTS:
* "Klasa bazowa dla innych klas do przechowywania 'wierszy' pliku"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef GOVERMENT_H
#define GOVERMENT_H
class C_goverment
{
public:
	C_goverment();
	C_goverment(const C_goverment & goverment);
	C_goverment& operator=(const C_goverment& goverment);
	bool operator==(const C_goverment& goverment);
	bool operator!=(const C_goverment& goverment);
	virtual ~C_goverment();
};
#endif // !GOVERMENT_H



