#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int console = 2;                                                                                
char p1symbol = 'X';                                                                            
char p2symbol = 'O';                                                                            
char board[3][3];                                                                               
char p1move[1];
char p2move[1];
char row;
char column;
int counter = 1;

void menu(void)                 //main menu for console input
{

        printf("\nWelcome to Tic-Tac-Whoa! \nPlease type in an option.");
        printf("\n1. Start a new game");
        printf("\n2. Exit the program");
        printf("\n\nPlease type here: ");
        scanf("%d", &console);
}

void enter_p2symbol()           //function for player 2 to input what symbol they want
{
        printf("\nPlayer 2's symbol: ");
        scanf(" %c", &p2symbol);
}

void boardreset()               //function to reset the board in the case the players want to rematch
{
        for(int i = 0; i < 3; i++)      //for loops are to go through both row and column of the board
        {
                for(int j = 0; j < 3; j++)
                {
                        board[i][j] = ' ';
                }
        }
}

void printboard()               //function to print the tic tac toe board
{
        printf("\n\n3   %c| %c |%c", board[2][0], board[2][1], board[2][2]);
        printf("\n  ---|---|---");
        printf("\n2   %c| %c |%c", board[1][0], board[1][1], board[1][2]);
        printf("\n  ---|---|---");
        printf("\n1   %c| %c |%c\n", board[0][0], board[0][1], board[0][2]);
        printf("   A   B   C\n\n");
}

void wincheck()         //function to check win conditions
{

        for(int i = 0; i < 3; i++)              //each for loop represents the win condition of either 3 in a row/column/diagonal
        {
                if(board[0][i] == board[1][i] &&
                board[0][i] == board[2][i] &&
                board[0][i] != ' ')
                {

                        if(p1symbol == board[0][i])             //statement to check column win conditions
                        {
                                printf("\n\nPlayer 1 is the winner!!\n\n");
                                exit(0);
                        }
                        else if(p2symbol == board[0][i])
                        {
                                printf("\n\nPlayer 2 is the winner!!\n\n");
                                exit(0);
                        }


                }
        }

        for(int i = 0; i < 3; i++)
        {
                if(board[i][0] == board[i][1] &&        //statement to check row win conditions
                board[i][0] == board[i][2] &&
                board[i][0] != ' ')
                {
                        if(p1symbol == board[i][0])
                        {
                                printf("\n\nPlayer 1 is the winner!!\n\n");
                                exit(0);
                        }
                        else if(p2symbol == board[i][0])
                        {
                                printf("\n\nPlayer 2 is the winner!!\n\n");
                                exit(0);
                        }

                }
        }

        if(board[0][0] == board[1][1] &&
           board[0][0] == board[2][2] &&
           board[0][0] != ' ')
        {
                if(p1symbol == board[0][0])             //statement to check diagonal win condition
                {
                        printf("\n\nPlayer 1 is the winner!!\n\n");
                        exit(0);
                }
                else if(p2symbol == board[0][0])
                {
                        printf("\n\nPlayer 2 is the winner!!\n\n");
                        exit(0);
                }
        }

        if(board[2][0] == board[1][1] &&
           board[2][0] == board[0][2] &&
           board[2][0] != ' ')
        {
                if(p1symbol == board[2][0])             //statement to check diagonal win condition
                {
                        printf("\n\nPlayer 1 is the winner!!\n\n");
                        exit(0);
                }
                else if(p2symbol == board[2][0])
                {
                        printf("\n\nPlayer 2 is the winner!!\n\n");
                        exit(0);
                }

        }

}


void p2_move()                  //function for player 2's move
{
        printf("\nPlayer 2's Move: ");
        scanf(" %c%c", &column, &row);
                if(board[row - '1'][column - 'A'] == ' ')       //if statement to check what the player 2 has inputted
                {
                        board[row - '1'][column - 'A'] = p2symbol;
                        printboard();
                        counter++;
                        wincheck();
                }
                else if(board[row - '1'][column - 'A'] != ' ')  //if statement to check invalid input
                {
                        printf("\n\nInvalid input! Please try again.\n\n");
                        p2_move();
                }
}

void gamelaunch()               //function to start the match with player 1's input
{
        while(counter != 10)
        {
                printf("\nPlayer 1's Move: ");
                scanf(" %c%c", &column, &row);

                        if(board[row - '1'][column - 'A'] == ' ')               //statement to check player 1's input
                        {
                                board[row - '1'][column - 'A'] = p1symbol;
                                printboard();
                                counter++;
                                wincheck();
                                        if(counter >= 9)
                                        {
                                                break;
                                        }
                                p2_move();
                        }

                        else if(board[row - '1'][column - 'A'] != ' ')
                        {
                                printf("\n\nInvalid move! Please try again. \n\n");
                        }

                        else if(column == 1)
                        {
                                printf("\n\nexit\n");
                                exit(0);
                        }
        }

printf("\n\nA draw has occurred, exitting program\n");
exit(0);
}

void check()            //function used for players to input what symbols they want
{
                        if ((p1symbol >= 'a' && p1symbol <= 'z') ||
                            (p1symbol >= 'A' && p1symbol <= 'Z') ||
                            (p1symbol >= '0' && p1symbol <= '9') ||
                            (p1symbol >= 33 && p1symbol <= 64) ||  //if statement allowed the players to have whatever character they want on the ascii table
                            (p1symbol >= 91 && p1symbol <= 96) ||
                            (p1symbol >= 123 && p1symbol <= 126))
                        {
                                        enter_p2symbol();

                                        if (p1symbol == p2symbol)
                                        {
                                                printf("\nThat's player 1's symbol! Please enter another symbol");
                                                check();
                                        }

                                        else if (p1symbol != p2symbol)
                                        {
                                                printf("\n\nGame is now starting!");
                                                printf("\n\nPlayer 1's symbol: %c", p1symbol);
                                                printf("\nPlayer 2's symbol: %c\n\n\n\n", p2symbol);
                                                printboard();
                                        }
                        }
}

void symbol()           //player 1's symbol input
{
        printf("\nPlayer 1's symbol: ");

                scanf(" %c", &p1symbol);
}

int main()              //main function
{

        menu();

        if (console == 1)
        {
                boardreset();
                symbol();
                check();
                gamelaunch();
                wincheck();
                //      if(winner == 1)
                //      {
                //              printf("\ntesting final.\n");
                //      }

        }

        else if (console == 2)
        {
                printf("\nExiting program\n");
                return 0;
        }

        return 0;

}
