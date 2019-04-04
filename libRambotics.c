#include <kipr/botball.h>

#include "libRambotics.h"

int armMoveTo(int dest, int hold, int overshoot, int debug){
	int currentPos = analog(0);
    int distanceToDest = 0;
    int distanceNorm = 0;
    printf("Destination value: %d\n", dest);
    printf("Holding at end?: %d\n", hold);
    printf("Overshoot value: %d\n", overshoot);
    printf("Debug mode?: %d\n", debug);
  	//Check if value is within range
    if(dest > 4050 || dest < 50){
    	printf("Invalid Value!\n");
    	return(1);
    }
 	printf("Value OK\n");
    //How far to destination?
    distanceToDest = dest - currentPos;
    //Move the arm
    printf("Starting moving\n");
    while(abs(distanceToDest) > 20){
    	currentPos = analog(0);
        distanceToDest = dest - currentPos;
        //Turn distance into speed value for motor and set min speed
    	distanceNorm = distanceToDest / 40;
    	if(abs(distanceNorm) < 20){
            if(distanceNorm < 0){
            	distanceNorm = -20;
            }
            else{
                distanceNorm = 20;
            }
        }
        //Show speed and distance for debugging
        if(debug == 1){
        printf("%d\n", distanceToDest);
        printf("%d\n", distanceNorm);
        }
        //Move the motor
        motor(0, (distanceNorm*-1);    
    }
    if(overshoot != 0){
    	printf("Overshooting- be careful!\n");
        mrp(0, 50, overshoot);
        msleep(500);
    }
    if(hold == 1){
        mav(0, 0);
        return(0);
    }
    else{
        ao();
        return(0);
    }
}

