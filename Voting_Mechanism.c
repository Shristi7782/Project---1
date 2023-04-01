#include<stdio.h>
int N,votes=0,students; 
/* 
	    N    : Number of Candidates
	students : Number of students voting
*/


// ForVote : voting + return winner

void print(char candidate[N][20],int count[N]){
	int k;
	for(k=0;k<N;++k){
		printf("\n\t|  %10s      |      %2d        |",candidate[k],count[k]);
	}
	printf(" \n\t_____________________________________\n");
}




void Give_Vote(char candidate[N][20],int count[N]){
	int i,choice;
	
	// choices 
		printf(" \n There are options to choose your favourite candidate to make CR\n");
		for(i=0;i<N;i++){
			printf("\t %d : %s \n",i,candidate[i]);  //  0 : Candidates_name
		}
		printf(" \n Enter Your Choice From ( 0 - %d ): \n",N-1);
		scanf("%d",&choice);
		count[choice]+=1;
}

// For Result
int result(int count[N]){
	int cnt=0;
	
	int i,person;
	for(i=0;i<N;i++){
		if(votes < count[i]){
		   votes = count[i];
		   person = i;
		}
		/*else if(votes==count[i]){
			return -1;
		}*/	   //miantainance
	}
	int j;
//	printf("_______%d_____________",votes);
	for(j=0;j<N;++j){
		if(votes == count[j]){
			cnt+=1;
		}
	}
//	printf("_________%d_____",cnt);
	if(cnt==1){
		return person;
	}
	else{
		return -1;
	}
	
	
	
	
//return person;
}

int main(){
	printf("Number Of Candidates : ");
	scanf("%d",&N);
	printf("Count Of Students who can Vote :");
	scanf("%d",&students);
	
	int i,j,winner,vid,vid1;
	//those are voting	
	int voting[students]; // cheack wheather a student can vote or not { 0 : Yes , 1 : No }
	//count for those are standing
	int count[N];
	
	char candidate[N][20]; // Array of Candidates Name
	printf("Candidates Name : \n");
	for(i=0;i<N;i++){
		scanf("%s",&candidate[i][0]);  
	}
	
	for(i=0;i<students;i++) voting[i]=0;
	for(i=0;i<N;i++) count[i]=0;
	
	int ch;
	do{
		printf("\n Enter Your Voter ID Number (1 - %d):",students);
		scanf("%d",&vid1);
		vid=vid1-1;
		
		if(voting[vid]==0){
			Give_Vote(candidate,count);
			voting[vid]=1;
		}
		else{
			printf("\n Already have voted..!");
		}
		
		printf("\n Wish To Continue ( 0 : NO , 1 : YES ) :");
		scanf("%d",&ch);
		
	}while(ch != 0);
	
	winner=result(count);
	
	//if thier is a draw result will return -1 as a value
	
	if(winner == -1){
		printf("draw \n");
		printf("\n\n\t  CANDIDATE     |    RESPECTIVE VOTE\n");
	    printf(" \t_____________________________________\n");
	    print(candidate,count);
	    
	    
	    
	}
	
	// if there is only 1 winner and  no draw
	
	else{
		printf("   Winner : %s \n Total_votes : %d",candidate[winner],votes);
		printf("\n\n\t  CANDIDATE     |    RESPECTIVE VOTE\n");
	    printf(" \t_____________________________________\n");
	    print(candidate,count);
	    
	}
	
	
}
