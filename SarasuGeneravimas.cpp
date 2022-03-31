#include "funkcijos.h"
void SarasuGeneravimas()
{
	std::vector<std::vector<Mokinys>> sarasuSarasas;
	int n = 1000; // kiek mokiniu pirmame faile
	int kiek = 5; // kiek pazymiu vienam mokiniui

	for (int i = 0; i < 5; i++)
	{
		std::vector<Mokinys> mokSarasas;
		for (int j = 0; j < n; j++)
		{
			Mokinys mok = Mokinys();

			mok.vardas = "Vardas" + std::to_string(j + 1);
			mok.pavarde = "Pavarde" + std::to_string(j + 1);

			mok.paz = new int[kiek];
			for (int k = 0; k < kiek; k++)
			{
				int pazLaik;
				pazLaik = rand() % 10 + 1;
				mok.paz[k] = pazLaik;
			}
			mok.egz = rand() % 10 + 1;
			mokSarasas.push_back(mok);
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
		auto start0 = std::chrono::high_resolution_clock::now();
		auto st0 = start0;

		std::string writeFile = "Mokiniai" + std::to_string(sarasuSarasas[i].size()) + ".txt";
		std::string writeFileRez = "Mokiniai" + std::to_string(sarasuSarasas[i].size()) + "Rez.txt";
		std::ofstream out_f(writeFile);
		std::vector<Mokinys> mokSarasas;
		for (int j = 0; j < sarasuSarasas[i].size(); j++)
		{
			out_f << sarasuSarasas[i][j].vardas << " ";
			out_f << sarasuSarasas[i][j].pavarde << " ";

			for (int k = 0; k < kiek; k++)
			{
				out_f << sarasuSarasas[i][j].paz[k] << " ";
			}
			out_f << sarasuSarasas[i][j].egz << " ";
			out_f << endl;
		}
		auto end0 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff0 = end0 - start0; // Skirtumas (s)
		std::cout << "Failo sukurimo su " << sarasuSarasas[i].size() << " mokiniu laikas: " << diff0.count() << " s\n";

		// bufer_nusk(writeFile, writeFileRez);

		// bendro laiko pabaiga

		cout << endl;

		out_f.close();
	}
}