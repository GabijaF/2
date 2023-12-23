#include "funkcijos.h"
#include <chrono>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iterator>


int main() {
    std::vector<Studentas> studentai;
    std::vector<Studentas> vargsiukai;
    std::vector<Studentas> galvociai;

    char pasirinkimas;
    std::cout << "Ar norite ivesti duomenis (R) ar skaityti is failo (F)? ";
    std::cin >> pasirinkimas;

    

    if (pasirinkimas == 'R' || pasirinkimas == 'r') {
        Studentas naujasStudentas;
        naujasStudentas.address = &naujasStudentas;
        std::cout << "adresas:" << &naujasStudentas << std::endl;

        do {
            std::cout << "Iveskite studento varda: ";
            std::cin >> naujasStudentas.vardas;
            std::cout << "Iveskite studento pavarde: ";
            std::cin >> naujasStudentas.pavarde;

            char generuotiPazymius;
            std::cout << "Ar norite, kad namu darbu ir egzamino pazymiai butu generuojami? (T/N): ";
            std::cin >> generuotiPazymius;

            if (generuotiPazymius == 'T' || generuotiPazymius == 't') {
                int NdKiekis = rand() % 10 + 1;
                for (int i = 0; i < NdKiekis; ++i) {
                    naujasStudentas.Nd.push_back(generuotiNdBala());
                }
                naujasStudentas.egz = generuotiEgzBala();
            } else {
                try {
                    int pazymys;
                    std::cout << "Iveskite namu darbu pazymius (baigus parasyk -1): ";
                    while (std::cin >> pazymys) {
                        if (pazymys == -1) {
                            break;
                        }
                        if (pazymys < 1 || pazymys > 10) {
                            throw std::runtime_error("Invalid. ND pazymys turi buti tarp 1-10.");
                        }
                        naujasStudentas.Nd.push_back(pazymys);
                    }
                    std::cout << "Iveskite egzamino pazymi: ";
                    std::cin >> naujasStudentas.egz;
                    if (naujasStudentas.egz < 1 || naujasStudentas.egz > 10) {
                        throw std::runtime_error("Invalid. Egzamino pazymys turi buti tarp 1-10.");
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Klaida: " << e.what() << std::endl;
                    return 1;
                }
            }

            studentai.push_back(naujasStudentas);

            std::cout << "adresas:" << &naujasStudentas << std::endl;
            std::cout << "Ar norite ivesti dar vieno studento duomenis? (T/N): ";
            std::cin >> pasirinkimas;

        } while (pasirinkimas == 'T' || pasirinkimas == 't');

        char baloSkaiciavimoBudas;
        std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
        std::cin >> baloSkaiciavimoBudas;



        auto startSortTime = std::chrono::high_resolution_clock::now();

        std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai), [&](const Studentas& studentas) {
            double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
            return galutinisBalas >= 5.0;
        });

        // Kopijuoja galvocius
        std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(galvociai), [&](const Studentas& studentas) {
            double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
            return galutinisBalas < 5.0;
        });

        auto endSortTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sortTime = endSortTime - startSortTime;

        char rikiavimas;
        std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
        std::cin >> rikiavimas;

        if (rikiavimas == 'Y' || rikiavimas == 'y') {
            std::cout << "Kaip norite surikiuoti rezultatus - didziausi pirma (D) ar maziausi pirma (M)? ";
            char rikiavimoBudas;
            std::cin >> rikiavimoBudas;

            auto compareByFinalGrade = [baloSkaiciavimoBudas](const Studentas& a, const Studentas& b) {
                return skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) > skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas);
            };

            
            std::sort(vargsiukai.begin(), vargsiukai.end(), compareByFinalGrade);

            
            std::sort(galvociai.begin(), galvociai.end(), compareByFinalGrade);
        }

        std::cout << std::endl;
        int studentCount = studentai.size();
        std::cout <<"studentu sk:" << studentCount << std::endl;

        std::cout << "studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;


        auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

        std::ofstream galvociaiFile("galvociai.txt");
        galvociaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
        galvociaiFile << "---------------------------------------------" << std::endl;
        for (const Studentas& studentas : galvociai) {
            double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
            galvociaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
        }
        galvociaiFile.close();
        auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
        std::cout << "Failo isvedimas i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;


        
        auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

        std::ofstream vargsiukaiFile("vargsiukai.txt");
        vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
        vargsiukaiFile << "---------------------------------------------" << std::endl;
        for (const Studentas& studentas : vargsiukai) {
            double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
            vargsiukaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
        }
        vargsiukaiFile.close();
        auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
        std::cout << "Failo isvedimas i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;



    } else if (pasirinkimas == 'F' || pasirinkimas == 'f') {
        try {
            std::string failoPavadinimas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failoPavadinimas;

            std::ifstream inFile(failoPavadinimas);
            if (!inFile) {
                throw std::runtime_error("Nepavyko atidaryti failo");
            }

            char baloSkaiciavimoBudas;
            std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
            std::cin >> baloSkaiciavimoBudas;


            auto startReadFileTime = std::chrono::high_resolution_clock::now();

            std::string eilute;
            while (std::getline(inFile, eilute)) {
                Studentas naujasStudentas;
                std::istringstream iss(eilute);
                iss >> naujasStudentas.vardas >> naujasStudentas.pavarde;

                int pazymys;
                while (iss >> pazymys) {
                    naujasStudentas.Nd.push_back(pazymys);
                }

                if (!naujasStudentas.Nd.empty()) {
                    naujasStudentas.egz = naujasStudentas.Nd.back();
                    naujasStudentas.Nd.pop_back();

                    studentai.push_back(naujasStudentas);
                }
            }

            inFile.close();
            int studentCount = studentai.size();
            auto endReadFileTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;



            auto startSortTime = std::chrono::high_resolution_clock::now();

            std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai), [&](const Studentas& studentas) {
                double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
                return galutinisBalas >= 5.0;
            });

            std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(galvociai), [&](const Studentas& studentas) {
                double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
                return galutinisBalas < 5.0;
            });

            auto endSortTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> sortTime = endSortTime - startSortTime;

            std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
            char rikiavimas;
            std::cin >> rikiavimas;

            if (rikiavimas == 'Y' || rikiavimas == 'y') {
                std::cout << "Kaip norite surikiuoti rezultatus - didziausi pirma (D) ar maziausi pirma (M)? ";
                char rikiavimoBudas;
                std::cin >> rikiavimoBudas;

                auto compareByFinalGrade = [baloSkaiciavimoBudas](const Studentas& a, const Studentas& b) {
                    return skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) > skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas);
                };

                
                std::sort(vargsiukai.begin(), vargsiukai.end(), compareByFinalGrade);

                
                std::sort(galvociai.begin(), galvociai.end(), compareByFinalGrade);
            }

            std::cout << std::endl;
            std::cout << "Studentu skaicius: " << studentCount << std::endl;
            std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;


            std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;



            auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream vargsiukaiFile("vargsiukai.txt");
            vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            vargsiukaiFile << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : vargsiukai) {
                double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
                vargsiukaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            vargsiukaiFile.close();
            auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

            auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream galvociaiFile("galvociai.txt");
            galvociaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            galvociaiFile << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : galvociai) {
                double galutinisBalas = skaiciuotiGalutiniBala(studentas, baloSkaiciavimoBudas);
                galvociaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            galvociaiFile.close();
            auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "Klaida: " << e.what() << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Neteisingas pasirinkimas." << std::endl;
        return 1;
    }

    return 0;
}
