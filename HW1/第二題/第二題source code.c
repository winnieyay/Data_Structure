#include<stdio.h>
#include <math.h>

#define TowerA 1
#define TowerB 2
#define TowerC 3

void how_to_change(int, int, int, int);

int main(){
        int n,k;
        printf("Disks(>=0): ");
        scanf("%d", &n);
        how_to_change(n,TowerA,TowerB,TowerC);
        k=pow(2,n)-1;
        printf("Total steps:%d\n",k);
}

void how_to_change(int n, int from, int temporary, int to){
  if (n == 1 )
    printf("Move disk %d from tower %d to tower %d.\n", n, from, to);
   else {

      how_to_change(n-1,from,temporary,to);
        printf("Move disk %d from tower %d to tower %d.\n", n, from, to);

      how_to_change(n-1,temporary,to,from);
  }
}

