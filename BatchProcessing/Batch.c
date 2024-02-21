
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// declare global variables including a table structure to hold scheduling information


struct node{
    int id;
    int arrival;
    
}*table=NULL;

typedef struct node table_typle;
int n;

// optional: define a function that finds the maximum of two integers
#define max(a,b) (a>b ? a : b)

//***************************************************************
void printBatch() {
	// declare local variables
	// print table header 	
	// for each process 
		// print the contents (id, arrival time, total_cycles) of each field of the table's index 
		// if process has been scheduled ("done" field is 1, print other contents (start time, end time, turnaround time) 
	return;
}


//*************************************************************
void "PROCEDURE FOR OPTION #1"() {
	// declare local variables 
	
	// prompt for total number of processes 
	printf("Enter the number of processes:");
	scanf("%d",&n)
	// allocate memory for table to hold process parameters 
	table = (table_typle*)()malloc(n*sizeof(table_typle));
	// for each auto-numbered process (starting from 0): 
	for(int i=0;i<n;i++){
	    // prompt for arrival time, and total cycle time 
	    printf("Enter arrival for process %d: ",i);
	    scanf("%d",&table[i].arrival);
	    printf("Enter total cycle time %d:",i);
	    scanf("%d",&table[i].total);
	    // same thing for other fields
	    
	    
	    table[i].id=i;
	}
	    
	}
			
	// print contents of table 
	return;		
}	
		

//*************************************************************
void FIFO() {
	// declare (and initilize when appropriate) local variables 
	int num_done=0;
	int earliest_time;
	// for each process, reset "done" field to 0 
	for(int i=0;i<)
	// while there are still processes to schedule 	
	while(num_done < n){
		// initilize the earliest arrival time to INT_MAX (largest integer value) 
		earliest_time = INT_MAX;
		// for each process not yet scheduled
		// check if process has earlier arrival time than current earliest and update 
		for(int i=0;i<n;i++){
		    
		    if(table[i].done ==0){
		        if(table[i].arrival<earliest_time) 
		        
		    }
		}
		 
				
		// set start time, end time, turnaround time, done fields for unscheduled process with earliest arrival time        	
		// update current cycle time and increment number of processes scheduled 
		
		
		
	}
	// print contents of table 
	return;		
}	


//*************************************************************
void "PROCEDURE FOR OPTION #3"() {
	// declare (and initilize when appropriate) local variables 
	// for each process, reset "done" field to 0 
	// while there are still processes to schedule 	
		// initilize the lowest total cycle time to INT_MAX (largest integer value) 
		// for each process not yet scheduled 
			// check if process has lower total cycle time than current lowest and has arrival time less than current cycle time and update 	
		// set start time, end time, turnaround time, done fields for unscheduled process with lowest (and available) total cycle time        	
		// update current cycle time and increment number of processes scheduled 
	// print contents of table 
	return;		
}	
        	

//*************************************************************
void "PROCEDURE FOR OPTION #4"() {
	// declare (and initilize when appropriate) local variables 
	// for each process, reset "done", "total_remaining" and "already_started" fields to 0 
	// while there are still processes to schedule 	
		// initilize the lowest total remaining time to INT_MAX (largest integer value) 
		// for each process not yet scheduled 
			// check if process has lower total remaining time than current lowest and has arrival time less than current cycle time and update 	
		// check if process already partially-scheduled 
			// if so, set "start time", "already_started" fields of process with lowest (and available) total remaining cycle time        	
		// set end time, turnaround time of process with lowest (and available) total remaining cycle time 
		// decrement total remaining time of process with lowest (and available) total remaining cycle time 
		// if remaining time is 0, set done field to 1, increment cycle time and number of scheduled processes
	// print contents of table 
	return;		
}	
        	

//*************************************************************
void "PROCEDURE FOR OPTION #5"() {
	// free the schedule table if not NULL 
	return;
}


//*************************************************************
int main() {
	// declare local vars 
	// while user has not chosen to quit 
		// print menu of options 
		// prompt for menu selection 
		// call appropriate procedure based on choice--use switch statement or series of if, else if, else statements 	
	} // while loop 
	 return 1; // indicates success 
} // end of procedure 
Displaying comp322_asmt2_skeleton_s24.txt.