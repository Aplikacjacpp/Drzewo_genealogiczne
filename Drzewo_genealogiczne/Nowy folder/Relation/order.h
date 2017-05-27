/***************************************************************************************************************
*"order.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_relation"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     23.05.2017  Orginal design																	Lukasz Janus
*1.1	 .05.2017								  
****************************************************************************************************************/
#ifndef C_ORDER_H
#define C_ORDER_H
#include "relation.h"

class C_order :public C_relation
{
public:
	C_order();
	C_order(C_id &id);
	C_order(const C_id &id);
	C_order(const C_order &parent);
	C_order &operator=(const C_order &parent);
	bool operator==(const C_order &parent);
	bool operator!=(const C_order &parent);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	virtual int m_set_variable();
	virtual ~C_order();
	virtual void m_get_complete_content(N_striing data);
	virtual void m_get_complete_content(C_id index, C_id value);

	void m_set_sOrd(N_striing sOrdm);

private:
	N_striing  sOrd;
	C_id ID_index;
	C_id ID_value;
};
#endif // !C_ORDER_H
