/***************************************************************************************************************
*"gender.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     26.04.2017  Orginal design													  Mateusz Marchelewicz
****************************************************************************************************************/

#ifndef GENDER_H
#define GENDER_H
#include "data.h"
class C_gender: public C_data
{
public:
	C_gender();
	C_gender(const C_gender &C);
	C_gender& operator=(const C_gender &C);
	bool operator==(const C_gender &C);
	bool operator!=(const C_gender &C);
	~C_gender();
protected:

private:
	N_striing s_data_gender;
};
#endif // !GENDER_H

