#pragma once
#include <cstdint>
#include <vector>
#pragma pack(push, 1)
using namespace std;
/// <summary>
/// Entête de fichier
/// </summary>
struct TP2FichierEnTete {
    uint16_t tyoe_fichier;
    uint32_t taille_fichier;
    uint32_t offset_lien;
    uint32_t taille_labyrinthe;
    uint16_t nombre_case;
    uint16_t numero_case_depart;
    uint16_t numero_case_fin;
};
/// <summary>
/// Entête de solution
/// </summary>
struct TP2SolutionrEnTete {
    uint32_t taille_chemin;
    uint32_t offset_solution;
};
/// <summary>
/// Lien entre les pièces
/// </summary>
struct TP2LienPiece {
    uint16_t origine;
    uint16_t destination;
};
/// <summary>
/// Étape de chemin
/// </summary>
struct TP2EtapeChemin {
    uint16_t numero_case;
};
/// <summary>
/// structure Pour me simplifier la vie avec la recherche de la solution
/// </summary>
struct TP2LienCases {
    uint16_t origine;
    vector<uint16_t> destinations;
};
/// <summary>
/// J'ai fait cette struct comme cela je peut mettre un attribut de ce type ¸et avoir tout le fichier
/// </summary>
struct TP2Fichier
{
    TP2FichierEnTete ficEntete;
    TP2SolutionrEnTete solEntete;
    vector<TP2LienPiece> lab;
    vector<TP2EtapeChemin> sol;
};
#pragma pack(pop)