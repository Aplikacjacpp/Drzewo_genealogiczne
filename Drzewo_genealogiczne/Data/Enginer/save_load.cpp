#include "save_load.h"
C_save_load::C_save_load() {}
C_save_load::C_save_load(const C_save_load & save_load) {}
C_save_load& C_save_load::operator=(const C_save_load& save_load) {
	if (this == &save_load) return *this;
	if (*this == save_load) return *this;

	return *this;
}
bool C_save_load::operator==(const C_save_load& save_load) {
	if (true) return true;
	return false;
}
bool C_save_load::operator!=(const C_save_load& save_load) {
	if (true) return true;
	return false;
}
C_save_load::~C_save_load() {}