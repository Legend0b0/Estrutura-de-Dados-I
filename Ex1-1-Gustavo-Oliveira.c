#include <stdio.h>
#include <math.h>

char print1[] = "%-10s%-12s%-12s%-12s%-12s%-13s%-12s%-12s\n\n";
char print2[] = "%-10s%-12.2E%-12.2E%-12.2E%-12.2E%-12.2E%-12.2E%-12.2E\n";
char print3[] = "%-10s%-12.2LE%-12.2LE%-12.2LE%-12.2LE%-12.2LE%-12.2LE%-12.2LE\n";

double n[7];
long double ln[7];

void titulos()
  {
  char start[] = "";
  char seg[] = "1 segundo";
  char min[] = "1 minuto";
  char hr[] = "1 hora";
  char dia[] = "1 dia";
  char mes[] = "1 mês";
  char ano[] = "1 ano";
  char sec[] = "1 século";

  printf(print1, start, seg, min, hr, dia, mes, ano, sec);
  }

void flgn() // INF
  {
  printf(print3, "lg(n)", powl(2,ln[0]), powl(2,ln[1]), powl(2,ln[2]), powl(2,ln[3]), powl(2,ln[4]), powl(2,ln[5]), powl(2,ln[6]));
  }

void fsqrtn()
  {
  printf(print2, "sqrt(n)", pow(n[0],2), pow(n[1],2), pow(n[2],2), pow(n[3],2), pow(n[4],2), pow(n[5],2), pow(n[6],2));
  }

void fn()
  {
  printf(print2, "n", n[0], n[1], n[2], n[3], n[4], n[5], n[6]);
  }

void fnlgn() // INF
  {
  printf(print3, "n*lg(n)", powl(2.0/ln[0],ln[0]), powl(2.0/ln[1],ln[1]), powl(2.0/ln[2],ln[2]), powl(2.0/ln[3],ln[3]), powl(2.0/ln[4],ln[4]), powl(2.0/ln[5],ln[5]), powl(2.0/ln[6],ln[6]));
  }

void fpown2()
  {
  printf(print2, "pow(n,2)", sqrt(n[0]), sqrt(n[1]), sqrt(n[2]), sqrt(n[3]), sqrt(n[4]), sqrt(n[5]), sqrt(n[6]));
  }

void fpown3() 
  {
  printf(print2, "pow(n,3)", cbrt(n[0]), cbrt(n[1]), cbrt(n[2]), cbrt(n[3]), cbrt(n[4]), cbrt(n[5]), cbrt(n[6]));
  }

void fpow2n()
  {
  printf(print2, "pow(2,n)", log2(n[0]), log2(n[1]), log2(n[2]), log2(n[3]), log2(n[4]), log2(n[5]), log2(n[6]));
  }

double fatorial(double N)
  {
  if(N <= 1)
    {
    return(1.0);
    }
  else
    {
    return(N*fatorial(N-1));
    }
  }

void fnfat()
  {
  printf("%-10s", "n!");
  for(int i = 0; i < 7; i++)
    {
    double x = 1.0;
    double tmp = 1.0;
    while(x >= 0.0001)
      {
      while(n[i] > fatorial(tmp))
        {
        tmp += x;
        }
      tmp -= x;
      x /= 10.0;
      }

    printf("%-12.2E", tmp);
    }
  }

int
main()
  {
  n[0] = 1000000.0;
  n[1] = n[0] * 60;
  n[2] = n[1] * 60;
  n[3] = n[2] * 24;
  n[4] = n[3] * (365/12);
  n[5] = n[3] * 365;
  n[6] = n[5] * 100;
  
  for(int i = 0; i < 7; i++)
    {
    ln[i] = n[i];
    }

  titulos();

  flgn();   // Valores muito altos para serem computados
  fsqrtn();
  fn();
  fnlgn();  // Valores muito altos para serem computados
  fpown2();
  fpown3();
  fpow2n();
  fnfat();

  printf("\n\nINF - Valores muito altos para serem computados\n"); 
  printf("%LE - Valores muito altos para serem computados\n", powl(2.0/ln[0],ln[0]));

  return(0);
  }
