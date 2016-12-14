#include <stdio.h>
int gcf(int a, int b){
	int i,hcf;
	for(i=1; i<=a && i<=b; i++)
		if(a%i==0 && b%i==0) hcf = i;
	return hcf;
}

int lcm(int a, int b){
	int i;
	for (i=1; i>=1; i++){
	 	if(i%a==0 && i%b==0){
	 		return i;
//	 		break;
	 	}
	}
}

// A function returns only one value. 
// function exits after the return statement.
int main(){
	int n1,n2;
	printf("Enter 2 numbers\n");
	scanf("%d%d",&n1,&n2);
	printf("gcd = %d\n",gcf(n1,n2));
	printf("lcm = %d\n",lcm(n1,n2));
	return 0;
}