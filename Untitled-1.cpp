#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int main ()
{
  int i, r, len, dec = 0;

  string Hex = "00000001";
  
  len = Hex.length();
    
  for (i = 0; i < 8; i++)
  {
    if (Hex[i] >= '0' && Hex[i] <= '9') {
      r = Hex[i] - 48 ;
    } else if (Hex[i] == 'A'){
        r = 10;
    } else if (Hex[i] == 'B'){
        r = 11;
    } else if (Hex[i] == 'C'){
        r = 12;   
    } else if (Hex[i] == 'D'){
        r = 13;
    } else if (Hex[i] == 'E'){
        r = 14;
    } else if (Hex[i] == 'F'){
        r = 15;
    } 
    dec += r * pow(16, 7-i);
  }

  printf("decimal is %i\n", dec);

}
