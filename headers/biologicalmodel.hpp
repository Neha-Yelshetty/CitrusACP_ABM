#ifndef BIOLOGICALMODEL_HPP
#define BIOLOGICALMODEL_HPP
#include "grove.hpp"
#include "math.h"
#include "planningFunc.hpp"
#include "../headers/behavior.hpp"
#include "bioABM.h"
#include<vector>

using namespace std;

class BiologicalModel {
public:
     void biologicalmodel(int farmid); 
     double biohlbseverity(int i,int j);
     bool bioisTreeAlive(int i,int j);
     void initalize();
};

#endif