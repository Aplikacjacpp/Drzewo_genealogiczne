/***************************************************************************************************************
*"year.h"
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

#ifndef YEAR_H
#define YEAR_H
#include "data.h"
class C_year: public C_data
{
public:
	C_year();
	C_year(const C_year &C);
	C_year& operator=(const C_year &C);
	bool operator==(const C_year &C);
	bool operator!=(const C_year &C);
	~C_year();
protected:

private:
	//N_striing s_data_year;
	int s_data_year;
};
#endif // !year_H




