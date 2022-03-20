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
#include <boost/algorithm/algorithm.hpp>


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

void ivestis(std::vector<Mokinys> &mok,int kiek);
void isvestis(std::vector<Mokinys> &mok,int kiek);
double skaiciavimas(double a, std::vector<Mokinys> &mok, int i);
double skaiciavimasVid(std::vector<Mokinys> &mok, int a,int kiek);
void rikiavimas(std::vector<Mokinys> &mok, int a,int kiek);
double skaiciavimasMed(std::vector<Mokinys> &mok, int i,int kiek);
void pazymiuIvestis(Mokinys mok, int kiek);
void bufer_nusk(std::string read_vardas, std::string write_vardas);
std::vector<std::string> split(std::string str, char delimiter);
std::vector<Mokinys> sortabc(std::vector<Mokinys> mok);
void SarasuGeneravimas();
void sarasuIsvedimas(std::vector<std::vector<Mokinys>> sarasuSarasas,int kiek);