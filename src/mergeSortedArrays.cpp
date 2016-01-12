/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int index1, index2, year[2], month[2], date1[2], index;
	struct transaction *res;
	res = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
	if (A&&B)
	{
		for (index = index1 = index2 = 0; index1 < ALen&&index2 < BLen;)
		{
			year[0] = (A[index1].date[6] - '0') * 1000 + (A[index1].date[7] - '0') * 100 + (A[index1].date[8] - '0') * 10 + A[index1].date[9] - '0';
			month[0] = ((A[index1].date[3] - '0') * 10 + A[index1].date[4] - '0');
			date1[0] = (A[index1].date[0] - '0') * 10 + A[index1].date[1] - '0';
			year[1] = (B[index2].date[6] - '0') * 1000 + (B[index2].date[7] - '0') * 100 + (B[index2].date[8] - '0') * 10 + B[index2].date[9] - '0';
			month[1] = ((B[index2].date[3] - '0') * 10 + B[index2].date[4] - '0');
			date1[1] = (B[index2].date[0] - '0') * 10 + B[index2].date[1] - '0';
			if (year[0] < year[1] || (year[0] == year[1] && month[0] < month[1]) || (year[0] == year[1] && month[0] == month[1] && date1[0] < date1[1]))
				res[index++] = A[index1++];
			else
				res[index++] = B[index2++];
		}
		for (; index1 < ALen;)
			res[index++] = A[index1++];
		for (; index2 < BLen;)
			res[index++] = B[index2++];
		return res;
	}
	return NULL;
}