/* self study of conditional compilation */
#include <stdio.h>

//#define TEST
#define DEBUG
#define DIAMETER 3.2
#define PII 3.14159
#define SALUTE "Did You know that ... "
#define CIRCLE_AREA(d) PII*d*d/4;

void subprogram(void);

int main(void)
{
    printf(SALUTE);

#ifdef DEBUG
    printf("When is this line printed out ?\n");
#endif

#ifdef USE_MACRO
    printf("The area of a circle with diameter of %f is %f\n", DIAMETER, CIRCLE_AREA(DIAMETER));
#else
    printf("The area of a circle with diameter of %f is %f\n", DIAMETER, PII * DIAMETER * DIAMETER / 4);
#endif

    printf("the calculation was made with PII having value %f\n", PII);
    subprogram();
}

void subprogram(void)
{
    printf("Global constants and macros work here too\n");
#ifdef TEST
    printf("This printf is visible if You have TEST constant defined ?\n");
#else
    printf("and this printf if will be available if You do NOT have TEST defined \n");
#endif
}


