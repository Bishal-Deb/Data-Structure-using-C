/*You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.
Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.
*/


#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	printf("***LAB 4 - EQUAL STACKS****\n\n");
	int n1,n2,n3,i,j,k;
	printf("Number of cylinders in stack 1 :");
	scanf("%d",&n1);
	printf("Number of cylinders in stack 2 :");
	scanf("%d",&n2);
	printf("Number of cylinders in stack 3 :");
	scanf("%d",&n3);
	int a[n1+1],b[n2+1],c[n3+1];
	
	printf("\n");
	for(i=0;i<n1;i++)
	{
		printf("Weight %d in Stack 1 is:" , i+1);
		scanf("%d",&a[i]);
	}
	a[n1]=0;
	for(i=n1-2;i>=0;i--){
		a[i]+=a[i+1];
	}
	printf("\n");
	for(i=0;i<n2;i++)
	{
		printf("Weight %d in Stack 2 is:" , i+1);
		scanf("%d",&b[i]);
	}
	b[n2]=0;
	for(i=n2-2;i>=0;i--){
		b[i]+=b[i+1];
	}
	printf("\n");
	for(i=0;i<n3;i++)
	{
		printf("Weight %d in Stack 3 is:" , i+1);
		scanf("%d",&c[i]);
	}
	c[n3]=0;
	for(i=n3-2;i>=0;i--){
		c[i]+=c[i+1];
	}
	
	
	i=0;
	j=0;
	k=0;
	
	while((a[i]!=b[j] || b[j]!=c[k] || c[k]!=a[i]) && i<n1 && j<n2 && k<n3){
		if(a[i]>=b[j] && a[i]>=c[k])
            {i++;}
        else{
            if(b[j]>=a[i] && b[j]>=c[k])
            {j++;}
		else  if(c[k]>=b[j] && c[k]>=a[i])
            {k++;}
        }
		
	}
	if(a[i]!=b[j] || b[j]!=c[k] || c[k]!=a[i]){
		printf("\nNo optimum Solution!!!!!");
	}
	else{
		printf("\nWeight of Each Stack Should be: %d",a[i]);
	}
	
	return 0;
}