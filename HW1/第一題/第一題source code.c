#include <stdio.h>
double recurlast(int, int);
double recurfirst(int n);

int main()
{
   int n,k;

   printf("n:(>=0): ");
   scanf("%d", &n);
   while (n < 0)
   {
     printf("error!\n");
     printf("n:(>=0): ");
     scanf("%d", &n);
   }

   printf("k:(<=n): ");
   scanf("%d", &k);
   while (k>n)
   {
     printf("error!\n");
     printf("k:(>=0): ");
     scanf("%d", &k);
   }

  printf("The answer is %f.\n",recurlast(n,k));

}



double recurfirst(int n)
{
  if ((n==0) || (n==1))  return 1;
  return n*recurfirst(n-1);
}

double recurlast(int n, int k)
{
  return recurfirst(n)/(recurfirst(k)*recurfirst(n-k));
}


