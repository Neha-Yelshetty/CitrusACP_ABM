#ifndef PREVIOUSYEARPROFITDATA_HPP
#define PREVIOUSYEARPROFITDATA_HPP
#include <vector>
#include <sstream>
using namespace std;

// This class is used to keep the information of all the grovers

class previousyearprofitdata;

class previousyearprofitdata {

public:

  int t;
  double costs;
  double returns;
  double profits;
  double hlb_severity;
  double discreteprobability_doublerand ;
  double psylliddistribution_infected_doublerand;
  double psylliddistribution_female_doublerand;
  double modality1_infected_doublerand;
  double modality1_female_doublerand;
  double modality3_infected_doublerand;
  double modality3_female_doublerand;
  double modality5_infected_doublerand;
  double modality5_female_doublerand;
  double birtnewflush_doublerand;
  string no_invasionmodaility;



    previousyearprofitdata();
  
    void setnoactiondata(int,double,double,double,double ,double ,double ,double ,double ,double , double ,double ,double ,double ,double,string );
    void ReadPreviousData(previousyearprofitdata[],int);

    double return_discreteprobability_doublerand(){return this->discreteprobability_doublerand;}
    double return_psylliddistribution_infected_doublerand(){return this->psylliddistribution_infected_doublerand;}
    double return_psylliddistribution_female_doublerand(){return this->psylliddistribution_female_doublerand;}
    double return_modality1_infected_doublerand(){return this->modality1_infected_doublerand;}
    double return_modality1_female_doublerand(){return this->modality1_female_doublerand;}
    double return_modality3_infected_doublerand(){return this->modality3_infected_doublerand;}
    double return_modality3_female_doublerand(){return this->modality3_female_doublerand;}
    double return_modality5_infected_doublerand(){return this->modality5_infected_doublerand;}
    double return_modality5_female_doublerand(){return this->modality5_female_doublerand;}
    double return_birtnewflush_doublerand(){return this->birtnewflush_doublerand;}
    string return_no_invasionmodaility(){return this->no_invasionmodaility;}





};


#endif