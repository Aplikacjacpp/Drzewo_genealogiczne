#include <iostream>
#include <Windows.h>
#include "Data\Databases\tree.h"
#include "Data\Interface\aplication_txt.h"
#include "Data\Date\date.h"
#include "Data\Relation\relation.h"
#include "Data\Enginer\enginer.h"

int main()
{
	C_sl_personalys personal;
	
	C_enginer Engin;
	//C_data Data;
	C_day day;		// definicja zmiennej day
	C_month month;
	C_year year;
	C_id Id(102);
	C_date date('.');
	C_date date_s('.');

	date.m_shift_day("21");
	date.m_shift_month("10");
	date.m_shift_year("1945");
	date.m_set_DD_MM_YYYY();

	date_s.m_shift_day("11");
	date_s.m_shift_month("10");
	date_s.m_shift_year("1995");
	date_s.m_set_DD_MM_YYYY();

	N_striing data, datak;
	data = "Witek";
	C_first_name First(data);
	C_last_name Last(data);
	datak = "Witkowski";
	C_last_name Last1(datak);

	C_human human;
	C_gender gender(true);

	/*ponizsza metoda ucina stringi do podanej liczby bedacej suma imienia i nazwiska - tutaj podobnie musialem zastosowac stigni (2 pierwsze arg) bo by nie dzialaly meody
	size cut i erase - znowu human pobiera siebie w argumencie - byc moze nie tak sie robi ale jeszcze nie opanowalem dobrze programowania - pewnie beda poprawki:P*/
	human.interf_cut(datak, data, human, 13);

	human.m_get_first_name(First);
	human.m_get_last_name(Last);
	human.m_get_last_name(Last1);
	human.m_get_gender(gender);

	std::cout << std::endl << std::endl;

	/*ponizsza metoda wyswietlajaca dane humana- niestety musialem date zrobic drugim argumentem gdyz operator ostream nie toleruje intow i mimo ze kombinowalem
	z przeciazeniami operatora to nie udalo mi sie zroibc tak zeby je tolerowal - argument daty smierci jest domniemany wiec mozna go usunac jesli ktos zyje
	- i nie wiem czy dodanie obiektu humana do wlasnej metody jest zgodne ze sztuka programowania ale dziala :P - pewnie beda jeszcze poprawki bo zamotalem :P */
	human.interf_m(human, date, date_s);

	std::cout << std::endl;

	/*tutaj z data podobnie bo ostream nie toleruje intow - niestety musialem zmienic poki co na recznie wstawianego striinga bo z danych humana nie mozna
	uzywac metody stringowej m_size() jak rowniez m_erase_ray() wiec tez pewno beda jeszcze poprawki*/
	human.interf_mb("Rick", "Grimes", date, date_s);
	
	std::cout << std::endl;

	/*ponizej to samo co wyzej ale jakby obramowanie dynamiczne poszerzajace sie wraz z imieniem i naziwksiem, ale pewnie nie bedzie uzywane */
	human.interf_mbd("Tywin", "Lannisterrrr", date, date_s);

	std::cout << std::endl << std::endl;

	
	N_vektor<int> V;
	V.m_push_back(10);
	V.m_push_back(11);
	N_vektor<int> D;
	D = V;
	std::cout << D[0] << D[1] << "\n";
	//return 0;
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

	/*C_aplication_txt AP;		// test menu w aplikacji - dzia�a!!!
	AP.SetWindow(100, 45);
	AP.CreateLogo();
	AP.MainMenu();*/
	

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
	data = "#+";
	C_date date14(date13);
	C_date *date15 = new C_date;
	*date15 = date14;
	//std::cout << date15[0].m_set_YYYY_DD_MM() << "\n";
	N_vektor<C_date> Vektorek;
	Vektorek.m_push_back(date15[0]);
	std::cout <<"z wektora"<< Vektorek[0].m_set_YYYY_DD_MM() << "\n";
	std::cout <<"oddzielnie: "<< date14.m_day_set() << "/" << date14.m_month_set() <<"/"<< date14.m_year_set() << "\n";
	date13.m_get_type(data);
	human.m_get_date(date15[0]);
	Engin.m_new_human(human);
	Engin.m_create_human(0);
	//test na poskie znaki
	/*C_first_name test101;
	N_striing fff = "�ukasz";
	test101.m_get_contens(fff);
	std::cout <<"test 101:"<< test101<<"\n";

	C_last_name test102;
	N_striing fff2 = "Miku�a";
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
	//N_striing fff3 = "False";			--> nie dzia�a!!!
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
	//Engin.m_save_files();
	system("type data.save");
	std::cout << "\n";
	system("type date.save");

	system("PAUSE");

	return 0;
}