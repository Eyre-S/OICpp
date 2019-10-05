#include <stdio.h>
#define W 20
#define H 20
char s[W][H];
int getValue(int i,int j)
{
if(i<0 || i>=W || j<0 || j>=H) return 0;
else return s[i][j];
}
int getAlive(int i,int j)
{
return getValue(i-1,j-1) +
getValue(i-1,j) +
getValue(i-1,j+1) +
getValue(i, j-1) +
getValue(i, j+1) +
getValue(i+1,j-1) +
getValue(i+1,j) +
getValue(i+1,j+1) ;
}
int show()
{
int i,j;
printf("\n\n\n\n");
for(i = 0;i<H;i++)
{
for(j = 0;j<W;j++)
{
printf("%c",s[j][i]==0?'.':'@');
}
printf("\n");
}
//getchar();
}
int main(void)
{
int i,j;
srand(time(0));
for(i = 0;i<W;i++)
{
for(j = 0;j<H;j++)
{
s[i][j] = rand()%2;
}
}
show();
while(1)
{
for(i = 0;i<W;i++)
{
for(j = 0;j<H;j++)
{
int v = getAlive(i,j);
if(v==3)s[i][j]=1;
else if(v!=2)s[i][j]=0;
}
}
show();
}
return 0;
}