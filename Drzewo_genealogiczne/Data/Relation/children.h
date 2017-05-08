/***************************************************************************************************************
*"children.h"
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
#ifndef CHILDREN_H
#define CHILDREN_H
#include "relation.h"
class C_children :public C_relation
{
public:
	C_children();
	C_children(C_id &id);
	C_children(const C_id &id);
	C_children(const C_children &children);
	C_children& operator=(const C_children &children);
	bool operator==(const C_children &children);
	bool operator!=(const C_children &children);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	//~C_children();
	virtual ~C_children();
private:
	C_id ID_index;
	C_id ID_value;
};
#endif // !CHILDREN_H


