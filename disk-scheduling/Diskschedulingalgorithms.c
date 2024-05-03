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
// Shortest Seek Time First
void sstf() {
	// declare local variables
    int current;
    int num_traversed = 0;
    int num_done = 0;
    int shortest_distance;
    int *done = (int *)calloc(sequence_size, sizeof(int)); // Allocates and clears all to 0
    int closest_track;

	// prompt for starting track, store in index 0
    printf("\nEnter starting track");
    printf("%d", &sequence[0]);

	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
    printf("\nEnter sequence of tracks to seek");
	for (int i = 1; i <= sequence_size; i++)
    {
        scanf("%d", &sequence[i]);
    }

	// initialize current track and distance traversed to starting track   
    current = sequence[0];
    
	// begin printing sequence of traversal 
    printf("Traversed Sequence from track %d: ", sequence[0]);

	// until every track is traversed
    while(num_done < sequence_size)
    {
		// initilize shortest distance to INT_MAX
        shortest_distance = INT_MAX;

		// for each track in sequence
        for(int i = 1; i <= sequence_size; i++)
        {
			// if not already traversed
            if(done[i] == 0)
            {
				//if distance to traverse is shorter than current shortest distance
                if(abs(sequence[i] - current) < shortest_distance)
                {
					// set current shortest distance and index of the track	w/ shortest distance
                    shortest_distance = abs(sequence[i] - current);
                    closest_track = sequence[i];
                }
            }
        }
		// set "done" value for track w/shortest distance to 1 (mark as traversed)
        done[closest_track] = 1;

		// increment number of tracks that have been traversed
        num_done ++;

		// update total distance traversed
        num_traversed += shortest_distance;

		//set current track to new position, print position
        current = closest_track;
        
        printf("%d",&closest_track);
    }
  	// print total distance traversed
    printf("%d", &num_traversed);

	return;

} // "OPTION #3" 



/*********************************************************/
void scan() {

	// declare local variables
	int num_traversed = 0;
	int at_least_one;
	int shortest_distance;
	int closest_track;

	// prompt for starting track, store in index 0
	 printf("\nEnter starting track");
    printf("%d", &sequence[0]);

	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
	//prompt for initial direction (0=descreasing, 1=increasing)
	printf("Provide the Initial ")
	// initialize current track and distance traversed to starting track
	// begin printing sequence of traversal 
	// until every track is traversed
	while(num_done < sequence_size){
		at_least_one=0;
		// initilize shortest distance to INT_MAX
		// for each track in sequence
			// if not already traversed
				//if distance to traverse is shorter than current shortest distance in the current direction
		if(abs(sequence[i]-current)< shortest_distance){
				if(((sequence[i] >current) && (direction==1))||((sequence[i]<current)&&(direction==0))){
					// set current shortest distance and index of the track	w/ shortest distance
					shortest_distance = abs(current-sequence[i]);
					closest_track = sequence[i];
					// set flag that at least one track was traversed
					at_least_one = 1;


				}

		}//for

			// if at least one track was traversed
			if(at_least_one==1){
				// if at least one track was traversed
    			// set "done" value for track w/shortest distance to 1 (mark as traversed)
			// increment number of traversed tracks
			// update total distance traversed
			//set current track to new position, print position


			}
			else{ // else change direction
				direction = 1-direction; // change the direction
			}

			}	
     					
		
		
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