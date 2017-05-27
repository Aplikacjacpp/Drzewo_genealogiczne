/***************************************************************************************************************
*"tree.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_element zawiera tablice dynamiczna ludzi"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     01.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 03.05.2015	 adding methods												      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef TREE_H
#define TREE_H
#include "element.h"
class C_tree :public C_element
{
public:
	C_tree();
	C_tree(const C_human &human);
	C_tree(const C_tree &tree);
	C_tree& operator=(const C_tree &tree);
	bool operator==(const C_tree &tree);
	bool operator!=(const C_tree &tree);
	void m_get_human(C_human& human);
	void m_update_human(int value, C_human &human);
	void m_delete_human(int value);
	C_human m_set_human();
	C_human m_set_human(int value);
	C_human m_set_human_index();
	//~C_tree();
	virtual ~C_tree();
private:
		N_vektor<C_human> V_human;
};
#endif // !TREE_H



