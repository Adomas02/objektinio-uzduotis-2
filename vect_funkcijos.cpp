#include "funkcijos.h"

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



void bufer_nusk(std::string read_vardas)
{
	std::vector<std::string> splited;
	std::string eil, tmp;
	std::stringstream my_buffer;

	// nuskaitymas i bufferi
	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	std::ifstream open_f(read_vardas);
	try
	{
		if (!open_f){
			throw 1;
		}
			
	}catch (int x){
		cout<<"Failas neegzistuoja "<<endl;
		return;
	}

	my_buffer << open_f.rdbuf();

	open_f.close();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start; // Skirtumas (s)
	std::cout << "Failo nuskaitymo laikas: " << diff.count() << " s\n";

	auto start5 = std::chrono::high_resolution_clock::now();
	auto st5 = start5;

	int kiek = 0;
	int toliauKiek;

	std::vector<Mokinys> mokiniai;

	// bufferio padalijimas i eiluciu vektoriu
	while (my_buffer)
	{
		// cout << "ciklo pradzia " << endl;

		if (!my_buffer.eof())
		{
			std::getline(my_buffer, eil);
			// cout << "ciklo viduj " << eil << endl;
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
				toliauKiek = kiek;
				kiek = 0;
				mok.rezult=skaiciavimasVid(mok,toliauKiek);
				mokiniai.push_back(mok);
				// cout<<mokiniai.vardas;
				splited.push_back(eil);
			}
			else
			{
				break;
			}

			// cout << "prad" << endl;
		}
	}

	auto end5 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff5 = end5 - start5; // Skirtumas (s)
	std::cout << "Failo paruosimo laikas: " << diff5.count() << " s\n";


	// Skirstymas i dvi grupes pirma strategija
	auto start1 = std::chrono::high_resolution_clock::now();
	auto st1 = start1;
	std::vector<Mokinys> ProtingiMokiniai;
	std::vector<Mokinys> NeprotingiMokiniai;
	double galutinis;
	for(auto el:mokiniai)
	{
		
		if (el.rezult >= 5)
		{
			ProtingiMokiniai.push_back(el);
		}
		else
		{
			NeprotingiMokiniai.push_back(el);
		}
	}
	
	int mokSk = mokiniai.size();
	//mokiniai.clear();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1; // Skirtumas (s)
	std::cout << "Iraso dalinimo i dvi grupes laikas: " << diff1.count() << " s\n";
    
	// Protingu isvedimas
	protinguIsvedimas(ProtingiMokiniai, mokSk);

	// Neprotingu isvedimas
	neProtinguIsvedimas(NeprotingiMokiniai, mokSk);
    

	// Skirstymas i dvi grupes antra strategija
	auto start11 = std::chrono::high_resolution_clock::now();
	auto st11 = start11;
	std::vector<Mokinys> NeprotingiMokiniai2;
	
	for(auto el:mokiniai)
	{
		
		if (el.rezult >= 5)
		{
			
		}
		else
		{
			NeprotingiMokiniai2.push_back(el);
		}
	}

	std::erase_if(mokiniai, [](Mokinys x) { return x.rezult < 5; });
	auto end11 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff11 = end11 - start11; // Skirtumas (s)
	std::cout << "Iraso dalinimo i dvi grupes kuriant viena konteineri laikas: " << diff11.count() << " s\n";

	// Protingu isvedimas
	protinguIsvedimas(mokiniai, mokSk);

	// Neprotingu isvedimas
	neProtinguIsvedimas(NeprotingiMokiniai2, mokSk);

	NeprotingiMokiniai2.clear();
	mokiniai.clear();
	NeprotingiMokiniai.clear();
	ProtingiMokiniai.clear();
	auto end4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff4 = end4 - start; // Skirtumas (s)
	std::cout << mokSk << " Bendras su vector laikas: " << diff4.count() << " s\n";
	std::cout <<endl;
	
}
double skaiciavimasVid(Mokinys mokiniai, int toliauKiek)
{
	double vid, galutinis;
	double sum = 0;
	for (int j = 0; j < toliauKiek - 3; j++)
	{
		sum += mokiniai.paz[j];
	}
	vid = sum / (toliauKiek - 3);
	return galutinis = vid * 0.4 + mokiniai.egz * 0.6;
}
void protinguIsvedimas(std::vector<Mokinys> ProtingiMokiniai, int mokSk)
{
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;

	sort(ProtingiMokiniai.begin(),ProtingiMokiniai.end(),[](Mokinys& x, Mokinys& y){return x.vardas<y.vardas;});

	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2; // Skirtumas (s)
	std::cout << "Protingu rusiavimo laikas: " << diff2.count() << " s\n";

	std::string writeFileRez = "Protingi_Mokiniai_is" + std::to_string(mokSk) + "_Rez.txt";
	std::ofstream out_f(writeFileRez);
	for (int i = 0; i < ProtingiMokiniai.size(); i++)
	{
		out_f << ProtingiMokiniai[i].vardas << " " << fixed << setprecision(2) << ProtingiMokiniai[i].rezult << endl;
	}
	out_f.close();

}
void neProtinguIsvedimas(std::vector<Mokinys> NeprotingiMokiniai, int mokSk)
{
	auto start3 = std::chrono::high_resolution_clock::now();
	auto st3 = start3;
	std::string writeFileRez = "Neprotingi_Mokiniai_is" + std::to_string(mokSk) + "_Rez.txt";

	sort(NeprotingiMokiniai.begin(),NeprotingiMokiniai.end(),[](Mokinys& x, Mokinys& y){return x.vardas<y.vardas;});

	auto end3 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff3 = end3 - start3; // Skirtumas (s)
	std::cout << "Neprotingu rusiavimo laikas: " << diff3.count() << " s\n";

	std::ofstream out_nf(writeFileRez);
	for (int i = 0; i < NeprotingiMokiniai.size(); i++)
	{
		out_nf << NeprotingiMokiniai[i].vardas << " " << fixed << setprecision(2) << NeprotingiMokiniai[i].rezult << endl;
	}
	out_nf.close();
}

