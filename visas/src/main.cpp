#include <iostream>

int vektoriai();
int listai();

int main() {
    char choice;
    do {
        std::cout << "Pasirinkite tipa (vektorius(1) arba listas(2)): ";
        std::cin >> choice;

        if (choice == '1') {
            // Execute vektoriai.cpp
            vektoriai();  // Replace with the actual command for execution
        } else if (choice == '2') {
            // Execute listai.cpp
            listai();  // Replace with the actual command for execution
        } else {
            std::cout << "Neteisingas pasirinkimas." << std::endl;
        }
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "Ar norite kartoti programa? (y/n): ";
        std::cin >> choice;


    } while (choice == 'y' || choice == 'Y');

    std::cout << "einam lauk" << std::endl;

    return 0;
}
