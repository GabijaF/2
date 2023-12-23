#pragma once

#include <iostream>
#include <list>
#include <vector>

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
