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
*1.0     02.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 03.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.2	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
*1.3	 17.05.2017  Adding priority methods										  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_GRANDCHILDREN_H
#define C_GRANDCHILDREN_H
#include "relation.h"
#include "parent.h"
#include "children.h"
#include "partner.h"
#include "sibling.h"
#include "grandparents.h"
class C_grandchildren :	public C_relation
{
public:
	C_grandchildren();
	C_grandchildren(C_id& id);
	C_grandchildren(const C_grandchildren & grandchildren);
	C_grandchildren& operator=(const C_grandchildren& grandchildren);
	bool operator==(const C_grandchildren& grandchildren);
	bool operator!=(const C_grandchildren& grandchildren);
	virtual ~C_grandchildren();
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	virtual int m_set_variable();
	virtual void m_get_complete_content(N_striing data);
	virtual void m_get_complete_content(C_id index, C_id value);
	N_striing m_get_contens();
private:
	C_id ID_index;
	C_id ID_value;
};
#endif // !C_GRANDCHILDREN_H



