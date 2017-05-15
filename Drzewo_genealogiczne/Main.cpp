#include <iostream>
#include <Windows.h>
#include "Data\Databases\tree.h"
#include "Data\Interface\aplication_txt.h"
#include "Data\Date\date.h"

int main()
{
	HANDLE okno = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD size;

	size.X = 120;
	size.Y = 60;

	SetConsoleScreenBufferSize(okno, size);

	//C_data Data;
	C_day day;		// definicja zmiennej day
	C_month month;
	C_year year;
	C_id Id;
	C_date date;
	C_last_name Last;
	C_gender gender(true);
	N_striing data = "Luka sz";
	C_first_name First(data);
	//date()
	int X;
	int Return = 0;
	data = day.m_what_type();
	for (X = 0; X < data.m_size(); X++)
	{
		Return += (int)data[X];
	}
	int Return1 = 0;
	data = month.m_what_type();
	for (X = 0; X < data.m_size(); X++)
	{
		Return1 += (int)data[X];
	}
	int Return2 = 0;
	data = year.m_what_type();
	for (X = 0; X < data.m_size(); X++)
	{
		Return2 += (int)data[X];
	}
	int Return3 = 0;
	data = Id.m_what_type();
	for (X = 0; X < data.m_size(); X++)
	{
		Return3 += (int)data[X];
	}
	int Return4 = 0;
	data = First.m_what_type();
	for (X = 0; X < data.m_size(); X++)
	{
		Return4 += (int)data[X];
	}
	int Return5 = 0;
	data = Last.m_what_type();
	for (X = 0; X < data.m_size(); X++)
	{
		Return5 += (int)data[X];
	}
	int Return6 = 0;
	data = gender.m_what_type();
	for (X = 0; X < data.m_size(); X++)
	{
		Return6 += (int)data[X];
	}
	std::cout << "day:\t" <<day.m_what_type()<<"\t"<< Return << "\nmonth:\t" << month.m_what_type() << "\t"<< Return1 << "\nyear:\t" <<year.m_what_type()<<"\t"<< Return2 << "\nId:\t" <<Id.m_what_type()<<"\t"<< Return3 <<
		"\nFirst_name:\t" <<First.m_what_type()<<"\t"<< Return4 << "\nLast_name:\t" <<Last.m_what_type()<<"\t"<< Return5 << "\nGender:\t" <<gender.m_what_type()<<"\t"<< Return6 << "\n";
/* test*/
	C_id D1(100), D2(14);
	if (D1 > D2) std::cout << "dobrze\n";else std::cout << "zle\n";
	data = "acdd";
	N_striing data1 = "abc";
	if (data > data1) std::cout << "dobrze\n"; else std::cout << "zle\n";
C_last_name L1, L2;
	data = "acb";
	L1.m_get_contens(data);
	data = "abc";
	L2.m_get_contens(data);
	if (L1 > L2) std::cout << "dobrze\n";else std::cout << "zle\n";

	C_aplication_txt AP;		// test menu w aplikacji - dzia³a!!!

	AP.CreateLogo();
	AP.MainMenu();
	

					//test na dzialanie C_date
	/*C_date date13('/');
	date13.m_shift_day(12); 
	date13.m_shift_month(10);
	date13.m_shift_year(1991);
	std::cout << date13.m_set_DD_MM_YYYY()<<'\n';

	//test na poskie znaki
	C_first_name test101;
	N_striing fff = "£ukasz";
	test101.m_get_contens(fff);
	std::cout <<"test 101:"<< test101<<"\n\n";

	*/

	/*main_szyfrowanie("plik.txt", "dom", 5);
	system("type plik.txt");
	main_odszyfrowywanie("plik.txt", "dom", 5);*/
	return 0;
}