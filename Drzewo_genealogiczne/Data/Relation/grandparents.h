#ifndef C_GRANDPARENTS_H
#define C_GRANDPARENTS_H
#include "relation.h"
class C_grandparents :	public C_relation
{
public:
	C_grandparents();
	C_grandparents(const C_grandparents & grandparents);
	C_grandparents& operator=(const C_grandparents& grandparents);
	bool operator==(const C_grandparents& grandparents);
	bool operator!=(const C_grandparents& grandparents);
	virtual ~C_grandparents();
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	virtual int m_set_variable();
private:
	C_id ID_index;
	C_id ID_value;
};
#endif // !C_GRANDPARENTS_H



