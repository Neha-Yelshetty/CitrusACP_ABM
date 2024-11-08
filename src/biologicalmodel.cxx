#include "biologicalmodel.hpp"
#include "../headers/behavior.hpp"
#include "bioABM.h"

Behavior* behaviorPatterns[3];

void BiologicalModel::biologicalmodel(int farmid) {
    bioABM::advanceBiologicalModel(farmid);  
}

double BiologicalModel::biohlbseverity(int i, int j){
  return bioABM::getSeverityAt(i, j);
}

bool BiologicalModel::bioisTreeAlive (int i, int j){
   return bioABM::isTreeAlive(i,j);
}

void BiologicalModel::initalize(){
    bioABM :: initalize();
 }