/*
 * Exercice4.cpp
 *
 *  Created on: 14 nov. 2026
 *      Author: hP
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

// 1. Interface
class StrategieTri {
public:
    virtual void trier(vector<string>& v) const = 0;
    virtual string nom() const = 0;
    virtual ~StrategieTri() {}
};

// 2. Stratégies concrètes
class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& v) const override {
        sort(v.begin(), v.end());
    }
    string nom() const override { return "Tri croissant"; }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& v) const override {
        sort(v.begin(), v.end(), greater<string>());
    }
    string nom() const override { return "Tri decroissant"; }
};

class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& v) const override {
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() < b.size();
            return a < b;   // à longueur égale : ordre alphabétique
        });
    }
    string nom() const override { return "Tri par longueur"; }
};

// 3. Contexte
class GestionnaireTri {
private:
    unique_ptr<StrategieTri> strategie;

public:
    GestionnaireTri(unique_ptr<StrategieTri> s) : strategie(move(s)) {}

    // Changement de stratégie à l'exécution
    void setStrategie(unique_ptr<StrategieTri> s) {
        strategie = move(s);
    }

    void executer(vector<string>& v) const {
        cout << "[" << strategie->nom() << "] : ";
        strategie->trier(v);
    }
};

void afficher(const vector<string>& v) {
    for (const string& s : v) cout << s << " ";
    cout << endl;
}

int main() {
    const vector<string> original = {"banane", "kiwi", "pomme", "fraise", "ananas", "figue"};

    // 4. Tests
    GestionnaireTri g(make_unique<TriCroissant>());

    vector<string> v = original;
    g.executer(v);
    afficher(v);

    g.setStrategie(make_unique<TriDecroissant>());
    v = original;
    g.executer(v);
    afficher(v);

    g.setStrategie(make_unique<TriParLongueur>());
    v = original;
    g.executer(v);
    afficher(v);

    return 0;
}



