#include <stdio.h>
#include <stdlib.h>



// Declare dynamic arrays/vectors and global variables
int *resource = NULL; // all existing units of each resource //vector
int *available = NULL; // available units of each resource //vector
int *maxclaim = NULL; // all units of each resource that each process may claim 
int *allocated = NULL; // all units of each resource that each process currently holds
int *need = NULL; // all units of each resource that each process still wantsint maxclaim;
int num_processes;
int num_resources;
 

//*********************************************************
void print_vector(int *vector, char *title) {
    // Print the title
    printf("%s\n", title);
    
    // Print resource indices and corresponding values
    for (int j = 0; j < num_resources; j++) {
        printf("r%d: %d\n", j, vector[j]);
    }

    printf("\n");
}


//*************************************************************
void print_matrix(int *matrix, char *title) { 

    //Print the title
   
    printf("%s\n", title);
    
    // for loop j: print each resource index 
    for(int j = 0; j < num_resources; j++)
    {
        printf("\tr%d\t", j);
    }

    // for each process i: 
    for(int i = 0; i < num_processes; i++)
    {
        printf("\tp%d\t", i);

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
void resource_claim() {


    // prompt for number of resources 
    printf("Number of resources?");
    scanf("%d", &num_resources);

    // allocate memory for vectors 
    resource = (int *)malloc(num_resources * sizeof(int));
    available = (int *)malloc(num_resources * sizeof(int));

    // for each resource, prompt for number of units, set resource and available vectors indices
    printf("Enter the number of units for resources r0 to r%d: ", num_resources - 1);

    for(int j = 0; j < num_resources; j++)
    {
        scanf("%d",&resource[j]);
        available[j] = resource[j];
    }

    // prompt for number of processes
    printf("Num of procs? :");
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
            scanf("%d", &maxclaim[i * num_resources + j]);
            need[i * num_resources + j] = maxclaim[i * num_resources + j];// similar to need[i][j] = maxclaim[i][j]
        }
    }
// Do same for allocated
    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter maximum number of resources r0 to r%d that p%d will request: ", num_resources - 1, i );

        // for each process, for each resource, prompt for number of resource units allocated to process 
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocated[i * num_resources + j]);
            need[i * num_resources + j] -= allocated[i * num_resources + j];
            available[j] -= allocated[i * num_resources + j];
        }
    }
    
    // print resource vector, available vector, maxclaim array, allocated array, need array 
    print_vector(resource, "Resources");
    print_vector(available, "Available");
    print_matrix(maxclaim, "Maxlaim")
;    print_matrix(allocated, "Allocated");
    print_matrix(need, "Need");

    return;
}

//**************************************************************
void request_resource() {
    // declare local variables
    int i, j, n;
    int num_done = 0;
    // prompt for process, resource, and number of units requested
    printf("Enter requesting process: p");
    scanf("%d", &i);

    printf("request resource from a process: r");
    scanf("%d",&j);


    printf("Enter the number of units process p%d is requesting from r%d: ",i,j);
    scanf("%d",&n);

    
          
    // if enough units available and request is less than need
    if((n<=available[j]) && (n<=need[i*num_resources+j])){
        // reduce number of available units
    available[j] -= n;

        // increase number of allocated units
    allocated[i*num_resources+j] +=n;
        // reduce number of needed units
    need[i*num_processes+j] -=n;        
        }       
    
        // print updated available, allocated, and need vectors/matrices
    
    // else
    else{
        printf("Request Denied");
    }
    return;
}


//**************************************************************
void release_resource() {
    // declare local variables
    // prompt for process, resource, and number of units requested
    // if enough units allocated
      int i,j,n;
      int num_done = 0;
    printf("Enter Realease process: p");
    scanf("%d", &i);

    printf("Realease resource from a process: r");
    scanf("%d",&j);


    printf("Enter the number of units process p%d is releasing from r%d: ",i,j);
    scanf("%d",&n);

        
    // prompt for process, resource, and number of units requested
    
    if((n<=allocated[i*num_resources+j])){
        // increase number of available units
    available[j] += n;

        // reduce number of allocated units
    allocated[i*num_resources+j] -= n;
            // increase number of needed units
    need[i*num_processes+j] +=n; 

        // print updated available, allocated, and need vectors/matrices
    } 
        // print updated available, allocated, and need vectors/matrices
    // else
    else{
       printf("Cannot Realease");
    }
    return;
}


//******************************************************************
void sequence() {

    // declare local variables
    
    int *done = (int *)calloc(num_processes,sizeof(int)); // calloc means malloc and clear + for some oblivous reason in calloc you need two argument calloc(index, width of the index)
    int *sequence = (int *)malloc(num_processes* sizeof(int));
    int at_least_one = 1;
    int less_than_or_equal;
    int num_done = 0;

    // while not all processes are processed
    while((num_done< num_processes)&&(at_least_one ==1)){

        at_least_one = 0;
        // for each process  
        for(int i=0;i< num_processes;i++){
            less_than_or_equal=1; 
            // if process has not been processed yet    
            if(done[i]==0){
                // print message comparing need vector with available vector
                printf("Comparing: <");
                for( int j=0;j<num_resources;j++){
                    printf("%d", need[i*num_resources+j]);
                    printf(",");
                    
                }
                printf("> <=");
            // for each resource 
                printf("<");
            for(int j=0;j<num_resources;j++){
                 printf("%d", available[i*num_resources+j]); 
                 printf(",");

            }
                printf(">");



                for(int j=0;j<num_resources;j++){
                    // check for safe processing by comparing process' need vector to available vector 
                     less_than_or_equal &=(need[i*num_resources+j]<=available[j]);


                }
                    // if each resource is available 
                if(less_than_or_equal ==1){
                        // print message that process can be processed
                    printf(": Safe to run process p %d", i);
                        // update number of available units of for each resource 
                        for(int j=0;j<num_resources;j++){
                            available [j] += allocated[i*num_processes+j];
                            allocated[i*num_resources+j] = 0;
                        }
                    sequence[num_done] =i;
                    num_done ++; 
                    done[i] = i;
                    at_least_one = 1;   


                }

            }

        }
             
                
                
                    
                
                
                    

                       // free all resources allocated to process 
                        // increment number of sequenced processes 
                // else print message that process cannot be processed
    //if (no process was processed in the final round of the for-loop)
        // print message of deadlock among processes not processed
    // else print safe sequence of processes

    }
    return;
}


//******************************************************************
void quit() {
    // check if vectors/array are not NULL--if so, free each vector/array   );
    return;
}


//*************************************************************
int main() {
    // declare local vars 
    // while user has not chosen to quit 
        // print menu of options 
        // prompt for menu selection 
        // call appropriate procedure based on choice--use switch statement or series of if, else if, else statements   
     // while loop 
    resource_claim(); 
     return 1; // indicates success 

}