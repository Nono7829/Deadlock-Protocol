#include <iostream>
#include <string>

class Personnage {
public:
	std::string nom;
	int pointsDeVie;
	int PuissanceAttaque;
	Personnage(std::string n, int pv, int atk) {
		nom = n;
		pointsDeVie = pv;
		PuissanceAttaque = atk;
	}

	void recevoirDegats(int degats) {
		if (pointsDeVie > 0) {
			pointsDeVie -= degats;
			if (pointsDeVie < 0) {
				pointsDeVie = 0;
			}
		}
	}
	void attaquer(Personnage& cible) {
		std::cout << nom << " attaque " << cible.nom << std::endl;
		cible.recevoirDegats(PuissanceAttaque);
	}

	bool estVivant() {
		return pointsDeVie > 0;
	}
};


int main()
{
	Personnage joueur("Héros",100,25);
	Personnage gobelin("Gobelin", 60, 15);
	while (joueur.estVivant() && gobelin.estVivant()) {
		joueur.attaquer(gobelin);
		if (gobelin.estVivant()) {
			gobelin.attaquer(joueur);
		}
	}
	if (joueur.estVivant()) {
		std::cout << "Vous avez gagné !" << std::endl;
	}
	else {
		std::cout << "Vous êtes mort..." << std::endl;
	}
	return 0;
}
