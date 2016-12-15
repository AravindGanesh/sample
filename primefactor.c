#include <stdio.h>
void primefactor(int n){
	int prime,junk,p,flag;
	for(prime=2; prime<=n; prime++){
		flag = 0;
		for (p=2; p<=prime; p++)
			if(prime%p==0) flag++;
		if(flag==1){
			if(n%prime==0){
				while(n%prime==0){
					n=n/prime;
					printf("%d\t",prime);
				}
			}
		}
	}
}

int main(){
	int number;
	scanf("%d",&number);
	primefactor(number);
	printf("\n");
	return 0;
}