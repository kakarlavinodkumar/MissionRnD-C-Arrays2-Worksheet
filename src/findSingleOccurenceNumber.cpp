/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<malloc.h>
int findSingleOccurenceNumber(int *A, int len) {
	int index, index1, count;
	bool *status;
	status = (bool*)malloc(sizeof(bool)*len);
	for (index = 0; index < len; index++)
		status[index] = 0;
	if (A)
	{
		for (index = 0; index < len; index++)
		{
			if (status[index] == 0)
			{
				for (index1 = index + 1, count = 1, status[index] = 1; index1 < len; index1++)
				{	
					if (A[index] == A[index1])
					{
						count++;
						status[index1] = 1;
					}
				}
				if (count == 1)
					return A[index];
			}
		}
	}
	return -1;
}