#pragma once
#include "IAffichable.h"
#include "Header.h"
#include <vector>
#include <string>
using namespace std;
class TP2Affichache: IAffichable
{ 
public:
	// Hérité via IAffichable
	void afficherLiens(vector<TP2LienPiece> tabLab);
	void afficherSolution(vector<TP2EtapeChemin> tabSol);
};

