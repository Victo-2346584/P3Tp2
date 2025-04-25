#include "TP2GestionFichier.h"
#include <iostream>
#include <fstream>
using namespace std;
void TP2GestionFichier::grandeurVariable(TP2Fichier* fichierParam)
{
	int nbLiens = fichierParam->ficEntete.taille_labyrinthe / 4;
	fichierParam->lab.resize(nbLiens);
	fichierParam->sol.resize(fichierParam->solEntete.taille_chemin);
}
TP2Fichier* TP2GestionFichier::lireLabyrinthe(const string filePath)
{

	std::ifstream TP2{ filePath, std::ios::in | std::ios::binary };
	if (TP2.is_open())
	{
		TP2Fichier* fichier = new TP2Fichier();

		TP2.read((char*)&fichier->ficEntete, sizeof(TP2FichierEnTete));

		TP2.read((char*)&fichier->solEntete, sizeof(TP2SolutionrEnTete));

		grandeurVariable(fichier);

		TP2.seekg(fichier->ficEntete.offset_lien, TP2.beg);
		TP2.read((char*)fichier->lab.data(), fichier->ficEntete.taille_labyrinthe);

		TP2.seekg(fichier->solEntete.offset_solution, TP2.beg);
		TP2.read((char*)fichier->sol.data(), fichier->solEntete.taille_chemin * 2);

		TP2.close();
		return fichier;
	}
	else
	{
		cout << "Impossible a lire";
		return NULL;
	}
}

void TP2GestionFichier::ecrireSolution(const string filePath, TP2Fichier* fichier)
{
	std::ofstream outTP2{ filePath, std::ios_base::binary };
	if (outTP2)
	{
		outTP2.write((char*)&fichier->ficEntete, sizeof(TP2FichierEnTete));
		outTP2.write((char*)&fichier->solEntete, sizeof(TP2SolutionrEnTete));
		outTP2.write((char*)fichier->lab.data(), fichier->lab.size() * sizeof(TP2LienPiece));
		outTP2.write((char*)fichier->sol.data(), fichier->sol.size() * sizeof(TP2EtapeChemin));
	}
	else
	{
		cout << "Impossible a ecrire";
		return;
	}
}
