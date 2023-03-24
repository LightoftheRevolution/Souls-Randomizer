#include "RandomElementSelector.cc"
#include <conio.h>


int main(){
    RandomElementSelector selector;
    // Checks if file does not exists
    if (!selector.loadElementsFromFile("DSR_Stats.txt")){
        std::cout << "Error: could not load Elements from file.\n";
        return 1;
    }

    std::string random_Element = selector.selectRandomElement();
    std::cout << "Randomly selected Element: " << random_Element << std::endl;
    std::cout << "Press any key to Exit...";
    // Waits for a key press
    while (!kbhit()); 
    getch();

    return 0;
}