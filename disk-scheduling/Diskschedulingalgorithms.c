#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Declare global variables, including dynamic array to store sequence of traversed tracks
int *sequence = NULL;
int sequence_size;

/*********************************************************/
void Enter_Parameters() {
	// prompt for the sequence size
	printf("Sequence size:");
	scanf("%d",&sequence_size);
	// allocate memory for the sequence of traversed tracks
	sequence= (int *)malloc((sequence_size+1)*sizeof(int));

  return;
} // "OPTION #1"


/*********************************************************/
void FIFO() {
	// declare local variables
	// prompt for starting track, store in index 0	
	int num_traversed =0; // the counter 


	
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
	printf("Starting track:");
	scanf("%d",&sequence[0]);

	for(int i=0;i<=sequence_size;i++){
		scanf("..");


	}
	printf("Traversed Sequence from track %d:",sequence[0]);


	// calculate total distance of traversed tracks
	for(int i=0;i<sequence_size;i++){
		num_traversed += abs(sequence[i]-sequence[i-1];
			printf("%d",...);

	}		

	
	// print sequence of traversal

	printf()
	// print total distance of tracks traversed
	return;
// "OPTION #2"	
}

/*********************************************************/
void "OPTION #3"() {
	// declare local variables
	// prompt for starting track, store in index 0
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
	// initialize current track and distance traversed to starting track   
	// begin printing sequence of traversal 
	// until every track is traversed
		// initilize shortest distance to INT_MAX
		// for each track in sequence
			// if not already traversed
				//if distance to traverse is shorter than current shortest distance
					// set current shortest distance and index of the track	w/ shortest distance
		// set "done" value for track w/shortest distance to 1 (mark as traversed)
		// increment number of tracks that have been traversed
		// update total distance traversed
		//set current track to new position, print position
  	// print total distance traversed
	return;

} // "OPTION #3" 


/*********************************************************/
void "OPTION #4"() {

	// declare local variables
	// prompt for starting track, store in index 0
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
	//prompt for initial direction (0=descreasing, 1=increasing)
	// initialize current track and distance traversed to starting track
	// begin printing sequence of traversal 
	// until every track is traversed
		// initilize shortest distance to INT_MAX
		// for each track in sequence
			// if not already traversed
				//if distance to traverse is shorter than current shortest distance in the current direction
					// set current shortest distance and index of the track	w/ shortest distance
     					// set flag that at least one track was traversed
		// if at least one track was traversed
    			// set "done" value for track w/shortest distance to 1 (mark as traversed)
			// increment number of traversed tracks
			// update total distance traversed
			//set current track to new position, print position
		// else change direction
 	// print total distance traversed
	return;
} // "OPTION #4"


/*********************************************************/
void "OPTION #5"() {
	// declare local variables
	// prompt for starting track, store in index 0
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
	// initialize current track and number traversed to starting track
	// begin printing sequence of traversal 
	// until every track is traversed
		// initilize shortest distance to INT_MAX
		// for each track in sequence
			// if not already traversed
				//if distance to traverse is shorter than current shortest distance and a positive value (only increasing direction)
					// set current shortest distance and index of the track	w/ shortest distance
     					// set flag that at least one track was traversed
		// if at least one track was traversed
    			// set "done" value for track w/shortest distance to 1 (mark as traversed)
			// increment number of tracks that have been traversed
			// if largest track was reached
				// update total distance traversed by derementing by distance to track (subtracts distance from 0 to track)
				// reset "largest track" flag
			// else
				// update total distance traversed by distance to track
			//set current track to new position, print position
		// else (no track was traversed)
			// update total distance by current track (adds remaining distance before going back to 0)
			// reset current track to 0 (loop back around)
			// set "end reached" flag to 1
 	// print total distance traversed
	return;    
} // "OPTION #5


/***************************************************************/
void "OPTION #6"() {
	// if sequence is not NULL, free sequence
	return;
} // "OPTION #6


/***************************************************************/
int main() {
	// declare local vars
	// while user has not chosen to quit
		// print menu of options
		// prompt for menu selection
		// call appropriate procedure based on choice--use switch statement or series of if, else if, else statements
	return 1; // indicates success
} // main	