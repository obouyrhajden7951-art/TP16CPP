/*
 * Exercice3.cpp
 *
 *  Created on: 14 nov. 2026
 *      Author: hP
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2. Interface Observateur
class Observateur {
public:
    virtual void mettreAJour(float temperature, float humidite, float pression) = 0;
    virtual ~Observateur() {}
};

// 1. Sujet : StationMeteo
class StationMeteo {
private:
    vector<Observateur*> observateurs;
    float temperature = 0, humidite = 0, pression = 0;

public:
    void ajouterObservateur(Observateur* o) {
        observateurs.push_back(o);
    }

    void retirerObservateur(Observateur* o) {
        observateurs.erase(remove(observateurs.begin(), observateurs.end(), o),
                           observateurs.end());
    }

    void notifier() {
        for (Observateur* o : observateurs)
            o->mettreAJour(temperature, humidite, pression);
    }

    void setMesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        notifier();   // notification automatique
    }
};

// 3. Observateurs concrets
class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float t, float, float) override {
        cout << "[Temperature] " << t << " C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float, float h, float) override {
        cout << "[Humidite]    " << h << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float, float, float p) override {
        cout << "[Pression]    " << p << " hPa" << endl;
    }
};

int main() {
    StationMeteo station;
    AffichageTemperature affT;
    AffichageHumidite affH;
    AffichagePression affP;

    // 4. Relation dynamique
    station.ajouterObservateur(&affT);
    station.ajouterObservateur(&affH);
    station.ajouterObservateur(&affP);

    cout << "--- Mesure 1 ---" << endl;
    station.setMesures(25.5f, 60.0f, 1013.0f);

    cout << "\n--- On retire l'affichage de l'humidite ---" << endl;
    station.retirerObservateur(&affH);

    cout << "\n--- Mesure 2 ---" << endl;
    station.setMesures(28.0f, 55.0f, 1010.0f);

    return 0;
}

