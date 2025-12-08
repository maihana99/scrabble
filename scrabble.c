#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// predefined points given per character 'A-Z'
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// prototype for function to computer score
int compute_score(string word);

int main(void)
{
    // string input from 2 users
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    // setting score 1 as 0 to remove garbage variable
    int score1 = 0;

    // loop that will go through each character of player 1's input
    for (int i = 0, len = strlen(player1); i < len; i++)
    {
        // checks if character is in the alphabet
        if (isalpha(player1[i]))
        {
            // converts character to uppercase
            char c = toupper(player1[i]);
            // character's position in alphabet is found in the POINTS array and is then added to the current score
            score1 += POINTS[c - 65];
        }
    }

    // setting score 2 as 0 to remove garbage variable
    int score2 = 0;

    // loop that will go through each character of player 2's input
    for (int i = 0, len = strlen(player2); i < len; i++)
    {
        // checks if character is in the alphabet
        if (isalpha(player2[i]))
        {
            char c = toupper(player2[i]);
            // character's position in alphabet is found in the POINTS array and is then added to the current score
            score2 += POINTS[c - 65];
        }
    }

    // checking if score 1 is larger than score 2
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    // checking if score 2 is larger than score 1
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    // will be a tie if the above two conditions are false
    else
    {
        printf("Tie!\n");
    }
}
