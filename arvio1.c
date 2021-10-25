/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/***************************************************************************
 *   Copyright (C) $Year$ by $Author$   *
 *   $Email$   *
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
     StringManipulationProgram.c

 2.  DESCRIPTION
     Program manipulates a string of characters stored in main().
     The Program display a menu of different actions and
     user may select what action the program may perform to this string.

 3.  VERSIONS
       Original:
         26.3.2020 / Marko Sulkunen

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
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
void display_menu (void);
char ask_command (void);
void read_string (char s[]);
void print_string (char s[]);
int count_vowels (char s[]);
int count_consonants (char s[]);
void to_lowercase (char s[]);
void to_uppercase (char s[]);
void read_file (char s[]);
void write_file (char s[]);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void)
{
  char given_character;
  char string[100] = "Hello World";

  display_menu ();
  
  while (given_character != 'X')
    {
      int consonants;
      int vowels;
      given_character = ask_command ();
      
      switch (given_character)
        {
          case 'A':
            vowels = count_vowels (string);
            printf ("Number of vowels in the string is: %d\n", vowels);
            break;
          case 'B':
            consonants = count_consonants (string);
            printf ("Number of consonants in the string is: %d\n", consonants);
            break;
          case 'C':
            to_uppercase (string);
            break;	
          case 'D':    
            to_lowercase (string);
            break;
          case 'E':
            print_string (string);
            break;
          case 'F':
            printf ("Give string: ");
            read_string (string);
            break;
          case 'G':
            read_file (string);
            break;
          case 'H':
            write_file (string);
            break;
          case 'M':
            display_menu ();
            break;
          case 'X':
            exit (0);      
            break;
        }
    }

  return 0;
}

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

void 
display_menu (void)
{
  printf ("A) Count the number of vowels in the string\n");
  printf ("B) Count the number of consonants in the string\n");
  printf ("C) Convert the string to uppercase\n");
  printf ("D) Convert the string to lowercase\n");
  printf ("E) Display the current string\n");
  printf ("F) Enter another string\n");
  printf ("G) Read string from file\n");
  printf ("H) Write string to file\n");
  printf ("\nM) Display this menu\n");
  printf ("X) Exit the program\n");
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: display_menu
 DESCRIPTION: Prints menu of commands
        Input:  void
        Output: void
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

char 
ask_command (void)
{
  char given_character;
  
  printf ("\nEnter command: ");
  scanf (" %c", &given_character);

  return given_character;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: ask_command
 DESCRIPTION: Asks command from user
        Input:  void
        Output: character
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

int 
count_vowels (char string[])
{
  int character = 0;
  int count = 0;

  while (string[character] != '\0') 
    {
      if (string[character] == 'a' || string[character] == 'A' || string[character] == 'e' ||
          string[character] == 'E' || string[character] == 'i' || string[character] == 'I' ||
          string[character] == 'o' || string[character] == 'O' || string[character] == 'u' || 
          string[character] == 'U' || string[character] == 'y' || string[character] == 'Y')
        {
          count++;
        }
          character++;
    }
   return count;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_vowels
 DESCRIPTION: Counts amount of wovels in a string
        Input:  char string[]
        Output: Integer
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

int 
count_consonants (char string[])  
{
  int character = 0;
  int count = 0;

  while (string[character] != '\0') 
    {
      if (string[character] == 'a' || string[character] == 'A' || string[character] == 'e' || 
          string[character] == 'E' || string[character] == 'i' || string[character] == 'I' || 
          string[character] == 'o' || string[character] == 'O' || string[character] == 'u' ||
          string[character] == 'U' || string[character] == 'y' || string[character] == 'Y' || 
          string[character] == ' ')
        {   
          character++;
        }
      else
        {
          count++;
          character++;
        }
    }

   return count;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_consonants
 DESCRIPTION: Counts amount of consonants in a string
        Input:  char string[]
        Output: Integer
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void 
to_uppercase (char string[])  
{
  int character;

  for (character = 0; string[character] != '\0'; character++)
    {
      if (string[character] >= 'a' && string[character] <= 'z')
        {
          /* a - 32 = A */
          string[character] = string[character] - 32;
        }
    }
  printf ("%s\n", string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: to_uppercase
 DESCRIPTION: Converts string to uppercase letters
        Input:  char string[]
        Output: void
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void 
to_lowercase (char string[])  
{
  int character;

  for (character = 0; string[character] != '\0'; character++)
    {
      if (string[character] >= 'A' && string[character] <= 'Z')
        {
          /* A + 32 = a */
          string[character] = string[character] + 32;
        }
    }
  printf ("%s\n", string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: to_lowercase
 DESCRIPTION: Converts string to lowercase letters 
        Input:  char string[]
        Output: void
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void 
print_string (char string[])  
{
  printf ("%s\n", string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_string
 DESCRIPTION: Prints current string
        Input:  char string[]
        Output: void
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void 
read_string (char string[])  
{
  scanf (" %s", string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: read_string
 DESCRIPTION: Reads string from user
        Input:  char string[]   
        Output: void
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void 
read_file (char string[])  
{
  FILE *filePointer ; 
      
  char dataToBeRead[50]; 

  filePointer = fopen ("File.c", "r"); 
      
  if (filePointer == NULL) 
    { 
      printf ("File.c file failed to open.\n"); 
    } 
  else
    {           
      printf ("The file is now opened.\n");           
      while (fgets (dataToBeRead, 50, filePointer) != NULL) 
        {          
          printf ("%s" , dataToBeRead); 
        } 
          
      fclose (filePointer);           
      printf ("The file is now closed.\n"); 
    } 
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: read_file
 DESCRIPTION: Reads file named File.c
        Input: char string[]
        Output: void
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void 
write_file (char string[])  
{
  FILE *filePointer; 
      
  char dataToBeWritten[50];  
  scanf ("%s", dataToBeWritten); 

  filePointer = fopen ("File.c", "w"); 

  if (filePointer == NULL) 
    { 
      printf ("File.c file failed to open.\n"); 
    }
  else
    {          
      printf ("The file is now opened.\n");           
      if (strlen (dataToBeWritten) > 0) 
        {              
          fputs (dataToBeWritten, filePointer);    
          fputs ("\n", filePointer); 
        } 

      fclose (filePointer); 
      printf ("Data successfully written in file File.c\n");
      printf ("The file is now closed.\n"); 
    }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: write_file
 DESCRIPTION: Asks string from user, creates file and writes string in the file
        Input:  char string[]
        Output: void
  Used global variables:
 REMARKS when using this function:
*********************************************************************/