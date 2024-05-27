#include <stdio.h>
#include <stdlib.h>

// Define structures and global variables

struct node{
    int parent;
    int child;
	int older_sibling;
	int younger_sibling;
};

typedef struct node  pcb_type;
int n;

pcb_type *pcb;
int quit=0;



void printPCBTable() {
    printf("i  Parent  First  Older  Younger\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-2d ", i);
        
        if (pcb[i].parent != -1)
            printf("%-7d ", pcb[i].parent);
        else
            printf("        ");

        if (pcb[i].child != -1)
            printf("%-6d ", pcb[i].child);
        else
            printf("      ");

        if (pcb[i].older_sibling != -1)
            printf("%-6d ", pcb[i].older_sibling);
        else
            printf("      ");

        if (pcb[i].younger_sibling != -1)
            printf("%-6d ", pcb[i].younger_sibling);
        else
            printf("      ");
        
        printf("\n");
    }
    printf("-----------------------------------\n");
}



void parameters() {

	// Declare local variables 
	
	int parent = 0;
	int child = 0;
	// Prompt for maximum number of processes
	printf("The maximum of number of processes: ");
	scanf("%d",&n);

	// Allocate memmory for dynamic array of PCB's 
	pcb = (pcb_type*)malloc(n*sizeof(pcb_type));

	// Initialize fields of PCB[0] 
	pcb[0].parent = 0;
	pcb[0].child = -1;

  
	// Intitialize all other PCBs' parent, first_child, younger_sibling, older_sibling 
	for(int i=1;i<n;i++){
		pcb[i].parent = -1;
		pcb[i].child = -1;
		pcb[i].older_sibling=-1;
		pcb[i].younger_sibling=-1;
	}
	// Print PCB table 	
	printf("i Parent First Older Younger\n");
	printf("--------------------------------\n");
	printf("0   0\n");
  return;
}


void create() {
  
	// Declare local variables 
	int parent=0;
	int child=1;
	// Prompt for the parent PCB index 
	printf("Enter the parent process index: ");
	scanf("%d",&parent);
	
	// Search for the next unused PCB index q 
	while(pcb[child].parent !=-1){

		child++;

	}
  
	// Record the parent PCB index p in PCB[q] 
	pcb[child].parent = parent;
	pcb[parent].younger_sibling=-1;
	pcb[parent].older_sibling = -1;

	// Initialize the first_child & younger_sibling of PCB[q] 
	pcb[child].younger_sibling = -1;
	pcb[child].child = -1;


	// Check if parent PCB has no first child--if so, set fields appropriately 
	
	if(pcb[parent].child ==-1){
		pcb[parent].child = child;
	}	
	else{

		int current = pcb[parent].child;
		while(pcb[current].younger_sibling!=-1){
			current = pcb[current].younger_sibling;
		}

		pcb[current].younger_sibling = child;
	//	printf("Y.S %d",pcb[current].younger_sibling);
		pcb[child].older_sibling = current;
		
	}
	// Else, search for appropriate available spot for next child, set fields appropriately 
   
	// Print PCB table 
	printPCBTable();
  return;
}

//*************************************************************
void destroy_descendants(int q) {

	// If the formal parameter is -1, return  
	if(q==-1){
		return ;
	}
	
	// Else:
	else{

		destroy_descendants(pcb[q].younger_sibling);

		destroy_descendants(pcb[q].child);


		pcb[q].child =-1;
		pcb[q].parent =-1;
		pcb[q].younger_sibling =-1;
		pcb[q].older_sibling = -1;
	}

		// Call this procedure on the current PCB's younger sibling

		// Call this procedure on the current PCB's first child

		// Set all fields to invalid 
	
  return;
}

//*************************************************************
void recursive_destroy() {
  
	// Declare local variables 
	
	int p;
	int q;
	// Prompt for the parent PCB index p
	printf("Enter to Parent to destory child processes: ");
	scanf("%d",&p);
	

	destroy_descendants(pcb[p].child);

	pcb[p].child = -1;
	// Call recursive procedure on PCB[p]'s first child 
	

	// Set PCB[p]'s first child to invalid 
	
	// Print PCB table 
	printPCBTable();
  return;
}

//*************************************************************
void free_memory() {

	// If the dynamic array "PCB" is not NULL, free the memory 
	if(pcb !=NULL){
		free(pcb);
	}
	quit=1;
  return;
}

//*************************************************************
int main() {

	// Declare local variables 
	
	// Until the user quits, print the menu, prompt for the menu choice, call the appropriate procedure 
	while(quit==0){
		printf("Menu\n");
		printf("1.Enter Parameters\n");
		printf("2.Create a new child process\n");
		printf("3.Destroy all descendants of a process\n");
		printf("4.Quit program and free memory\n");

		int selection;
		printf("Enter selection: ");
		scanf("%d",&selection);

		switch(selection){
			case 1:
			parameters();
			break;
			case 2:
			create();
			break;
			case 3:
			recursive_destroy();
			break;
			case 4:
			printf("Bye!\n");
			free_memory();
			break;
			default:
			printf("Invalid Input\n");
			main();
		}

	}
}
