#include <iostream>
#include <Windows.h>
#include "Data\Databases\tree.h"
#include "Data\Interface\aplication_txt.h"
#include "Data\Date\date.h"
#include "Data\Relation\relation.h"

int main()
{
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

	/*
	std::cout << "day:\t" <<day.m_what_type()<<"\t"<< Return << "\nmonth:\t" << month.m_what_type() << "\t"<< Return1 << "\nyear:\t" <<year.m_what_type()<<"\t"<< Return2 << "\nId:\t" <<Id.m_what_type()<<"\t"<< Return3 <<
		"\nFirst_name:\t" <<First.m_what_type()<<"\t"<< Return4 << "\nLast_name:\t" <<Last.m_what_type()<<"\t"<< Return5 << "\nGender:\t" <<gender.m_what_type()<<"\t"<< Return6 << "\n";

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
	if (L1 > L2) std::cout << "dobrze\n";else std::cout << "zle\n";    */

	/*C_aplication_txt AP;		// test menu w aplikacji - dzia³a!!!
	AP.SetWindow(100, 45);
	AP.CreateLogo();
	AP.MainMenu();
	*/

					//test na dzialanie C_date
	C_date date13('/');
	//date13.m_shift_day(12); 
	//date13.m_shift_month(10);
	//date13.m_shift_year(1991);
	date13.m_shift_day("31");
	date13.m_shift_month("2");
	date13.m_shift_year("1716");
	//std::cout << date13.m_set_DD_MM_YYYY()<<'\n';
	//std::cout << date13.m_set_MM_DD_YYYY() << "\n";
	//std::cout << date13.m_set_YYYY_MM_DD() << "\n";
	std::cout << date13.m_set_YYYY_DD_MM() << "\n";
	

	//test na poskie znaki
	/*C_first_name test101;
	N_striing fff = "£ukasz";
	test101.m_get_contens(fff);
	std::cout <<"test 101:"<< test101<<"\n";

	C_last_name test102;
	N_striing fff2 = "Miku³a";
	test102.m_get_contens(fff2);
	std::cout << "test 102:" << test102 << "\n";

	C_gender test103;
	//N_striing fff3 = "Men";
	//N_striing fff3 = "men";
	//N_striing fff3 = "1";
	//N_striing fff3 = "true";
	N_striing fff3 = "Women";
	//N_striing fff3 = "women";
	//N_striing fff3 = "0";
	//N_striing fff3 = "False";			--> nie dzia³a!!!
	test103.m_get_contens(fff3);
	std::cout << "test 103:" << test103 << "\n";
	*/

	//C_id test104;
	//test104.m_get_contens(45);
	//test104.m_get_contens(4543434);
	//test104.m_get_contens(05);
	//std::cout << test104.m_set_contens();


	/*C_day day2;
	N_striing ddd = "20";


	day2.m_get_day(ddd);
	std::cout << ddd << "\n";

	C_month month2;
	N_striing mmm = "10";


	month2.m_get_month(mmm);
	std::cout << mmm << "\n";

	C_year year2;
	N_striing yyy = "1999";


	year2.m_get_year(yyy);
	std::cout << yyy << "\n";
	*/

	C_children chil;

	chil.m_get_complete_content(34, 3);


	/*main_szyfrowanie("plik.txt", "dom", 5);
	system("type plik.txt");
	main_odszyfrowywanie("plik.txt", "dom", 5);*/



	return 0;
}