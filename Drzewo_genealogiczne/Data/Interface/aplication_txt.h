/***************************************************************************************************************
*"aplication_txt.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_aplication"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.01    09.05.2017  Adding methods for menu										  Mateusz Marchelewicz
****************************************************************************************************************/
#ifndef APLICATION_TXT_H
#define APLICATION_TXT_H
#include "aplication.h"
#include <Windows.h>

using std::cout;
using std::endl;

class C_aplication_txt :
	public C_aplication
{
public:
	C_aplication_txt();
	C_aplication_txt(const C_aplication_txt & aplication_txt);
	C_aplication_txt& operator=(const C_aplication_txt& aplication_txt);
	bool operator==(const C_aplication_txt& aplication_txt);
	bool operator!=(const C_aplication_txt& aplication_txt);
	virtual ~C_aplication_txt();
	void MainMenu();
	void Sub1();
	void SubMenu1();
	void SubMenu2();
	void CreateLogo();
};
#endif // !APLICATION_TXT_H
