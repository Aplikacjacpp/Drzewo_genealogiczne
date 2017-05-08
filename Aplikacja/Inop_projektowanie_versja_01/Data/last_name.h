/***************************************************************************************************************
*"last_name.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     25.04.2017  Orginal design													  Mateusz Marchelewicz
****************************************************************************************************************/
#ifndef C_LAST_NAME_H
#define C_LAST_NAME_H
#include "data.h"
class C_last_name : public C_data
{
public:
	C_last_name();
	C_last_name(N_striing &last);
	C_last_name(const C_last_name &last);
	C_last_name& operator=(const C_last_name &last);
	bool operator==(const C_last_name &last);
	bool operator!=(const C_last_name &last);
	~C_last_name();
protected:

private:
	N_striing s_data_last_name;
};
#endif // !C_LAST_NAME_H


