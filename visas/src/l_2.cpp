#include <iostream>
#include "f.h"

#include <chrono>
#include <algorithm>
#include <fstream>
#include <iomanip>


int l_2() {
    std::list<StudentasL> studentaiL;
    std::list<StudentasL> vargsiukai;

    char pasirinkimas;
    std::cout << "Ar norite ivesti duomenis (R) ar skaityti is failo (F) ar generuoti (G)? ";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 'G' || pasirinkimas == 'g') {
        int studentuSkaicius;
        std::cout << "Kiek studentu norite sugeneruoti? ";
        std::cin >> studentuSkaicius;

        auto startCreateFileTime = std::chrono::high_resolution_clock::now();

        std::string fileName = "studentaiL_" + std::to_string(studentuSkaicius) + ".txt";
        std::ofstream outFile(fileName);
        outFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde";

        for (int i = 1; i <= 5; ++i) {
            outFile << std::setw(5) << std::right << "nd" << i;
        }
        outFile << std::setw(5) << std::right << "egz\n";
        outFile << "-----------------------------------------------------------------------\n";

        for (int i = 1; i <= studentuSkaicius; ++i) {
            outFile << std::setw(15) << std::left << "Vardas" + std::to_string(i)
                    << std::setw(15) << std::left << "Pavarde" + std::to_string(i);
            for (int j = 0; j < 5; ++j) {
                outFile << std::setw(5) << std::right << generuotiNdBala();
            }
            outFile << std::setw(5) << std::right << generuotiEgzBala() << "\n";
        }

        outFile.close();

        auto endCreateFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> CreateFileTime = endCreateFileTime - startCreateFileTime;
        std::cout << "Failo" << fileName << "kūrimas uztruko: " << CreateFileTime.count() << " sekundes" << std::endl;


        std::cout << "Failas '" << fileName << "' buvo sugeneruotas.\n";

        std::ifstream inFile(fileName);
        if (!inFile) {
            std::cerr << "Nepavyko atidaryti failo " << fileName << std::endl;
            return 1;
        }

        char baloSkaiciavimoBudas;
        std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
        std::cin >> baloSkaiciavimoBudas;

        auto startReadFileTime = std::chrono::high_resolution_clock::now();

        std::string eilute;
        while (std::getline(inFile, eilute)) {
            StudentasL naujasStudentasL;
            std::istringstream iss(eilute);
            iss >> naujasStudentasL.vardas >> naujasStudentasL.pavarde;

            int pazymys;
            while (iss >> pazymys) {
                naujasStudentasL.Nd.push_back(pazymys);
            }

            if (!naujasStudentasL.Nd.empty()) {
                naujasStudentasL.egz = naujasStudentasL.Nd.back();
                naujasStudentasL.Nd.pop_back();

                studentaiL.push_back(naujasStudentasL);
            }
        }

        inFile.close();
        int studentCount = studentaiL.size();
        auto endReadFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;


        auto startSortTime = std::chrono::high_resolution_clock::now();

            for (auto it = studentaiL.begin(); it != studentaiL.end();) {
            const StudentasL& StudentasL = *it;
            double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);

            if (galutinisBalas <= 5.0) {
                vargsiukai.push_back(StudentasL);
                it = studentaiL.erase(it); // Use the iterator returned by erase
            } else {
                ++it;
            }
        }
            auto endSortTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> sortTime = endSortTime - startSortTime;

            std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
            char rikiavimas;
            std::cin >> rikiavimas;


            if (rikiavimas == 'Y' || rikiavimas == 'y') {
            std::cout << "Kaip norite surikiuoti rezultatus:\n"
                         "1. Pagal varda\n"
                         "2. Pagal pavarde\n"
                         "3. Pagal galutini bala\n"
                         "Jusu pasirinkimas: ";
            int rikiavimoKriterijus;
            std::cin >> rikiavimoKriterijus;

            char rikiavimoTvarka;
            std::cout << "Kaip norite surikiuoti rezultatus - didžiausi pirma (D) ar mažiausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const StudentasL& a, const StudentasL& b) {
                switch (rikiavimoKriterijus) {
                    case 1:{
                        std::string numStrA = a.vardas.substr(6); 
                        std::string numStrB = b.vardas.substr(6);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }

                    case 2:{
                        std::string numStrA = a.pavarde.substr(7); 
                        std::string numStrB = b.pavarde.substr(7);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }

                    case 3:
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ?
                            skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) > skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas) :
                            skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) < skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas);
                    default:
                        
                        return false;
                }
            };

            vargsiukai.sort(compareByCriterion);
            studentaiL.sort(compareByCriterion);

            }
            std::cout << std::endl;
            std::cout << "Studentu skaicius: " << studentCount << std::endl;
            std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;


            std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;


            auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream vargsiukaiFile("vargsiukai.txt");
            vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            vargsiukaiFile << "---------------------------------------------" << std::endl;
            for (const StudentasL& StudentasL : vargsiukai) {
                double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);
                vargsiukaiFile << std::setw(15) << std::left << StudentasL.vardas << std::setw(15) << std::left << StudentasL.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            vargsiukaiFile.close();
            auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

            auto startWritestudentaiLTime = std::chrono::high_resolution_clock::now();

            std::ofstream studentaiLFile("studentaiLg.txt");
            studentaiLFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            studentaiLFile << "---------------------------------------------" << std::endl;
            for (const StudentasL& StudentasL : studentaiL) {
                double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);
                studentaiLFile << std::setw(15) << std::left << StudentasL.vardas << std::setw(15) << std::left << StudentasL.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            studentaiLFile.close();
            auto endWritestudentaiLTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writestudentaiLTime = endWritestudentaiLTime - startWritestudentaiLTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i galvociai uztruko: " << writestudentaiLTime.count() << " sekundes" << std::endl;






        return 0;
    }



    if (pasirinkimas == 'R' || pasirinkimas == 'r') {
        StudentasL naujasStudentasL;
        naujasStudentasL.address = &naujasStudentasL;

        do {
            std::cout << "Iveskite studento varda: ";
            std::cin >> naujasStudentasL.vardas;
            std::cout << "Iveskite studento pavarde: ";
            std::cin >> naujasStudentasL.pavarde;

            char generuotiPazymius;
            std::cout << "Ar norite, kad namu darbu ir egzamino pazymiai butu generuojami? (T/N): ";
            std::cin >> generuotiPazymius;

            if (generuotiPazymius == 'T' || generuotiPazymius == 't') {
                int NdKiekis = rand() % 10 + 1;
                for (int i = 0; i < NdKiekis; ++i) {
                    naujasStudentasL.Nd.push_back(generuotiNdBala());
                }
                naujasStudentasL.egz = generuotiEgzBala();
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
                        naujasStudentasL.Nd.push_back(pazymys);
                    }
                    std::cout << "Iveskite egzamino pazymi: ";
                    std::cin >> naujasStudentasL.egz;
                    if (naujasStudentasL.egz < 1 || naujasStudentasL.egz > 10) {
                        throw std::runtime_error("Invalid. Egzamino pazymys turi buti tarp 1-10.");
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Klaida: " << e.what() << std::endl;
                    return 1;
                }
            }

            studentaiL.push_back(naujasStudentasL);

            std::cout << "Ar norite ivesti dar vieno studento duomenis? (T/N): ";
            std::cin >> pasirinkimas;

        } while (pasirinkimas == 'T' || pasirinkimas == 't');

        char baloSkaiciavimoBudas;
        std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
        std::cin >> baloSkaiciavimoBudas;


        for (auto it = studentaiL.begin(); it != studentaiL.end();) {
        const StudentasL& StudentasL = *it;
        double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);

        if (galutinisBalas <= 5.0) {
            vargsiukai.push_back(StudentasL);
            it = studentaiL.erase(it); // Use the iterator returned by erase
        } else {
            ++it;
        }
    }

        char rikiavimas;
        std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
        std::cin >> rikiavimas;

        if (rikiavimas == 'Y' || rikiavimas == 'y') {
        std::cout << "Kaip norite surikiuoti rezultatus:\n"
                     "1. Pagal varda\n"
                     "2. Pagal pavarde\n"
                     "3. Pagal galutini bala\n"
                     "Jusu pasirinkimas: ";
        int rikiavimoKriterijus;
        std::cin >> rikiavimoKriterijus;

        char rikiavimoTvarka;
        std::cout << "Kaip norite surikiuoti rezultatus - didžiausi pirma (D) ar mažiausi pirma (M)? ";
        std::cin >> rikiavimoTvarka;

        auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const StudentasL& a, const StudentasL& b) {
            switch (rikiavimoKriterijus) {
                case 1:
                    return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? a.vardas > b.vardas : a.vardas < b.vardas;
                case 2:
                    return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? a.pavarde > b.pavarde : a.pavarde < b.pavarde;
                case 3:
                    return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ?
                        skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) > skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas) :
                        skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) < skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas);
                default:
                    // Jei pasirinktas neteisingas kriterijus, nekeičiame tvarkos.
                    return false;
            }
        };

        vargsiukai.sort(compareByCriterion);
        studentaiL.sort(compareByCriterion);

        }


        std::cout << std::endl;
        int studentCount = studentaiL.size();
        std::cout <<"studentu sk:" << studentCount << std::endl;


        std::cout << std::endl;
        std::cout << "vargsiukai:" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde"
                  << std::setw(15) << std::right << "Galutinis" << std::setw(15) << std::right << "Adresas" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;

        for (const StudentasL& StudentasL : vargsiukai) {
            double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);
            std::cout << std::setw(15) << std::left << StudentasL.vardas << std::setw(15) << std::left << StudentasL.pavarde
                      << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas
                      << std::setw(15) << std::right << &naujasStudentasL << "\n";
        }

        std::cout << std::endl;
        std::cout << std::endl;


        std::cout << "galvociai:" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde"
                  << std::setw(15) << std::right << "Galutinis" << std::setw(15) << std::right << "Adresas" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;

        for (const StudentasL& StudentasL : studentaiL) {
            double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);
            std::cout << std::setw(15) << std::left << StudentasL.vardas << std::setw(15) << std::left << StudentasL.pavarde
                      << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas
                      << std::setw(15) << std::right << &naujasStudentasL << "\n";
        }

        std::cout << std::endl;



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
                StudentasL naujasStudentasL;
                std::istringstream iss(eilute);
                iss >> naujasStudentasL.vardas >> naujasStudentasL.pavarde;

                int pazymys;
                while (iss >> pazymys) {
                    naujasStudentasL.Nd.push_back(pazymys);
                }

                if (!naujasStudentasL.Nd.empty()) {
                    naujasStudentasL.egz = naujasStudentasL.Nd.back();
                    naujasStudentasL.Nd.pop_back();

                    studentaiL.push_back(naujasStudentasL);
                }
            }

            inFile.close();
            int studentCount = studentaiL.size();
            auto endReadFileTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;



            auto startSortTime = std::chrono::high_resolution_clock::now();

            for (auto it = studentaiL.begin(); it != studentaiL.end();) {
            const StudentasL& StudentasL = *it;
            double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);

            if (galutinisBalas <= 5.0) {
                vargsiukai.push_back(StudentasL);
                it = studentaiL.erase(it); // Use the iterator returned by erase
            } else {
                ++it;
            }
        }
            auto endSortTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> sortTime = endSortTime - startSortTime;

            std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
            char rikiavimas;
            std::cin >> rikiavimas;


            if (rikiavimas == 'Y' || rikiavimas == 'y') {
            std::cout << "Kaip norite surikiuoti rezultatus:\n"
                         "1. Pagal varda\n"
                         "2. Pagal pavarde\n"
                         "3. Pagal galutini bala\n"
                         "Jusu pasirinkimas: ";
            int rikiavimoKriterijus;
            std::cin >> rikiavimoKriterijus;

            char rikiavimoTvarka;
            std::cout << "Kaip norite surikiuoti rezultatus - didžiausi pirma (D) ar mažiausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const StudentasL& a, const StudentasL& b) {
                switch (rikiavimoKriterijus) {
                    case 1:{
                        std::string numStrA = a.vardas.substr(6); // Assuming "vardas" is followed by a number
                        std::string numStrB = b.vardas.substr(6);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }

                    case 2:{
                        std::string numStrA = a.pavarde.substr(7); // Assuming "vardas" is followed by a number
                        std::string numStrB = b.pavarde.substr(7);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }

                    case 3:
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ?
                            skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) > skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas) :
                            skaiciuotiGalutiniBala(a, baloSkaiciavimoBudas) < skaiciuotiGalutiniBala(b, baloSkaiciavimoBudas);
                    default:
                        // Jei pasirinktas neteisingas kriterijus, nekeičiame tvarkos.
                        return false;
                }
            };

            vargsiukai.sort(compareByCriterion);
            studentaiL.sort(compareByCriterion);

            }
            std::cout << std::endl;
            std::cout << "Studentu skaicius: " << studentCount << std::endl;
            std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;


            std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;


            auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream vargsiukaiFile("vargsiukai.txt");
            vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            vargsiukaiFile << "---------------------------------------------" << std::endl;
            for (const StudentasL& StudentasL : vargsiukai) {
                double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);
                vargsiukaiFile << std::setw(15) << std::left << StudentasL.vardas << std::setw(15) << std::left << StudentasL.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            vargsiukaiFile.close();
            auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

            auto startWritestudentaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream studentaiFile("studentaiLg.txt");
            studentaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            studentaiFile << "---------------------------------------------" << std::endl;
            for (const StudentasL& StudentasL : studentaiL) {
                double galutinisBalas = skaiciuotiGalutiniBala(StudentasL, baloSkaiciavimoBudas);
                studentaiFile << std::setw(15) << std::left << StudentasL.vardas << std::setw(15) << std::left << StudentasL.pavarde << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            studentaiFile.close();
            auto endWritestudentaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writestudentaiTime = endWritestudentaiTime - startWritestudentaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i galvociai uztruko: " << writestudentaiTime.count() << " sekundes" << std::endl;


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

