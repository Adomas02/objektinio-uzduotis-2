#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;

const int kiek = 5;

struct Mokinys {
	string vardas, pavarde;
	int paz[kiek];
	int egz;
	double rezult = 0;
};

void ivestis(std::vector<Mokinys>& mok);
void isvestis(std::vector<Mokinys>& mok, int a);
double skaiciavimas(double a, std::vector<Mokinys>& mok, int i);
double skaiciavimasVid(std::vector<Mokinys>& mok, int a);
void rikiavimas(std::vector<Mokinys>& mok, int a);
double skaiciavimasMed(std::vector<Mokinys>& mok, int i);
void pazymiuIvestis(std::vector<Mokinys>& mok, int a);

int main()
{
	srand(time(NULL));
	std::vector<Mokinys> a;
	//Mokinys a;
	ivestis(a);
}
void ivestis(std::vector<Mokinys>& mok)
{
	int i = 0;
	char y;
	while (1)
	{
		cout << "Ar norite ivesti mokini? y/n" << endl;
		cin >> y;
		if (y == 'y')
		{
			cout << "Iveskite mokinio varda ";
			mok.push_back(Mokinys());
			string vardas;
			cin >> vardas;
			mok[i].vardas = vardas;
			cout << "Iveskite mokinio pavarde ";
			string pavarde;
			cin >> pavarde;
			mok[i].pavarde = pavarde;

			cout << "Iveskite egzamino pazymi ";
			mok[i].egz = rand() % 10 + 1;
			cout << mok[i].egz << endl;
			pazymiuIvestis(mok, i);
			rikiavimas(mok, i);
			i++;

		}
		else
		{
			break;
		}

	}
	isvestis(mok, i);
}
void isvestis(std::vector<Mokinys>& mok, int a)
{
	cout << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0;i < a;i++)
	{
		cout << mok[i].vardas << setw(10) << mok[i].pavarde << setw(15) << fixed << setprecision(2) << skaiciavimasVid(mok, i) << setw(15) << fixed << setprecision(2) << skaiciavimasMed(mok, i) << endl;
	}

}
double skaiciavimasVid(std::vector<Mokinys>& mok, int a)
{
	double sum = 0, vid;//pazymiu suma, vidurkis
	for (int i = 0;i < kiek;i++)
	{
		sum += mok[a].paz[i];
	}
	vid = sum / kiek;
	mok[a].rezult = skaiciavimas(vid, mok, a);
	return mok[a].rezult;
}
void rikiavimas(std::vector<Mokinys>& mok, int a)
{
	int laikinas;
	for (int i = 0;i < kiek; i++)
		for (int j = i + 1;j < kiek;j++)
		{
			if (mok[a].paz[i] > mok[a].paz[j])
			{
				laikinas = mok[a].paz[i];
				mok[a].paz[i] = mok[a].paz[j];
				mok[a].paz[j] = laikinas;
			}

		}
}
double skaiciavimas(double a, std::vector<Mokinys>& mok, int i)
{
	mok[i].rezult = 0.4 * a + 0.6 * mok[i].egz;
	return mok[i].rezult;
}
double skaiciavimasMed(std::vector<Mokinys>& mok, int i)
{
	if (kiek % 2 == 0)
	{
		double laikMed;
		laikMed = ((mok[i].paz[kiek / 2] + mok[i].paz[kiek / 2 - 1]) / 2.0);
		mok[i].rezult = skaiciavimas(laikMed, mok, i);
		return mok[i].rezult;
	}
	else
	{
		mok[i].rezult = skaiciavimas(mok[i].paz[kiek / 2], mok, i);
		return mok[i].rezult;
	}
}
void pazymiuIvestis(std::vector<Mokinys>& mok, int a)
{
	int i = 0;
	for (int j = 0;j < kiek;j++)
	{
		cout << "Iveskite namu darbu pazymi ";

		int pazLaik;//laikinas pazimys
		pazLaik = rand() % 10 + 1;
		cout << pazLaik << endl;
		mok[a].paz[i] = pazLaik;
		i++;
	}
}