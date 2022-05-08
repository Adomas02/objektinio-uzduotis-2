#include<iostream>
#include<iomanip>
#include"Studentas.h"

int main(){
    Studentas mokinys;

    mokinys.setVardas("Adomas");
    std::cout<<mokinys.getVardas();
    mokinys.setPavarde("Kazenas");
    std::cout<<mokinys.getPavarde();
    mokinys.setEgzaminas(10);
    std::cout<<mokinys.getEgzaminas();
    
}