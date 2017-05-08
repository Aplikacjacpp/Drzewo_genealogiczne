/***************************************************************************************************************
*"month.h"
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

#ifndef MONTH_H
#define MONTH_H
#include "data.h"
class C_month: public C_data
{
public:
	C_month();
	C_month(const C_month &C);
	C_month& operator=(const C_month &C);
	bool operator==(const C_month &C);
	bool operator!=(const C_month &C);
	~C_month();
protected:

private:
	//N_striing s_data_month;
	int s_data_month;
};
#endif // !month_H



