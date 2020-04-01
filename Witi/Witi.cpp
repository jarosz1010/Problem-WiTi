// Witi.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include "pch.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int koszt1, koszt2, koszt3;
int cz2;
struct problem {
	int p;
	int w;
	int d;
	int lp;
};
std::vector < problem > tab;
ostream& operator<< (ostream& wyjscie, const problem& pom) {
	return wyjscie <<"Numer:"<<pom.lp << " p:" << pom.p << " w:" << pom.w << " d:" << pom.d << endl;
}
bool d_sort(const problem& a, const problem& b)
{
	// smallest comes first
	return a.d < b.d;
}
/////////////////////////////////////////////////////////////////
void Wczytaj(string Nazwapliku) {
	string linia;
	fstream plik;
	int liczba;

	plik.open(Nazwapliku, ios::in);
	if (plik.good() == true)
	{
		plik >> liczba;

		string pomoc;
		plik >> pomoc;
		for (int i = 0; i < liczba; i++)
		{
			problem tmp;
			plik >> tmp.p >> tmp.w >> tmp.d;
			tmp.lp = i;
			tab.push_back(tmp);

		}
		plik.close();
	}
}
////////////////////////////////////////////////////////////////////////

int funkcja_celu(vector<problem> tabela) {
	int koszt = 0;
	int czas = 0;
	for (int i = 0; i < tabela.size(); i++) {
		czas = czas + tabela[i].p;
		if (czas > tabela[i].d) koszt = koszt + ((czas - tabela[i].d)*tabela[i].w);
	}
	return koszt;
}




void permutuj(vector<problem> &tabela, int poz = 0) {
	
	if (poz == tabela.size()) {
		cz2 = funkcja_celu(tabela);
		
		koszt3 = min(koszt3, cz2);
	}
	else {
		for (int i = poz; i < tabela.size(); i++) {
			swap(tabela[i], tabela[poz]);
			permutuj(tabela, poz + 1);
			swap(tabela[i], tabela[poz]);
		}
	}
}

	int main()
	{
		
		
		Wczytaj("data10.txt");
		koszt3 =koszt1 = funkcja_celu(tab);
		cout << "1234:" << koszt1 <<endl;
		sort(tab.begin(), tab.end(), d_sort);
		koszt2 = funkcja_celu(tab);
		cout << "sortD:" << koszt2 << endl;
		
		permutuj(tab, 0);
		cout <<"opt:" <<koszt3<<endl;


	}

