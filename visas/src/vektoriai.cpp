#include <iostream>

int v_1();
int v_2();
int v_3();

int vektoriai() {
    char choice;
    std::cout << "pasirinkite strategija (1 ar 2 ar 3): ";
    std::cin >> choice;

    if (choice == '1') {
        
        v_1();  
    } else if (choice == '2') {
        
        v_2();
    } else if (choice == '3') {
       
        v_3();      
    } else {
        std::cout << "Invalid choice. Exiting." << std::endl;
    }

    return 0;
}

