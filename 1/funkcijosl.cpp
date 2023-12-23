#include "funkcijosl.h"
#include <fstream>
#include <algorithm>
#include <random>
#include <sstream>


int generuotiNdBala() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

int generuotiEgzBala() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

double skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) {
        return 0.0;
    }
    double suma = 0.0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return suma / pazymiai.size();
}

double skaiciuotiMediana(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) {
        return 0.0;
    }
    std::vector<int> kopija = pazymiai;
    std::sort(kopija.begin(), kopija.end());
    int dydis = kopija.size();
    if (dydis % 2 == 0) {
        int vidurinis1 = kopija[dydis / 2 - 1];
        int vidurinis2 = kopija[dydis / 2];
        return (vidurinis1 + vidurinis2) / 2.0;
    } else {
        return kopija[dydis / 2];
    }
}

double skaiciuotiGalutiniBala(const Studentas& studentas, char baloSkaiciavimoBudas) {
    double NdBalas = (baloSkaiciavimoBudas == 'V' || baloSkaiciavimoBudas == 'v') ? skaiciuotiVidurki(studentas.Nd) : skaiciuotiMediana(studentas.Nd);
    double galutinisBalas = (0.4 * NdBalas + 0.6 * studentas.egz);
    return galutinisBalas;
}



