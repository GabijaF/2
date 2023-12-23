#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> Nd;
    int egz;
};

double skaiciuotiVidurki(const std::vector<int>& pazymiai);
double skaiciuotiGalutiniBala(const Studentas& studentas, bool naudotiVidurki);
double skaiciuotiGalutiniBalaMediana(const Studentas& studentas);
void readStudentData(std::vector<Studentas>& studentai, const std::string& fileName);
void writeResultsToFile(const std::vector<Studentas>& studentai, const std::string& vargsiukaiFileName, const std::string& galvociaiFileName);

