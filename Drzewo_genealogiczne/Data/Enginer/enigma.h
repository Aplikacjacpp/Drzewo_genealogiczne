#include <iostream>
#include <fstream>
#include <string>
#include "../narzedzia/Vektor.h"
#include "../narzedzia/striing.h"
struct alfabet
{
	char litera;
	int lp;
	int ascii;
};
N_striing szyfrowanie_sz(N_vektor<alfabet>& v, N_striing& haslo, N_vektor<N_striing>& s);
void ladowanie_sz(N_vektor<alfabet> &v);
int main_rozkowowywanie(N_striing a);
void wczytuj_sz(N_striing& slowo, N_vektor<N_striing>& s);
void zapis_sz(N_striing a, N_striing& haslo, int* s);
N_striing szyfrowanie(N_striing& slowo, N_vektor<alfabet> &v, N_striing& haslo);
void wczytuj(N_striing& haslo, bool& istnieje);
void wczytaj(N_striing a, N_striing& slowo)
{
	std::fstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		N_striing	slow = "";
		while (getline(file, slow.m_sts()))
		{
			slowo += slow;
		}
		file.close();
	}
}
void zapis(N_striing a, N_striing& haslo);
void wczytaj_rozkodowacz(N_striing a, N_vektor <N_striing> &date, bool& istnieje);
void analizuj_rozkodowacz(N_vektor <N_striing> &date, N_striing files);
int main_odszyfrowywanie(N_striing a, N_striing tablica[], int X)
{
	N_vektor <alfabet> v;
	N_striing slowo = "", haslo = "";
	haslo = tablica[X];
	wczytaj(a, slowo);
	ladowanie_sz(v);
	haslo = szyfrowanie(slowo, v, haslo);
	zapis(a, haslo);
	main_rozkowowywanie(a);
	return 0;
}
N_striing szyfrowanie(N_striing& slowo, N_vektor<alfabet>& v, N_striing& haslo)
{
	N_striing szyfr = "";
	int x = 0;

	for (int j = 0; j < slowo.m_size(); j++)
	{

		alfabet t, d;
		for (int o = 0; o < 222; o++)
		{
			t = v[o];

			if (t.litera == slowo[j])
			{
				break;
			}
		}
		for (int o = 0; o < 222; o++)
		{
			d = v[o];

			if (d.litera == haslo[x])
			{
				break;
			}
			else
			{
				if (x == haslo.m_size() - 1)
					x = 0;
				else
					x++;
			}
		}
		if ((t.lp - d.lp) >0)
		{
			szyfr += t.litera - d.lp;
		}
		else if ((t.lp - d.lp) == 0)
		{
			szyfr += v[(t.lp - 1 - d.lp - 1) + 220].litera;
		}
		else
		{
			szyfr += v[(t.lp - d.lp) + 220].litera;
		}
	}
	return szyfr;
}
void zapis(N_striing a, N_striing& haslo)
{
	std::ofstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		file << haslo;
		file.close();
	}
}

void wczytuj(N_striing& haslo, bool& istnieje)
{

	std::fstream file;
	file.open(haslo.m_c_str());
	if (file.good())
	{
		N_striing linie = "";
		istnieje = true;
		haslo = "";
		while (getline(file, linie.m_sts()))
		{
			haslo += linie;
		}
		file.close();
	}
	else
	{
		istnieje = false;
	}
}
int main_rozkowowywanie(N_striing a)
{
	N_vektor <N_striing> data;
	bool istnieje;
	wczytaj_rozkodowacz(a, data, istnieje);
	analizuj_rozkodowacz(data, a);
	return 0;
}
void wczytaj_rozkodowacz(N_striing a, N_vektor <N_striing> &date, bool& istnieje)
{
	std::fstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		istnieje = true;
		N_striing linia;
		while (getline(file, linia.m_sts()))
		{
			date.m_push_back(linia);
		}
		file.close();
	}
	else
	{
		istnieje = false;
	}
}
void analizuj_rozkodowacz(N_vektor <N_striing> &date, N_striing files)
{
	std::ofstream file;
	file.open(files.m_c_str());
	if (file.good())
	{
		for (long long i = 0; i < date.m_size(); i++)
		{
			N_striing retu;
			retu = date[i];
			int x = retu.m_size();
			for (int j = 0; j < x - 2; j++)
			{
				if (retu[j] == '#'&&retu[j + 1] == '@'&&retu[j + 2] == '#')
				{
					file << "\n";
					j = j + 2;
				}
				else
				{
					file << retu[j];
				}
			}
		}
		file.close();
	}
}
int main_szyfrowanie(N_striing a, N_striing tablica[], int X)
{
	int s = 0;
	N_vektor <alfabet> v;
	N_vektor <N_striing> slo;
	N_striing  haslo = "";
	haslo = tablica[X];
	ladowanie_sz(v);
	wczytuj_sz(a, slo);
	haslo = szyfrowanie_sz(v, haslo, slo);
	zapis_sz(a, haslo, &s);
	return 0;
}
void ladowanie_sz(N_vektor<alfabet> &v)
{
	char lit = ' ';
	for (int i = 0; i <222; i++)
	{
		alfabet t;
		t.litera = lit;
		t.lp = i + 1;
		t.ascii = (int)lit;

		v.m_push_back(t);
		lit++;
	}
}
N_striing szyfrowanie_sz(N_vektor<alfabet>& v, N_striing& haslo, N_vektor<N_striing>& s)
{
	N_striing slowo = "", szyfr = "";
	for (int i = 0; i < s.m_size(); i++)
	{
		N_striing g;
		g = s[i];
		slowo = slowo + g;
	}
	int x = 0;
	for (int j = 0; j < slowo.m_size(); j++)
	{
		alfabet t, d;
		for (int o = 0; o < 222; o++)
		{
			t = v[o];

			if (t.litera == slowo[j])
			{
				break;
			}
		}
		for (int o = 0; o < 222; o++)
		{
			d = v[o];

			if (d.litera == haslo[x])
			{
				break;
			}
			else
			{
				if (x == haslo.m_size() - 1)
					x = 0;
				else
					x++;
			}
		}
		if ((t.lp + d.lp) < 222)
		{
			szyfr += t.litera + d.lp;
		}
		else if ((t.lp + d.lp) == 444)
		{
			szyfr += v[(t.lp - 1 + d.lp - 1) - 222].litera;
		}
		else if ((t.lp + d.lp) >= 222 && (t.lp + d.lp)<444)
		{
			szyfr += v[(t.lp + d.lp) - 222].litera;
		}
	}
	return szyfr;
}
void zapis_sz(N_striing a, N_striing& haslo, int* s)
{
	std::ofstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		int x = haslo.m_size();
		if (x>256)
		{
			int y = x / 256;

			for (int i = 0; i < y; i++)
			{
				if (i == 0)
				{
					for (int j = 0; j < 256; j++) {
						file << haslo[j];
					}
					file << "\n";
				}
				if (i > 0)
				{
					if (i == y - 1)
					{
						for (int ze = i * 256; ze < (i + 1) * 256; ze++)
						{
							file << haslo[ze];
						}
						file << "\n";
						for (int st = ((i + 1) * 256) + 1; st < x; st++)
						{
							file << haslo[st];
						}
						file << "\n";
					}
					else
					{
						for (int z = i * 256; z < (i + 1) * 256; z++)
						{
							file << haslo[z];
						}
						file << "\n";
					}
				}
			}
		}
		else
		{
			file << haslo;

		}
		file.close();
	}
	else
	{
		*s = 1;
	}
}
void wczytuj_sz(N_striing& slowo, N_vektor<N_striing>& s)
{
	N_striing linia = "";
	std::fstream file;
	file.open(slowo.m_c_str());
	if (file.good())
	{

		while (getline(file, linia.m_sts())) {
			linia += "#@#";
			s.m_push_back(linia);
		}
		file.close();
	}
}
