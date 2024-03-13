
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
	  printBatch();
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
	for(int i=0;i<n;i++){
		table[i].done=0;
	}
	
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
				//	printf("%d",min_index);
				
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
    int current_cycle = 0;
    int num_done = 0;
	 int min_index;
        int at_least_one;
		 int lowest_cycle = INT_MAX;
    
	for(int i=0;i<n;i++){
		table[i].done=0;
	}

    while (num_done < n) {
        //printf("num done: %d \n",num_done);
         lowest_cycle = INT_MAX;

         at_least_one = 0;

        for (int i = 0; i < n; i++) {
			if(table[i].done ==0){
            if ( (table[i].arrival <= current_cycle) && table[i].total_cpu < lowest_cycle) {
                lowest_cycle = table[i].total_cpu;
                min_index = i;
                at_least_one = 1;
				
				
            }
			}
        }

        if (at_least_one == 1) {
            
            table[min_index].start_time = max(table[min_index].arrival, current_cycle);

           
            table[min_index].end_time = table[min_index].start_time + table[min_index].total_cpu;

	
            table[min_index].turnaround_time = table[min_index].end_time - table[min_index].arrival;

            
            table[min_index].done = 1;
            num_done++;

            current_cycle = table[min_index].end_time;
			printf("Cycle: %d\n",current_cycle);
        } else {
            // If no process is available, move to the next cycle
            current_cycle++;
        }
    }

    // Print contents of the table 
    printBatch();
    return;
}

//*************************************************************
void SRT() {
    int lowest_remaining;
    int current_cycle = 0;
    int min_index;
    int at_least_one;
    int num_done = 0;

    // Initialize process fields
    for (int i = 0; i < n; i++) {
        table[i].done = 0;
        table[i].already_started = 0;
        table[i].total_remaining = table[i].total_cpu;
    }

    while (num_done < n) {
        lowest_remaining = INT_MAX;
        at_least_one = 0;

        for (int i = 0; i < n; i++) {
            if (!table[i].done && table[i].arrival <= current_cycle && table[i].total_remaining < lowest_remaining) {
                lowest_remaining = table[i].total_remaining;
                min_index = i;
                at_least_one = 1;
            }
        }

        if (at_least_one==1) {
            if (table[min_index].already_started == 0) {
                table[min_index].start_time = current_cycle;
                table[min_index].already_started = 1;
            }

            table[min_index].end_time = current_cycle + 1;
            table[min_index].turnaround_time = table[min_index].end_time - table[min_index].arrival;
            table[min_index].total_remaining--;

            if (table[min_index].total_remaining == 0) {
                table[min_index].done = 1;
                num_done++;
            }

            current_cycle++;
        } else {
            current_cycle++;
        }
    }

    // Print contents of table 
    printBatch();
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
    
    while (quit == 0) {
        int choice;
        printf("1. Enter Parameters\n");
        printf("2. Schedule Processes with FIFO Algorithm\n");
        printf("3. Schedule Processes with SJF Algorithm\n");
        printf("4. Schedule Processes with SRT Algorithm\n");
        printf("5. Quit Program and free memory\n");
        printf("Choose: ");
        scanf("%d", &choice);
        printf("choice %d \n",choice);
        switch (choice) {
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
                break;
        }
    }

    return 0;
}
 // while loop 
	  // indicates succes\ns// end of procedur\ne
	  