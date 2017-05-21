#include "aplication_txt.h"
#include <cstdlib>
#include <Windows.h>

C_aplication_txt::C_aplication_txt() {}
C_aplication_txt::C_aplication_txt(const C_aplication_txt & aplication_txt) {}
C_aplication_txt& C_aplication_txt::operator=(const C_aplication_txt& aplication_txt) {
	if (this == &aplication_txt) return *this;
	if (*this == aplication_txt) return *this;

	return *this;
}
bool C_aplication_txt::operator==(const C_aplication_txt& aplication_txt) {
	if (true) return true;
	return false;
}
bool C_aplication_txt::operator!=(const C_aplication_txt& aplication_txt) {
	if (true) return true;
	return false;
}
C_aplication_txt::~C_aplication_txt() {}


void C_aplication_txt::SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_BOLD;			//FW_NORMAL
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}



void C_aplication_txt::CreateLogo()       // metoda tworzy logo (atrape "drzewka")
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

void C_aplication_txt::MainMenu()
{
	N_striing Menu[3] = { "1. Create Tree", "2. Import", "3. Exit" };
	N_striing SubMenu[3] = { "[Create Your Tree]", "[Import Your Created Trees]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
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

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";

		while (true)
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
					Sleep(1500);
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

void C_aplication_txt::Sub1()
{
	N_striing MenuSub1[2] = { "1. Create New Tree", "2. Exit" };
	N_striing SubSub1[2] = { "[Create Your New Tree]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
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

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
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



void C_aplication_txt::SubMenuPerson()
{
	N_striing MenuSubPerson[4] = { "1. Add a personal data", "2. Add a marital relationship", "3. Add a family relationship", "4. Add to..." };
	N_striing SubSubPerson[4] = { "[Add a personal data: name, surname, date of birth, date of death etc.]", 
		"[Add a relationship data: date of wedding, data of husbands and wives]", 
		"[Add a family relationship data: children, siblings etc.]", "[Join a person to another person as sibling, child or parent]" };
	int ptr = 0, p = 0;

	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 4; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSubPerson[i] << " \n\t\t " << SubSubPerson[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSubPerson[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 4)       // gdy wykracza poza menu, znow wraca na poczatek
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
					
				} break;

				case 1:
				{
					
				} break;


				case 2:
				{
					
				} break;

				case 3:
				{
					
				} break;


				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}



void C_aplication_txt::SubMenu1()
{
	N_striing Menu1[3] = { "1. Add a person", "2. Save a tree", "3. Exit" };
	N_striing SubMenu1[3] = { "[You can add a person to your tree]",
		"[You can savie your created tree]", "[Exit From Program]" };
	int pter = 0;

	while (true)
	{

		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		for (int i = 0; i < 3; ++i)
		{
			if (i == pter)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu1[i] << " \n\t\t\t " << SubMenu1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu1[i] << endl;
			}
		}


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				pter -= 1;
				if (pter == -1)      // gdy wykracza wraca na koniec
				{
					pter = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				pter += 1;
				if (pter == 3)       // gdy wykracza poza menu, znow wraca na poczatek
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
					Sleep(1500);
					SubMenuPerson();
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

void C_aplication_txt::SubMenu2()
{
	N_striing Menu2[3] = { "1. Import Tree", "2. Delete Tree", "3. Exit" };
	N_striing SubMenu2[3] = { "[Import Your Created Trees]", "[Delete Your Created Trees]", "[Exit From Program]" };
	int pt = 0;

	while (true)
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

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";


		while (true)
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
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					ImportTree();
					//system("dir /s H:\TREE_INOP");
					//system("tree /f H:\TREE_INOP\\Drzewo_genealogiczne\\Drzewo_genealogiczne\\Data");	//w CodeBlocks dzia³a, tu nie...
					//system("PAUSE");

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



void C_aplication_txt::ImportTree()
{
	N_striing MenuSub1[2] = { "1. Give your tree name", "2. Exit" };
	N_striing SubSub1[2] = { "[You can give your created tree name]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
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

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
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
					SubMenu3();
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




void C_aplication_txt::SubMenu3()
{
	N_striing Menu1[6] = { "1. Add a person", "2. Find a person", "3. Display a tree", "4. Delete a person", "5. Save a tree", "6. Exit" };
	N_striing SubMenu1[6] = { "[You can add a person to your tree]",
		"[You can find created people in your tree]", "[You can display your created trees]",
		"[You can delete people from your created trees]", "[You can saving your created trees]", "[Exit From Program]" };
	int pter = 0;

	while (true)
	{

		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		for (int i = 0; i < 6; ++i)
		{
			if (i == pter)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu1[i] << " \n\t\t\t " << SubMenu1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu1[i] << endl;
			}
		}


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
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
					Sleep(1500);
					SubMenuPerson();
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
