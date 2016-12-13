#include <stdio.h>

int mm,date[117][12][42],days,yy,prechoice,M,Y;

void calendar(){
	int i,space=1;

	for(yy=1900; yy<2017; yy++){
		for(mm=1; mm<=12; mm++){
			if(mm==4 ||  mm==6 || mm==9 || mm==11) days=30;
			else if(mm==2){
				if(yy%4 == 0 && yy>1900) days=29;
				else days=28;
			}
			else if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12) days=31;
			else days=0;
			for(i=0; i<42; i++){
				if(i<space) date[yy-1900][mm-1][i] = 99;
				else if(i<(days+space)) date[yy-1900][mm-1][i] = i+1-space;
				else date[yy-1900][mm-1][i] = 88;
			}
			space = (days+space)%7;
		}
	}
}

void month(int MM, int YY){
	calendar();
	int i;
	
	if(MM>=1 && MM<=12 && YY>=1900 && YY<=2016){
		printf("          %d          \n");	
		switch (MM) {
			case  1:
				printf("       JANUARY      \n");
				break;
			case  2:
				printf("      FEBRUARY      \n");
				break;
			case  3:
				printf("       MARCH        \n");
				break;
			case  4:
				printf("       APRIL        \n");
				break;
			case  5:
				printf("        MAY         \n");
				break;
			case  6:
				printf("        JUNE        \n");
				break;
			case  7:
				printf("        JULY        \n");
				break;
			case  8:
				printf("       AUGUST       \n");
				break;
			case  9:
				printf("     SEPTEMBER      \n");
				break;
			case 10:
				printf("       OCTOBER      \n");
				break;
			case 11:
				printf("      NOVEMBER      \n");
				break;
			case 12:
				printf("      DECEMBER      \n");
				break;
			default:
				break;
		}

		printf("Su Mo Tu We Th Fr Sa\n");
		for(i=0; i<42; i++){
			if(date[YY-1900][MM-1][i] == 88) printf("  ");
			else if(date[YY-1900][MM-1][i] == 99) printf("   ");
			else printf("%2d ",date[YY-1900][MM-1][i]);
			if(i%7 == 6) printf("\n");
		}
		printf("\n");
	}
	else printf("Not available.\nAvailable from JANUARY 1900 to DECEMBER 2016 only.\n");	
}

void year(int YY){

	calendar();
	
	
}

void calendarmenu(){
	int choice;
	printf("CALANDER MENU\n1. Year\n2. Month\n3. Next\n4. Previous\n5. EXIT\n");
	scanf("%d",&choice);
	switch (choice){
		case 1:
			printf("Enter Year\n");
			scanf("%d",&Y);
			year(Y);
			prechoice = 1;
			calendarmenu();
			break;
		case 2:
			printf("Enter Year\n");
			scanf("%d",&Y);
			printf("Enter month\n");
			scanf("%d",&M);
			month(M,Y);
			prechoice = 2;
			calendarmenu();
			break;
		case 3:
			if(prechoice==1){
				Y++;
				year(Y);
			}
			else if(prechoice==2){
				if(M==12){
					month(1,Y+1);
					M=1;
					Y++;
				}
				else{
					month(M+1,Y);
					M++;
				}
			}
			calendarmenu();
			break;
		case 4:
			if(prechoice==1){
				Y--;
				year(Y);
			}
			else if(prechoice==2){
				if(M==1){
					month(12,Y-1);
					M=12;
					Y--;
				}
				else {
					month(M-1,Y);
					M--;
				}
			}
			calendarmenu();
			break;
		case 5:  break;
		default: break;
	}
}

int main(){
	calendarmenu();
	return 0;
}
