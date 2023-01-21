/*
C program for 2 sum.

what is 2 sum?
In this program, we will read an array from the user. After reading this array, we will read one number, say target.
So the two sum is nothing but find the sum of two indices from the array and compare it with the value of the target.
 If both the values are equal then these two indices values are our output.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[100],i,j,size,target,sum=0;
    printf("Enter the size of an array\n");
    scanf("%d",&size);
    printf("Enter an array elements\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&nums[i]);
    }
    printf("Enter the value for target\n");
    scanf("%d",&target);
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            sum=nums[i]+nums[j];
            if(sum==target)
            {
                printf("Output : [%d, %d]",i,j);
            }
        }
    }
    return 0;
}
