#include "../headers/previousyearprofitdata.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <random>
#include <boost/algorithm/string.hpp>
#include <boost/math/distributions.hpp>
#include <boost/math/distributions/normal.hpp>



using namespace std;

previousyearprofitdata::previousyearprofitdata() {  
}



void previousyearprofitdata::setnoactiondata(int t,double costs,double returns,
    double profits,double hlb_severity,double discreteprobability_doublerand,double psylliddistribution_infected_doublerand,double psylliddistribution_female_doublerand,
    double modality1_infected_doublerand,double modality1_female_doublerand, double modality3_infected_doublerand,double modality3_female_doublerand,double modality5_infected_doublerand,
    double modality5_female_doublerand,double birtnewflush_doublerand,string no_invasionmodaility) {
        this-> t = t;
        this->costs = costs;
        this->returns = returns;
        this->profits = profits;
        this->hlb_severity = hlb_severity;
        this->discreteprobability_doublerand = discreteprobability_doublerand;
        this->psylliddistribution_infected_doublerand = psylliddistribution_infected_doublerand;
        this->psylliddistribution_female_doublerand = psylliddistribution_female_doublerand;
        this->modality1_infected_doublerand = modality1_infected_doublerand;
        this->modality1_female_doublerand = modality1_female_doublerand;
        this->modality3_infected_doublerand = modality3_infected_doublerand;
        this->modality3_female_doublerand = modality3_female_doublerand;
        this->modality5_infected_doublerand = modality5_infected_doublerand;
        this->modality5_female_doublerand = modality5_female_doublerand;
        this->birtnewflush_doublerand = birtnewflush_doublerand;
        this->no_invasionmodaility = no_invasionmodaility;
}

void previousyearprofitdata::ReadPreviousData(previousyearprofitdata pdata[],int time)
{
    //if(pdata[0].getPreviousyeartime() != currentyear)
    //{

        ifstream inFile;
        std::string filePath = "./output/TESTER/noAction_baseCase/" + std::to_string(time) + "_econ.csv";
        inFile.open(filePath);

        std::vector<std::string> tokens;
        std::string token;
        string readString;
        int i = 0;
        while (!inFile.eof()) {
            readString = "";
            tokens.clear() ;
            getline(inFile,readString);
            std::stringstream tempstr; 
            
            tempstr<< readString;
            while (std::getline(tempstr, token, ',')) {
                tokens.push_back(token);
            }
            if(tokens[0] != "t")
            {   
               
                int y = stoi(tokens[0])/365;
                pdata[i].setnoactiondata(
                    stoi(tokens[0]),      // 1st argument (int)
                    stod(tokens[2]),      // 2nd argument (double)
                    stod(tokens[3]),      // 3rd argument (double)
                    stod(tokens[4]),      // 4th argument (double)
                    stod(tokens[5]),      // 5th argument (double)
                    stod(tokens[10]),     // 6th argument (double)
                    stod(tokens[11]),     // 7th argument (double)
                    stod(tokens[12]),     // 8th argument (double)
                    stod(tokens[13]),     // 9th argument (double)
                    stod(tokens[14]),     // 10th argument (double)
                    stod(tokens[15]),     // 11th argument (double)
                    stod(tokens[16]),     // 12th argument (double)
                    stod(tokens[17]),     // 13th argument (double)
                    stod(tokens[18]),     // 14th argument (double)
                    stod(tokens[19]),      // 15th argument (double)
                    std::string(tokens[20])
                    );

                i++;
            }
            
        }
        inFile.close();
   // }
}




