
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// declare global variables including a table structure to hold scheduling information


struct node{
    int id;
    int arrival;
	int total_cpu;
	int total_remaining;
	int done; // flag to indicate whether the process has been finished or not
	int start_time; 
	int end_time;
	int turnaround_time;
    
}*table=NULL;

typedef struct node table_type;
int n; // total number of processes

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
void parameters() {
	// declare local variables 
	
	// prompt for total number of processes 
	printf("Enter the number of processes:");
	scanf("%d",&n);
	// allocate memory for table to hold process parameters 
	table = (table_type*)malloc(n*sizeof(table_type));
	// for each auto-numbered process (starting from 0): 
	for(int i=0;i<n;i++){
	    // prompt for arrival time, and total cycle time 
	    printf("Enter arrival for process %d: ",i);
	    scanf("%d",&table[i].arrival);
	    printf("Enter total cycles for the process %d:",i);
	    scanf("%d",&table[i].total_cpu);
	    // same thing for other fields   
	    
	    table[i].id=i;
	}
	  // print contents of table 
	return;	  
}

//*************************************************************
void FIFO() {
	// declare (and initilize when appropriate) local variables 
	int num_done=0;
	int earliest_time;
	int min_index;
	int current_cycle=0;
	// for each process, reset "done" field to 0 

	// while there are still processes to schedule 	
	while(num_done < n){
		// initilize the earliest arrival time to INT_MAX (largest integer value) 
		earliest_time = INT_MAX;
		// for each process not yet scheduled
		// check if process has earlier arrival time than current earliest and update 
		for(int i=0;i<n;i++){
		    
		    if(table[i].done ==0){
		        if(table[i].arrival<earliest_time) {
					earliest_time = table[i].arrival;
					min_index = i;
				}
		        current_cycle = 0;
		    }
		}
		 
				
		// set start time, end time, turnaround time, done fields for unscheduled process with earliest arrival time   
		table[min_index].start_time=max(table[min_index].arrival,current_cycle);
		table[min_index].end_time=table[min_index].start_time;  	
		// update current cycle time and increment number of processes scheduled 
		
		
		
	}
	// print contents of table 
	return;		
}	


//*************************************************************
void SJF() {
	// declare (and initilize when appropriate) local variables
	int lowest_cycle;
	int current_cycle=0; 
	int at_least_one;
	int num_done=0;
	// for each process, reset "done" field to 0 
	// while there are still processes to schedule 	
	while(num_done<0){
		// initilize the lowest total cycle time to INT_MAX (largest integer value) 
		lowest_cycle = INT_MAX;
		at_least_one = 0;

		// for each process not yet scheduled 
			for(int i=0;i<n;i++){}
			// check if process has lower total cycle time than current lowest and has arrival time less than current cycle time and update 
			if((table[i].total_cpu<lowest_cycle)&&(table[i].arrival<= current_cycle))	{
				lowest_cycle = table[i].total_cpu;
				min_index = i;
				at_least_one = 1;
			}

	}

		// set start time, end time, turnaround time, done fields for unscheduled process with lowest (and available) total cycle time
		if(at_least_one==1){
			table[min.index].start_time = max(time[min_index].arrival,current_cycle);
			table[min_index].end_time = ...;
			table[min_index].turnaround_time = ...;
			// update current cycle time and increment number of processes scheduled 
			current_cycle++;
			table[min_index].done =1;
		}   
		else{
			current_cycle++;
		}    
	} 	
	// while ends here	
	// print contents of table 
	return;		
}	
        	

//*************************************************************
void SRT() {
	// declare (and initilize when appropriate) local variables
	int lowest_remaining;
	int current_cycle=0; 


	for(int i=0;..){
		table[i].done = 0;
		table[i].already_started = 0;
		table[i].total_remaining = table[i].total_cpu;
		
	}
	// for each process, reset "done" field to 0 
	// while there are still processes to schedule 	
	...
		// initilize the lowest total cycle time to INT_MAX (largest integer value) 
		lowest_remaining = INT_MAX;
		at_least_one = 0;

		// for each process not yet scheduled 
		
			// check if process has lower total cycle time than current lowest and has arrival time less than current cycle time and update 
			if((table[i].total_remaining < lowest_remaining)&&(table[i].arrival<= current_cycle))	{
				lowest_remaining = ..;
				min_index = ...;
				at_least_one = 1;
			}



		// set start time, end time, turnaround time, done fields for unscheduled process with lowest (and available) total cycle time
		if(at_least_one==1){
			if(table[min_index].already_started ==0){
				table[min.index].start_time = max(time[min_index].arrival,current_cycle);
				table[min_index].already_started =1;
			}
			
			table[min_index].end_time = current_cycle+1;
			table[min_index].turnaround_time = table[min_index].end_time-table[min_index].arrival;
			table[min_index].total_remaining--;
			// update current cycle time and increment number of processes scheduled 
			if(table[min_index].total_remaining ==0){
				table[min_index].done =1;
				num_done++;

			}
			current_cycle++;
			table[min_index].done =1;
		}   
			current_cycle++;
		     	
		
	// print contents of table 
	return;		
}	
        	

//*************************************************************
void "PROCEDURE FOR OPTION #5"() {
	// free the schedule table if not NULL 
	if(table != NULL)
	free(table);	
	return;
}


//*************************************************************
int main() {
	// declare local vars 
	int choice;
	// while user has not chosen to quit 
		// print menu of options 

		printf("1.Enter Parameters");
		printf("2.Schedule Processes with FIFO Algorithm");
		printf("3.Schedule Processes with SJF Algorithm");
		printf("4.Schedule Processes with SRT Algorithm");
		printf("Quit Program and free memory");

		// prompt for menu selection 
		printf("Choose: ");
		scanf()
		// call appropriate procedure based on choice--use switch statement or series of if, else if, else statements 	
	} // while loop 
	 return 1; // indicates success 
// end of procedure 
