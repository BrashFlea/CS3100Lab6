/*
	Jonathan Mirabile
	CS3100
	Lab 6 - Disk Scheduling
*/

#include <stdio.h>
#include <stdlib.h>

void usage(){
    printf("Usage: ./disksked START T1 T2 T3 T4 T5 T6 T7 T8\n");
}

int main(int argc, char *argv[]){
    if(argc != 10){
        usage();
        return 1;
    }

    int Start = atoi(argv[1]);
    int tracks[8];
    int distance[9];
    int Total = 0;

    int scan_tracks[8];
    int scan_total = 0;
    int scan_index = -1;
    int temp = 0;

    int cscan_tracks[8];
    int cscan_total = 0;
    int cscan_index = -3;
    int ctemp = 0;

    //FCFS
    for(int i = 0; i < 8; i++) {
        tracks[i] = atoi(argv[i + 2]);
    }
    distance[0]  = abs(Start - tracks[0]);

    for(int i = 1; i < 9; i++) {
        distance[i] = abs(tracks[i-1] - tracks[i]);
    }

    for(int i = 0; i < 8; i++) {
        Total += distance[i];
    }

    //FCFS Print Function
    printf("FCFS: Start:%i", Start);
    for(int i = 0; i < 8; i++){
        printf(" %i:%i", tracks[i], distance[i]);
    }
    printf(" Total:%i\n", Total);

    //SCAN
    printf("SCAN: Start:%i", Start);

    for (int i = 0; i < 8; i++) {
        scan_tracks[i] = tracks[i];
    }

    //Sort tracks
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if(scan_tracks[j] > scan_tracks[j+1]){
                temp = scan_tracks[j];
                scan_tracks[j] = scan_tracks[j + 1];
                scan_tracks[j + 1] = temp;
            }
        }
    }

    /*printf("\nscan_tracks: ");
    for (int i = 0; i < 8; i++) {
        printf("%i:%i ", i, scan_tracks[i]);
    }
    printf("\n");*/

    for (int i = 1; i < 8; i++) {
        if((scan_tracks[i-1] < Start) && (Start <= scan_tracks[i])){
            scan_index = i;
        }
    }
    //printf("scan_index is: %i\n",scan_index);

    if (scan_index != -1) {
        //Collect the Start and first index values
        printf(" %i:%i ", scan_tracks[scan_index], abs(Start - scan_tracks[scan_index]));
        //Traverse values higher than the index
        scan_total += abs(Start - scan_tracks[scan_index]);
        for (int i = (scan_index + 1); i < 8; i++) {
            printf("%i:%i ", scan_tracks[i], abs(scan_tracks[i-1] - scan_tracks[i]));
            scan_total += abs(scan_tracks[i-1] - scan_tracks[i]);
        }
        //Wrap around to the beginning of the array
        printf("%i:%i ", scan_tracks[0], abs(scan_tracks[0] - scan_tracks[7]));
        scan_total += abs(scan_tracks[0] - scan_tracks[7]);
        //Process values from the start to the index
        for (int i = 1; i < scan_index; i++) {
            printf("%i:%i ", scan_tracks[i], abs(scan_tracks[i-1] - scan_tracks[i]));
            scan_total += abs(scan_tracks[i-1] - scan_tracks[i]);
        }
        printf("Total:%i\n", scan_total);
    } else {
        //Start is at beginning of array
        printf(" %i:%i ", scan_tracks[0], abs(Start - scan_tracks[0]));
        scan_total += abs(Start - scan_tracks[0]);
        for (int i = 1; i < 8; i++) {
            printf("%i:%i ", scan_tracks[i], abs(scan_tracks[i-1] - scan_tracks[i]));
            scan_total += abs(scan_tracks[i-1] - scan_tracks[i]);
        }
        printf("Total:%i\n", scan_total);
    }

    //CSCAN
    printf("C_SCAN: Start:%i", Start);

    for (int i = 0; i < 8; i++) {
        cscan_tracks[i] = tracks[i];
    }

    //Sort tracks
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if(cscan_tracks[j] > cscan_tracks[j+1]){
                ctemp = cscan_tracks[j];
                cscan_tracks[j] = cscan_tracks[j + 1];
                cscan_tracks[j + 1] = ctemp;
            }
        }
    }

    /*printf("\ncscan_tracks: ");
    for (int i = 0; i < 8; i++) {
        printf("%i:%i ", i, cscan_tracks[i]);
    }
    printf("\n");*/

    if(Start > cscan_tracks[7]) {
        cscan_index = -1;
    } else if(Start < cscan_tracks[7]) {
        cscan_index = -2;
    }

    for (int i = 1; i < 8; i++) {
        if((cscan_tracks[i-1] < Start) && (Start <= cscan_tracks[i])){
            cscan_index = i;
        }
    }
    //printf("cscan_index is: %i\n",cscan_index);

    if (cscan_index == -1) {
        //Process from the end of the array to the beginning
        printf(" %i:%i ", cscan_tracks[7], abs(Start - cscan_tracks[7]));
        cscan_total += abs(Start - cscan_tracks[7]);
        for (int i = 6; i >= 0; i--) {
            printf("%i:%i ", cscan_tracks[i], abs(cscan_tracks[i + 1] - cscan_tracks[i]));
            cscan_total += abs(cscan_tracks[i + 1] - cscan_tracks[i]);
        }
        printf("Total:%i\n", cscan_total);
    }

    if (cscan_index == -2) {
        //Process the beginning of array
        printf(" %i:%i ", cscan_tracks[0], abs(Start - cscan_tracks[0]));
        cscan_total += abs(Start - cscan_tracks[0]);
        for (int i = 1; i < 8; i++) {
            printf("%i:%i ", cscan_tracks[i], abs(cscan_tracks[i - 1] - cscan_tracks[i]));
            cscan_total += abs(cscan_tracks[i - 1] - cscan_tracks[i]);
        }
        printf("Total:%i\n", cscan_total);

    }

    else if (cscan_index != -1) {
        //Collect the Start and first index values
        printf(" %i:%i ", cscan_tracks[cscan_index], abs(Start - cscan_tracks[cscan_index]));
        //Traverse values higher than the index
        cscan_total += abs(Start - cscan_tracks[cscan_index]);
        for (int i = (cscan_index + 1); i < 8; i++) {
            printf("%i:%i ", cscan_tracks[i], abs(cscan_tracks[i - 1] - cscan_tracks[i]));
            cscan_total += abs(cscan_tracks[i - 1] - cscan_tracks[i]);
        }
        //Wrap around to the beginning of the array
        printf("%i:%i ", scan_tracks[cscan_index - 1], abs(scan_tracks[cscan_index - 1] - scan_tracks[7]));
        cscan_total += abs(cscan_tracks[cscan_index - 1] - cscan_tracks[7]);
        //Process smaller values in descending order
        for (int i = cscan_index - 2; i >= 0; i--) {
            printf("%i:%i ", cscan_tracks[i], abs(cscan_tracks[i + 1] - cscan_tracks[i]));
            cscan_total += abs(cscan_tracks[i + 1] - cscan_tracks[i]);
        }
        printf("Total:%i\n", cscan_total);
    }


    return 0;
}
