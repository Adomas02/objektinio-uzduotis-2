#include "funkcijos.h"

std::list<std::string> split_list(std::string str, char delimiter)
{
	std::list<std::string> result;
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delimiter, end)) != std::string::npos)
	{
		end = str.find(delimiter, start);
		result.push_back(str.substr(start, end - start));
	}

	return result;
}
bool Pagal_Varda(const Mokinys &a, const Mokinys &b)
{ return a.vardas < b.vardas; }
void bufer_nusk_list(std::string read_vardas)
{
	std::list<std::string> splited;
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
   
	std::list<Mokinys> mokiniai;
    
	// bufferio padalijimas i eiluciu vektoriu
	while (my_buffer)
	{
        
		 //cout << "ciklo pradzia " << endl;

		if (!my_buffer.eof())
		{
			std::getline(my_buffer, eil);
			// cout << "ciklo viduj " << eil << endl;
			if (eil.size() > 0)
			{
				std::list<std::string> eilDalys = split_list(eil, ' ');
				for (std::string &a : eilDalys)
				{
					kiek++;
				}
				//cout<<kiek;
				Mokinys mok = Mokinys();
				auto eilDalys_front = eilDalys.begin();

				std::advance(eilDalys_front, 0);
				
				mok.vardas = *eilDalys_front;
				
				//cout<<mok.vardas<<endl;

				std::advance(eilDalys_front, 1);
				mok.pavarde = *eilDalys_front;

				//cout<<mok.pavarde<<endl;

				mok.paz = new int[kiek];
				for (int i = 0; i < kiek - 3; i++)
				{
					auto eilDalys_front = eilDalys.begin();
					std::advance(eilDalys_front, 2+i);
					mok.paz[i] = std::stoi(*eilDalys_front);
					//cout<<mok.paz[i]<<endl;
				}

				//auto eilDalys_front = eilDalys.begin();
				
				std::advance(eilDalys_front,kiek-2);
				
				mok.egz = std::stoi(*eilDalys_front);
				//cout<<mok.egz<<endl;
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

	PirmaStrategija(mokiniai);

	
	AntraStrategija(mokiniai);


	
	auto end4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff4 = end4 - start; // Skirtumas (s)
	std::cout << mokiniai.size() << " Bendras su list laikas: " << diff4.count() << " s\n";
	std::cout <<endl;
}
void protinguIsvedimas(std::list<Mokinys> ProtingiMokiniai, int mokSk)
{
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;

	std::string writeFileRez = "List_Protingi_Mokiniai_is" + std::to_string(mokSk) + "_Rez.txt";
	std::ofstream out_f(writeFileRez);

	ProtingiMokiniai.sort([](Mokinys& x, Mokinys& y){return x.vardas<y.vardas;});
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2; // Skirtumas (s)
	std::cout << "Protingu rusiavimo laikas: " << diff2.count() << " s\n";

   	for(auto& el:ProtingiMokiniai)
	{
		
		out_f << el.vardas << " " << fixed << setprecision(2) << el.rezult << endl;
	}

	out_f.close();

}
void neProtinguIsvedimas(std::list<Mokinys> NeprotingiMokiniai, int mokSk)
{
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;

	std::string writeFileRez = "List_NeProtingi_Mokiniai_is" + std::to_string(mokSk) + "_Rez.txt";
	std::ofstream out_f(writeFileRez);
	
	NeprotingiMokiniai.sort([](Mokinys& x, Mokinys& y){return x.vardas<y.vardas;});
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2; // Skirtumas (s)
	std::cout << "Neprotingu rusiavimo laikas: " << diff2.count() << " s\n";

  	for(auto& el:NeprotingiMokiniai)
	{
		
		out_f << el.vardas << " " << fixed << setprecision(2) << el.rezult << endl;
	}
	out_f.close();

}

void PirmaStrategija(std::list<Mokinys> mokiniai)
{
// Skirstymas i dvi grupes pirma strategija
	auto start1 = std::chrono::high_resolution_clock::now();
	auto st1 = start1;
	std::list<Mokinys> ProtingiMokiniai;
	std::list<Mokinys> NeprotingiMokiniai;
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
	std::cout << "Iraso dalinimo i dvi grupes kuriant du konteinerius laikas: " << diff1.count() << " s\n";

	
	// Protingu isvedimas
	protinguIsvedimas(ProtingiMokiniai, mokSk);

	// Neprotingu isvedimas
	neProtinguIsvedimas(NeprotingiMokiniai, mokSk);
	NeprotingiMokiniai.clear();
	ProtingiMokiniai.clear();
}
void AntraStrategija(std::list<Mokinys> mokiniai)
{
// Skirstymas i dvi grupes antra strategija
	auto start11 = std::chrono::high_resolution_clock::now();
	auto st11 = start11;
	std::list<Mokinys> NeprotingiMokiniai2;
	
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
	int mokSk = mokiniai.size();
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
	
}
double skaiciavimasVid(Mokinys mokiniai, int toliauKiek)
{
	double vid, galutinis;
	double sum = 0;
//std::vector<double> temp ;
	for (int j = 0; j < toliauKiek - 3; j++)
	{
		sum += mokiniai.paz[j];
	}
	vid = sum / (toliauKiek - 3);
	return galutinis = vid * 0.4 + mokiniai.egz * 0.6;
}