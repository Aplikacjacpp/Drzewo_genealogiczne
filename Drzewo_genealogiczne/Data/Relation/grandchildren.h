#ifndef C_GRANDCHILDREN_H
#define C_GRANDCHILDREN_H
#include "relation.h"
class C_grandchildren :	public C_relation
{
public:
	C_grandchildren();
	C_grandchildren(const C_grandchildren & grandchildren);
	C_grandchildren& operator=(const C_grandchildren& grandchildren);
	bool operator==(const C_grandchildren& grandchildren);
	bool operator!=(const C_grandchildren& grandchildren);
	virtual ~C_grandchildren();
};
#endif // !C_GRANDCHILDREN_H



