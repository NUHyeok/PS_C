int hIndex(int* citations, int citationsSize) {
    int left = 0;
    int right = citationsSize - 1;
    int ans = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        int candidate = citationsSize - mid;

        if(candidate <= citations[mid]) {
            ans = candidate;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}