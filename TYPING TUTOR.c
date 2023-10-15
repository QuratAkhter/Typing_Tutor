#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<conio.h>
int dictionary(char str[]);
int write();
void timer();
int main(){
	
	printf("================================WELCOME TO OUR PROGRAM===================================\n\n");
	printf("**************************************TYPING TUTOR*******************************************\n\n");
	printf("--------------------------------LET'S HAVE FUN WITH TYPING--------------------------------\n\n");
	
	
	printf("Do you Want to check your typing errors?\nDo you want to check your typing accuracy?\nDo you want to check your Typing speed?\nif yes!Let's get started with typing tutor\n");
	
	
	printf("\nPress any key to start time:\n\n");
	getch();
	timer();

	
}
int write(){
	char str[1000];
	printf("Press enter key to stop time:\n");
	int len,words;
	printf("WRITE YOUR PARAGRAPH:\n");
	printf("-----------------------------------------------------------------------\n");
	fflush(stdin);
	gets(str);
	len=strlen(str);
	if(len>1000){
		printf("Too much long string Entered!");
		exit(0);
		
	}
	printf("-----------------------------------------------------------------------\n");
	words=dictionary(str);
	return words;
}
void timer(){
	time_t start,end;
	char *ptr,*ptr2;
	int words;
	float t,speed;
	
	start=time(NULL);
	printf("Your time starts now!\n");
	ptr=ctime(&start);
	printf("You started at: %s\n",ptr);
	words=write();
	end=time(NULL);
	
	ptr2=ctime(&end);
	printf("You stopped at: %s\n",ptr2);
	t=difftime(end,start);
	printf("You have taken %.2f seconds to write this paragraph\n",t);
	t=t/60;
	speed=(float)words/t;
	printf("Your average typing speed is %.2f words per minute\n",speed);
	
	
}
int dictionary(char str[]){
	char temp[200][20];
	int tempsize=0;
	int lenght[200];
	int i=0,j=0,stop=0,z=0;
	
	
	for(i=0 ; i < 20 ; i++)
	{
		tempsize++;
		for( j ; j < 1000 ; j++)
		{
			
			if(str[j]  == ' '){
			j++;
			lenght[i]=z;
			z=0;
			break;	
			}
			if(str[j] == '.' || str[j] == ',' || str[j] == '!' || str[j] == '"' || str[j] == '?'){
				continue;
			}
			if(str[j] == '\0'){
				lenght[i]=z;
				stop=1;
				break;
			}
			
			temp[i][z]= str[j];
			z++;
		}
		
		if(stop==1)
		break;
	}
	FILE *fp ;
	int c=0 ;
	int count=0;
	char s[1000];
	float mistake_no=0;
	int size=0, rows=0;
	int x,y,w=0;
	i=0;
	stop=0;
	char mistake[200][20];
		
	for(rows =0 ; rows < tempsize ;  rows ++){	
		
		fp = fopen ( "dictionary400000.txt", "r" );
		if ( fp == NULL ) 
		{
	 		puts ( "Cannot open file" ) ; 
	 		exit(0); 
		}
		
		stop=0;
		
		while( fgets( s , sizeof(s) , fp)  != NULL ){
			
			count =0;
				
			for(j=0 ; j < lenght[rows] ; j++) {
					
				if( tolower(s[j] ) == tolower(temp[rows][j] )){
					
					
					count++;
					if( count == lenght[rows])
					{
						c++;
						stop=1;
					}
					if(stop==1)
					break;	
				}
				
				if(stop==1)
				break;
			}
			
			if(stop==1)
			break;
		}
		
		if(stop == 0 ){
			mistake_no++;
			for(y=0 ; y < lenght[rows] ; y++){
				mistake[w][y]=temp[rows][y];
			}
			w++;
		}
		
	}
		
				
	printf("\nMatched letters are %d \n", c );
	
	printf("\nMistakes are \n" );
	if(mistake_no > 0)
	for(i=0 ; i < w ; i++){
		if(mistake[i] != NULL)
		printf(" - %s \n", mistake[i]);
	}
	else{
		printf("none\n");
	}
	

	
	float accuracy ;
	accuracy = mistake_no / tempsize;
	accuracy = accuracy * 100.00;
	accuracy = 100.00 - accuracy;
	printf("\nAccuracy is %.2f percent \n\n" , accuracy);


	return tempsize;

	
	
	fclose(fp);
	
	
}
