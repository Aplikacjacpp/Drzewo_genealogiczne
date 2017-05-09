#include <iostream>
#include "Data\Databases\tree.h"
#include "Data\Enginer\enigma.h"
int main()
{
	//C_data Data;
	C_day day;		// definicja zmiennej day
	C_month month;
	C_year year;
	C_id Id;
	
	C_last_name Last;
	C_gender gender(true);
	N_striing data = "Luka sz";
	C_first_name First(data);
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
	

	
	/*

	main_szyfrowanie("plik.txt", "dom", 5);
	system("type plik.txt");
	main_odszyfrowywanie("plik.txt", "dom", 5);*/
	return 0;
}