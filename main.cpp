#include <iostream>
#include <string>
using namespace std;
enum enGame
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};
enum enWinner
{
    NoChoice = 0,
    User = 1,
    Computer = 2,
    Equal = 3
};
// ask how many rounds
short roundNumbers()
{
    short roundNumbers;
    cout << "How Many Rounds Do You Want From [1] to [10]: ";
    cin >> roundNumbers;
    return roundNumbers;
}

// ------------------ Round[?] -------------

void roundBeginSeperator(short roundCounter)
{

    cout << "\n\t----------------------Round[" << roundCounter << "]---------------------\n"
         << endl;
}
// player 1 choise

enGame playerChoice()
{
    short playerChoice;
    cout << "Please Chose [1] Rock [2] Paper [3] Scissors";
    cin >> playerChoice;
    return (enGame)playerChoice;
}
void printPlayerChoice(enGame choice)
{
    switch (choice)
    {
    case enGame::Paper:
        cout << "\t\tYour Choice is => Paper" << endl;
        break;
    case enGame::Rock:
        cout << "\t\tYour Choice is => Rock" << endl;
        break;

    default:
        cout << "\t\tYour Choice is => Scissors" << endl;
        break;
    }
}
// computer choise
int randNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
enGame computerChoice()
{
    enGame computerChoice;
    computerChoice = (enGame)randNumber(1, 3);
    return computerChoice;
}
void printComputerChoice(enGame choice)
{
    switch (choice)
    {
    case enGame::Paper:
        cout << "\t\tComputer Choice is => Paper" << endl;
        break;
    case enGame::Rock:
        cout << "\t\tComputer Choice is => Rock" << endl;
        break;

    default:
        cout << "\t\tcomputer Choice is => Scissors" << endl;
        break;
    }
}
// round winner
enWinner roundWinner(short playerChoice, short computerChoice)
{

    if (playerChoice == enGame::Paper)

        if (computerChoice == enGame::Rock)
            return enWinner::User;
        else if (computerChoice == enGame::Scissors)
            return enWinner::Computer;
        else
            return enWinner::Equal;

    else if (playerChoice == enGame::Rock)

        if (computerChoice == enGame::Scissors)
            return enWinner::User;
        else if (computerChoice == enGame::Paper)
            return enWinner::Computer;
        else
            return enWinner::Equal;

    else if (playerChoice == enGame::Scissors)

        if (computerChoice == enGame::Paper)
            return enWinner::User;
        else if (computerChoice == enGame::Rock)
            return enWinner::Computer;
        else
            return enWinner::Equal;

    return enWinner::NoChoice;
}
void printRoundWinner(enWinner roundWinner)
{
    if (roundWinner == enWinner::User)
    {
        cout << "\n\t\tRond Winner is PLAYER\n";
        system("Color 2A");
    }
    else if (roundWinner == enWinner::Computer)
    {
        cout << "\n\t\tRound Winner is COMPUTER\n";
        system("Color 4A");
    }
    else if (roundWinner == enWinner::Equal)
    {
        cout << "\n\t\tNO Winner..\n";
        system("Color 6A");
    }
    else
    {
        cout << "\n\t\ttWrong Choice\n";
    }
}
// End Seprator
void endSeperator()
{
    cout << "\n\t---------------------------------------------------------------------\n"
         << endl;
}
void resultSheetHeader()
{
    cout << "\n\t-------------------------------------------------------------------------\n";
    cout << "\t\t\t\t +++ GAME OVER +++\n";
    cout << "\t-------------------------------------------------------------------------\n";
    cout << "\t---------------------------[ GAME RESULT ]-------------------------------\n\n";
}
void printResulrSheet(short gamerounds, short playerResult, short computerResult, short drowResult, string finalWinner)
{
    cout << "\t\t\tGame Rounds: " << gamerounds << endl;
    cout << "\t\t\tPlayer Won Times: " << playerResult << endl;
    cout << "\t\t\tComputer Won Times: " << computerResult << endl;
    cout << "\t\t\tDrow Times: " << drowResult << endl;
    cout << "\t\t\tFinal Winner: " << finalWinner << endl;
}
short PlayAgain()
{
    bool playAgain;
    cout << "Do you Want To Play Again ? [1]-> yes | [0]-> No";
    cin >> playAgain;
    return playAgain;
}
// Start Game Function
void startGame()
{
    bool playAgain = true;
    while (playAgain)
    {
        short roundsNumbers = roundNumbers();
        short playerResult = 0;
        short computerResult = 0;
        short drowResult = 0;
        string finalWinner;
        short roundCounter = 1;

        do
        {

            if (roundCounter > 1)
            {
                cout << "\t\tRound [" << roundCounter << "] Begins: \n\n";
            }

            enGame PlayerChoice = playerChoice();
            enGame ComputerChoice = computerChoice();

            roundBeginSeperator(roundCounter);

            printPlayerChoice(PlayerChoice);
            printComputerChoice(ComputerChoice);
            printRoundWinner(roundWinner(PlayerChoice, ComputerChoice));

            endSeperator();
            if (roundWinner(PlayerChoice, ComputerChoice) == enWinner::User)
            {
                playerResult++;
            }
            else if (roundWinner(PlayerChoice, ComputerChoice) == enWinner::Computer)
            {
                computerResult++;
            }
            else
            {
                drowResult++;
            }

            roundCounter++;
        } while (roundCounter <= roundsNumbers);
        if (playerResult > computerResult)
        {
            cout << "\t\tCongratolations To The Player.." << endl;
            finalWinner = "Player";
        }
        else if (computerResult > playerResult)
        {
            cout << "\t\tCongratolations To The Computer.." << endl;
            finalWinner = "Computer";
        }
        else
        {
            cout << "\t\tHard Luck To Each Of You You Are Equal..\n\n";
            finalWinner = "No Winner";
        }
        resultSheetHeader();
        printResulrSheet(roundsNumbers, playerResult, computerResult, drowResult, finalWinner);
        endSeperator();
        if (!PlayAgain())
            playAgain = false;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}