#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
    //Intro message
    std::cout << "\n\nHello James Bond, you have to break into a level " << Difficulty;
    std::cout << " secure server room to retrieve some top secret documents..\nUse the clues and Enter the correct code to progress...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);

    //declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product
    std::cout << "-- There are 3 numbers in the code\n";

    std::cout << "-- The codes add up to: " << CodeSum;
    std::cout << "\n-- The codes multiply to give: " << CodeProduct << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done Mr.Bond, File successfully extracted! ***";
        return true;
    }
    else
    {
        std::cout << "\nTry Again Mr.Bond, we have to get this right!";
        return false;
    }
    
}

int main()
{
    srand(time(NULL)); //create new randon sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop till all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  //clears any errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty; //increase difficulty by 1
        }
        
    }

    std::cout << "\n*** Congratulations Mr.Bond, all files extracted. Return to base for your next mission ***";


    return 0;
}