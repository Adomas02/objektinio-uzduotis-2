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
			int b;
			cout<<"Su kuriuo konteineriu norite atlikti testavima?"<<endl;
			cout<<"0 - std::vector"<<endl;
			cout<<"1 - std::list"<<endl;
			cout<<"2 - std::deque"<<endl;
			cin>>b;
			if(b==0)
			{
			string failoPavadinimas;
			cout << "Iveskite kokio failo rezultatu norit ";
			cin >> failoPavadinimas;
			cout << endl;
			bufer_nusk(failoPavadinimas);				
			}
			else if(b==1)
			{
			string failoPavadinimas;
			cout << "Iveskite kokio failo rezultatu norit ";
			cin >> failoPavadinimas;
			cout<<endl;
			bufer_nusk_list(failoPavadinimas);				
				//funkcija su std::list
			}
			else if(b==2)
			{
			string failoPavadinimas;
			cout << "Iveskite kokio failo rezultatu norit ";
			cin >> failoPavadinimas;				
				//funkcija su std::deque
			}

		}
	}

	srand(time(NULL));
	std::vector<Mokinys> mok;
	// Mokinys a;
	// ivestis(mok);
	// bufer_nusk("studentai.txt", "kursiokai.txt");
}
