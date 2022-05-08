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
    void setRezultatas ( double aRez){rezultatas_=aRez;}
   

    inline std::string getVardas() const { return vardas_; }
    std::string getPavarde(){ return pavarde_; }
    double getEgzaminas(){ return egzaminas_; }
    std::vector<double> getNd(){return nd_;}
    double getRezultatas(){ return rezultatas_; }
   

    Studentas() : egzaminas_(0) { }  // default konstruktorius
 
    Studentas(std::istream& is);
    std::istream& readStudent(std::istream&);  // set'eriai
};

