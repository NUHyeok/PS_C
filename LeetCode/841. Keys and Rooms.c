int checked[1000];

void dfs(int** rooms, int roomsSize, int* roomsColSize, int room_nums){
    if(checked[room_nums]) return;

    checked[room_nums] = 1;

    for(int i = 0; i < roomsColSize[room_nums]; i++) {
        dfs(rooms, roomsSize, roomsColSize, rooms[room_nums][i]);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    memset(checked, 0, sizeof(checked));
    dfs(rooms, roomsSize, roomsColSize, 0);

    for(int i = 0; i < roomsSize; i++){
        if(!checked[i]) return false;
    }
    
    return true;
}