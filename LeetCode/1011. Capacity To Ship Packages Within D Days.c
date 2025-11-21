int shipWithinDays(int* weights, int weightsSize, int days) {
    int ans = -1;
    int left = 0;
    int right = 0;

    for(int i = 0; i < weightsSize; i++){
        if(weights[i] > left) left = weights[i];
        right += weights[i];
    }

    while(left <= right){
        int mid = (left + right) / 2;
        int is = 1;
        int d = 1;
        int sum = 0;
        for(int i = 0; i < weightsSize; i++){
            if(sum + weights[i] <= mid) sum += weights[i];
            else{
                d++;
                sum = weights[i];
            }
            

            if(d > days) {
                is = 0;
                break;
            }
        }

        if(is){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }

    }
    return ans;
}