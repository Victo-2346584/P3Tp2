#pragma once
#include <string>	
#include "Header.h"
using namespace std;
class ILectureEcriture
{
public:
	virtual TP2Fichier* lireLabyrinthe(const string filePath) = 0;
	virtual void ecrireSolution(const string filePath, TP2Fichier* fichier) = 0;

};
