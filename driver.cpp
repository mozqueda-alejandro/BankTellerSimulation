//GitHub team: mozqueda-long
#include <limits>
#include "BankSim.h"

int main() {
    bool repeatProg = true;
    do {
        system("clear"); // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        BankSim newSimulation;
        newSimulation.runSimulation();
        newSimulation.printStats();
        newSimulation.initVars();

        std::cout << "Please make a selection\n";
        std::cout << "1: Print trace of bank simulation\n";
        std::cout << "2: Try another simulation\n";
        std::cout << "0: Exit" << std::endl;
        std::string userInput;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        if (userInput == "0") {
            repeatProg = false;
        } else if (userInput == "1") {
            newSimulation.runSimulation("trace");
            std::cout << "Press ENTER to continue. . ." << std::endl;
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            system("clear"); // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                // repeatProg = false;
                std::cout << "Please make a selection\n";
                std::cout << "1: Try another simulation\n";
                std::cout << "0: Exit" << std::endl;
                std::cin >> userInput;
                if (userInput == "0") repeatProg = false;
        }
        system("clear"); // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    } while (repeatProg);
    return 0;
};