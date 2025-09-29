// O(N^2)
/*
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    if(gasSize != costSize) return -1;

    for(int i = 0; i < gasSize; i++){
        int g = i, c = i;
        int is = 1;
        int tank = gas[g];

        for(int k = 0; k < gasSize -1; k++){
            g += 1;
            if(g == gasSize) g = 0;
            tank = tank - cost[c] + gas[g];
            if (tank < 0) {
                is = 0;
                break;
            }
            c += 1;
            if(c == costSize) c = 0;
        }

        if(is) {
            if(tank - cost[c] >= 0) return i;
        }
    }



    return -1;
}
*/

// O(N)

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total_tank = 0;
    int current_tank = 0;
    int start_station = 0;
    
    for(int i = 0; i < gasSize; i++){
        current_tank += gas[i] - cost[i];
        total_tank += gas[i] - cost[i];

        if(current_tank < 0){
            current_tank = 0;
            start_station = i+1;
        }
    }

    if (total_tank < 0) return -1;
    else return start_station;
}