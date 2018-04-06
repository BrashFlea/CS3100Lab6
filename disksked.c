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

    //int start = atoi(argv[1])
    //int tracks[8]
    //for(int i = 0; i < 8; i++)
    //tracks[i]=atoi(argv[i+2])

    int Start = atoi(argv[1]);
    int T1 = atoi(argv[2]);
    int T2 = atoi(argv[3]);
    int T3 = atoi(argv[4]);
    int T4 = atoi(argv[5]);
    int T5 = atoi(argv[6]);
    int T6 = atoi(argv[7]);
    int T7 = atoi(argv[8]);
    int T8 = atoi(argv[9]);

    //FCFS
    int D1 = abs(Start - T1);
    int D2 = abs(T1 - T2);
    int D3 = abs(T2 - T3);
    int D4 = abs(T3 - T4);
    int D5 = abs(T4 - T5);
    int D6 = abs(T5 - T6);
    int D7 = abs(T6 - T7);
    int D8 = abs(T7 - T8);
    int Total = D1 + D2 + D3 + D4 + D5 + D6 + D7 + D8;

    printf("FCFS: Start:%i %i:%i %i:%i %i:%i %i:%i %i:%i %i:%i %i:%i %i:%i Total:%i\n",
           Start, T1, D1, T2, D2, T3, D3, T4, D4, T5, D5, T6, D6, T7, D7, T8, D8, Total);

    return 0;
}
