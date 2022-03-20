#include "funkcijos.h"

/*
void ivestis(std::vector<Mokinys> &mok,int kiek)
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
			pazymiuIvestis(mok, i,kiek);
			rikiavimas(mok, i,kiek);
			i++;
		}
		else
		{
			break;
		}
	}
	//isvestis(mok, i);
}*/
/*
void isvestis(std::vector<Mokinys> &mok, int kiek)
{
	std::ofstream out_f("kursiokai.txt");

	// out_f << outputas;

	out_f << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
	out_f << "----------------------------------------------------------" << endl;
	int i = 0;
	// sortabc(mok);
	for (Mokinys &m : mok)
	{
		rikiavimas(mok, i, kiek);
		out_f << mok[i].vardas << setw(20) << mok[i].pavarde << setw(15) << fixed << setprecision(2) << skaiciavimasVid(mok, i, kiek) << setw(15) << fixed << setprecision(2) << skaiciavimasMed(mok, i, kiek) << endl;
		i++;
	}
	out_f.close();
}*/
/*double skaiciavimasVid(Mokinys mok, int kiek)
{
	double sum = 0, vid; // pazymiu suma, vidurkis
	for (int i = 0; i < kiek; i++)
	{
		sum += mok.paz[i];
	}
	vid = sum / kiek;
	mok.rezult = skaiciavimas(vid, mok);
	return mok.rezult;
}*/



/*void pazymiuIvestis(std::vector<Mokinys> &mok, int a, int kiek)
{
	int i = 0;
	for (int j = 0; j < kiek; j++)
	{
		cout << "Iveskite namu darbu pazymi ";

		int pazLaik; // laikinas pazimys
		pazLaik = rand() % 10 + 1;
		cout << pazLaik << endl;
		mok[a].paz[i] = pazLaik;
		i++;
	}
}*/

/*void pazymiuIvestis(Mokinys mok, int kiek)
{
	int i = 0;
	for (int j = 0; j < kiek; j++)
	{
		// cout << "Iveskite namu darbu pazymi ";

		int pazLaik; // laikinas pazimys
		pazLaik = rand() % 10 + 1;
		// cout << pazLaik << endl;
		mok.paz[i] = pazLaik;
		i++;
	}
}*/

std::vector<std::string> split(std::string str, char delimiter)
{
	std::vector<std::string> result;
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delimiter, end)) != std::string::npos)
	{
		end = str.find(delimiter, start);
		result.push_back(str.substr(start, end - start));
	}

	return result;
}
/*std::vector<Mokinys> sortabc(std::vector<Mokinys> mok)
{
	Mokinys laikinas;
	for (Mokinys &m : mok)
		for (Mokinys &n : mok)
			if (m.vardas > n.vardas)
			{
				laikinas = m;
				m = n;
				n = m;
			}

	return mok;
}*/
void SarasuGeneravimas()
{
	std::vector<std::vector<Mokinys>> sarasuSarasas;
	int n = 1000; //kiek mokiniu pirmame faile
	int kiek = 5; // kiek pazymiu vienam mokiniui

	// cout << "pradzia" << endl;

	for (int i = 0; i < 5; i++)
	{
		std::vector<Mokinys> mokSarasas;
		for (int j = 0; j < n; j++)
		{
			Mokinys mok = Mokinys();
			// cout << "mokinys sukurtas" << endl;

			mok.vardas = "Vardas" + std::to_string(j + 1);
			mok.pavarde = "Pavarde" + std::to_string(j + 1);

			mok.paz = new int[kiek];
			for (int k = 0; k < kiek; k++)
			{
				int pazLaik; // laikinas pazimys
				pazLaik = rand() % 10 + 1;
				mok.paz[k] = pazLaik;
			}
			mok.egz = rand() % 10 + 1;
			mokSarasas.push_back(mok);
			// cout << "mokinys idetas" << endl;

			// sarasuSarasas[i][j].vardas="Vardas";
			// cout << sarasuSarasas[i][j].vardas;
		}
		sarasuSarasas.push_back(mokSarasas);

		n = n * 10;
	}

	sarasuIsvedimas(sarasuSarasas, kiek);
}
void sarasuIsvedimas(std::vector<std::vector<Mokinys>> sarasuSarasas, int kiek)
{

	for (int i = 0; i < sarasuSarasas.size(); i++)
	{
		std::string writeFile = "Mokiniai" + std::to_string(sarasuSarasas[i].size()) + ".txt";
		std::string writeFileRez = "Mokiniai" + std::to_string(sarasuSarasas[i].size()) + "Rez.txt";
		std::ofstream out_f(writeFile);
		std::vector<Mokinys> mokSarasas;
		for (int j = 0; j < sarasuSarasas[i].size(); j++)
		{
			out_f << sarasuSarasas[i][j].vardas << " ";
			out_f << sarasuSarasas[i][j].pavarde << " ";
			out_f << sarasuSarasas[i][j].egz << " ";
			for (int k = 0; k < kiek; k++)
			{
				out_f << sarasuSarasas[i][j].paz[k] << " ";
			}
			out_f << endl;
		}
		// cout << i + 1 << " saraso pabaiga" << endl;
		bufer_nusk(writeFile, writeFileRez);
		out_f.close();
	}

	// bufer_nusk(writeFile, write_vardas);

	// cout << "pabaiga" << endl;
}
void bufer_nusk(std::string read_vardas, std::string write_vardas)
{


	std::vector<std::string> splited;
	std::string eil, tmp;
	std::stringstream my_buffer;

	// nuskaitymas i bufferi
	auto start = std::chrono::high_resolution_clock::now(); auto st=start;
	std::ifstream open_f(read_vardas);

	my_buffer << open_f.rdbuf();

	open_f.close();
	int kiek=0;

	std::vector<Mokinys> mokiniai;

	// bufferio padalijimas i eiluciu vektoriu
	while (my_buffer)
	{
		//cout << "ciklo pradzia " << endl;

		if (!my_buffer.eof())
		{
			std::getline(my_buffer, eil);
			//cout << "ciklo viduj " << eil << endl;
			if (eil.size() > 0)
			{
				std::vector<std::string> eilDalys = split(eil, ' ');
				for (std::string &a : eilDalys)
				{
					kiek++;
				}

				Mokinys mok = Mokinys();
				mok.vardas = eilDalys[0];
				mok.pavarde = eilDalys[1];

				mok.paz = new int[kiek];
				for (int i = 0; i < kiek - 3; i++)
				{
					mok.paz[i] = std::stoi(eilDalys[2 + i]);
				}

				mok.egz = std::stoi(eilDalys[kiek - 1]);
				kiek=0;

				mokiniai.push_back(mok);
				// cout<<mokiniai.vardas;
				splited.push_back(eil);
			}
			else
			{
				break;
			}

			//cout << "prad" << endl;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end-start; // Skirtumas (s)
	std::cout << "Failo nuskaitymo su "<< mokiniai.size()<<" mokiniu laikas: "<< diff.count() << " s\n";

	std::vector<Mokinys> ProtingiMokiniai;
	std::vector<Mokinys> NeprotingiMokiniai;
	int vid;
	for(int i=0;i<mokiniai.size();i++)
	{ 
		int sum=0;
		for(int j=0;j<kiek - 3;j++)
		{
			sum+=mokiniai[i].paz[j];

		}
		
		vid=sum/(kiek - 3)*1.0;
		
		if(vid>=5)
		{
			
			ProtingiMokiniai.push_back(mokiniai[i]);
			

		}
		else{
			NeprotingiMokiniai.push_back(mokiniai[i]);
		}
		

	}
	cout<<"po skirstymo";
	cout<<ProtingiMokiniai[0].vardas<<endl;
	cout<<NeprotingiMokiniai[0].vardas<<endl;



	for(int i=0;i<ProtingiMokiniai.size();i++)
	{
		cout<<ProtingiMokiniai[i].vardas<<endl;
	}


	
	
	
	//cout<<"Press any key to continue... ";
	//string a;
	//cin>>a;



	/*for(int i=0;i<mokiniai.size();i++)
	{
		cout<<mokiniai[i].vardas<<" "<<mokiniai[i].pavarde<<" ";
		for (int j = 0; j < 2; j++)
		{
			cout<<mokiniai[i].paz[j]<<" ";
		}
		cout<<mokiniai[i].egz<<endl;

	}
	*/

}

