#include "RandomElementSelector.cpp"
#include <ncurses.h>

int main(){
    RandomElementSelector selector;
    if (!selector.loadElementsFromFile("DSR_Stats.json")){
        std::cout << "Error: could not load Elements from file.\n";
        return 1;
    }

    initscr(); // Initialize ncurses
    cbreak(); // Disable line buffering
    noecho(); // Disable echoing of input characters
    keypad(stdscr, TRUE); // Enable function keys

    std::string random_Element;
    bool selected = false;
    while (!selected){
        clear(); // Clear the screen
        mvprintw(0, 0, "Press 'q' to quit...");
        random_Element = selector.selectRandomElement();
        mvprintw(1, 0, "Randomly selected Element: %s", random_Element.c_str());
        refresh(); // Refresh the screen

        int ch = getch(); // Wait for user input
        if (ch == 'q'){
            selected = true;
        }
    }

    endwin(); // End ncurses mode
    return 0;
}