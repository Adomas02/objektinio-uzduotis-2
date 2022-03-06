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

const int kiek = 15;

struct Mokinys
{
	string vardas, pavarde;
	int paz[kiek];
	int egz;
	double rezult = 0;
};

void ivestis(std::vector<Mokinys> &mok);
void isvestis(std::vector<Mokinys> &mok);
double skaiciavimas(double a, std::vector<Mokinys> &mok, int i);
double skaiciavimasVid(std::vector<Mokinys> &mok, int a);
void rikiavimas(std::vector<Mokinys> &mok, int a);
double skaiciavimasMed(std::vector<Mokinys> &mok, int i);
void pazymiuIvestis(std::vector<Mokinys> &mok, int a);
void bufer_nusk(std::string read_vardas, std::string write_vardas);
std::vector<std::string> split(std::string str, char delimiter);
std::vector<Mokinys> sortabc(std::vector<Mokinys> mok);