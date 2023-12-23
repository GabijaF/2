#ifndef F_H
#define F_H

#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <sstream>


struct StudentasL {
    std::string vardas;
    std::string pavarde;
    std::list<int> Nd;
    int egz;
    StudentasL* address;
};

int generuotiNdBala();
int generuotiEgzBala();
double skaiciuotiVidurki(const std::list<int>& pazymiai);
double skaiciuotiMediana(const std::list<int>& pazymiai);
double skaiciuotiGalutiniBala(const StudentasL& studentasL, char baloSkaiciavimoBudas);

#endif // STUDENTAS_H
