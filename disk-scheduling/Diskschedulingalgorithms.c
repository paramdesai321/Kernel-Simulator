#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Declare global variables, including dynamic array to store sequence of traversed tracks
int *sequence = NULL;
int sequence_size;
int quit =0;
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
	int start_track;

    
	
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
	
	printf("Starting track:");
	scanf("%d",&sequence[0]);
	
	printf("Enter the sequence of tracks to seek: ");

	for(int i=1;i<=sequence_size;i++){
		scanf("%d",&sequence[i]);


	}

	printf("Traverse Sequence from track %d:",sequence[0]);


	
	for(int i=1;i<=sequence_size;i++){
		// calculate total distance of traversed tracks
		num_traversed += abs(sequence[i]-sequence[i-1]);
		// print sequence of traversal
			printf("%d ",sequence[i]);

	}		

	
	printf("\n");

	printf("The distance of the traversed trackes from track %d:%d\n",sequence[0],num_traversed);
	// print total distance of tracks traversed
	return;
// "OPTION #2"	
}


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
    printf("\nEnter starting track: ");
    scanf("%d", &sequence[0]);

	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"
    printf("\nEnter sequence of tracks to seek:");
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
                   
                    closest_track = i;
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
        
        current = sequence[closest_track];
        printf("%d ",current);
    }
  	// print total distance traversed
  	printf("\n");
    printf("The num of track traversed:%d \n", num_traversed);

	return;

} // "OPTION #3" 


void scan() {

	// declare local variables
	int num_traversed = 0;
	int at_least_one;
	int shortest_distance;
	int closest_track;
	int direction;
	int current;
	int num_done =0;
	int *done = (int *)calloc(sequence_size, sizeof(int)); // Allocates and clears all to 0

	// prompt for starting track, store in index 0
	 printf("\nEnter starting track: ");
    scanf("%d", &sequence[0]);

	// prompt for sequence of tracks to seek, store in index 1 to "sequence size"


	 printf("\nEnter sequence of tracks to seek: ");
	for (int i = 1; i <= sequence_size; i++)
    {
        scanf("%d", &sequence[i]);
    }
	//prompt for initial direction (0=descreasing, 1=increasing)
	printf("\n");
	printf("Provide the Initial direction:");
	scanf("%d",&direction);
	// initialize current track and distance traversed to starting track
	current = sequence[0];
	
	// begin printing sequence of traversal 
	printf("Traversed Sequence from track %d: ", sequence[0]);

	// until every track is traversed
	while(num_done < sequence_size){
		at_least_one=0;
		shortest_distance = INT_MAX;
		// initilize shortest distance to INT_MAX
		// for each track in sequence
		for(int i=1;i<=sequence_size;i++){
			// if not already traversed
				//if distance to traverse is shorter than current shortest distance in the current direction
		if(done[i]==0){
		if(abs(sequence[i]-current)< shortest_distance){
				if(((sequence[i] >current) && (direction==1))||((sequence[i]<current)&&(direction==0))){
					// set current shortest distance and index of the track	w/ shortest distance
					shortest_distance = abs(current-sequence[i]);
					closest_track = i;
					// set flag that at least one track was traversed
					at_least_one = 1;


				}

    		}
		
		}//for
			} 		

			// if at least one track was traversed
			if(at_least_one==1){
				// if at least one track was traversed
    			// set "done" value for track w/shortest distance to 1 (mark as traversed)
    			
			// increment number of traversed tracks
    			num_traversed  += shortest_distance;
			// update total distance traversed

			//set current track to new position, print position
			num_done++;
    			current = sequence[closest_track];
    			done[closest_track] = 1;
                printf("%d ",current);

			}
			else{ // else change direction
				direction = 1-direction; // change the direction
			}
			

			}	
     					
		
		
 	// print total distance traversed
 		printf("\n");
    printf("The num of track traversed:%d \n", num_traversed);

	return;
} // "OPTION #4"



void c_scan() {
	// declare local variables
	int end_reached = 0;
	int num_traversed = 0;
	int at_least_one;
	int shortest_distance;
	int closest_track;
	int direction;
	int current;
	int num_done =0;
	int *done = (int *)calloc(sequence_size, sizeof(int)); // Allocates and clears all to 0
	// prompt for starting track, store in index 0
	// prompt for sequence of tracks to seek, store in
	 printf("\nEnter starting track: ");
    scanf("%d", &sequence[0]);
    
    printf("Enter the sequence of tracks to seek starting from track %d:",sequence[0]);

    for (int i = 1; i <= sequence_size; i++)
    {
        scanf("%d", &sequence[i]);
    }

	// initialize current track and number traversed to starting track
	
	current = sequence[0];

	// begin printing sequence of traversal 
		printf("Traversed Sequence from track %d: ", sequence[0]);
	// until every track is traversed
	while(num_done < sequence_size){
		// initilize shortest distance to INT_MAX
		shortest_distance= INT_MAX;
		at_least_one=0;
		// for each track in sequence

		for(int i=1;i<=sequence_size;i++){
			// if not already traversed
			if(done[i]==0){
				//if distance to traverse is shorter than current shortest distance and a positive value (only increasing direction)
			
			if(((sequence[i]-current)<shortest_distance)&& (sequence[i]>current)){

					// set current shortest distance and index of the track	w/ shortest distance
				closest_track =i;
				shortest_distance = sequence[i]-current;
     					// set flag that at least one track was traversed
				at_least_one =1;

			} // if shorter distance and upward direction 
			
			// for
		}
		}

		// if at least one track was traversed
			if(at_least_one==1){

    			// set "done" value for track w/shortest distance to 1 (mark as traversed)
    			done[closest_track] =1;
    			// increment number of tracks that have been traversed
    			num_done++;
    			// if largest track was reached
    			if(end_reached==1){

    					// update total distance traversed by derementing by distance to track (subtracts distance from 0 to track)
    				num_traversed -= shortest_distance;
    				
    				// reset "largest track" flag
    				end_reached = 0;

    			}
			
			else{// else
				// update total distance traversed by distance to track

			//set current track to new position, print position
				num_traversed += shortest_distance;
				}
				current = sequence[closest_track];
				printf("%d ",current);

			}
			
			// else (no track was traversed)
			else{ // the else for the at_least_one is 0 
				
					// update total distance by current track (adds remaining distance before going back to 0)
				end_reached = 1;
				num_traversed  += current;
        		current = 0;

                
			// reset current track to 0 (loop back around)
			
			}
			
			
				
		}	
		printf("\n");
			printf("The num of track traversed: %d\n",num_traversed);
				
			
			// set "end reached" flag to 1
 	// print total distance traversed
	return;    
} // "OPTION #5





void Quit(){
    
    
    if(sequence != NULL){
        free(sequence);
        sequence = NULL;
        
        
        
    }
    quit=1;
    printf("bye");
    return;
    
}


/***************************************************************/
int main() {
	// declare local vars
	// while user has not chosen to quit
		// print menu of options
		// prompt for menu selection
	int choice;

	while(quit==0){

		printf("1)Enter Parameter\n");
		printf("2)Calculate distance to traverse tracks using FIFO\n");
		printf("3) Calculate distance to traverse tracks using SSTF\n");
		printf("4) Calculate distance to traverse tracks using Scan\n");
		printf("5) Calculate distance to traverse tracks using C-Scan\n");
		printf("6) Quit program and free memory\n");
		printf("Enter Selection: ");
		scanf("%d",&choice);


		switch(choice){

		case 1:
			Enter_Parameters();
			break;
		case 2:
			FIFO();
			break;
		case 3:
			sstf();
			break;
		case 4:
			scan();
			break;
		case 5:
			c_scan();
			break;
		case 6:
			Quit();
			break;
		default:
			printf("Invalid Input, select again\n");

	

		}
	}
	


			// call appropriate procedure based on choice--use switch statement or series of if, else if, else statements
	return 1; // indicates success
} // main	