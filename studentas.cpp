#include "studentas.h"


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

double skaiciuotiGalutiniBala(const Studentas& studentas, bool naudotiVidurki) {
    double NdBalas = naudotiVidurki ? skaiciuotiVidurki(studentas.Nd) : *std::max_element(studentas.Nd.begin(), studentas.Nd.end());
    double galutinisBalas = (0.4 * NdBalas + 0.6 * studentas.egz);
    return galutinisBalas;
}

void readStudentData(std::vector<Studentas>& studentai, const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        throw std::runtime_error("Nepavyko atidaryti failo");
    }

    std::string eilute;
    while (std::getline(inFile, eilute)) {
        std::istringstream iss(eilute);
        Studentas naujasStudentas;
        iss >> naujasStudentas.vardas >> naujasStudentas.pavarde;

        int pazymys;
        while (iss >> pazymys) {
            naujasStudentas.Nd.push_back(pazymys);
        }

        if (naujasStudentas.Nd.empty()) {
            continue;
        }

        naujasStudentas.egz = naujasStudentas.Nd.back();
        naujasStudentas.Nd.pop_back();

        studentai.push_back(naujasStudentas);
    }

    inFile.close();
}

void writeResultsToFile(const std::vector<Studentas>& studentai, const std::string& vargsiukaiFileName, const std::string& galvociaiFileName) {
    std::ofstream vargsiukaiFile(vargsiukaiFileName);
    std::ofstream galvociaiFile(galvociaiFileName);

    vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::right << "Galutinis (Vid.)" << std::endl;
    vargsiukaiFile << "---------------------------------------------------------------------" << std::endl;

    galvociaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::right << "Galutinis (Vid.)" << std::endl;
    galvociaiFile << "---------------------------------------------------------------------" << std::endl;

    for (const Studentas& studentas : studentai) {
        double galutinisBalasVidurkis = skaiciuotiGalutiniBala(studentas, true);

        if (galutinisBalasVidurkis < 5.0) {
            vargsiukaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(5) << std::fixed << std::setprecision(2) << std::right << galutinisBalasVidurkis << std::endl;
        } else {
            galvociaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(5) << std::fixed << std::setprecision(2) << std::right << galutinisBalasVidurkis << std::endl;
        }
    }

    vargsiukaiFile.close();
    galvociaiFile.close();
}
