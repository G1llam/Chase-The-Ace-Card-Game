#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

struct Card{
    std::string rank;
    std::string suit;
};

std::vector<Card> GenerateDeck(){
    std::vector<Card> deck;
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    for(const auto& suit : suits){
        for(const auto& rank : ranks){
            deck.push_back({rank, suit});
        }
    }
    return deck;
}

void ShuffleDeck(std::vector<Card>& deck){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getRankValue(const std::string& rank) {
    if (rank == "Ace")
        return 1;
    else if (rank == "2")
        return 2;
    else if (rank == "3")
        return 3;
    else if (rank == "4")
        return 4;
    else if (rank == "5")
        return 5;
    else if (rank == "6")
        return 6;
    else if (rank == "7")
        return 7;
    else if (rank == "8")
        return 8;
    else if (rank == "9")
        return 9;
    else if (rank == "10" || rank == "Jack" || rank == "Queen" || rank == "King")
        return 10;

    // Handle invalid rank
    return 0;
}

int calculateScore(const std::vector<Card>& hand) {
    int score = 0;
    for (const auto& card : hand) {
        if (card.rank == "Ace" && card.suit == "Spades") {
            score += 11;
        } else {
            score += getRankValue(card.rank);
        }
    }
    return score;
}

void PlayGame() {
    std::vector<Card> deck = GenerateDeck();
    ShuffleDeck(deck);

    std::vector<Card> playerHand;
    std::vector<Card> aiHand;

    //Deal the initial cards
    playerHand.push_back(deck.back());
    deck.pop_back();
    aiHand.push_back(deck.back());
    deck.pop_back();

    bool GameOver = false;
    std::string PlayerPlayChoice {};
    char PlayAgain {};

    while (!GameOver) {
        std::cout << "\nYour hand: ";
        for (const auto& card : playerHand) {
            std::cout << card.rank << " of " << card.suit;
        }
        std::cout << std::endl;

        std::cout << "Would you like to stick or swap? ";
        std::cin >> PlayerPlayChoice;

        if (PlayerPlayChoice == "Stick" || PlayerPlayChoice == "stick") {
            int playerScore = calculateScore(playerHand);
            int aiScore = calculateScore(aiHand);

            std::cout << "\nYour final score: " << playerScore << std::endl;
            std::cout << "AI's final score: " << aiScore << "\n" << std::endl;

            // Determine the winner
            if (playerScore > aiScore) {
                std::cout << "You win! \n" << std::endl;
                GameOver = true;
            } else if (playerScore < aiScore) {
                std::cout << "you lost! Better luck next time!\n";
                GameOver = true;
            } else {
                std::cout << "It's a tie!\n" << std::endl;
                GameOver = true;
            }     
            
        } else if (PlayerPlayChoice == "Swap" || PlayerPlayChoice == "swap") {
            int swapCardChoice {1};

            if (swapCardChoice >= 1 && swapCardChoice <= playerHand.size()) {
                Card swappedCard = playerHand[swapCardChoice - 1];
                playerHand[swapCardChoice - 1] = aiHand.back();
                aiHand.back() = swappedCard;
            }

            std::cout << "You swapped a card with the AI.\n" << std::endl;

                int playerScore = calculateScore(playerHand);
                int aiScore = calculateScore(aiHand);

                std::cout << "Your final score: " << playerScore << std::endl;
                std::cout << "AI's final score: " << aiScore << " \n " << std::endl;

                if (playerScore > aiScore) {
                    std::cout << "You win! \n" << std::endl;
                    GameOver = true;
                } else if (playerScore < aiScore) {
                    std::cout << "you lost! Better luck next time!\n";
                    GameOver = true;
                } else {
                    std::cout << "It's a tie!\n" << std::endl;
                    GameOver = true;
                }           
        }
    }

    std::cout << "would you like to play again? \n";
    std::cin >> PlayAgain;
    if(PlayAgain == 'Y' || PlayAgain == 'y')
        PlayGame();
    else if(PlayAgain != 'Y' || PlayAgain != 'y')
        exit(0);
}
