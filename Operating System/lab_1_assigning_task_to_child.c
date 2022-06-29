#include<stdio.h>
#include<unistd.h>
int array[100];

int calculate_even_sum(int n)
{
int sum = 0;
	for(int i=0;i<n;i++)
	{
		if(array[i]%2==0)
			sum += array[i];
	}
return sum;
}

int count_even_freq(int n)
{
int count = 0;
	for(int i=0;i<n;i++)
	{
		if(array[i]%2==0)
			count++;
	}
return count;
}

void sort()
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
		 	{
		 		temp = a[j+1];
		 		a[j+1] = a[j];
		 		a[j] = a[j+1];
		 	}
		 }
	}
}

int main()
{
int pid1 = fork();
int pid2 = fork();

if(pid1==0 && pid2 == 0) 
{
	sort();
	calculate_even_sum(n);
}
else if(pid1==0 && pid2!=0) 
{
	count_even_freq(n);
}
if(pid3==0) 
{
	
}
else printf("Hello from parent");
}
