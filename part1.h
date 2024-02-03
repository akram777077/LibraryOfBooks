#pragma once
#include"declaration.h"
#include<algorithm>
#include<iostream>
#include<string>
Livre::Livre(const int& numero, const std::string& title, const std::string& auteur, const int& anneeEdition, const int& exemplaires)
{
    this->titre = title;
    this->auteur = auteur;
    this->anneeEdition = anneeEdition;
    this->exemplaires = exemplaires;
    this->numero = numero;
}
std::string Livre::livreOnLine(const std::string& separator)
{
    std::stringstream ss;
    ss << numero << separator
        << titre << separator
        << auteur << separator
        << anneeEdition << separator
        << exemplaires;
    return ss.str();
}
void Livre::afficher()
{
    std::cout << "Book Information:" << std::endl;
    std::cout << "Number: " << numero << std::endl;
    std::cout << "Title: " << titre << std::endl;
    std::cout << "Author: " << auteur << std::endl;
    std::cout << "Year of Edition: " << anneeEdition << std::endl;
    std::cout << "Number of Copies: " << exemplaires << std::endl;
}
Livre* library::reacherchN(const int& target)
{
    NoeudArbre* temp = racine;
    return library::rechercherLivreParNumero(temp, target);
}
NoeudArbre* library::insererLivre(NoeudArbre* racine, Livre nouveauLivre)
{
    if (racine == nullptr)
        return new NoeudArbre{ nouveauLivre, nullptr, nullptr };
    if (nouveauLivre.numero < racine->livre.numero)
        racine->gauche = insererLivre(racine->gauche, nouveauLivre);
    else if (nouveauLivre.numero > racine->livre.numero)
        racine->droit = insererLivre(racine->droit, nouveauLivre);
    return racine;
}
Livre Livre::readLivre()
{
    Livre livre;
    std::cout << "Enter the book number: ";
    std::cin >> livre.numero;
    std::cout << "Enter the book title: ";
    std::cin.ignore();
    std::getline(std::cin, livre.titre);
    std::cout << "Enter the author: ";
    std::getline(std::cin, livre.auteur);
    std::cout << "Enter the year of edition: ";
    std::cin >> livre.anneeEdition;
    std::cout << "Enter the number of copies: ";
    std::cin >> livre.exemplaires;
    return livre;
}
bool library::estLivreDisponible(int& numero)
{
    NoeudArbre* temp = racine;
    Livre* livreTrouve = rechercherLivreParNumero(temp, numero);
    if (!livreTrouve)
        return 0;
    return (livreTrouve->exemplaires > 0);
}
Livre* library::rechercherLivreParNumero(NoeudArbre* racine, int numero)
{
    if (racine == nullptr || racine->livre.numero == numero)
        return &racine->livre;
    if (numero < racine->livre.numero)
        return rechercherLivreParNumero(racine->gauche, numero);
    return rechercherLivreParNumero(racine->droit, numero);
}
Livre* library::rechercherLivreParTitre(NoeudArbre* racine, std::string titre)
{
    if (racine == nullptr || racine->livre.titre == titre)
        return &racine->livre;
    if (titre < racine->livre.titre)
        return rechercherLivreParTitre(racine->gauche, titre);
    return rechercherLivreParTitre(racine->droit, titre);
}
Livre* library::rechearchT(const std::string& target)
{
    NoeudArbre* temp = racine;
    return library::rechercherLivreParTitre(temp, target);
}
void library::ajouter(Livre& target)
{
    racine = library::insererLivre(racine, target);
}
void library::afficher()
{

}
namespace part1
{
    template <typename Func>
    void forEchLivresIN(NoeudArbre* racine, Func func)
    {
        if (racine != nullptr) {
            forEchLivresIN(racine->gauche, func);
            func(racine->livre);
            forEchLivresIN(racine->droit, func);
        }
    }
    void titels(const NoeudArbre* head,std::vector<std::string> &arrT)
    {
        if (!head)
        {
            arrT.push_back(head->livre.titre);
            titels(head->gauche,arrT);
            titels(head->droit,arrT);
        }
    }
    void BSort(std::vector<std::string>& myVector) {
        size_t n = myVector.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (myVector[j] > myVector[j + 1]) {
                    std::string temp = myVector[j];
                    myVector[j] = myVector[j + 1];
                    myVector[j + 1] = temp;
                }
            }
        }
    }
    void AffichageAlphabit(const NoeudArbre* head)
    {
        std::vector<std::string> temp;
        titels(head, temp);
        //BSort(temp);
        std::sort(temp.begin(), temp.end());
        for (auto& i : temp)
            std::cout << i << std::endl;

    }
}