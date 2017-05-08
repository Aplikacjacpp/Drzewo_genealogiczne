/***************************************************************************************************************
*"parent.h"
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
#ifndef PARENT_H
#define PARENT_H
#include "relation.h"
#include "../Personaly/id.h"
class C_parent :public C_relation
{
public:
	C_parent();
	C_parent(C_id &id);
	C_parent(const C_id &id);
	C_parent(const C_parent &parent);
	C_parent& operator=(const C_parent &parent);
	bool operator==(const C_parent &parent);
	bool operator!=(const C_parent &parent);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	//~C_parent();
	virtual ~C_parent();
private:
	C_id ID_index;
	C_id ID_value;
};
#endif // !PARENT_H



