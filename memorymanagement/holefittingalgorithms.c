#include <stdio.h>
#include <stdlib.h>
// declare global variables including linked list of blocks containing
id, starting address, ending address, link to next node in list
//********************************************************************
struct node{

	int block_id;
	int starting;
	int address;
	int ending;
	struct node *next;
}*block_list = NULL;

		void "PROCEDURE FOR OPTION 1"() {
	// declare/initialize local variables
	// prompt for size of physical memory
	// initilize remaining memory to size of physical memory
	// allocate memory for linked list of blocks
	// create "dummy" block with id -1, staring/ending address of 0 and
	link of NULL
	return;
	}
/********************************************************************/
void "PROCEDURE TO PRINT ALLOCATION TABLE"() {
// declare/initialize local variables
// print header of table containing fields: ID, Start, End
// print each block in list with while-loop, loop until end of list,
advancing "current block" pointer
return;
}
/********************************************************************/
void "PROCEDURE FOR OPTION 2"() {
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
// if block fits in hole, allocate new block,
set fields for new block, link to block list, reduce remaining memory,
print allocation table, return
// advance "current block" pointer
// if end of list reached, print message no fitting hole
return;
}
/***************************************************************/
void "PROCEDURE FOR OPTION 3"() {
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
/***************************************************************/
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
/********************************************************************/
void "PROCEDURE FOR OPTION 5"() {
// declare/initialize local variables
// prompt for block id
// initialize "current block"
// while id not found and end of block list not reached
// advance "previous block" pointer and "current block"
pointer
// if "current block" is NULL, print message id not found
// else remove block, adjusting "previous block" pointer around it,
increment remaining memory with block size, free block with matching id,
print allocation table
return;
}
/********************************************************************/
void "PROCEDURE FOR OPTION 6"() {
// declare/initialize local variables
// initialize "current block"
// while end of block list not reached
// adjust start and end fields of each block, compacting
together
//print allocation table
return;
}
/********************************************************************/
void "RECURSIVE PROCEDURE FOR OPTION 7"(block_type *node) {
// if node is NULL return
// else call self on link field of node, free node
return;
}
//*************************************************************
int main() {
// declare local vars
// while user has not chosen to quit
// print menu of options
// prompt for menu selection
// call appropriate procedure based on choice--use switch
statement or series of if, else if, else statements
} // while loop
return 1; // indicates success
} // end of procedure