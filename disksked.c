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


    printf("Start is at: %i\n",Start);
    for(int i = 0; i < 8; i++) {
        tracks[i] = atoi(argv[i + 2]);
        printf("Loaded Track: %i\n",tracks[i]);
    }

    distance[0]  = abs(Start - tracks[0]);
    printf("Initial starting distance: %i\n", distance[0]);

    for(int i = 1; i < 9; i++) {
        printf("Comparing Tracks: %i and %i\n",tracks[i], tracks[i+1]);
        distance[i] = abs(tracks[i-1] - tracks[i]);
        printf("Distance right now: %i\n", distance[i]);
    }

    for(int i = 0; i < 8; i++) {
        Total += distance[i];
        printf("Total right now: %i\n", Total);
    }

    printf("FCFS: Start:%i", Start);
    for(int i = 0; i < 8; i++){
        printf(" %i:%i", tracks[i], distance[i]);
    }
    printf(" Total:%i\n", Total);

    /*printf("FCFS: Start:%i %i:%i %i:%i %i:%i %i:%i %i:%i %i:%i %i:%i %i:%i Total:%i\n",
           Start, T1, D1, T2, D2, T3, D3, T4, D4, T5, D5, T6, D6, T7, D7, T8, D8, Total);*/

    return 0;
}
