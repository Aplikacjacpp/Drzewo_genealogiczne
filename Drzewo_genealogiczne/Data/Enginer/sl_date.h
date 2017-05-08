#ifndef C_SL_DATE_H
#define C_SL_DATE_H
#include "save_load.h"
class C_sl_date :public C_save_load
{
public:
	C_sl_date();
	C_sl_date(const C_sl_date & sl_date);
	C_sl_date& operator=(const C_sl_date& sl_date);
	bool operator==(const C_sl_date& sl_date);
	bool operator!=(const C_sl_date& sl_date);
	virtual ~C_sl_date();
};
#endif // !C_SL_DATE_H



