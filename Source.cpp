#include "funkcijos.h"

int main()
{
	
	std::ifstream open_f("studentai.txt");
	try{
		if(!open_f){
			throw 1;
		}
	}catch(int x){
		cout<<"Failas neegzistuoja"<<endl;
		return 0;		
	}

	try{
		if(open_f.peek() == std::ifstream::traits_type::eof()){
			throw 2;
		}
	}catch(int x){
		cout<<"Failas tuscias"<<endl;
		return 0;
	}


	srand(time(NULL));
	std::vector<Mokinys> mok;
	//Mokinys a;
	//ivestis(mok);
	bufer_nusk("studentai.txt", "kursiokai.txt");
}

