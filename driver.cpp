//GitHub team: mozqueda-long
#include "BankSim.h"

int main() {
    bool repeatProg = true;
    do {
        BankSim newSimulation;
        newSimulation.runSimulation();
        newSimulation.printStats();

        std::cout << "Please make a selection?\n";
        std::cout << "1: Print trace of bank simulation\n";
        std::cout << "2: Try another simulation\n";
        std::cout << "0: Exit" << std::endl;
        std::string userInput;
        std::cin >> userInput;
        if (userInput == "0") {
            repeatProg = false;
        } else if (userInput == "1") {
            
            repeatProg = false;
        }
        system("clear");
    } while (repeatProg);
    

    return 0;
};