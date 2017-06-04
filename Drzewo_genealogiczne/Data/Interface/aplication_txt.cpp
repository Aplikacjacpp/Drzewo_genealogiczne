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
									WH_KEYBOARD_LL;//hak do klawiatury
									bool b_what;
									N_striing data;
									Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
													// tutaj powinna byc metoda dolaczenia nowej osoby
									int i;
									while (true)
									{
										b_what = false;
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
										cout << "SPACEBAR";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
										cout << " if you want back to main menu.";
										while (true)
										{
											if (GetAsyncKeyState(VK_SPACE)) MainMenu();
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
											else
											{
											//	int yyy = getchar();
											//	data.m_push_back('a');
											//	std::cout << "klawisz!" << yyy << "\n";
												switch (m_get_key()) //male litery standartowe
												{
												case 97:{
													data.m_push_back((char)97);
												//	std::cout << "klawisz!\n";
												//	b_what = true;
													break;
												}
												case 98: {
													data.m_push_back((char)98);
													break;
												}
												case 99: {
													data.m_push_back((char)99);
													break;
												}
												case 100: {
													data.m_push_back((char)100);
													break;
												}
												case 101: {
													data.m_push_back((char)101);
													break;
												}
												case 102: {
													data.m_push_back((char)102);
													break;
												}
												case 103: {
													data.m_push_back((char)103);
													break;
												}
												case 104: {
													data.m_push_back((char)104);
													break;
												}
												case 105: {
													data.m_push_back((char)105);
													break;
												}
												case 106: {
													data.m_push_back((char)106);
													break;
												}
												case 107: {
													data.m_push_back((char)107);
													break;
												}
												case 108: {
													data.m_push_back((char)108);
													break;
												}
												case 109: {
													data.m_push_back((char)109);
													break;
												}
												case 110: {
													data.m_push_back((char)110);
													break;
												}
												case 111: {
													data.m_push_back((char)111);
													break;
												}
												case 112: {
													data.m_push_back((char)112);
													break;
												}
												case 113: {
													data.m_push_back((char)113);
													break;
												}
												case 114: {
													data.m_push_back((char)114);
													break;
												}
												case 115: {
													data.m_push_back((char)115);
													break;
												}
												case 116: {
													data.m_push_back((char)116);
													break;
												}
												case 117: {
													data.m_push_back((char)117);
													break;
												}
												case 118: {
													data.m_push_back((char)118);
													break;
												}
												case 119: {
													data.m_push_back((char)119);
													break;
												}
												case 120: {
													data.m_push_back((char)120);
													break;
												}
												case 121: {
													data.m_push_back((char)121);
													break;
												}
												case 122: {
													data.m_push_back((char)122);
													break;
												}
												case 0xA0:
												case 0xA1:
												{
													switch (WH_KEYBOARD)
													{
													case 0x41: {
														break;
													}
													case 0x42: {
														break;
													}
													case 0x43: {
														break;
													}
													case 0x44: {
														break;
													}
													case 0x45: {
														break;
													}
													case 0x46: {
														break;
													}
													case 0x47: {
														break;
													}
													case 0x48: {
														break;
													}
													case 0x49: {
														break;
													}
													case 0x4A: {
														break;
													}
													case 0x4B: {
														break;
													}
													case 0x4C: {
														break;
													}
													case 0x4D: {
														break;
													}
													case 0x4E: {
														break;
													}
													case 0x4F: {
														break;
													}
													case 0x50: {
														break;
													}
													case 0x51: {
														break;
													}
													case 0x52: {
														break;
													}
													case 0x53: {
														break;
													}
													case 0x54: {
														break;
													}
													case 0x55: {
														break;
													}
													case 0x56: {
														break;
													}
													case 0x57: {
														break;
													}
													case 0x58: {
														break;
													}
													case 0x59: {
														break;
													}
													case 0x5A: {
														break;
													}
													default:
														break;
													}
												}//koniec switcha z duzymi literami
												case 0xA2:
												case 0xA3:
												{
													switch (WH_KEYBOARD)
													{
													case 0x41:
													{
														break;
													}
													case 0x43:
													{
														break;
													}
													case 0x45:
													{
														break;
													}
													case 0x4C:
													{
														break;
													}
													case 0x4E:
													{
														break;
													}
													case 0x4F:
													{
														break;
													}
													case 0x53:
													{
														break;
													}
													case 0x58: //litera zi z kreska
													{
														break;
													}
													case 0x5A:
													{
														break;
													}
													case 0xA0:
													case 0xA1:
													{
														switch (WH_KEYBOARD)
														{
														case 0x41:
														{
															break;
														}
														case 0x43:
														{
															break;
														}
														case 0x45:
														{
															break;
														}
														case 0x4C:
														{
															break;
														}
														case 0x4E:
														{
															break;
														}
														case 0x4F:
														{
															break;
														}
														case 0x53:
														{
															break;
														}
														case 0x58: //litera zi z kreska
														{
															break;
														}
														case 0x5A:
														{
															break;
														}
														default:
															break;
														}
													}//koniec duzych liter polskich
													default:
														break;
													}
												}//koniec znakow z jezyka polskiego
												case VK_RETURN: {
													C_first_name first(data);
													human.m_get_first_name(first);
													break;
												}
												case VK_BACK: {
													data.m_pop_back();
													break;
												}
											}
											//if(b_what)
											break;
												//Mateusz dokoncz!!!
												//pobieraj litery i wstawiaj do N_striing data!!
												//nastepnie modul skopiuje i wstawie do innych danych :)
											
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
}
