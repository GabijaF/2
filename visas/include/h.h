#ifndef H_H
#define H_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>


struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> Nd;
    int egz;
    Studentas* address;
};

int generuotiNdBala();
int generuotiEgzBala();
double skaiciuotiVidurki(const std::vector<int>& pazymiai);
double skaiciuotiMediana(const std::vector<int>& pazymiai);
double skaiciuotiGalutiniBala(const Studentas& studentas, char baloSkaiciavimoBudas);

#endif // STUDENTAS_H

