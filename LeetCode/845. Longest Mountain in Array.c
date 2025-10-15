int longestMountain(int* arr, int arrSize) {
    int max = 0;
    for(int i = 1; i < arrSize-1; i++){
        int cnt = 0;
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            cnt = 3;
            for(int j = i-1; j >= 1; j--){
                if(arr[j] > arr[j-1]) cnt++;
                else break;
            }
            for(int j = i+1; j < arrSize-1; j++){
                if(arr[j] > arr[j+1]) cnt++;
                else break;
            }
        }

        if (cnt > max) max = cnt;
    }
    return max;
}