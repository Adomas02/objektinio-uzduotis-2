#include "funkcijos.h"

int main()
{

	int i;
	cout << "Ar norite generuoti failus? (1/0)";
	cin >> i;
	if (i == 1)
	{
		SarasuGeneravimas();
	}

	int a = 1;
	while (a == 1)
	{
		cout << "Ar norite rezultatu? (1/0) ";
		cin>>a;
		if (a == 1)
		{
			string failoPavadinimas;
			cout << "Iveskite kokio failo rezultatu norit ";
			cin >> failoPavadinimas;
			cout << endl;
			bufer_nusk(failoPavadinimas);
		}
	}

	srand(time(NULL));
	std::vector<Mokinys> mok;
	// Mokinys a;
	// ivestis(mok);
	// bufer_nusk("studentai.txt", "kursiokai.txt");
}
