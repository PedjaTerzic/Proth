#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t a,c,e,s,N;
unsigned long  f,i,k,n;
char cont_prog = 'n';

void P(mpz_t p , unsigned long m , mpz_t x){
mpz_t p0,p1;
unsigned long l;

mpz_set(p,x);
mpz_init_set_ui(p0,2);
mpz_init_set(p1,x);
l=2;

while(l<=m)
{
mpz_mul(p,x,p1);
mpz_sub(p,p,p0);
mpz_set(p0,p1);
mpz_set(p1,p);
l=l+1;
}
}

int main(void)
{
putchar ('\n');
printf("                     ***** PROTH *****\n\n\n");
do {
mpz_t r;

printf("Enter the coefficient :");
scanf("%lu",&k);
printf("Enter the exponent :");
scanf("%lu",&n);

mpz_init(r);
mpz_init(a);
f=0;
mpz_init(e);
mpz_init(c);
mpz_ui_pow_ui(e,2,n);
mpz_set_ui(c,k);

if(mpz_cmp(c,e)<0)
{
if((k%42==1 && (n%6==2 || n%6==4))
|| (k%42==5 && n%6==3)
|| (k%42==11 && (n%6==3 || n%6==5))
|| (k%42==13 && n%6==4)
|| (k%42==17 && n%6==5)
|| (k%42==19 && n%6==0)
|| (k%42==23 && (n%6==1 || n%6==3))
|| (k%42==25 && (n%6==0 || n%6==2))
|| (k%42==29 && (n%6==1 || n%6==5))
|| (k%42==31 && n%6==2)
|| (k%42==37 && (n%6==0 || n%6==4))
|| (k%42==41 && n%6==1))
{
mpz_set_ui(a,5);
}
else if(((k%30==1 || k%30==7) && n%4==0)
|| ((k%30==11 || k%30==23) && n%4==1)
|| ((k%30==13 || k%30==19) && n%4==2)
||((k%30==17 || k%30==29) && n%4==3))
{
mpz_set_ui(a,8);
}
else
{
f=1;
printf("Enter another coefficient and exponent\n");
}

}
else
{
f=1;
printf("Coefficient must be less than 2^exponent\n");
}

if(f==0)
{
P(r,k,a);
mpz_init_set(s,r);

mpz_init(N);
mpz_ui_pow_ui(N,2,n);
mpz_mul_ui(N,N,k);
mpz_add_ui(N,N,1);

for (i = 1; i <= n-2; i++)
{
mpz_pow_ui(s,s,2);
mpz_sub_ui(s,s,2);
mpz_mod(s,s,N);
}
mpz_clear(N);
if(mpz_cmp_ui(s,0)==0)
{
printf("%lu*2^%lu+1 is prime\n" , k,n);
}
else
{
printf("%lu*2^%lu+1 is composite\n" , k,n); 
}
mpz_clear(s);
}	
fflush(stdout);
getchar();//getchar();
//return 0;
printf("Do you want to start again? (y/n) : ");
cont_prog = getchar();

}
while (cont_prog == 'y' || cont_prog == 'Y');
return 0;
}