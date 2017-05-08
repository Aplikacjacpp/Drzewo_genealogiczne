/***************************************************************************************************************
*"day.h"
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

#ifndef DAY_H
#define DAY_H
#include "data.h"
class C_day: public C_data
{
public:
	C_day();
	C_day(const C_day &C);
	C_day& operator=(const C_day &C);
	bool operator==(const C_day &C);
	bool operator!=(const C_day &C);
	~C_day();
protected:

private:
	//N_striing s_data_day;
	int s_data_day;
};
#endif // !day_H


