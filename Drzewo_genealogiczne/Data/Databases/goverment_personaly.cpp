#include "goverment_personaly.h"
C_goverment_personaly::C_goverment_personaly() {}
C_goverment_personaly::C_goverment_personaly(const C_goverment_personaly & goverment_personaly) {}
C_goverment_personaly& C_goverment_personaly::operator=(const C_goverment_personaly& goverment_personaly) {
	if (this == &goverment_personaly) return *this;
	if (*this == goverment_personaly) return *this;

	return *this;
}
bool C_goverment_personaly::operator==(const C_goverment_personaly& goverment_personaly) {
	if (true) return true;
	return false;
}
bool C_goverment_personaly::operator!=(const C_goverment_personaly& goverment_personaly) {
	if (true) return true;
	return false;
}
C_goverment_personaly::~C_goverment_personaly() {}