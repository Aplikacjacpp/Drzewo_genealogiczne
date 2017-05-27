#ifndef C_partner_H
#define C_partner_H
#include "relation.h"
class C_partner :public C_relation
{
public:
	C_partner();
	C_partner(C_id &id);
	C_partner(const C_id &id);
	C_partner(const C_partner &partner);
	C_partner& operator=(const C_partner &partner);
	bool operator==(const C_partner &partner);
	bool operator!=(const C_partner &partner);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	virtual int m_set_variable();
	virtual ~C_partner();
	virtual void m_get_complete_content(N_striing data);
	virtual void m_get_complete_content(C_id index, C_id value);
	N_striing m_get_contens();
private:
	C_id ID_index;
	C_id ID_value;
};
#endif // !C_partner_H



