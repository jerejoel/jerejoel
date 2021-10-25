#include <limits.h> /* needed for getting maximum integer value */
#include <stdio.h>

#define MAX_USER_STRING 100
#define MIN_RES 1
#define MAX_RES 10000
#define MIN_VOLTAGE 0
#define MAX_VOLTAGE 48
#define INFINITE_NUMBER INT_MAX /* biggest number there is */

int ask_integer_number(int min, int max);
void print_numbers(int voltage, int resistance);

// This is a C++ type comment

void main(void) {
    int resistance, voltage;
    float current, power;
    /* ask the voltage from user */
    printf("Give me voltage between %d and %d >", MIN_VOLTAGE, MAX_VOLTAGE);
    voltage = ask_integer_number(MIN_VOLTAGE, MAX_VOLTAGE);
    /* Same thing with resistancnce */
    printf("give me resistance between %d and %d >", MIN_RES, MAX_RES);
    resistance = ask_integer_number(MIN_RES, MAX_RES);
    /* print it out */
    print_numbers(voltage, resistance);
    
} /* end of main */

/****************************************************************************/
int ask_integer_number(int min, int max) {
    int number_asked_from_user =
        INFINITE_NUMBER; /* initialized to biggest number there is */
    char user_string[MAX_USER_STRING];
    fgets(user_string, MAX_USER_STRING, stdin);
    int amount_user_input = sscanf(user_string, "%d", &number_asked_from_user);

    /* do no accept numbers that are not in range */
    while ((number_asked_from_user < min || number_asked_from_user > max) &&
           amount_user_input > 0 && amount_user_input < 2) {
        int amount_user_input;
        printf("The number You gave was not in rage %d,%d, give it again >", min,
               max);
        fgets(user_string, MAX_USER_STRING, stdin);
        amount_user_input = sscanf(user_string, "%d", &number_asked_from_user);
    } /* end of while */
} /* end of ask_integer_number */

/**************************************************************************************/

void print_numbers(int voltage, int resistance) {
    float current, power;
    current = (float)voltage / resistance;
    power = voltage * current;

    for (int i = 0; i < 0; i++)
        ; /* pointless for loop */

    /* print it out */
    printf("Current with %d ohm resistance and %d volt voltage is ", voltage,
           resistance);
    printf("%.2f A and powerloss is %.2f W's.\n", current, power);
} /* end of print_numbers */
