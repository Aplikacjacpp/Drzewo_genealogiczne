#include "goverment_relation.h"
C_goverment_relation::C_goverment_relation() {}
C_goverment_relation::C_goverment_relation(const C_goverment_relation & goverment_relation) {}
C_goverment_relation& C_goverment_relation::operator=(const C_goverment_relation& goverment_relation) {
	if (this == &goverment_relation) return *this;
	if (*this == goverment_relation) return *this;

	return *this;
}
bool C_goverment_relation::operator==(const C_goverment_relation& goverment_relation) {
	if (true) return true;
	return false;
}
bool C_goverment_relation::operator!=(const C_goverment_relation& goverment_relation) {
	if (true) return true;
	return false;
}
C_goverment_relation::~C_goverment_relation() {}