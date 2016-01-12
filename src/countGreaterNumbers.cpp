/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int countGreaterNumbers(struct transaction *A, int len, char *date) {
	int index1,  year[2], month[2], date1[2];
	if (A&&date)
	{
		year[1] = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + date[9] - '0';
		month[1] = ((date[3] - '0') * 10 + date[4] - '0');
		date1[1] = (date[0] - '0') * 10 + date[1] - '0';
		for (index1 = 0; index1 < len; index1++)
		{
			year[0] = (A[index1].date[6] - '0') * 1000 + (A[index1].date[7] - '0') * 100 + (A[index1].date[8] - '0') * 10 + A[index1].date[9] - '0';
			month[0] = ((A[index1].date[3] - '0') * 10 + A[index1].date[4] - '0');
			date1[0] = (A[index1].date[0] - '0') * 10 + A[index1].date[1] - '0';
			if (year[0] > year[1] || (year[0] == year[1] && month[0] > month[1]) || (year[0] == year[1] && month[0] == month[1] && date1[0] > date1[1]))
				return len - index1;
		}
		return 0;
	}
	return -1;
}
