#include "TP2Solution.h"
#include <vector>
#include <queue>
using namespace std;
vector<TP2EtapeChemin> TP2Solution::trouverChemin(uint16_t caseDepart, uint16_t caseArrive, vector<TP2LienPiece> lab, uint16_t nbCases)
{
    vectorLien(lab);
    vector<bool> visite(nbCases, false);
    vector<int> precedent(nbCases, -1);

    queue<uint16_t> file;

    file.push(caseDepart);
    visite[caseDepart] = true;

    bool trouve = false;

    while (!file.empty() && !trouve) {
        uint16_t courant = file.front();
        file.pop();

        if (courant == caseArrive) {
            trouve = true;
        }
        else
        {
            int index = atIndexLien(courant);
            if (index != -1)
            {
                for (int i = 0; i < m_lien[index].destinations.size(); ++i) {
                    uint16_t voisin = m_lien[index].destinations[i];
                    if (!visite[voisin])
                    {
                        visite[voisin] = true;
                        precedent[voisin] = courant;
                        file.push(voisin);
                    }
                }
            }
        }
    }

    if (!trouve)
    {
        return {};
    }
    vector<TP2EtapeChemin> chemin;
    uint16_t courant = caseArrive;

    while (courant != caseDepart) {
        chemin.push_back({ courant });
        courant = precedent[courant];
    }
    chemin.push_back({ caseDepart });
    reverse(chemin.begin(), chemin.end());

    return chemin;
}


void TP2Solution::vectorLien(vector<TP2LienPiece> lab)
{
	m_lien.clear();
	for (int c = 0; c < lab.size(); c++)
	{
		int index = atIndexLien(lab[c].origine);
		if (index != -1)
		{
			m_lien[index].destinations.push_back(lab[c].destination);
		}
		else
		{
			m_lien.push_back({ lab[c].origine, { lab[c].destination } });
		}
	}
}

int TP2Solution::atIndexLien(uint16_t nombre)
{
	for (int i = 0; i < m_lien.size(); i++)
	{
		if (nombre == m_lien[i].origine)
		{
			return i;
		}
	}
	return -1;
}

int TP2Solution::atIndexLienDestination(uint16_t nombre)
{
	for (int i = 0; i < m_lien.size(); i++)
	{
		for (int j = 0; j < m_lien[i].destinations.size(); j++)
		{
			if (nombre == m_lien[i].destinations[j])
			{
				return i;
			}
		}
	}
	return -1;
}
