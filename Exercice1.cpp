/*
 * Exercice1.cpp
 *
 *  Created on: 14 nov. 2026
 *      Author: hP
 */

#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    // Constructeur privé : personne ne peut faire "Configuration c;"
    Configuration()
        : cheminFichier("C:/data/config.ini"),
          utilisateur("admin"),
          motDePasse("1234") {
        cout << "[Configuration creee]" << endl;
    }

public:
    // Suppression de la copie et de l'affectation
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    // Instance unique (thread-safe en C++11, "Meyers Singleton")
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void setUtilisateur(const string& u) { utilisateur = u; }
    void setCheminFichier(const string& c) { cheminFichier = c; }

    void afficherParametres() const {
        cout << "--- Parametres ---" << endl;
        cout << "Fichier     : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe: " << string(motDePasse.size(), '*') << endl;
    }
};

int main() {
    Configuration& c1 = Configuration::getInstance();
    c1.afficherParametres();

    Configuration& c2 = Configuration::getInstance();
    c2.setUtilisateur("hajar");

    c1.afficherParametres();   // c1 voit la modification faite via c2

    cout << "Meme instance ? " << (&c1 == &c2 ? "oui" : "non") << endl;

    // Configuration c3;               // ERREUR : constructeur privé
    // Configuration c4 = c1;          // ERREUR : copie supprimée
    return 0;
}


