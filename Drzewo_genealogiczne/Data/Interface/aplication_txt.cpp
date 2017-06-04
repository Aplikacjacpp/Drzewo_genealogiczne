#include "aplication_txt.h"
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
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					C_human human; //id dodaje sie dopiero w silniku
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
								switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
								{
								case 0:
								{
									N_striing data;
									N_striing MenuSub_add_first_name[2] = { "First name:", "Return" };
									N_striing SubSub_add_first_name[2] = {data ,"[Return From Add Person]" };
									Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
													// tutaj powinna byc metoda dolaczenia nowej osoby
									int i;
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
												if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
												{
													ptr = 0;
												}
												break;
											}
											else if (GetAsyncKeyState(VK_RETURN) != 0)
											{
												//Mateusz dokoncz!!!
												//pobieraj litery i wstawiaj do N_striing data!!
												//nastepnie modul skopiuje i wstawie do innych danych :)
												if (GetAsyncKeyState(VK_RETURN) != 0)
												{
													C_first_name first(data);
													human.m_get_first_name(first);
												}
											}
											Sleep(200);     // szybkosc poruszania sie po menu
										}
										Sleep(200);     // szybkosc poruszania sie po menu
									}
								
									C_gender gender;
									N_vektor<C_last_name> V_last;
									N_vektor<C_date> V_date;
									C_last_name last;
									C_date date;
									//dalsza instrukcja do wstawiania odpowiednich wartosci
									//gdy poda wartosci trzeba je zaladowac do obiektu human i przeslac jako argument ponizszej metody!
								
									human.m_get_gender(gender);
									for (i = 0; i < V_last.m_size(); i++)
										human.m_get_last_name(V_last[i].m_set_contens());
									for (i = 0; i < V_date.m_size(); i++)
										human.m_get_date(V_date[i]);
									m_new_human(human); //ta metoda prosto z silnika :d

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

								case 4:
								{
									exit(1);
								} break;
								}
								break;
							}
						}
						Sleep(200);     // szybkosc poruszania sie po menu
					}
					Sleep(200);     // szybkosc poruszania sie po menu
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

				case 4:
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
					//system("tree /f H:\TREE_INOP\\Drzewo_genealogiczne\\Drzewo_genealogiczne\\Data");	//w CodeBlocks dzia³a, tu nie...
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
}
