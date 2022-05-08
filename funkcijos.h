#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
//#include <boost/algorithm/algorithm.hpp>
#include <list>
#include <iterator>
#include <deque>
#include <algorithm>
#include <numeric>
 


using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::string;


struct Mokinys
{
	string vardas, pavarde;
	int* paz;
	int egz;
	double rezult = 0;
};



void bufer_nusk(std::string read_vardas);
std::vector<std::string> split(std::string str, char delimiter);
//std::vector<Mokinys> sortabc(std::vector<Mokinys> mok);
void SarasuGeneravimas();
void sarasuIsvedimas(std::vector<std::vector<Mokinys>> sarasuSarasas,int kiek);
double skaiciavimasVid(Mokinys mokiniai,int toliauKiek);
void protinguIsvedimas(std::vector<Mokinys> ProtingiMokiniai,int mokSk);
void neProtinguIsvedimas(std::vector<Mokinys> NeprotingiMokiniai,int mokSk);
void bufer_nusk_list(std::string read_vardas);
void protinguIsvedimas(std::list<Mokinys> ProtingiMokiniai, int mokSk);
void neProtinguIsvedimas(std::list<Mokinys> NeprotingiMokiniai, int mokSk);
std::deque<std::string> split_deq(std::string str, char delimiter);
std::list<std::string> split_list(std::string str, char delimiter);
void protinguIsvedimas(std::deque<Mokinys> ProtingiMokiniai, int mokSk);
void neProtinguIsvedimas(std::deque<Mokinys> NeprotingiMokiniai, int mokSk);

void bufer_nusk_deq(std::string read_vardas);
bool Pagal_Varda(const Mokinys &a, const Mokinys &b);
void PirmaStrategija(std::list<Mokinys> mokiniai);
void AntraStrategija(std::list<Mokinys> mokiniai);