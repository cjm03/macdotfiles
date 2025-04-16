/*
    WORKING
*/


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int k = m + n - 1;
    m --;
    n --;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            nums1[k--] = nums1[m--];
        }
        nums1[k--] = nums2[n--];
    }
}

