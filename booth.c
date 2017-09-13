#include<stdio.h>
#include<stdlib.h>
int sum[4]={0},A[4]={0},P[4]={0};
void recode(int *Q)
{
	int t=0;
	for(int i=0;i<3;++i)
	{
		t=Q[i]-Q[i+1];
		//printf("\n%d",t);
		if(t==0)
			Q[i]=0;
		else if(t==1)
			Q[i]=-1;
		else if(t==-1)
			Q[i]=1;
	}
	if(Q[3]==0)
		Q[3]=0;
	else
		Q[3]=-1;
}

void add(int m[],int q[])
{
	int carry=0;
	for(int i=3;i>=0;--i)
	{	//printf("\n%d    %d\n",m[i],q[i]);
		if((q[i]+m[i]+carry)==1)
		{
			m[i]=1;
			carry=0;
		}

		else if((q[i]+m[i]+carry)==2)
		{
			m[i]=0;
			carry=1;
		}
		else if((q[i]+m[i]+carry)==3)
		{
			m[i]=1;
			carry=1;
		}
		else
			m[i]=0;
	}
}

void shift(int *A,int *P)
{
	for(int i=3;i>0;--i)
	{
		P[i]=P[i-1];
	}
	P[0]=A[3];
	for(int i=3;i>0;--i)
	{
		A[i]=A[i-1];
	}
	A[0]=A[1];
}

void twocomp(int *x)
{
	for(int i=0;i<4;++i)
	{
		if(x[i]==0)
			x[i]=1;
		else
			x[i]=0;
	}
	int carry=1;
	for(int i=3;i>=0;--i)
	{
		if((x[i]==1) && (carry==1))
		{
			x[i]=0;
			carry=1;
		}
		else if((x[i]+carry)==1)
		{
			x[i]=1;
			carry=0;
		}
		else
			x[i]=0;
	}
}


int main()
{
	char a[4],b[4];
	int M[4],Q[4],Mcomp[4]={0};
	printf("Enter 4-bit signed multiplicand,M: ");
	scanf("%s",a);
	printf("Enter 4-bit signed multiplier,Q: ");
	scanf("%s",b);
	
	for(int i=1;i<4;++i)
		M[i]=a[i]-'0';
	printf("\n");
	for(int i=0;i<4;++i)
		printf("%d",M[i]);
	for(int i=0;b[i]!='\0';++i)
		Q[i]=b[i]-'0';
	printf("\n");
	for(int i=0;i<4;++i)
		printf("%d",Q[i]);
	recode(Q);
	printf("\nRecoded Q: ");
	for(int i=0;i<4;++i)
		printf("%d",Q[i]);
	for(int i=0;i<4;++i)
		Mcomp[i]=M[i];
	printf("\n");
	twocomp(Mcomp);
	printf("\n2's comp of M: ");
	for(int i=0;i<4;++i)
		printf("%d",Mcomp[i]);
    for(int i=3;i>=0;--i)    
    {
    	if(Q[i]==0)
    		shift(A,P);
    	else if(Q[i]==1)
    	{
    		add(A,M);
    		shift(A,P);
    	}
    	else if(Q[i]==-1)
    	{
    		add(A,Mcomp);
    		shift(A,P);
    	}
    }
    printf("\nProduct is: ");
    for(int i=0;i<4;++i)
		printf("%d",A[i]);
	printf("  ");
	for(int i=0;i<4;++i)
		printf("%d",P[i]);
	printf("\n");
    return 0;
}
