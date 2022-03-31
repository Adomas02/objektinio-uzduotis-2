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


	// Skirstymas i dvi grupes
	auto start1 = std::chrono::high_resolution_clock::now();
	auto st1 = start1;
	std::list<Mokinys> ProtingiMokiniai;
	std::list<Mokinys> NeprotingiMokiniai;
	double galutinis;
	
	auto mokiniai_front = mokiniai.begin();
    Mokinys tmpmok;


	for (int i = 0; i < mokiniai.size(); i++)
	{
		tmpmok = *std::next(mokiniai_front, i);
        
		tmpmok.rezult=skaiciavimasVid(tmpmok,toliauKiek);
		if (tmpmok.rezult >= 5)
		{
			ProtingiMokiniai.push_back(tmpmok);
		}
		else
		{
			NeprotingiMokiniai.push_back(tmpmok);
		}
	}
	int mokSk = mokiniai.size();
	mokiniai.clear();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1; // Skirtumas (s)
	std::cout << "Iraso dalinimo i dvi grupes laikas: " << diff1.count() << " s\n";

	// Protingu isvedimas
	protinguIsvedimas(ProtingiMokiniai, mokSk);

	// Neprotingu isvedimas
	neProtinguIsvedimas(NeprotingiMokiniai, mokSk);

	auto end4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff4 = end4 - start; // Skirtumas (s)
	std::cout << mokSk << " Bendras laikas: " << diff4.count() << " s\n";
	std::cout <<endl;
}
void protinguIsvedimas(std::list<Mokinys> ProtingiMokiniai, int mokSk)
{
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;

	std::string writeFileRez = "List_Protingi_Mokiniai_is" + std::to_string(mokSk) + "_Rez.txt";
	std::ofstream out_f(writeFileRez);
    auto ProtigiMokiniai_front = ProtingiMokiniai.begin();
    std::advance(ProtigiMokiniai_front, 0);
    Mokinys tmpmok=*ProtigiMokiniai_front;

    out_f << tmpmok.vardas << " " << fixed << setprecision(2) << tmpmok.rezult << endl;

	for (int i = 1; i < ProtingiMokiniai.size(); i++)
	{
        tmpmok = *std::next(ProtigiMokiniai_front, i);

		out_f << tmpmok.vardas << " " << fixed << setprecision(2) << tmpmok.rezult << endl;
	}
	out_f.close();
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2; // Skirtumas (s)
	std::cout << "Protingu isvedimo laikas: " << diff2.count() << " s\n";
}
void neProtinguIsvedimas(std::list<Mokinys> NeprotingiMokiniai, int mokSk)
{
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;

	std::string writeFileRez = "List_NeProtingi_Mokiniai_is" + std::to_string(mokSk) + "_Rez.txt";
	std::ofstream out_f(writeFileRez);
    auto NeprotingiMokiniai_front = NeprotingiMokiniai.begin();
    std::advance(NeprotingiMokiniai_front, 0);
    Mokinys tmpmok=*NeprotingiMokiniai_front;

    out_f << tmpmok.vardas << " " << fixed << setprecision(2) << tmpmok.rezult << endl;

	for (int i = 1; i < NeprotingiMokiniai.size(); i++)
	{
        tmpmok = *std::next(NeprotingiMokiniai_front, i);

		out_f << tmpmok.vardas << " " << fixed << setprecision(2) << tmpmok.rezult << endl;
	}
	out_f.close();
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2; // Skirtumas (s)
	std::cout << "Protingu isvedimo laikas: " << diff2.count() << " s\n";
}
