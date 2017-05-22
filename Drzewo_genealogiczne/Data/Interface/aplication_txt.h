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
*1.1     15.05.2017  Windows size changed										      Mateusz Marchelewicz
*1.1     17.05.2017  Font size changed										          Mateusz Marchelewicz
*1.2     21.05.2017  Menu modified, new methods added								  Mateusz Marchelewicz
*1.2     21.05.2017  Descriptions of menu modified								      Mateusz Marchelewicz
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
	void SetWindow(int Width, int Height);
	void MainMenu();
	void Sub1();
	void SubMenu1();
	void SubMenu2();
	void SubMenu3();
	void ImportTree();
	void SubMenuPerson();
	void CreateLogo();
};
#endif // !APLICATION_TXT_H
