#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
int a[3][3];

void PrintField()
{
   int i, j;
   system("cls");
   printf("_______\n");
   for(i=0;i<3;i++)
   {
      for(j=0;j<3;j++)
      {
         printf("|");
         if (a[i][j] == 1) printf("X");
         else if (a[i][j] == -1) printf("0");
         else printf(" ");
      }
      printf("|\n_______\n");
   }
}

int TestWin(int x,int y)
{
   if((a[y][0] == a[y][1]) && (a[y][1] == a[y][2]) && (a[y][0] != 0)) return 1;
   if((a[0][x] == a[1][x]) && (a[1][x] == a[2][x]) && (a[0][x] != 0)) return 1;
   if(((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) && (a[0][0] != 0) || ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && a[0][2] != 0))) return 1;
   return 0;
}

int main(int argc, char *argv[])
{


setlocale(LC_ALL, "Rus");
   int i, j,  c;
   bool bol=true;
   for(c =0;c<9;c++)
   {
       if(bol==true)
       {
           printf("(О)Ходит первый игрок: ");
           bol=false;
       }
      else if(bol==false){
        printf("(Х)Ходит второй игрок: ");
           bol=true;
      }
      scanf("%d %d", &i, &j);
      if (a[i-1][j-1] != 0) {printf("ХОД ЗАНЯТ,Сходите заного\n");bol=!bol; continue;}
      if(c % 2 == 0) a[i-1][j-1] = -1;
      else a[i-1][j-1] = 1;
      PrintField();
      if (TestWin(j-1, i-1))
      {
            if(bol==false) printf("ВЫЙГРАЛ ПЕРВЫЙ ИГРОК!!!");
            else if(bol==true) printf("ВЫЙГРАЛ ВТОРОЙ ИГРОК!!!");
         exit(0);
      }
   }
   return 0;
}
