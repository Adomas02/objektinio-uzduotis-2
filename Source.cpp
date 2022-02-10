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

struct data {
	string vardas, pavarde;
	int paz[3], egz,kiek;
	double rezult = 0;
};
void ivestis(data& temp);
void isvestis(data& temp);
double skaiciavimas(data& temp);
int main()
{
	data a;
	ivestis(a);
	isvestis(a);
	
}
void ivestis(data& temp)
{
	cout << "Iveskite mokinio varda ";
	cin >> temp.vardas;
	cout << "Iveskite mokinio pavarde ";
	cin >> temp.pavarde;
	cout << "Iveskite pazymiu skaiciu ";
	cin >> temp.kiek;
	cout << "Iveskite pazymius"<<endl;
	for (int i = 0;i < temp.kiek;i++)
	{
		cin >> temp.paz[i];
	}
	cout << "Iveskite egzamino pazymi ";
	cin >> temp.egz;
}
void isvestis(data& temp)
{
	cout <<"Vardas" << setw(10) <<"Pavarde" << setw(20) <<"Galutinis (Vid.)"<<endl;
	cout << "--------------------------------------"<<endl;
	cout << temp.vardas << setw(10) << temp.pavarde<<setw(10)<<fixed<<setprecision(2)<<skaiciavimas(temp);
}
double skaiciavimas(data& temp)
{
	double sum=0,vid;//pazymiu suma, vidurkis ir galutinis
	for (int i = 0;i < temp.kiek;i++)
	{
		sum += temp.paz[i];
	}
	vid = sum / temp.kiek;
	temp.rezult = 0.4 * vid + 0.6 * temp.egz;
	return temp.rezult;
	
}
