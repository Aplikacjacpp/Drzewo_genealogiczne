#ifndef C_SL_RELATIONS
#define C_SL_RELATIONS
#include "save_load.h"
class C_sl_relations :public C_save_load
{
public:
	C_sl_relations();
	C_sl_relations(const C_sl_relations & sl_relations);
	C_sl_relations& operator=(const C_sl_relations& sl_relations);
	bool operator==(const C_sl_relations& sl_relations);
	bool operator!=(const C_sl_relations& sl_relations);
	virtual ~C_sl_relations();
};
#endif // !C_SL_RELATIONS



