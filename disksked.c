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

    /*int sstf_tracks[8];
    int sstf_tracks_ordered[8];
    int sstf_distance = 0;
    int sstf_current_dist = 257;
    int sstf_next = 0;
    int sstf_start = -1;*/

    int scan_tracks[9];
    int scan_total = 0;
    int scan_distance[8];
    int scan_counter = 8;
    int scan_current_dist = 257;
    int scan_next = 0;
    int scan_index = -1;
    int temp = 0;

    //printf("Start is at: %i\n",Start);
    for(int i = 0; i < 8; i++) {
        tracks[i] = atoi(argv[i + 2]);
        //printf("Loaded Track: %i\n",tracks[i]);
    }

    distance[0]  = abs(Start - tracks[0]);
    //printf("Initial starting distance: %i\n", distance[0]);

    for(int i = 1; i < 9; i++) {
        //printf("Comparing Tracks: %i and %i\n",tracks[i-1], tracks[i]);
        distance[i] = abs(tracks[i-1] - tracks[i]);
        //printf("Distance right now: %i\n", distance[i]);
    }

    for(int i = 0; i < 8; i++) {
        Total += distance[i];
        //printf("Total right now: %i\n", Total);
    }

    //FCFS Print Function
    printf("FCFS: Start:%i", Start);
    for(int i = 0; i < 8; i++){
        printf(" %i:%i", tracks[i], distance[i]);
    }
    printf(" Total:%i\n", Total);


    //SSTF WIP
    /*for (int i = 0; i < 8; i++) {
        sstf_tracks[i] = tracks[i];
    }

    printf("Start track: %i\n", Start);
    for (int i = 0; i < 8; i++) {
        sstf_distance = abs(Start - sstf_tracks[i]);
        if (sstf_distance < sstf_current_dist){
            sstf_current_dist = sstf_distance;
            sstf_next = sstf_tracks[i];
        }
    }
    printf("Next track to move to: %i\n", sstf_next);

    for (int j = 0; j < 8; j++){
        printf("Currently on track: %i\n", sstf_tracks[j]);
        for (int i = 0; i < 8; i++) {
            sstf_distance = abs(sstf_tracks[j] - sstf_tracks[i]);
            //printf("Comparing tracks: %i and %i\n", sstf_tracks[j], sstf_tracks[i]);
            if (sstf_distance < sstf_current_dist){
                sstf_current_dist = sstf_distance;
                sstf_next = sstf_tracks[j];
            }

        }
        //printf("Next track to move to: %i\n", sstf_next);
        sstf_tracks_ordered[j] = sstf_next;
    }*/

    printf("SCAN: Start:%i", Start);

    for (int i = 0; i < 8; i++) {
        scan_tracks[i] = tracks[i];
    }

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
        //Print values from the start to the index
        scan_total += abs(scan_tracks[0] - scan_tracks[7]);
        for (int i = 1; i < scan_index; i++) {
            printf("%i:%i ", scan_tracks[i], abs(scan_tracks[i-1] - scan_tracks[i]));
            scan_total += abs(scan_tracks[i-1] - scan_tracks[i]);
        }
        printf("Total:%i\n", scan_total);
    } else {
        printf(" %i:%i ", scan_tracks[0], abs(Start - scan_tracks[0]));
        scan_total += abs(Start - scan_tracks[0]);
        for (int i = 1; i < 8; i++) {
            printf("%i:%i ", scan_tracks[i], abs(scan_tracks[i-1] - scan_tracks[i]));
            scan_total += abs(scan_tracks[i-1] - scan_tracks[i]);
        }
        printf("Total:%i\n", scan_total);
    }



    
return 0;
}
