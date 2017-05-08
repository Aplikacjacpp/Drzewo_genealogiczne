#include "sl_relations.h"
C_sl_relations::C_sl_relations() {}
C_sl_relations::C_sl_relations(const C_sl_relations & sl_relations) {}
C_sl_relations& C_sl_relations::operator=(const C_sl_relations& sl_relations) {
	if (this == &sl_relations) return *this;
	if (*this == sl_relations) return *this;

	return *this;
}
bool C_sl_relations::operator==(const C_sl_relations& sl_relations) {
	if (true) return true;
	return false;
}
bool C_sl_relations::operator!=(const C_sl_relations& sl_relations) {
	if (true) return true;
	return false;
}
C_sl_relations::~C_sl_relations() {}
