#include "f.h"
#include <fstream>
#include <algorithm>
#include <random>
#include <sstream>


int generuotiNdBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

int generuotiEgzBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

double skaiciuotiGalutiniBala(const StudentasL& studentasL, char baloSkaiciavimoBudas) {
    double NdBalas = (baloSkaiciavimoBudas == 'V' || baloSkaiciavimoBudas == 'v') ? skaiciuotiVidurki(studentasL.Nd) : skaiciuotiMediana(studentasL.Nd);
    double galutinisBalas = (0.4 * NdBalas + 0.6 * studentasL.egz);
    return galutinisBalas;
}



double skaiciuotiVidurki(const std::list<int>& pazymiai) {
    if (pazymiai.empty()) {
        return 0.0;
    }
    double suma = 0.0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return suma / pazymiai.size();
}

double skaiciuotiMediana(const std::list<int>& pazymiai) {
    if (pazymiai.empty()) {
        return 0.0;
    }
    std::list<int> kopija = pazymiai;
    kopija.sort();
    int dydis = kopija.size();
    auto it = kopija.begin();
    std::advance(it, dydis / 2);
    if (dydis % 2 == 0) {
        int vidurinis1 = *std::prev(it);
        int vidurinis2 = *it;
        return (vidurinis1 + vidurinis2) / 2.0;
    } else {
        return *it;
    }
}



