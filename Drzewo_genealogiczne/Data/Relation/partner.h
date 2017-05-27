/***************************************************************************************************************
*"grandchildren.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_relation"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     02.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.2	 25.05.2017  Adding private bool variable and method "m_set_bPart()"		  Lukasz Janus
****************************************************************************************************************/
#ifndef C_partner_H
#define C_partner_H
#include "relation.h"
class C_partner :public C_relation
{
public:
	C_partner();
	C_partner(const C_partner & partner);
	C_partner& operator=(const C_partner& partner);
	bool operator==(const C_partner& partner);
	bool operator!=(const C_partner& partner);
	virtual ~C_partner();
	void m_set_bPart(bool bPartm);

private:
	bool bPart;
};
#endif // !C_partner_H



