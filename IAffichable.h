#pragma once
#include <vector>
#include "Header.h"
using namespace std;
class IAffichable
{
public:
	virtual void afficherLiens(vector<TP2LienPiece> tabLab) = 0;
	virtual void afficherSolution(vector<TP2EtapeChemin> tabSol) = 0;
};