/***************************************************************************
 *   Copyright (C) 2021 by Matti Syvapuro                                  *
 *   e2000933(at)edu.vamk.fi                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

 /*********************************************************************

  1.  NAME
        String manipulation program


  2.  DESCRIPTION
        A program to manipulate text string.


  3.  VERSIONS
        Original:
            17.3.2021 / MS

        Version history:
            25.3.2021 / MS
                Code formatting done.


 **********************************************************************/

 /*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

 /*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
 /* Control flags */
#define DEBUG 

/* Global constants */
#define MIN 10

/* Global variables */

/* Global structures */


/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void display_menu(void);
void ask_command(char commandString[]);
void read_string(char manipulateString[]);
void print_string(char manipulateString[]);
int count_vowels(char manipulateString[]);
int count_consonants(char manipulateString[]);
void to_lower(char manipulateString[]);
void to_upper(char manipulateString[]);
void read_file(char manipulateString[]);
void write_file(char manipulateString[]);

/*********************************************************************
*    MAIN PROGRAM                                                    *
**********************************************************************/

int main(void)
{
    // Initialize manipulated string and command variables
    char manipulateString[] = { "Final work in grading" };
    char commandString[MIN];

    // Display options for user to start.
    display_menu();

    // Start command loop until user exit 'X' is given
    do
    {
        ask_command(commandString);

        switch (commandString[0])
        {
            case 'A':
                count_vowels(manipulateString);
                break;

            case 'B':
                count_consonants(manipulateString);
                break;

            case 'C':
                to_upper(manipulateString);
                break;

            case 'D':
                to_lower(manipulateString);
                break;

            case 'E':
                print_string(manipulateString);
                break;

            case 'F':
                read_string(manipulateString);
                break;

            case 'G':
                read_file(manipulateString);
                break;

           case 'H':
                write_file(manipulateString);
                break;

            case 'M':
                display_menu();
                break;
        }
    } while (commandString[0] != 'X');

} /* end of main */


/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

void display_menu(void)
{
    printf("A) Count the number of vowels in the string\n");
    printf("B) Count the number of consonants in the string\n");
    printf("C) Convert the string to uppercase\n");
    printf("D) Convert the string to lowercase\n");
    printf("E) Display the current string\n");
    printf("F) Enter another string\n");
    printf("G) Read string from file\n");
    printf("H) Write string to file\n\n");
    printf("M) Display this menu\n");
    printf("X) Exit the program\n\n");

} /* End of display_menu*/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: void display_menu(void)
DESCRIPTION: Display menu options
    INPUT:
    OUTPUT: Print menu
Used global variables:
REMARKS when using this function: Display menu-options for user.
*********************************************************************/

void ask_command(char commandString[])
{
    printf("Enter command: ");
    do
    {
        fgets(commandString, MIN, stdin);

        // Change input from lower case to upper case if necessary.
        if (commandString[0] >= 'a' && commandString[0] <= 'z')
        {
            commandString[0] = commandString[0] - 32;
        }

        // Print an error message in entered command is invalid.
        if (commandString[0] != 'A' && commandString[0] != 'B' && commandString[0] != 'C' && commandString[0] != 'D' && 
            commandString[0] != 'E' && commandString[0] != 'F' && commandString[0] != 'G' && commandString[0] != 'H' && 
            commandString[0] != 'M' && commandString[0] != 'X' )
        {
            printf("Not a valid command, please give a valid command\n");
        }
    }
    // Loop until input is in valid range
    while ( commandString[0] != 'A' && commandString[0] != 'B' && commandString[0] != 'C' && commandString[0] != 'D' &&
            commandString[0] != 'E' && commandString[0] != 'F' && commandString[0] != 'G' && commandString[0] != 'H' && 
            commandString[0] != 'M' && commandString[0] != 'X' );

    fflush(stdin);      // Clear keyboard buffer, although irrelevant with current structure.

} /* End of ask_command */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: char ask_command(void);
DESCRIPTION: Function to read command from user
    INPUT: 
    OUTPUT: commandString
Used global variables:
REMARKS when using this function: Ask command input, and check validity
         of the entered command. Clears keyboard buffer.
*********************************************************************/

void read_string(char manipulateString[])
{
    printf("Give string:\n");               // Print instruction for user
    fgets(manipulateString, 100, stdin);    // Read user input to string 

} /* End of read_string */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: void read_string(char manipulateString[]);
DESCRIPTION: Function will print guide text (Give string:) and read string
    INPUT: manipulateString
    OUTPUT: manipulateString 
Used global variables: 
REMARKS when using this function: Ask user for a new string to manipulate
**********************************************************************/

void print_string(char manipulateString[])
{
    printf("%s\n", manipulateString);

} /* End of print_string */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: void print_string(char manipulateString[]);
DESCRIPTION: Function will print current string
    INPUT: manipulateString
    OUTPUT: Print manipulateString
Used global variables:
REMARKS when using this function: prints the current string for user
*********************************************************************/

int count_vowels(char manipulateString[])
{
    int i, countVowels = 0;

    // Count vowels using case-sensitive for-loop
    for ( i = 0 ; manipulateString[i] != '\0' ; i++ )
    {
        if (manipulateString[i] == 'a' || manipulateString[i] == 'A' || manipulateString[i] == 'e' || 
            manipulateString[i] == 'E' || manipulateString[i] == 'i' || manipulateString[i] == 'I' || 
            manipulateString[i] == 'o' || manipulateString[i] == 'O' || manipulateString[i] == 'u' || 
            manipulateString[i] == 'U' || manipulateString[i] == 'y' || manipulateString[i] == 'Y')
        {
            countVowels++;
        }
    }
    printf("Vowels in String: %d.\n", countVowels);

} /* End of count_vowels */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: int count_vowels(char manipulateString[]);
DESCRIPTION: function that counts and returns the number of vowels in the string.
    Input: manipulateString
    Output: number of vowels in manipulateString
Used global variables: 
REMARKS when using this function: counts tbe number of vowels in string
*********************************************************************/

int count_consonants(char manipulateString[])
{
    // Count consonants by excluding vowels
    int i, countConsonants = 0;
    for (i = 0; manipulateString[i] != '\0'; i++)
    {
        if (manipulateString[i] >= 'a' && manipulateString[i] <= 'z' || 
            manipulateString[i] >= 'A' && manipulateString[i] <= 'Z' )
        {
            if (manipulateString[i] != 'a' && manipulateString[i] != 'A' && manipulateString[i] != 'e' && 
                manipulateString[i] != 'E' && manipulateString[i] != 'i' && manipulateString[i] != 'I' && 
                manipulateString[i] != 'o' && manipulateString[i] != 'O' && manipulateString[i] != 'u' && 
                manipulateString[i] != 'U' && manipulateString[i] != 'y' && manipulateString[i] != 'Y' )        
            {
                countConsonants++;
            }
        }
    }
    printf("Consonants in string: %d.\n", countConsonants);

} /* End of count_consonants */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: int count_consonants(char manipulateString[]);
DESCRIPTION: a function that counts and returns the number of consonants in the string.
    Input: manipulateString
    Output: number of consonants in manipulateString
Used global variables: 
REMARKS when using this function: counts the number of consonants in manipulateString
*********************************************************************/

void to_lower(char manipulateString[])
{
    int i = 0;

    // Change to lower case if upper case is found.
    while (manipulateString[i] != '\0')
    {
        if (manipulateString[i] >= 'A' && manipulateString[i] <= 'Z')
        {
            manipulateString[i] = manipulateString[i] + 32;
        }
        i++;
    }
    
} /* End of to_lower */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: void to_lower(char manipulateString[]);
DESCRIPTION: a function that converts the string to all lowercase.
    Input: manipulateString
    Output: manipulateString
Used global variables: 
REMARKS when using this function: Changes manipulateString to lower case
*********************************************************************/

void to_upper(char manipulateString[])
{
    int i = 0;

    // Change to upper case if lower case is found.
    while (manipulateString[i] != '\0') 
    {
        if (manipulateString[i] >= 'a' && manipulateString[i] <= 'z') 
        {
            manipulateString[i] = manipulateString[i] - 32;
        }
        i++;
    }

} /* End of to_upper */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: void to_upper(char manipulateString[]);
DESCRIPTION: a function that converts the string to all uppercase.
    Input: manipulateString
    Output: manipulateString
Used global variables: 
REMARKS when using this function: Changes text in manipulateString TO UPPER CASE
*********************************************************************/

void read_file(char manipulateString[])
{
    FILE* filePointer;

    // Open file "aGradeWork.txt" in read mode
    filePointer = fopen("aGradeWork.txt", "r");

    // Check if file opens
    if (filePointer == NULL)
    {
        printf("Error opening file 'aGradeWork.txt'\n");
    }
    else
    {
        printf("The file is open\n");

        // Read the string from file with fgets
        while (fgets(manipulateString, 100, filePointer) != NULL);
        {
            // Print the data to be read
            printf("%s", manipulateString);
            printf("\n");
        }
        // Close the file and announce it
        fclose(filePointer);
        printf("The file is closed\n");
    }

} /* End of read_file */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: void read_file(char manipulateString[]);
DESCRIPTION: Read the string from file. Filename may be hard coded in function
    Input: manipulateString
    Output: manipulateString
Used global variables:
REMARKS when using this function: filename: aGradeWork.txt
*********************************************************************/

void write_file(char manipulateString[])
{
    FILE* filePointer;

    // Open the file "aGradeWork.txt" in write mode
    filePointer = fopen("aGradeWork.txt", "w");

    // Print the manipulated string s to opened file
    fprintf(filePointer, "%s", manipulateString);

    // Print what is written to file
    printf("%s\n", manipulateString);

    // Close the file and announce it
    fclose(filePointer);
    printf("The file is closed\n");

} /* End of write_file */

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------
NAME: void write_file(char manipulateString[]);
DESCRIPTION: Saves string to file
    Input: manipulateString
    Output: manipulateString to a file "aGradeWork.txt"
Used global variables: 
REMARKS when using this function: filename: "aGradeWork.txt"
*********************************************************************/