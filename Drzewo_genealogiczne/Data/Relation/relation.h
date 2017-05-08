/***************************************************************************************************************
*"relation.h"
*
*
*
*
*
*CONTENTS:
* "Klasa virtualno basowa"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     30.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 03.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_RELATION_H
#define C_RELATION_H
#include "..\narzedzia\striing.h"
#include "../Personaly/id.h"
class C_relation
{
public:
	C_relation();
	C_relation(N_striing realt);
	C_relation(const C_relation &relat);
	C_relation& operator=(const C_relation &relat);
	bool operator==(const C_relation &relat);
	bool operator!=(const C_relation &relat);
	virtual void m_get_id(C_id &id) = 0;
	virtual C_id m_set_id() = 0;	//~C_relation();
	virtual ~C_relation();
	N_striing m_what_type();
private:
	N_striing S_relation_text;
};
#endif // !C_RELATION_H