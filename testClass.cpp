#include<iostream>
#include<iomanip>
#include"Studentas.h"

int main(){
    
    Studentas mokinys;
    std::vector<double> temp;

    mokinys.setVardas("Adomas");
    std::cout<<mokinys.getVardas();
    mokinys.setPavarde("Kazenas");
    std::cout<<mokinys.getPavarde();
    mokinys.setEgzaminas(10);
    std::cout<<mokinys.getEgzaminas();
    double paz;
    std::cout<<std::endl;
    for(int i=0;i<3;i++)
    {
        std::cin>>paz;
        temp.push_back(paz);
    }
    mokinys.setNd(temp);
    //std::cout<<temp[0];
    
   
}