#include"includes.h"
int main()
{
	NoeudArbre* racine = nullptr;
	files::load(racine, "Livre.txt");
	part1::AffichageAlphabit(racine);
	
}