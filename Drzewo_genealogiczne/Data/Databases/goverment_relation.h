#ifndef GOVERMENT_RELATION_H
#define GOVERMENT_RELATION_H
#include "goverment.h"
class C_goverment_relation :
	public C_goverment
{
public:
	C_goverment_relation();
	C_goverment_relation(const C_goverment_relation & goverment_relation);
	C_goverment_relation& operator=(const C_goverment_relation& goverment_relation);
	bool operator==(const C_goverment_relation& goverment_relation);
	bool operator!=(const C_goverment_relation& goverment_relation);
	virtual ~C_goverment_relation();
};
#endif // !GOVERMENT_RELATION_H


//doxygen 
