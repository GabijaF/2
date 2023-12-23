#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> Nd;
    int egz;
};

// Funkcija generuojan namu darbo balus nuo 1 iki 10
int generuotiNdBala() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

int generuotiEgzBala() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

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

double skaiciuotiMediana(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) {
        return 0.0;
    }
    std::vector<int> kopija = pazymiai;
    std::sort(kopija.begin(), kopija.end());
    int dydis = kopija.size();
    if (dydis % 2 == 0) {
        int vidurinis1 = kopija[dydis / 2 - 1];
        int vidurinis2 = kopija[dydis / 2];
        return (vidurinis1 + vidurinis2) / 2.0;
    } else {
        return kopija[dydis / 2];
    }
}

double skaiciuotiGalutiniBala(const Studentas& studentas, bool naudotiVidurki) {
    double NdBalas = skaiciuotiVidurki(studentas.Nd);
    double galutinisBalas = (0.4 * NdBalas + 0.6 * studentas.egz);
    if (naudotiVidurki) {
        return galutinisBalas;
    } else {
        double mediana = skaiciuotiMediana(studentas.Nd);
        return (0.4 * mediana + 0.6 * studentas.egz);
    }
}

int main() {
    std::vector<Studentas> studentai;
    char pasirinkimas;

    srand(time(nullptr));

    do {
        Studentas naujasStudentas;
        std::cout << "iveskite studento varda: ";
        std::cin >> naujasStudentas.vardas;
        std::cout << "iveskite studento pavarde: ";
        std::cin >> naujasStudentas.pavarde;

        char generuotiPazymius;
        std::cout << "Ar norite, kad namu darbu ir egzamino pazymiai būtų generuojami? (T/N): ";
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
                std::cout << "iveskite namu darbu pazymius (baigus parašyk -1): ";
                while (std::cin >> pazymys) {
                    if (pazymys == -1) {
                        break;
                    }
                    if (pazymys < 1 || pazymys > 10) {
                        throw std::runtime_error("Invalid.ND pazymys turi buti  tarp 1-10.");
                    }
                    naujasStudentas.Nd.push_back(pazymys);
                }
                std::cout << "iveskite egzamino pažymi: ";
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

        std::cout << "Ar norite ivesti dar vieno studento duomenis? (T/N): ";
        std::cin >> pasirinkimas;

    } while (pasirinkimas == 'T' || pasirinkimas == 't');

    char baloSkaiciavimoBudas;
    std::cout << "Kaip norite skaičiuoti galutini baa pagal vidurki (V) ar pagal medianą (M)? ";
    std::cin >> baloSkaiciavimoBudas;

    std::cout << std::endl;
    std::cout << std::setw(20) << std::left << "Vardas" << std::setw(20) << std::left << "Pavardė" << std::setw(20) << std::right;

    if (baloSkaiciavimoBudas == 'M' || baloSkaiciavimoBudas == 'm') {
        std::cout << "Galutinis (Med.)" << std::endl;
    } else {
        std::cout << "Galutinis (Vid.)" << std::endl;
    }

    std::cout << "---------------------------------------------------------------" << std::endl;

    for (const Studentas& studentas : studentai) {
        double galutinisBalas = (baloSkaiciavimoBudas == 'V' || baloSkaiciavimoBudas == 'v') ?
            skaiciuotiGalutiniBala(studentas, true) :
            skaiciuotiGalutiniBala(studentas, false);

        std::cout << std::setw(20) << std::left << studentas.vardas << std::setw(20) << std::left << studentas.pavarde << std::setw(7) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << std::endl;
    }

    return 0;
}
