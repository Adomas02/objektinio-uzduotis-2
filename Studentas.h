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
// interfeisas
public:
    void setVardas (std::string aVardas){ vardas_=aVardas; }
    void setPavarde (std::string aPavarde){ pavarde_=aPavarde; }
    void setEgzaminas (double aEgzaminas){ egzaminas_ = aEgzaminas;}
    
    std::string getVardas(){ return vardas_; }
    std::string getPavarde(){ return pavarde_; }
    double getEgzaminas(){ return egzaminas_; }
    Studentas() : egzaminas_(0) { }  // default konstruktorius
    Studentas(std::istream& is);
  std::istream& readStudent(std::istream&);  // set'eriai
};