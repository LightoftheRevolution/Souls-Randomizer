#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class RandomElementSelector{
private:
    //Initializes array
    static const int MAX_Elements = 100; //Change later to be not hard coded
    std::string Elements[MAX_Elements];
    int num_Elements;

public:
    RandomElementSelector(){
        num_Elements = 0;
    }

    bool loadElementsFromFile(std::string filename){
        std::ifstream infile(filename);
        if (!infile){
            return false;
        }

        int i = 0;
        while (std::getline(infile, Elements[i]) && i < MAX_Elements){
            i++;
        }
        infile.close();

        num_Elements = i;
        return true;
    }

    std::string selectRandomElement(){
        //Uses system time to get random number within bounds of array
        srand(time(NULL));
        int random_index = rand() % num_Elements;
        return Elements[random_index];
    }
};
