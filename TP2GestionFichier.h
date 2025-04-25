#pragma once
#include "ILectureEcriture.h"
#include "Header.h"
using namespace std;
class TP2GestionFichier : ILectureEcriture
{
private :
	void grandeurVariable(TP2Fichier* fichierParam);
	// Hérité via ILectureEcriture
public:

	TP2Fichier* lireLabyrinthe(const string filePath);
	void ecrireSolution(const string filePath, TP2Fichier* fichier);
};

