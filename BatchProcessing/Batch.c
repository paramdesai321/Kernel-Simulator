
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
	int already_started;
    
}*table=NULL;

typedef struct node table_type;
int n; // total number of processes
int quit=0;

// optional: define a function that finds the maximum of two integers
#define max(a,b) (a>b ? a : b)

//***************************************************************
void printBatch() {
    // Print table header
    printf("%-5s%-10s%-10s%-10s%-10s%-10s\n", "PID", "Arrival", "Total", "Start", "End", "Turnaround");
    printf("-----------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-5d%-10d%-10d%-10d%-10d%-10d\n",
               table[i].id,
               table[i].arrival,
               table[i].total_cpu,
               table[i].start_time,
               table[i].end_time,
               table[i].turnaround_time);
    }
    printf("-----------------------------------------\n");
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
		        
		    }
			
		}
		 
				
		// set start time, end time, turnaround time, done fields for unscheduled process with earliest arrival time   
		table[min_index].start_time=max(table[min_index].arrival,current_cycle);
		table[min_index].end_time=table[min_index].start_time+table[min_index].total_cpu;  	
		table[min_index].turnaround_time = table[min_index].end_time - table[min_index].arrival; 
		// update current cycle time and increment number of processes scheduled 
		current_cycle = table[min_index].end_time;
		num_done++;
		table[min_index].done =1;
		
		
	}
	// print contents of table 
	printBatch();
	return;		
}	


//*************************************************************
void SJF() {
	// declare (and initilize when appropriate) local variables
	int lowest_cycle;
	int current_cycle=0; 
	int min_index;
	int at_least_one;
	int num_done=0;
	// for each process, reset "done" field to 0 
	// while there are still processes to schedule 	
	while(num_done<0){
		// initilize the lowest total cycle time to INT_MAX (largest integer value) 
		lowest_cycle = INT_MAX;
		at_least_one = 0;

		// for each process not yet scheduled 
			for(int i=0;i<n;i++){
			// check if process has lower total cycle time than current lowest and has arrival time less than current cycle time and update 
			if((table[i].total_cpu<lowest_cycle)&&(table[i].arrival<=current_cycle))	{
				lowest_cycle = table[i].total_cpu;
				min_index = i;	
				at_least_one = 1;
			}

	}

		// set start time, end time, turnaround time, done fields for unscheduled process with lowest (and available) total cycle time
		if(at_least_one==1){
			table[min_index].start_time=max(table[min_index].arrival,current_cycle);
		table[min_index].end_time=table[min_index].start_time+table[min_index].total_cpu;  	
		table[min_index].turnaround_time = table[min_index].end_time - table[min_index].arrival; 
			// update current cycle time and increment number of processes scheduled 
			current_cycle = table[min_index].end_time;
			table[min_index].done =1;
			num_done++;

		}   
		else{
			current_cycle++;
		}    
	} 	
	// while ends here	
	// print contents of table 
	printBatch();
	return;		
}	
        	

//*************************************************************
void SRT() {
	// declare (and initilize when appropriate) local variables
	int lowest_remaining;
	int current_cycle=0; 
	int min_index;
	int at_least_one;
	int num_done = 0;

	for(int i=0;i<n;i++){
		table[i].done = 0;
		table[i].already_started = 0;
		table[i].total_remaining = table[i].total_cpu;
		
	}
	// for each process, reset "done" field to 0 
	// while there are still processes to schedule 	
	while(num_done<n){
		// initilize the lowest total cycle time to INT_MAX (largest integer value) 
		lowest_remaining = INT_MAX;
		at_least_one = 0;

		// for each process not yet scheduled 
		for(int i=0;i<n;i++){
			// check if process has lower total cycle time than current lowest and has arrival time less than current cycle time and update 
			if((table[i].total_remaining < lowest_remaining)&&(table[i].arrival<= current_cycle))	{
				lowest_remaining = table[i].total_remaining;
				min_index = i;
				at_least_one = 1;
			}

		}

		// set start time, end time, turnaround time, done fields for unscheduled process with lowest (and available) total cycle time
		if(at_least_one==1){
			if(table[min_index].already_started ==0){
				table[min_index].start_time = max(table[min_index].arrival,current_cycle);
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
			
		}   
			
		     	
	}	
	// print contents of table 
	printBatch();
	return;		
}	
        	

//*************************************************************
void memoryfree() {
	// free the schedule table if not NULL 
	if(table != NULL){
	free(table);	
	}
	quit=1;
	return;
}


//*************************************************************
int main() {
	// declare local vars 
	int choice;
	// while user has not chosen to quit 
		// print menu of options 
		while(quit==0){
	
		printf("1.Enter Parameters\n");
		printf("2.Schedule Processes with FIFO Algorithm\n");
		printf("3.Schedule Processes with SJF Algorithm\n");
		printf("4.Schedule Processes with SRT Algorithm\n");
		printf("Quit Program and free memory\n");

		// prompt for menu selection 
		printf("Choose: ");
		scanf("%d",&choice);


		switch(choice){
			case 1: 
				parameters();
				break;
			case 2:
			    FIFO();
				break;
			case 3: 
			    SJF();
				break;
			case 4:
			    SRT();
				break;
			case 5:
			    memoryfree();
				break;
			default:
				printf("Invalid Input\n");
				main();
		}

		}
		return 1;
		// call appropriate procedure based on choice--use switch statement or series of if, else if, else statements 	
	} // while loop 
	  // indicates succes\ns// end of procedur\ne