﻿#include "aplication_txt.h"
// #include "Data\Enginer\enginer.h"     nie widzi tego!
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
	N_striing Menu[3] = { "1. New Tree", "2. Load Tree", "3. Exit" };
	N_striing SubMenu[3] = { "[Create New Tree]", "[Import Your Created Trees]", "[Exit From Program]" };
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
	N_striing MenuSub1[3] = { "1. Create New Tree", "2. Import Tree" ,"3. Exit" };
	N_striing SubSub1[3] = { "[Create Your New Tree]", "[Import Your Created Trees]", "[Exit From Program]" };
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
					EditTree();

				} break;

				case 1:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!

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


void C_aplication_txt::EditTree()
{
	char C;
	C_human human; //id dodaje sie dopiero w silniku
	N_striing data;
	N_striing MenuSub1[5] = { "1. Add a person", "2. Edit a person", "3. Add a relation", "4. Edit a relation", "5. Exit" };
	N_striing SubSub1[5] = { "[You can add a person to your tree]", "[You can edit a person]", "[You can add a relation to a person]",
		"[You can edit a relation to a person]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 5; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << endl;


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
					ptr = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(1500);
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0: {
					Add_human:
					N_striing MenuSub_add_person[5] = { "1. Add a first name", "2. Add a surname", "3. Add a gender", "4. Add a date", "5. Return" };
					N_striing SubSub_add_person[5] = { "[You can add a first name to your person]", "[You can add a surname to your person]", "[You can add a gender to your person]",
						"[You can add a date to your person]", "[Return From Add Person]" };
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
									// tutaj powinna byc metoda dolaczenia nowej osoby
					int i;
					while (true)
					{
						system("cls");
						CreateLogo();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

						for (int i = 0; i < 5; ++i)
						{
							if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								cout << "\t\t\t\t" << "--> " << MenuSub_add_person[i] << " \n\t\t " << SubSub_add_person[i] << endl;


							}
							else                // niewybrane opcje sa biale
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								cout << "\t\t\t\t" << MenuSub_add_person[i] << endl;
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
									ptr = 4;
								}
								break;
							}
							else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
							{
								ptr += 1;
								if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
								{
									ptr = 0;
								}
								break;
							}
							else if (GetAsyncKeyState(VK_RETURN) != 0)
							{
								Sleep(1500);
								switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
								{
								case 0: {

									//WH_KEYBOARD_LL;//hak do klawiatury
									//bool b_what;

									Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
													// tutaj powinna byc metoda dolaczenia nowej osoby
									int i;
									while (true) 
									{
										//	b_what = false;
										N_striing MenuSub_add_first_name[2] = { "First name:", "Return" };
										N_striing SubSub_add_first_name[2] = { data ,"[Return From Add Person]" };
										system("cls");
										CreateLogo();
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


										for (int i = 0; i < 2; ++i)
										{
											if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
												cout << "\t\t\t\t" << "--> " << MenuSub_add_first_name[i] << " \n\t\t " << SubSub_add_first_name[i] << endl;


											}
											else                // niewybrane opcje sa biale
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
												cout << "\t\t\t\t" << MenuSub_add_first_name[i] << endl;
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
										cout << "ESCAPE";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
										cout << " if you want back to main menu.";
										while (true)
										{
											if (GetAsyncKeyState(VK_ESCAPE)) MainMenu();
											if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
																				//naprawione:)
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
											else if (ptr==0&&GetAsyncKeyState(VK_BACK) != 0)
											{
												data.m_pop_back();
												Sleep(150);
												break;
											}
											else if (ptr==0&&GetAsyncKeyState(VK_RETURN) != 0)
											{
												C_first_name First(data);
												human.m_get_first_name(First);
												data.m_clear();
												goto Add_human;
											}
											else if(ptr==0)
											{
												C = m_get_key();
												if (C != '\0') {
													data.m_push_back(C);
												}
												break;
											}
											else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
											{
												goto Add_human;
											}
											Sleep(150);
										}
									//	Sleep(150);
									}
								}
								case 1: {

									//WH_KEYBOARD_LL;//hak do klawiatury
									//bool b_what;

									Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
													// tutaj powinna byc metoda dolaczenia nowej osoby
									int i;
									while (true)
									{
										//	b_what = false;
										N_striing MenuSub_add_last_name[2] = { "Last name:", "Return" };
										N_striing SubSub_add_last_name[2] = { data ,"[Return From Add Person]" };
										system("cls");
										CreateLogo();
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


										for (int i = 0; i < 2; ++i)
										{
											if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
												cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
											}
											else                // niewybrane opcje sa biale
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
												cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
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
										cout << "ESCAPE";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
										cout << " if you want back to main menu.";
										while (true)
										{
											if (GetAsyncKeyState(VK_ESCAPE)) MainMenu();
											if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
																				//naprawione:)
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
											else if (ptr==0&&GetAsyncKeyState(VK_BACK) != 0)
											{
												data.m_pop_back();
												Sleep(150);
												break;
											}
											else if (ptr==0&&GetAsyncKeyState(VK_RETURN) != 0)
											{
												C_last_name Last(data);
												human.m_get_last_name(Last);
												data.m_clear();

											}
											else if (ptr==0)
											{
												C = m_get_key();
												if (C != '\0') {
													data.m_push_back(C);
												}
												break;
											}
											else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
											{
												goto Add_human;
											}
											Sleep(150);
										}
									//	Sleep(150);
									}
									break;
								}
								case 2: {
									Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
													// tutaj powinna byc metoda dolaczenia nowej osoby
									int i;
									while (true)
									{
										//	b_what = false;
										N_striing MenuSub_add_last_name[4] = { "Gender:","- Men","-Women", "Return" };
										N_striing SubSub_add_last_name[4] = { "","","" ,"[Return From Add Person]" };
										system("cls");
										CreateLogo();
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


										for (int i = 0; i < 4; ++i)
										{
											if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
												cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
											}
											else                // niewybrane opcje sa biale
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
												cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
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
										cout << "ESCAPE";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
										cout << " if you want back to main menu.";
										while (true)
										{
											if (GetAsyncKeyState(VK_ESCAPE)) MainMenu();
											if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
																				//naprawione:)
											{
												ptr -= 1;
												if (ptr == 0)      // gdy wykracza wraca na koniec
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
													ptr = 1;
												}
												break;
											}
											else if (ptr==1&& GetAsyncKeyState(VK_RETURN) != 0)
											{
												human.m_get_gender(true);
												Sleep(150);
												break;
											}
											else if (ptr==2&& GetAsyncKeyState(VK_RETURN) != 0)
											{
												human.m_get_gender(false);
												Sleep(150);
												break;
											}
											else if (ptr == 3 && GetAsyncKeyState(VK_RETURN) != 0)
											{
												goto Add_human;
											}
											Sleep(150);
										}
									//	Sleep(150);
									}
									break;
									break; }//Dodawanie pluci
								case 3: {
									N_striing dd, mm, yy;
									Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
													// tutaj powinna byc metoda dolaczenia nowej osoby
									int i;
									while (true)
									{
										//	b_what = false;
										data = dd;
										data += '-';
										data += mm;
										data += '-';
										data += yy;
										N_striing MenuSub_add_last_name[2] = { "Date:", "Return" };
										N_striing SubSub_add_last_name[2] = { data ,"[Return From Add Person]" };
										system("cls");
										CreateLogo();
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


										for (int i = 0; i < 2; ++i)
										{
											if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
												cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
											}
											else                // niewybrane opcje sa biale
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
												cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
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
										cout << "ESCAPE";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
										cout << " if you want back to main menu.";
										while (true)
										{
											if (GetAsyncKeyState(VK_ESCAPE)) MainMenu();
											if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
																				//naprawione:)
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
											else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
											{
												data.m_pop_back();
												Sleep(150);
												break;
											}
											else if (ptr == 0 && GetAsyncKeyState(VK_RETURN) != 0)
											{
												C_last_name Last(data);
												human.m_get_last_name(Last);
												data.m_clear();

											}
											else if (ptr == 0)
											{
												if (dd.m_size() < 2) {
													C = m_get_key();
													if (C != '\0') {
														dd.m_push_back(C);
													}
												}
												else
												{
													if (mm.m_size() < 2) {
														C = m_get_key();
														if (C != '\0') {
															mm.m_push_back(C);
														}
													}
													else
													{
														if (yy.m_size() < 4) {
															C = m_get_key();
															if (C != '\0') {
																yy.m_push_back(C);
															}
														}
														else
														{
															C_date date;
															date.m_get_day(dd);
															date.m_get_month(mm);
															date.m_get_year(yy);
															human.m_get_date(date);
															goto Add_human;
														}
													}
												}
												break;
											}
											else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
											{
												goto Add_human;
											}
											Sleep(150);
										}
										//	Sleep(150);
									}
									break; //Dodawanie daty
										} 
								}
							}
							Sleep(150);
						}
						Sleep(150);
					}
				//	Sleep(150);
				}
				case 1: {

					break;
				}
				case 2:
				{
					break;
				}
				case 3:
				{
					break;
				}
				case 4:
				{
					exit(1);
					break;
				}
				default:
					break;
				}

				Sleep(150);     // szybkosc poruszania sie po menu
			}
			Sleep(150);     // szybkosc poruszania sie po menu
		}
	//	Sleep(150);
	} 
}
/*	case 1:
{

} break;

case 2:
{

} break;

case 3:
{

} break;

case 4:
{
exit(1);
} break;
default:
break;*/




void C_aplication_txt::SearchTree()
{
	N_striing MenuSub1[3] = { "1. Search by personal data", "2. Search by date" , "3. Exit" };
	N_striing SubSub1[3] = { "[You can search person by personal data]", "[You can search person by dates]", "[Exit From Program]" };
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
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << endl;


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
									//SubMenu3();
				} break;

				case 1:
				{

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


void C_aplication_txt::DisplayTree()
{
	N_striing MenuSub1[3] = { "1. Display from the oldest", "2. Search" , "3. Exit" };
	N_striing SubSub1[3] = { "[You can display trees from the oldest]", "[Search your created trees]", "[Exit From Program]" };
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
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << endl;


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
									//SubMenu3();
				} break;

				case 1:
				{
					Sleep(1500);
					SearchTree();
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



void C_aplication_txt::SubMenu2()
{
	N_striing Menu2[4] = { "1. Display Tree", "2. Edit Tree", "3. Export Tree", "4. Exit" };
	N_striing SubMenu2[4] = { "[Display Your Created Trees]", "[Edit Your Created Trees]", "[Export Your Created Trees]", "[Exit From Program]" };
	int pt = 0;

	while (true)
	{

		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		for (int i = 0; i < 4; ++i)
		{
			if (i == pt)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu2[i] << " \n\t\t " << SubMenu2[i] << endl;


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
					pt = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				pt += 1;
				if (pt == 4)       // gdy wykracza poza menu, znow wraca na poczatek
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
					DisplayTree();
					//ImportTree();
					//system("dir /s H:\TREE_INOP");
					//system("tree /f H:\TREE_INOP\\Drzewo_genealogiczne\\Drzewo_genealogiczne\\Data");	//w CodeBlocks dzia�a, tu nie...
					//system("PAUSE");

				} break;

				case 1:
				{
					Sleep(1500);
					EditTree();
				} break;

				case 2:
				{
					//EditTree();
				} break;


				case 3:
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
									//SubMenu3();
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
}/*
 char& operator >> (std::iostream& is, char &c) {
 c = NULL;
 is >> c;
 if (c != NULL)
 return c;
 }
 int C_aplication_txt::m_get_key() {
 char buf[1];
 buf[0]= NULL;
 scanf_s("%c", buf);
 return (int)buf[0];
 }*/
char C_aplication_txt::m_get_key() {
	char C;
	int Tab_key[26] = { 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
		0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A };
	int Tab_key_number[2][10] = { 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 };
	char Tab_letter[2][26];
	char Tab_number[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char Tab_polish[9] = { (char)185,(char)230,(char)234,(char)179,(char)241,(char)243,(char)156,(char)159,(char)191 }; //Polskie litery male
	char Tab_Polish[9] = { (char)165,(char)198,(char)202,(char)163,(char)209,(char)211,(char)140,(char)143,(char)175 }; //Polskie lityry duze
	int Tab_npolish[9] = { 0x41,0x43,0x45,0x4C,0x4E,0x4F,0x53,0x58,0x5A };
	int i;
	for (i = 0; i < 26; i++)
	{
		Tab_letter[0][i] = 'a' + i;
		Tab_letter[1][i] = 'A' + i;
	}
	while (true) {
		for (i = 0; i < 10; i++)
		{
			if (GetAsyncKeyState(Tab_key_number[0][i]) != 0)
			{
				C = Tab_number[i];
				Sleep(100);
				return C;
			}
		}
		for (i = 0; i < 9; i++)
		{
			if ((GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) == 0) &&
				(GetAsyncKeyState(VK_CAPITAL) == 0) && (GetAsyncKeyState(VK_MENU) != 0)) {
				C = Tab_polish[i];
				Sleep(100);
				return C;
			}
			if ((GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) != 0) && (GetAsyncKeyState(VK_MENU) != 0) ||
				(GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_MENU) != 0)) {
				C = Tab_Polish[i];
				Sleep(100);
				return C;
			}
		}
		for (i = 0; i < 26; i++)
		{
			if ((GetAsyncKeyState(Tab_key[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) == 0) && (GetAsyncKeyState(VK_CAPITAL) == 0) && (GetAsyncKeyState(VK_MENU) == 0))   // strzalka do gory przesuwa wyzej po menu
			{
				C = (Tab_letter[0][i]);
				Sleep(100);
				return C;
			}
			else if (((GetAsyncKeyState(VK_SHIFT) != 0) && (GetAsyncKeyState(Tab_key[i]) != 0)) && (GetAsyncKeyState(VK_MENU) == 0) || ((GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(VK_MENU) == 0)))
			{
				C = (Tab_letter[1][i]);
				Sleep(100);
				return C;
			}
			else if ((GetAsyncKeyState(VK_SPACE) != 0))
			{
				Sleep(100);
				return ' ';
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0) || (GetAsyncKeyState(VK_BACK) != 0) || (GetAsyncKeyState(VK_DOWN) != 0) || (GetAsyncKeyState(VK_UP) != 0) || (GetAsyncKeyState(VK_ESCAPE) != 0)) {
				return '\0';
			}
		}
	}
}