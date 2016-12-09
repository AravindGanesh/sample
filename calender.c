#include <stdio.h>

void month(){
	int mm,date[117][12][35],days,yy;
	int i,shit=6,boo;
	for(yy=1900; yy<2017; yy++){
		shit = 7 - shit;
		for(mm=1; mm<=12; mm++){
			if(mm==4 ||  mm==6 || mm==7 || mm==9) days=30;
			else if(mm==2){
				if(yy%4 == 0) days=29;
				else days=28;
			}
			else if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12) days=31;
			else days=0;
			for(i=0; i<35; i++){
				if(i<shit)
					date[yy-1900][mm-1][i] = 99;
	 			else if(i<(days+shit)){
					date[yy-1900][mm-1][i] = i+1-shit;
					boo = i;
	 			}
				else
					date[yy-1900][mm-1][i] = 88;
			}
			shit = (34 - boo)%7;
		}	
	}

	printf("Enter Year\n");
	scanf("%d",&yy);
	printf("Enter month\n");
	scanf("%d",&mm);
	printf("Su Mo Tu We Th Fr Sa\n");
	for(i=0; i<35; i++){
		if(date[yy-1900][mm-1][i] == 88) printf("  ");
		else if(date[yy-1900][mm-1][i] == 99) printf("   ");
		else printf("%2d ",date[yy-1900][mm-1][i]);
		if(i%7 == 6) printf("\n");
	}
	printf("\n");
}

int main(){
	month();
	return 0;
}