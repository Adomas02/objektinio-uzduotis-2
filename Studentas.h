#pragma once

#include<string>
#include<iomanip>
#include<vector>




class Studentas {
// realizacija
private:
  std::string vardas_;
  std::string pavarde_;
  double egzaminas_;
  std::vector<double> nd_;
  double rezultatas_;
  
// interfeisas
public:
    void setVardas (std::string aVardas){ vardas_=aVardas; }
    void setPavarde (std::string aPavarde){ pavarde_=aPavarde; }
    void setEgzaminas (double aEgzaminas){ egzaminas_ = aEgzaminas;}
    void setNd (std::vector<double> aNd){ for(auto el:aNd){nd_.push_back(el);}}

    inline void setRezultatas () {
      double vid, galutinis;
	    double sum = 0;
	    for (int j = 0; j <sizeof(nd_); j++)
	    {
	  	  sum +=nd_[j];
	    }
    	vid = sum / (sizeof(nd_));
	  rezultatas_ = vid * 0.4 + egzaminas_ * 0.6;
    }
   

    std::string getVardas() const { return vardas_; }
    std::string getPavarde(){ return pavarde_; }
    double getEgzaminas(){ return egzaminas_; }
    std::vector<double> getNd(){return nd_;}
    double getRezultatas(){ return rezultatas_; }
   

   Studentas() : egzaminas_(0) { }  // default konstruktorius
  

    Studentas(const Studentas& other): vardas_(other.vardas_),pavarde_(other.pavarde_),egzaminas_(other.egzaminas_),nd_(other.nd_),rezultatas_(other.rezultatas_){}	// copy constructor
	  //Studentas &operator=(const Studentas &s);	// copy assignment constructor
	  ~Studentas(){nd_.clear();}	//destructor
  
};

