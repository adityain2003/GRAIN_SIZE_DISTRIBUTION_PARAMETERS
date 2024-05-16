# THIS CODE PERMITS ESTIMATION OF GRAIN SIZE DISTRIBUTION PARAMETERS SUCH AS MEAN< STANDARD DEVIATION AND SKEWNESS
#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
int n,i;

printf("enter the number of sieve on which mass of soil retained(exclude pan)");
scanf("%d",&n);
double s[n],m[n],x[n],pan,mp[n],total,y[n],slope[n],yn,d10,d30,d50,d60,xmean[n],mean,sd[n],stdev,skewness,sk[n];
printf("enter mass retained in pan");
scanf("%lf",&pan);
total=pan+total;
for(i=1;i<=n;i++)
{
    printf("enter the sieve size-%d(in mm) \n",i);
    scanf ("%lf",&s[i]);
    printf("enter the mass retained on sieve in gram \n");
    scanf ("%lf",&m[i]);
    total=total+m[i];
}
printf("total mass= %lf \n",total);
y[1]=100*(pan/total);
for(i=1;i<=n;i++)
{
mp[i]=100*((m[i])/total);
y[i+1]=y[i]+(mp[i]);
x[i]=log10(s[i]);
x[1]=log10(s[1]);
}

for(i=1;i<=n-1;i++)
{
    slope[i]=((y[i+1]-y[i])/(x[i+1]-x[i]));
}
for(i=1;i<=n-1;i++)
{
    if(y[i]<=10&&y[i+1]>=10)
    {
    d10=x[i]+((10-y[i])/slope[i]);
    d10=pow(10,d10);
    printf("d10 = %lf \n",d10);
}
if(y[i]<=30&&y[i+1]>=30)
    {
    d30=x[i]+((30-y[i])/slope[i]);
    d30=pow(10,d30);
    printf("d30 = %lf \n",d30);
}
    if(y[i]<=50&&y[i+1]>=50)
    {
    d50=x[i]+((50-y[i])/slope[i]);
    d50=pow(10,d50);
    printf("d50 = %lf \n",d50);
}
    if(y[i]<=60&&y[i+1]>=60)
    {
    d60=x[i]+((60-y[i])/slope[i]);
    d60=pow(10,d60);
    printf("d60 = %lf \n",d60);
}
}
mean=0;
for(i=1;i<=n-1;i++)
{
    xmean[i]=(.5*(s[i]+s[i+1]))*((y[i+1]-y[i])/100);
    mean=mean+xmean[i];
}
stdev=0;
for(i=1;i<=n-1;i++)
{
    sd[i]=pow((mean)-(.5*(s[i]+s[i+1])),2)*((y[i+1]-y[i])/100);
    stdev=stdev+sd[i];
}
stdev=pow(stdev,0.5);
for(i=1;i<=n-1;i++)
{
    sk[i]=pow((.5*(s[i]+s[i+1])-(mean)),3)*((y[i+1]-y[i])/100);
    skewness=skewness+sk[i];
}
skewness=((skewness)/(pow(stdev,3)));
printf("\n mean %lf",mean);
printf("\n standard deviation = %lf",stdev);
printf("\n skewness = %lf",skewness);
getch();
}

