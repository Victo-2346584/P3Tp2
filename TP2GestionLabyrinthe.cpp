#include "TP2GestionLabyrinthe.h"
using namespace std;
void TP2GestionLabyrinthe::afficherLiens()
{
	m_affiche.afficherLiens(m_fichierLab->lab);
}

void TP2GestionLabyrinthe::afficherSolution()
{
	m_affiche.afficherSolution(m_fichierLab->sol);
}

void TP2GestionLabyrinthe::ecrireSolution(const string filePath)
{
	m_fichier.ecrireSolution(filePath, m_fichierLab);
}

void TP2GestionLabyrinthe::trouverSolution()
{
	m_fichierLab->sol=m_solution.trouverChemin(m_fichierLab->ficEntete.numero_case_depart, m_fichierLab->ficEntete.numero_case_fin, m_fichierLab->lab, m_fichierLab->ficEntete.nombre_case);
	m_fichierLab->solEntete.taille_chemin = m_fichierLab->sol.size();
}

TP2GestionLabyrinthe::TP2GestionLabyrinthe(const string filePath)
{
	m_fichierLab = m_fichier.lireLabyrinthe(filePath);
}

TP2GestionLabyrinthe::~TP2GestionLabyrinthe()
{
	delete m_fichierLab;
}
