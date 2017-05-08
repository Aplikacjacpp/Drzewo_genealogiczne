#ifndef C_OTHER_H
#define C_OTHER_H
#include "relation.h"
class C_other :public C_relation
{
public:
	C_other();
	C_other(const C_other & other);
	C_other& operator=(const C_other& other);
	bool operator==(const C_other& other);
	bool operator!=(const C_other& other);
	virtual ~C_other();
};
#endif // !C_OTHER_H



