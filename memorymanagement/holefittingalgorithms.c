#include <stdio.h>
#include <stdlib.h>
// declare global variables including linked list of blocks containing

//********************************************************************
struct node{

	int block_id;
	int starting;
	int address;
	int ending;
	struct node *next;
}*block_list = NULL;


typedef struct node block_type;
int pm_size;
int remaining;





		void Enter_Parameter() {
	// declare/initialize local variables
	// prompt for size of physical memory
			printf("Size of Physical memory: ");
			scanf("%d",&pm_size);

	// initilize remaining memory to size of physical memory
			remaining = pm_size;
	// allocate memory for linked list of blocks
			block_list = (block_type *)malloc(sizeof(block_type)); // this is to save the head, just in case if you choose to remove the actual first block and then your head pointer is gone

	// create "dummy" block with id -1, staring/ending address of 0 and
			block_list->block_id = -1;
			block_list->starting = 0;
			block_list->ending = 0;
			block_list->next = NULL;
	
	return;
	}
/********************************************************************/
// declare/initialize local variables
	void print_table() {
		block_type *current ;
	// print header of table containing fields: ID, Start, End
	// print each block in list with while-loop, loop until end of list,
		current = block_list->next;
	
		while(current!= NULL){
			printf("%d\t%d\t%d\n",current->block_id,current->starting,current->ending);
			current = current->next;
	
		}
	 
	return;
	
	}
/********************************************************************/
void First_Fit() {
// declare/initialize local variables
	int block_size;
	int id;
	block_type *new_block;
	block_type *current;
// prompt for block id & block size
	printf("Size:");
	scanf("%d",&block_size);
	printf("ID: ");
	scanf("%d",&id);

// if block size is larger than remaining memory, print message,
	if(block_size>remaining) {	//no fit
		printf("Out of memory\n");
		return;
	}
// if block list is "empty", allocate new block, set fields for new
	if(block_list->next == NULL){
		new_block = (block_type *)malloc(sizeof(block_type));
		new_block->block_id = id;
		new_block->starting = 0;
		new_block->ending = block_size;
		new_block->next = NULL;
		block_list->next = new_block;
		remaining -= block_size;
		print_table();
		return;
	}
	else{

			new_block = (block_type *)malloc(sizeof(block_type));
			current = block_list->next;

			int current_size = (current->ending)-(current->starting);
		 while((current->next !=NULL) && (current_size>=block_size)){

		 	current = current->next;


		 }

		 current->next = new_block;
		 new_block->block_id = id;
		 new_block->starting = current->ending;
		 new_block->ending = new_block->starting+block_size;
		 new_block->next = NULL;
		 remaining -= block_size;
		 print_table();
		 return;




	}
// initialize "current block" to compare hole
// while not end of list, loop
//if duplicate id, print message, return
// initialize "current block" to compare hole
// while not end of list, loop
//set values for start and end of current hole
// if block fits in hole, allocate new block,

// advance "current block" pointer
// if end of list reached, print message no fitting hole
return;
}

/***************************************************************/

void Best_Fit() {
// declare/initialize local variables
	int block_size;
	int id;
	block_type *new_block;
	block_type *current;
	block_type *best_block;
	block_type *best_block;
	int hole_size;

	int best_so_far  = pm_size; // to have the best one;

// prompt for block id & block size
	printf("Size: ");
	scanf("%d",&block_size);
	printf("ID: ");
	scanf("%d",&id);

// if block size is larger than remaining memory, print message,

	if(block_size=>remaining){

		printf("Not enough space\n");


	}

	// if block list is "empty", allocate new block, set fields for new
	if(block_list->next ==NULL){
		new_block = (block_type *)malloc(sizeof(block_type));
		new_block->block_id = id;
		new_block->starting = 0;
		new_block->ending = block_size;
		new_block->next = NULL;
		block_list->next = new_block;
		remaining -= block_size;
		print_table();

		return;
	}
	else{
		// initialize "current block" to compare hole

		new_block = (block_type *)malloc(sizeof(block_type));
			current = block_list->next;
			old = block_list;

			int current_size = (current->ending)-(current_starting);
			 			
			int compare  = (old->block_size)-size;
			hole_size = current->starting - old->ending;

			

		while((current!=NULL){

			if(hole_size>=block_size)
			{

			if(hole_size<best_so_far){
				best_so_far = hole_size;
				best_block = current;
				
			}


			}
			current = current->next;
			old = old->next;


		}

			new_block->next = best_block;
			old_block->next = new_block;

			new_block->starting = old_block->ending;
			new_blcok->ending = new_block->starting + block_size;

			new_block->id = block_id;

			

			
			remaing-=block_size;
			print_table();
			return;


	}


/*
// initialize "current block" to compare hole
// while not end of list, loop
//if duplicate id, print message, return
// initialize "current block" to compare hole
// while not end of list, loop
//set values for start and end of current hole
// if block fits in hole,
set flag "at least one" fitting hole found
// if current hole is smaller than best so
far
// set new value for "best so far",
"best start", copy "best block" to current block
//advance "current block" pointer
// if no hole was found large enough, print message, return
// allocated new block, set fields for new block, link to block
list, reduce remaining memory, print allocation table
return;
}

void "PROCEDURE FOR OPTION 4"() {
// declare/initialize local variables
// prompt for block id & block size
// if block size is larger than remaining memory, print message,
return
// if block list is "empty", allocate new block, set fields for new
block, link to block list, reduce remaining memory, print allocation
table, return
// initialize "current block" to compare hole
// while not end of list, loop
//if duplicate id, print message, return
// initialize "current block" to compare hole
// while not end of list, loop
//set values for start and end of current hole
// if block fits in hole,
set flag "at least one" fitting hole found
// if current hole is larger than worst so
far
// set new value for "worst so far",
"worst start", copy "worst block" to current block
//advance "current block" pointer
// if no hole was found large enough, print message, return
// allocated new block, set fields for new block, link to block
list, reduce remaining memory, print allocation table
return;
}

void dealloacate() {
// declare/initialize local variables
	int id;
	int block_size;
	block_type	*current_block = block_list;
	block_type	*previous_block;

// prompt for block id

	printf("Give a block id\n");
	scanf();
	printf("Block size\n");
	scanf();



// initialize "current block"
// while id not found and end of block list not reached
	while((current_block!=null)&&(block_id !=current->block_id){

		current_block = current_block->next;
		previous_block = current_block;
		current_block = current_block->next;
		
	}

	if(current_block ==NULL){
		printf("..");
		return;
	}

	previous_block->next = current_block->next;
	block_size = current_block->ending - current_starting;

	remaining += block_size;
	free(current_block);

// advance "previous block" pointer and "current block"
pointer
// if "current block" is NULL, print message id not found
// else remove block, adjusting "previous block" pointer around it,
increment remaining memory with block size, free block with matching id,
print allocation table
return;
}
void compaction() {
// declare/initialize local variables
// initialize "current block"
	block_type	*current_block = block_list;
	int previous_ending=0;

// while end of block list not reached
	while(current_block !=NULL){
		block_size = current_block->ending - current_block->starting;
		current_block->starting = previous_ending;
		current_block->ending = current_block->starting + block_size;
		previous_end = current_block->ending;
		current_block = current_block->next;

	}
// adjust start and end fields of each block, compacting
together
//print allocation table
return;
}

void free_memory(block_type *node) {
// if node is NULL return
// else call self on link field of node, free node
	if(node == NULL){

		return;
	}
	free(node);
	node = node->next;
	free_memory(node);


return;
}
//*************************************************************/
int main() {
// declare local vars
// while user has not chosen to quit
// print menu of options
// prompt for menu selection
// call appropriate procedure based on choice--use switch
 // indicates success
// end of procedure
	Enter_Parameter();
	First_Fit();
	First_Fit();
}