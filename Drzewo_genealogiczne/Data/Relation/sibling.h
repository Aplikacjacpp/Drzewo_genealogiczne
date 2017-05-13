/***************************************************************************************************************
*"sibling.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_relation"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     30.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 03.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef SIBLING_H
#define SIBLING_H
#include "relation.h"
class C_sibling:public C_relation
{
public:
	C_sibling();
	C_sibling(C_id &id);
	C_sibling(const C_id &id);
	C_sibling(const C_sibling &sib);
	C_sibling& operator=(const C_sibling &sib);
	bool operator==(const C_sibling &sib);
	bool operator!=(const C_sibling &sib);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	virtual int m_set_variable();
	virtual ~C_sibling();
private:
	C_id ID_index;
	C_id ID_value;
};
#endif // !SIBLING_H



