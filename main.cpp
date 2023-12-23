#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "funkcijos.h"

int main() {
    std::vector<Studentas> studentai;

    try {
        std::ifstream inFile("studentai000.txt");
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

        std::ofstream outFile("rezultatai.txt");

        outFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::right << "Galutinis (Vid.)" << std::setw(15) << std::right << "Galutinis (Med.)" << std::endl;
        outFile << "---------------------------------------------------------------------" << std::endl;

        for (const Studentas& studentas : studentai) {
            double galutinisBalasVidurkis = skaiciuotiGalutiniBala(studentas, true);
            double galutinisBalasMediana = skaiciuotiGalutiniBala(studentas, false);

            outFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalasVidurkis << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalasMediana << std::endl;
        }

        outFile.close();

        std::cout << "Rezultatai issaugoti failo rezultatai.txt." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
