// konvertoi binaryn decimaaliksi

#include <stdio.h>
#include <math.h>

// funktion prototype
int convert(long long);

// Maini
int main() {
  long long n;
  printf("Enter a binary number: ");
  scanf("%lld", &n);
  printf("%lld in binary = %d in decimal", n, convert(n));
  return 0;
}

// funktion määritys
int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
// Lopetus

  return dec;
}