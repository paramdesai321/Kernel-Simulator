#include <stdio.h>
#include <stdlib.h>

// Declare dynamic arrays/vectors and global variables
int *resource = NULL; // all existing units of each resource //vector
int *available = NULL; // available units of each resource //vector
int *maxclaim = NULL; // all units of each resource that each process may claim 
int *allocated = NULL; // all units of each resource that each process currently holds
int *need = NULL; // all units of each resource that each process still wants

int num_processes;
int num_resources;
 

//*********************************************************
void print_vector(int *vector, char *title) {

    //Print the title
    printf("%s", title);
    
    // for loop j: print each resource index 
    for(int j = 0; j < num_resources; j++)
    {
        printf("r%d\t", j);
    }

    // for loop j: print value of vector[j] 
    for(int j = 0; j < num_resources; j++)
    {
        printf("r%d\t", vector[j]);
    }

    printf("\n");

    return;
}

//*************************************************************
void print_matrix(int *matrix, char *title) { 

    //Print the title
    printf("%s", title);
    
    // for loop j: print each resource index 
    for(int j = 0; j < num_resources; j++)
    {
        printf("\tr%d\t", j);
    }

    // for each process i: 
    for(int i = 0; i < num_processes; i++)
    {
        printf("\tr%d\t", i);

        // for each resource j: 
        for(int j= 0; j < num_resources; j++)
        {
            // print value of matrix[i,j]
            printf("%d", matrix[(i * num_resources) + j ]); //Can't print 2d arrays in C. Neat trick. Other ways to do it. Who cares.
        }
            
    }
        
    return;
}
//**************************************************************
void "OPTION #1"() {

    // prompt for number of resources 
    printf("Number of resources? \n");
    scanf("%d", &num_resources);

    // allocate memory for vectors 
    resource = (int *)malloc(num_resources * sizeof(int));
    available = (int *)malloc(num_resources * sizeof(int));

    // for each resource, prompt for number of units, set resource and available vectors indices
    printf("Enter the number of units for resources r0 to r%d: ", num_resources - 1);

    for(int j = 0; j < num_resources; j++)
    {
        scanf("%d", resource[j]);
        available[j] = resource[j];
    }

    // prompt for number of processes
    printf("Num of procs? : \n");
    scanf("%d", &num_processes);

    // allocate memory for arrays
    maxclaim = (int *)malloc(num_processes * num_resources * sizeof(int));
    allocated = (int *)malloc(num_processes * num_resources * sizeof(int));
    need = (int *)malloc(num_processes * num_resources * sizeof(int));
    
    // for each process, for each resource, prompt for maximum number of units requested by process, update maxclaim and need arrays  
    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter maximum number of resources p%d will request from resources r0 to r%d : ", i, num_resources - 1);

        // for each process, for each resource, prompt for number of resource units allocated to process 
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", maxclaim[i * num_resources + j]);
            need[i * num_resources + j] = maxclaim[i * num_resources + j];
        }
    }
// Do same for allocated
    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter maximum number of resources r0 to r%d that p%d will request: ", num_resources - 1, i );

        // for each process, for each resource, prompt for number of resource units allocated to process 
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", allocated[i * num_resources + j]);
            need[i * num_resources + j] -= allocated[i * num_resources + j];
            available[j] -= allocated[i * num_resources + j];
        }
    }
    
    // print resource vector, available vector, maxclaim array, allocated array, need array 
    print_vector(resource, "Resources");
    print_vector(available, "Available");
    print_vector(maxclaim, "Maxlaim");
    print_vector(allocated, "Allocated");
    print_vector(need, "Need");

    return;
}

//**************************************************************
void "OPTION #2"() {
	// declare local variables
	int i,j,n;
	// prompt for process, resource, and number of units requested
	// if enough units available and request is less than need
		// reduce number of available units
	available[j] -= n;

		// increase number of allocated units
	allocated[i*num_resources+j] ++;
		// reduce number of needed units
    need[i*num_processes+j] +=n; 

		// print updated available, allocated, and need vectors/matrices
    
	// else
		print message that request was denied
	return;
}


//**************************************************************
void "OPTION #3"() {
	// declare local variables
	// prompt for process, resource, and number of units requested
	// if enough units allocated
		// increase number of available units
		// reduce number of allocated units
		// increase number of needed units
		// print updated available, allocated, and need vectors/matrices
	// else
		print message that release cannot be performed
	return;
}


//******************************************************************
void "OPTION #4"() {

	// declare local variables
	// while not all processes are processed
		// for each process  
			// if process has not been processed yet 	 
				// print message comparing need vector with available vector
				// for each resource 
					// check for safe processing by comparing process' need vector to available vector 
	      			// if each resource is available 
					// print message that process can be processed
					// update number of available units of resource 
					// for each resource 
						free all resources allocated to process 
						// increment number of sequenced processes 
				// else print message that process cannot be processed
	//if (no process was processed in the final round of the for-loop)
		// print message of deadlock among processes not processed
	// else print safe sequence of processes
	return;
}


//******************************************************************
void "OPTION #5"() {
	// check if vectors/array are not NULL--if so, free each vector/array 	);
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