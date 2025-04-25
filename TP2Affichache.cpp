#include "TP2Affichache.h"
#include <iostream>
#include <vector>
using namespace std;
void TP2Affichache::afficherLiens(vector<TP2LienPiece> tabLab)
{
	for (int i = 0; i < tabLab.size(); i++)
	{
		 cout<< tabLab[i].origine << "-" << tabLab[i].destination << "\n";
	}
}

void TP2Affichache::afficherSolution(vector<TP2EtapeChemin> tabSol)
{
	for (int i = 0; i < tabSol.size(); i++)
	{
		cout << tabSol[i].numero_case;
		if (i < tabSol.size() - 1)
		{
			cout << "-";
		}
	}
}
