#include <stdio.h>
#include <stdlib.h>

struct node {
    int block_id;
    int starting;
    int address;
    int ending;
    struct node *next;
} *block_list = NULL;

typedef struct node block_type;
int pm_size;
int remaining;

void Enter_Parameter() {
    printf("Size of Physical memory: ");
    scanf("%d", &pm_size);
    remaining = pm_size;
    block_list = (block_type *)malloc(sizeof(block_type)); // this is to save the head, just in case if you choose to remove the actual first block and then your head pointer is gone
    block_list->block_id = -1;
    block_list->starting = 0;
    block_list->ending = 0;
    block_list->next = NULL;
    return;
}

void print_table() {

    block_type *current;
    current = block_list->next;
    printf("ID\tStart\tEnd\n");
    while (current != NULL) {
        printf("%d\t%d\t%d\n", current->block_id, current->starting, current->ending);
        
        current = current->next;
    }
    return;
}

void First_Fit() {
    int block_size;
    int id;
    block_type *new_block;
    block_type *current;
    printf("Size: ");
    scanf("%d", &block_size);
    printf("ID: ");
    scanf("%d", &id);
    if (block_size > remaining) { // no fit
        printf("Out of memory\n");
        return;
    }
    if (block_list->next == NULL) {
        new_block = (block_type *)malloc(sizeof(block_type));
        new_block->block_id = id;
        new_block->starting = 0;
        new_block->ending = block_size;
        new_block->next = NULL;
        block_list->next = new_block;
        remaining -= block_size;
        print_table();
        return;
    } else {
        new_block = (block_type *)malloc(sizeof(block_type));
        current = block_list;
   
        int hole_end;
        int hole_size;
        int hole_start;
        while (current != NULL) {
            
            if(current->next ==NULL){
                    hole_end = pm_size;
                }
                else{
                    hole_end = current->next->starting;
                }
                hole_start = current->ending;
                hole_size = hole_end - hole_start;
            
            if(hole_size>= block_size){
                
                new_block->next = current->next;
                new_block->block_id = id;
                new_block->starting = hole_start;
                new_block->ending = hole_start+block_size;
                current->next= new_block;
                
                remaining -= block_size;
                 print_table();
                 return;
            }
        else{
            current = current->next;
        }
        }
        
    }
}

void Best_Fit() {
    int block_size;
    int id;
    block_type *new_block;
    block_type *current;
    block_type *best_block;
    int hole_size, hole_start, hole_end;
    int best_so_far = pm_size; // to have the best one;

    printf("Size: ");
    scanf("%d", &block_size);
    printf("ID: ");
    scanf("%d", &id);

    if (block_size >= remaining) {
        printf("Not enough space\n");
    }
    if (block_list->next == NULL) {
        new_block = (block_type *)malloc(sizeof(block_type));
        new_block->block_id = id;
        new_block->starting = 0;
        new_block->ending = block_size;
        new_block->next = NULL;
        block_list->next = new_block;
        remaining -= block_size;
        print_table();
        return;
    } else {
        new_block = (block_type *)malloc(sizeof(block_type));
        //block_type *old;
        current = block_list;
        //old = block_list;
      
        while (current != NULL) {
            if (current->next == NULL) {
                hole_end = pm_size;
            }
            else{
                hole_end = current->next->starting;
            }
                hole_start = current->ending;
                hole_size = hole_end - hole_start;
                  if (hole_size >= block_size) {
                if (hole_size < best_so_far) {
                    best_so_far = hole_size;
                    best_block = current;
                    
                }
            }
            //old = current;
            current = current->next;
           
        }
        
        new_block->next = best_block->next;
        //old->next = new_block;
        new_block->starting = best_block->ending;
        new_block->ending = new_block->starting + block_size;
        new_block->block_id = id;
        best_block->next = new_block;
        remaining -= block_size;
        print_table();
        return;
    }
}

void Worst_Fit() {
    int block_size;
    int id;
    block_type *new_block;
    block_type *current;
    block_type *best_block;
    int hole_size, hole_start, hole_end;
    int worst_so_far = 0; // to have the best one;

    printf("Size: ");
    scanf("%d", &block_size);
    printf("ID: ");
    scanf("%d", &id);

    if (block_size >= remaining) {
        printf("Not enough space\n");
    }
    if (block_list->next == NULL) {
        new_block = (block_type *)malloc(sizeof(block_type));
        new_block->block_id = id;
        new_block->starting = 0;
        new_block->ending = block_size;
        new_block->next = NULL;
        block_list->next = new_block;
        remaining -= block_size;
        print_table();
        return;
    } else {
        new_block = (block_type *)malloc(sizeof(block_type));
        //block_type *old;
        current = block_list;
        //old = block_list;
      
        while (current != NULL) {
            if (current->next == NULL) {
                hole_end = pm_size;
            }
            else{
                hole_end = current->next->starting;
            }
                hole_start = current->ending;
                hole_size = hole_end - hole_start;
                  if (hole_size >= block_size) {
                if (hole_size > worst_so_far) {
                    worst_so_far = hole_size;
                    best_block = current;
                    
                }
            }
            //old = current;
            current = current->next;
           
        }
        
        new_block->next = best_block->next;
        //old->next = new_block;
        new_block->starting = best_block->ending;
        new_block->ending = new_block->starting + block_size;
        new_block->block_id = id;
        best_block->next = new_block;
        remaining -= block_size;
        print_table();
        return;
    }
}
void dealloacate() {
    // declare/initialize local variables
    int id;
	int block_size;
	block_type *current_block ;
	block_type *previous_block;


// prompt for block id

	printf("Give a block id:");
	scanf("%d",&id);
	



// initialize "current block"
	current_block = block_list;
// while id not found and end of block list not reached
	while((current_block!=NULL)&&( id != current_block->block_id)){


		previous_block = current_block;
		current_block = current_block->next;
				
	}

	if(current_block ==NULL){
		printf("nothing is in the block");
		return;
	}

	previous_block->next = current_block->next;
	block_size = current_block->ending - current_block->starting;
	

	remaining += block_size;
	free(current_block);
	print_table();

    // advance "previous block" pointer and "current block"
    return;
}


int main() {
    Enter_Parameter();
    First_Fit();
    First_Fit();
    dealloacate();
    Best_Fit();
    Worst_Fit();

    
    return 0;
}
