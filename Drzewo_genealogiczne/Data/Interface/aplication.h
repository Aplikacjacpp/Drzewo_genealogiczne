#pragma once
#include "C:\Users\Lukasz\Documents\Visual Studio 2015\Projects\Studia_\Semestr_IV_\Project_Krys\Dzrewo_genealogiczne\Drzewo_genealogiczne\Data\Enginer\enginer.h"
class C_aplication :
	public C_enginer
{
public:
	C_aplication();
	C_aplication(const C_aplication & aplication);
	C_aplication& operator=(const C_aplication& aplication);
	bool operator==(const C_aplication& aplication);
	bool operator!=(const C_aplication& aplication);
	virtual ~C_aplication();
};

