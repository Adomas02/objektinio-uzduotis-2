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
		// cout << "ciklo pradzia " << endl;

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
	
	
	for (int i = 0; i < mokiniai.size(); i++)
	{
		auto mokiniai_front = mokiniai.begin();
		std::advance(mokiniai_front, i);

		Mokinys tmpmok=*mokiniai_front;

		tmpmok.rezult=skaiciavimasVid(tmpmok,toliauKiek);

		//std::advance(mokiniai_front, i);
		//*mokiniai_front.rezult = skaiciavimasVid(mokiniai[i], toliauKiek);
		//mokiniai[i].rezult = skaiciavimasVid(mokiniai[i], toliauKiek);

		if (tmpmok.rezult >= 5)
		{

			// mokiniai[i].rezult=galutinis;
			ProtingiMokiniai.push_back(tmpmok);
		}
		else
		{
			// mokiniai[i].rezult=galutinis;
			// cout<<mokiniai[i].rezult<<endl;
			NeprotingiMokiniai.push_back(tmpmok);
		}
	}
	int mokSk = mokiniai.size();
	mokiniai.clear();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1; // Skirtumas (s)
	std::cout << "Iraso dalinimo i dvi grupes laikas: " << diff1.count() << " s\n";

	// Protingu isvedimas
	//protinguIsvedimas(ProtingiMokiniai, mokSk);

	// Neprotingu isvedimas
	//neProtinguIsvedimas(NeprotingiMokiniai, mokSk);

	auto end4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff4 = end4 - start; // Skirtumas (s)
	std::cout << mokSk << " Bendras laikas: " << diff4.count() << " s\n";
	std::cout <<endl;
}
