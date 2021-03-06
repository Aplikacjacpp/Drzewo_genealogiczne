/***************************************************************************************************************
*"main.cpp"
*
*
*
*
*
*CONTENTS:
* "Main Menu Project + 'Logo' "
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     24.04.2017  Original design													      Mateusz Marchelewicz
*1.01    26.04.2017  Added menu descriptions                                                  Mateusz Marchelewicz
*1.02    28.04.2017  Added submenu + descriptions                                             Mateusz Marchelewicz
****************************************************************************************************************/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "striing.h"

using std::cout;
using std::endl;

void MainMenu();
void Sub1();
void SubMenu1();
void SubMenu2();
void CreateLogo();


int main()
{
    MainMenu();

    return 0;
}


void CreateLogo()       // metoda tworzy logo (atrape "drzewka")
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   // metoda ustawia kolory = 15 to bialy
    cout << "\n\n\t\t\t | \n \t\t\t | \n \t\t     ========= \n  \t\t    |         | \n \t\t    | \t      |";
    cout << "\n \t   =============      ====\n";
    cout << "\t  |      |      |\t  |\n";
    cout << "\t  |      |      |\t  |\n";
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "\n\n" << "\t\t\t" << "DRZEWO GENEALOGICZNE - FAMILY TREE\n\n";
}

void MainMenu()
{
    N_striing Menu[3] = {"1. Create Tree", "2. Import", "3. Exit"};
    N_striing SubMenu[3] = {"[Create Your Tree]", "[Import Your Created Trees]", "[Exit From Program]"};
	int ptr = 0, p = 0;

	while(true)
	{
	    system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu[i] << "  " << SubMenu[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Po menu poruszaj sie za pomoca strzalek ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Wybor zatwierdz klawiszem ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";

		while(true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
					case 0:
					{
					    Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
                        Sub1();
					} break;

					case 1:
					{
                        SubMenu2();
					} break;

					case 2:
					{
						exit(1);
					} break;
				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}

void Sub1()
{
    N_striing MenuSub1[2] = {"1. Enter Tree Name", "2. Exit"};
    N_striing SubSub1[2] = {"[Enter Your Tree Name]", "[Exit From Program]"};
	int ptr = 0, p = 0;

	while(true)
	{
	    system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 2; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Po menu poruszaj sie za pomoca strzalek ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Wybor zatwierdz klawiszem ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";

		while(true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
					case 0:
					{
					    Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
                        SubMenu1();
					} break;

					case 1:
					{
						exit(1);
					} break;
				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}

void SubMenu1()
{
    N_striing Menu1[6] = {"1. Add a person", "2. Find a person", "3. Display a tree", "4. Delete a person", "5. Save a tree", "6. Exit"};
    N_striing SubMenu1[6] = {"[You can add a person to your tree]",
    "[You can find created people in your tree]", "[You can display your created trees]",
    "[You can delete people from your created trees]", "[You can saving your created trees]", "[Exit From Program]"};
    int pter = 0;

    while(true)
    {

        system("cls");
        CreateLogo();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    for (int i = 0; i < 6; ++i)
		{
			if (i == pter)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu1[i] << "  " << SubMenu1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu1[i] << endl;
			}
		}


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Po menu poruszaj sie za pomoca strzalek ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Wybor zatwierdz klawiszem ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n By wyjsc do menu glownego kliknij ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACJE.";


		while(true)
		{
		    if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				pter -= 1;
				if (pter == -1)      // gdy wykracza wraca na koniec
				{
					pter = 5;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				pter += 1;
				if (pter == 6)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					pter = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pter)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
					case 0:
					{
						// instrukcje
					} break;

					case 1:
					{
						// instrukcje
					} break;

					case 2:
					{

					} break;

					case 3:
					{

					} break;

					case 4:
					{

					} break;

					case 5:
					{
					    exit(1);
					} break;

				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
    }
}

void SubMenu2()
{
    N_striing Menu2[3] = {"1. Import Tree", "2. Delete Tree", "3. Exit"};
    N_striing SubMenu2[3] = {"[Import Your Created Trees]", "[Delete Your Created Trees]", "[Exit From Program]"};
    int pt = 0;

    while(true)
    {

        system("cls");
        CreateLogo();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    for (int i = 0; i < 3; ++i)
		{
			if (i == pt)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu2[i] << "  " << SubMenu2[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu2[i] << endl;
			}
		}


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Po menu poruszaj sie za pomoca strzalek ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Wybor zatwierdz klawiszem ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n By wyjsc do menu glownego kliknij ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACJE.";


		while(true)
		{
		    if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				pt -= 1;
				if (pt == -1)      // gdy wykracza wraca na koniec
				{
					pt = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				pt += 1;
				if (pt == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					pt = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pt)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
					case 0:
					{
					    //cout << "IMPORT";
						// instrukcje
					} break;

					case 1:
					{
						// instrukcje
					} break;

					case 2:
					{
					    exit(1);
					} break;

				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
    }
}
