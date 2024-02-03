#pragma once
#include<iostream>
struct Livre 
{
    int numero;
    std::string titre;
    std::string auteur;
    int anneeEdition;
    int exemplaires;
    Livre(const int&, const std::string&, const std::string&, const int&, const int&);
    Livre() {};
    std::string livreOnLine(const std::string&);
    void afficher();
    static Livre readLivre();
};
struct Emprunt 
{
    int numeroLivre;
    int numeroEtudiant;
    std::string nomEtudiant;
    std::string prenomEtudiant;
    std::string dateEmprunt;
    std::string dateRetour;
};
struct NoeudArbre 
{
    Livre livre;
    NoeudArbre* gauche;
    NoeudArbre* droit;
};
class library
{
private:             
    NoeudArbre* racine;
    std::string fileName;
private:
    static NoeudArbre* insererLivre(NoeudArbre*, Livre);
    static Livre* rechercherLivreParNumero(NoeudArbre*,int);
    static Livre* rechercherLivreParTitre(NoeudArbre*, std::string);
public:

    library(const std::string&);
    void loid();
    void save();
    void ajouter(Livre&);
    Livre* rechearchT(const std::string&);
    Livre* reacherchN(const int&);
    void afficher();
    std::vector<std::string> getTitles();
    bool estLivreDisponible(int&);
};