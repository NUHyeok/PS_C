void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0, j = 0;
    int *A = (int *)malloc((m+n) * sizeof(int));

    for(int k = 0; k < m+n; k++){
        if(i == m){
            for(int z = k; z < m+n; z++){
                A[z] = nums2[j];
                j++;
            }
            break;
        }
        else if(j == n){
            for(int z = k; z < m+n; z++){
                A[z] = nums1[i];
                i++;
            }
            break;
        }
        else if(nums1[i] < nums2[j]){
            A[k] = nums1[i];
            i++;
        }
        else{
            A[k] = nums2[j];
            j++;
        }
    }
    for(int k = 0; k < nums1Size; k++){
        nums1[k] = A[k];
    }
}