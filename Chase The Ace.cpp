#include "Chase.h"
char _startgamechoice {};

int main(){

    std::cout << "*** Welcome To Chase The Ace ***" << std::endl;
    std::cout << "Avoid getting stuck with the Ace or the lowest card!" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Start Game? [y/n]" << std::endl;
    std::cin >> _startgamechoice; 

    if(_startgamechoice == 'y' || _startgamechoice == 'Y')
        PlayGame();
    else if(_startgamechoice != 'y' || _startgamechoice != 'Y')
        exit(0);

    return 0;
}