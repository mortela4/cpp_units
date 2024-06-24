//============================================================================
// Name        : distance_list_ex1.cpp
// Author      : ml
// Version     :
// Copyright   : 
// Description : 'units' library demo (actually demonstrates user literals).
//============================================================================

#include <iostream>
#include <list>
//
#include "unit.h"      /* "distance.h" included from here. */


using namespace std;
//
using namespace Distance::Unit;


int main()
{

  std:: cout << std::endl;

  const Distance::MyDistance oneKm = 1.0_km;
  const Distance::MyDistance oneDm = 1.0_dm;
  const Distance::MyDistance oneMeter = 1.0_m;
  const Distance::MyDistance oneCm = 1.0_cm;
  //
  const std::list<Distance::MyDistance> distanceList = {oneKm, oneDm, oneMeter, oneCm};

  std::cout << "1.0_km: " << oneKm << std::endl;
  std::cout << "1.0_m: " << oneMeter << std::endl;
  std::cout << "1.0_dm: " << oneDm << std::endl;
  std::cout << "1.0_cm: " << oneCm << std::endl;

  std::cout << std::endl;

  Distance::MyDistance totalDistance = 0.0_m;	// Results from calculations always end up in meters ...

  cout << "Distances:" << endl;
  unsigned int i = 0;
  for (auto& distance : distanceList)
  {
	  cout << "Element no." << i++ << ": " << distance << endl;
	  totalDistance = totalDistance + distance;					// NB: must overload operator '+=' to use it here!
  }
  cout << "Total distance = " << totalDistance << endl;

  auto avgDistance = totalDistance / distanceList.size();
  cout << "Average distance per trip = " << avgDistance << endl;

  return 0;
}

