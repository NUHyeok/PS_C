int longestMountain(int* arr, int arrSize) {
    int max_len = 0;
    for(int i = 1; i < arrSize-1; i++){
        int left = i;
        int right = i;
        if(arr[left] > arr[left-1] && arr[right] > arr[right+1]){
            while(left > 0 && arr[left] > arr[left-1]) left--;
            while(right < arrSize-1 && arr[right] > arr[right+1]) right++;

            int len = right - left + 1;
            if(max_len < len) max_len = len;
        }
    }
    return max_len;
}