/***************************************************************************************************************
*"odczyt.cpp"
*
*
*
*
*
*CONTENTS:
* "Klasa Person + odczyt z pliku"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     29.04.2017  Orginal design													  Mateusz Marchelewicz
****************************************************************************************************************/







#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Person
{

public:
    int ID, day, month, year;
    string name, surname;
    bool gender;

};


int main()
{
    char file[256];
    string z = "";

    cout << "Podaj nazwe pliku: ";
    cin >> file;

    ifstream ifs;
    ifs.open(file);

    if(ifs.is_open())
    {

        while(ifs.good())
        {

    int n;
    ifs >> n;

    Person *P = new Person[n];

    for(int i = 0; i < n; i++)
    {
        ifs >> z;
        if(z == "$0")
        {
           ifs >> P[i].ID;
        }
        else
        { cout << "Blad pliku"; exit(1); }

            ifs >> z;
            if(z == "$1")
            {
               ifs >> P[i].name;
            }
            else { cout << "Blad pliku"; exit(1); }

               ifs >> z;
               if(z == "$2")
               {
                   ifs >> P[i].surname;
               }
               else { cout << "Blad pliku"; exit(1); }

                 ifs >> z;
                 if(z=="$3")
                 {
                     ifs >> P[i].gender;
                 }
                 else { cout << "Blad pliku"; exit(1); }

                   ifs >> z;
                   if(z=="$4")
                   {
                     ifs >> P[i].day;
                   }
                   else { cout << "Blad pliku"; exit(1); }

                     ifs >> z;
                     if(z=="$5")
                     {
                       ifs >> P[i].month;
                     }
                     else { cout << "Blad pliku"; exit(1); }

                        ifs >> z;
                        if(z=="$6")
                        {
                           ifs >> P[i].year;
                        }
                        else { cout << "Blad pliku"; exit(1); }

    }

            for(int i = 0; i < n; i++)
            {
                cout << "ID = " << P[i].ID << "  " << "Name = " << P[i].name;
                cout << "  Surname = " << P[i].surname << "  g = " << P[i].gender;
                cout << "  Date of birth: " << P[i].day << "-" << P[i].month << "-" << P[i].year << endl;
            }


            for(int i = 1; i < 2; i++)      // wypisze TYLKO jedna osobe!!!
            {
            //int idd;          // szukanie po ID
            //cin >> idd;
            //if(P[i].ID == idd) cout << P[i].surname;  // np. wypisze nazwisko

            string sur;         // szukanie po nazwisku
            cin >> sur;
            if(P[i].surname == sur) cout << P[i].name;  // np. wypisze imie tej osoby (my bedziemy wyswietlac wszystkie dane)

            }


        }

    }

    else
    {
        cout << "Nie ma drzewa o takim pliku!!!";
    }


    return 0;
}
