#include "enginer.h"
C_enginer::C_enginer():C_tree() {}
C_enginer::C_enginer(const C_enginer &enginer):C_tree(enginer) { if (this != &enginer) *this = enginer; }
C_enginer& C_enginer::operator=(const C_enginer &enginer) {
	if (this == &enginer) return *this;
	//if (*this == enginer) return *this;
	return *this;
}
//bool C_enginer::operator==(const C_enginer &enginer) {}
C_enginer::~C_enginer() {}
