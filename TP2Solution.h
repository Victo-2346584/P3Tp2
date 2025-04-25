#pragma once
#include <vector>
#include"Header.h"
#include <cstdint>
using namespace std;
class TP2Solution
{
private: 
	vector<TP2LienCases> m_lien;
	
	/// <summary>
	/// Remplis m_lien sous format TP2LienCases
	/// </summary>
	void vectorLien(vector<TP2LienPiece> lab);
	/// <summary>
	/// trouve le premier index du nombre
	/// </summary>
	/// <returns> l'index d'ou ce trouve le nombre</returns>
	int atIndexLien(uint16_t nombre);
	/// <summary>
	/// Trouver le premier index dans lequel le nombre est dans les destinations
	/// </summary>
	/// <param name="nombre">nombre non null</param>
	/// <returns></returns>
	int atIndexLienDestination(uint16_t nombre);
public:
	/// <summary>
	/// Trouver la solution du labyrinthe
	/// </summary>
	/// <param name="caseDepart">case de départ</param>
	/// <param name="caseArrive">case d'arriver</param>
	/// <returns>le vecteur contenant la solution</returns>
	vector<TP2EtapeChemin>  trouverChemin(uint16_t caseDepart, uint16_t caseArrive, vector<TP2LienPiece> lab, uint16_t nbCases);
};

