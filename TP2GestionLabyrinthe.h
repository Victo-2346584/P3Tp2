#pragma once
#include "IAffichable.h"
#include "ILectureEcriture.h"
#include "Header.h"
#include <vector>
#include <string>
#include "TP2Affichache.h"
#include "TP2GestionFichier.h"
#include "TP2Solution.h"
using namespace std;
class TP2GestionLabyrinthe
{
private:
	TP2Fichier* m_fichierLab;
	TP2Affichache m_affiche;
	TP2GestionFichier m_fichier;
	TP2Solution m_solution;

public:
	void afficherLiens();
	void afficherSolution();
	void ecrireSolution(const string filePath);
	void trouverSolution();
	/// <summary>
	/// instantie les pointeurs attributes
	/// </summary>
	TP2GestionLabyrinthe(const string filePath);
	/// <summary>
	/// delete les pointeurs attributes
	/// </summary>
	~TP2GestionLabyrinthe();
};

