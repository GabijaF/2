#include "studentas.h"

int main() {
    std::vector<Studentas> studentai;

    try {
        std::string fileName;
        std::cout << "Failo vardas: ";
        std::cin >> fileName;

        std::ifstream inFile(fileName);
        if (!inFile) {
            std::cerr << "nerastas failas" << std::endl;
            return 1;
        }



        auto startReadFileTime = std::chrono::high_resolution_clock::now();

        std::string eilute;
        Studentas naujasStudentas;
        std::cout << "adresas: " << &naujasStudentas << std::endl;


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
        auto endReadFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;

        int studentCount = studentai.size();
        std::cout << "Galutinis balas pagal 'v' (vidurkis) ar 'm' (mediana): ";
        char calculationMethod;
        std::cin >> calculationMethod;
        std::string calculationName = (calculationMethod == 'v') ? "vidurkis" : "mediana";
        std::cout << "Studentu skaicius: " << studentCount << std::endl;
        std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;

        std::string vargsiukaiFileName, galvociaiFileName;
        if (calculationMethod == 'v') {
            vargsiukaiFileName = "vargsiukai_vid.txt";
            galvociaiFileName = "galvociai_vid.txt";
        } else if (calculationMethod == 'm') {
            vargsiukaiFileName = "vargsiukai_med.txt";
            galvociaiFileName = "galvociai_med.txt";
        } else {
            std::cerr << "Nateisingas skaiciavimo budas" << std::endl;
            return 1;
        }

        std::ofstream vargsiukaiFile(vargsiukaiFileName);
        std::ofstream galvociaiFile(galvociaiFileName);

        vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavardë" << std::setw(15) << std::right << "Galutinis" << std::endl;
        vargsiukaiFile << "---------------------------------------------------------------------" << std::endl;

        galvociaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavardë" << std::setw(15) << std::right << "Galutinis" << std::endl;
        galvociaiFile << "---------------------------------------------------------------------" << std::endl;

        auto startSortTime = std::chrono::high_resolution_clock::now();

        for (const Studentas& studentas : studentai) {
            double galutinisBalas = (calculationMethod == 'v') ? skaiciuotiGalutiniBala(studentas, true) : skaiciuotiGalutiniBalaMediana(studentas);

            if (galutinisBalas < 5.0) {
                vargsiukaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(10) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << std::endl;
            } else {
                galvociaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(10) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << std::endl;
            }
        }

        auto endSortTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sortTime = endSortTime - startSortTime;
        std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;

        vargsiukaiFile.close();
        galvociaiFile.close();

        auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();


        std::ofstream writeVargsiukaiFile("vargsiukai.txt");
        for (const Studentas& studentas : studentai) {
            double galutinisBalas = (calculationMethod == 'v') ? skaiciuotiGalutiniBala(studentas, true) : skaiciuotiGalutiniBalaMediana(studentas);
            if (galutinisBalas < 5.0) {
                writeVargsiukaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(10) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << std::endl;
            }
        }

        auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
        std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

        auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

        std::ofstream writeGalvociaiFile("galvociai.txt");
        for (const Studentas& studentas : studentai) {
            double galutinisBalas = (calculationMethod == 'v') ? skaiciuotiGalutiniBala(studentas, true) : skaiciuotiGalutiniBalaMediana(studentas);
            if (galutinisBalas >= 5.0) {
                writeGalvociaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(10) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << std::endl;
            }
        }

        auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
        std::cout << "Filo isvedimas su" << studentCount << " studentu i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

