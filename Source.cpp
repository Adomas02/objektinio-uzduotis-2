#include<iomanip>
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;

struct Mokinys {
	string vardas, pavarde;
	int* paz;
	int egz, kiek;
	double rezult = 0;
};
void ivestis(Mokinys& mok);
void isvestis(Mokinys& mok);
double skaiciavimas(double a, Mokinys& mok);
double skaiciavimasVid(Mokinys& mok);
void rikiavimas(Mokinys& mok);
double skaiciavimasMed(Mokinys& mok);

int main()
{
	Mokinys a;
	ivestis(a);
	rikiavimas(a);
	isvestis(a);

}
void ivestis(Mokinys& mok)
{
	cout << "Iveskite mokinio varda ";
	cin >> mok.vardas;
	cout << "Iveskite mokinio pavarde ";
	cin >> mok.pavarde;
	cout << "Iveskite pazymiu skaiciu ";
	cin >> mok.kiek;
	cout << "Iveskite pazymius" << endl;

	mok.paz = new int[mok.kiek];

	for (int i = 0;i < mok.kiek;i++)
	{
		cin >> mok.paz[i];
	}
	cout << "Iveskite egzamino pazymi ";
	cin >> mok.egz;
}
void isvestis(Mokinys& mok)
{
	cout << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) <<"Galutinis (Med.)" << endl;
	cout << "--------------------------------------" << endl;
	cout << mok.vardas << setw(10) << mok.pavarde << setw(10) << fixed << setprecision(2) << skaiciavimasVid(mok)<< setw(10) << skaiciavimasMed(mok) << endl;



}
double skaiciavimasVid(Mokinys& mok)
{
	double sum = 0, vid;//pazymiu suma, vidurkis
	for (int i = 0;i < mok.kiek;i++)
	{
		sum += mok.paz[i];
	}
	vid = sum / mok.kiek;
	mok.rezult=skaiciavimas(vid,mok);
	return mok.rezult;
}
void rikiavimas(Mokinys& mok)
{
	int laikinas;
	for (int i = 0;i < mok.kiek; i++)
		for (int j = i + 1;j < mok.kiek;j++)
		{
			if (mok.paz[i] > mok.paz[j])
			{
				laikinas = mok.paz[i];
				mok.paz[i] = mok.paz[j];
				mok.paz[j] = laikinas;
			}

		}
}
double skaiciavimas(double a,Mokinys& mok)
{
	mok.rezult = 0.4 * a + 0.6 * mok.egz;
	return mok.rezult;
}
double skaiciavimasMed(Mokinys& mok)
{
	if (mok.kiek % 2 == 0)
	{
		double laikMed;
		laikMed =( (mok.paz[mok.kiek / 2] + mok.paz[mok.kiek / 2 - 1]) / 2.0);
		mok.rezult = skaiciavimas(laikMed, mok);
		return mok.rezult;
	}
	else
	{
		mok.rezult = skaiciavimas(mok.paz[mok.kiek/2], mok);
		return mok.rezult;
	}
}
