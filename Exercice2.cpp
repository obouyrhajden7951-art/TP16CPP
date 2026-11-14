/*
 * Exercice2.cpp
 *
 *  Created on: 14 nov. 2026
 *      Author: hP
 */

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
using namespace std;

// 1. Classe abstraite
class Forme {
public:
    virtual void afficher() const = 0;
    virtual ~Forme() {}
};

// 2. Classes concrètes
class Cercle : public Forme {
public:
    void afficher() const override { cout << "Je suis un Cercle (O)" << endl; }
};

class Carre : public Forme {
public:
    void afficher() const override { cout << "Je suis un Carre ([])" << endl; }
};

class Triangle : public Forme {
public:
    void afficher() const override { cout << "Je suis un Triangle (/\\)" << endl; }
};

// 3. Fabrique simple
class FabriqueForme {
public:
    static unique_ptr<Forme> creer(const string& type) {
        if (type == "cercle")   return make_unique<Cercle>();
        if (type == "carre")    return make_unique<Carre>();
        if (type == "triangle") return make_unique<Triangle>();
        throw invalid_argument("Type de forme inconnu : " + type);
    }
};

// ----- Version modulaire : FabriqueAbstraite -----
class FabriqueAbstraite {
public:
    virtual unique_ptr<Forme> creerForme() const = 0;
    virtual ~FabriqueAbstraite() {}
};

class FabriqueCercle : public FabriqueAbstraite {
public:
    unique_ptr<Forme> creerForme() const override { return make_unique<Cercle>(); }
};

class FabriqueCarre : public FabriqueAbstraite {
public:
    unique_ptr<Forme> creerForme() const override { return make_unique<Carre>(); }
};

class FabriqueTriangle : public FabriqueAbstraite {
public:
    unique_ptr<Forme> creerForme() const override { return make_unique<Triangle>(); }
};

int main() {
    cout << "=== Fabrique simple ===" << endl;
    string types[] = {"cercle", "carre", "triangle", "hexagone"};
    for (const string& t : types) {
        try {
            auto f = FabriqueForme::creer(t);
            f->afficher();
        }
        catch (const invalid_argument& e) {
            cout << "Erreur : " << e.what() << endl;
        }
    }

    cout << "\n=== Fabrique abstraite ===" << endl;
    unique_ptr<FabriqueAbstraite> fab = make_unique<FabriqueTriangle>();
    fab->creerForme()->afficher();

    fab = make_unique<FabriqueCercle>();
    fab->creerForme()->afficher();

    return 0;
}


