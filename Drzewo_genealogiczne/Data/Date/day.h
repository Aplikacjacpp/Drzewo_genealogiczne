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
*1.1	 02.05.2015	 shift name variable										      Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.3	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.4	 02.05.2015	 Adding parameter constructors								      Lukasz Witek vel Witkowski
****************************************************************************************************************/

#ifndef DAY_H
#define DAY_H
#include "../Personaly/data.h"
class C_day: public C_data
{
public:
	C_day();
	C_day(N_striing &day);
	C_day(int day);
	C_day(const C_day &C);
	C_day& operator=(const C_day &C);
	bool operator==(const C_day &C);
	bool operator!=(const C_day &C);
	//~C_day();
	virtual ~C_day();
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual N_striing m_set_contens();
protected:

private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	int i_data_day = NULL;
};
#endif // !day_H


