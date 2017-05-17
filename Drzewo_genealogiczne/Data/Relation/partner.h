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
};
#endif // !C_partner_H



