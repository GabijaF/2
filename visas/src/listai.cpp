#include <iostream>

int l_1();
int l_2();
int l_3();

int listai() {
    char choice;
    std::cout << "pasirinkite strategija (1 ar 2 ar 3) ";
    std::cin >> choice;

    if (choice == '1') {
        // Execute main1.cpp
        l_1();  
    } else if (choice == '2') {
        // Execute main2.cpp
        l_2();
    } else if (choice == '3') {
        // Execute main2.cpp
        l_3();      
    } else {
        std::cout << "neteisingas pasirinkimas" << std::endl;
    }

    return 0;
}

