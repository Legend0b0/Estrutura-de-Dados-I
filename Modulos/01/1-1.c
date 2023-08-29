#include<stdio.h>
#include<math.h>

char cabecalho[] = "%-10s%-12s%-11s%-11s%-11s%-11s%-11s%-11s\n";
char resp[] = "%-10s%-12.2E%-11.2E%-11.2E%-11.2E%-10.2E%-11.2E%-11.2E\n";
double numero[7];

void primeira_linha()
    {
     char inicio[] = "";
     char seg[] = "1 segundo";
     char min[] = "1 minuto";
     char hora[] = "1 hora";
     char dia[] = "1 dia";
     char mes[] = "1 mês";
     char ano[] = "1 ano";
     char seculo[] = "1 século";
     
     printf(cabecalho, inicio, seg, min, hora, dia, mes, ano, seculo);
    }

    void log_2()
    {
     printf(resp, "lg(n)", pow(2,numero[0]), pow(2,numero[1]), pow(2,numero[2]), pow(2,numero[3]),pow(2,numero[4]), pow(2,numero[5]), pow(2,numero[6]));
    }
    void raiz()
    {
     printf(resp, "sqrt(n)", pow(numero[0],2), pow(numero[1],2), pow(numero[2],2), pow(numero[3],2), pow(numero[4],2), pow(numero[5],2), pow(numero[6],2));
    }
    void n()
    {
     printf(resp, "n", numero[0], numero[1], numero[2], numero[3], numero[4], numero[5], numero[6]);   
    }
    void n_log()
    {
     printf(resp, "n*lg(n)",  pow(2,numero[0])/numero[0], pow(2,numero[1])/numero[1], pow(2,numero[2])/numero[2], pow(2,numero[3])/numero[3],pow(2,numero[4])/numero[4], pow(2,numero[5])/numero[5], pow(2,numero[6])/numero[6]);
    }
    void quadrado()
    {
     printf(resp, "pow(n,2)", sqrt(numero[0]), sqrt(numero[1]), sqrt(numero[2]), sqrt(numero[3]), sqrt(numero[4]), sqrt(numero[5]), sqrt(numero[6]));
    }
    void cubo()
    {
     printf(resp, "pow(n,3)", cbrt(numero[0]), cbrt(numero[1]), cbrt(numero[2]), cbrt(numero[3]), cbrt(numero[4]), cbrt(numero[5]), cbrt(numero[6]));
    }
    void dn()
    {
     printf(resp, "pow(2,n)", sqrt(numero[0]), sqrt(numero[1]), sqrt(numero[2]), sqrt(numero[3]), sqrt(numero[4]), sqrt(numero[5]), sqrt(numero[6]));
    }
    double fatorial(double a)
    {
     if((a <= 1))
        {
        return 1;
        }
        else
        {

        return a*fatorial(a-1);
        } 
    }
    void pfatorial()
    {
     double f=1;
     for(int i=0;i<7;i++)
     {
        while(fatorial(f) < numero[i])
        {
         f += 1;
         
       }
        f -= 1;
     }
     
     printf("%E", f);   
     
    }

int main()
{
 numero[0] = 1000000;
 numero[1] = numero[0] * 60;
 numero[2] = numero[1] * 60;
 numero[3] = numero[2] * 24;
 numero[4] = numero[3] * (365/12);
 numero[5] = numero[4] * 12;
 numero[6] = numero[5] * 100;

 primeira_linha();
 log_2();
 raiz();
 n();
 n_log();
 quadrado();
 cubo();
 dn();
 pfatorial();

return 0;
}
