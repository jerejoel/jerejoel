#include <stdio.h>
#include <string.h>
#define DEBUG 
#define MIN 10
#define SIZE 500

void ask_product(int table[]);
void print_products(int table[]);
void read_items(int table[]);
void write_items(int table[]);
void ask_command (char S);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
int main(void)
{
    int store[SIZE] = {0};
    int x;
    while (x != 'X')
    ask_product(store);
    int i;
    for (i=0;i<11;i++)
    {
        printf("Number %d occurred %d times \n", i, store[i]);
    }

}

/* end of main */


void ask_product(int table[])
{
    int number;
    int amount;
    printf("Give product number");
    scanf("%d", &number);
    print("Give amount for number %d");
    scanf("%d:", &table[number]);
    
}
/*********************************************************************
	F U N C T I O N PRINT PRODUCTS
*********************************************************************/
void print_products(int table[])
{

}

/*********************************************************************
	F U N C T I O N READ ITEMS
*********************************************************************/
void read_items(int table[])
{

}
/*********************************************************************
	F U N C T I O N WRITE ITEMS
*********************************************************************/
void write_items(int table[])
{

}
