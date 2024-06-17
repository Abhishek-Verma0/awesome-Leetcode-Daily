// here we will find the sum of continuous subarray sum means 
/*
 A number will be given we need to find that the that number could be achieved by sum of two or more than two elements
 which are continuous in index not after the array ends only one from start to end starting could be at any index
*/





bool checkSubarraySum(int* nums, int numsSize, int k) {
    if(1 == numsSize) return false;
    if(1 == k) return true;

    // calculate sum of 0..n
    char cIsZero = 0 == *nums;
    int nNumsSize = numsSize;
    int* pnNums = nums;
    while(--nNumsSize)
    {
        int* pnPrev = pnNums++;
        if(0 == *pnNums)
        {
            if(cIsZero) return true;

            cIsZero = 1;
            *pnNums = *pnPrev;
        }
        else
        {
            cIsZero = 0;
            *pnNums += *pnPrev;
            if(0 == *pnNums % k) return true;
        }
    }

    if(*pnNums < k) return false;

    // trace sum of i..n
    pnNums = nums;
    while(numsSize--)
    {
        int* pnLeft = nums;
        while(1 < pnNums - pnLeft)
        {
            int nDiff = *pnNums - *(pnLeft++);
            if(0 == nDiff % k) return true;

            if(nDiff < k) break;
        }

        pnNums++;
    }

    return false;
}