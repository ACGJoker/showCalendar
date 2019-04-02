#include<stdio.h>
int all_days_yeartoyear(int y)
{
	int all = 0, i;
	for (i = 2010; i < y; i++)
	{
		if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0))
			all += 366;
		else
			all += 365;
	}
	return all;
}
int all_days_dayinyear(int y, int m)
{
	int all = 0, i;
	for (i = 1; i < m; i++)
	{
		switch (i)
		{
		case 1:case 3:case 5: case 7:case 8:case 10: case 12:all += 31; break;
		case 4:case 6: case 9: case 11:all += 30; break;
		case 2:if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) { all += 29; }
			   else
			all += 28;
		default:
			break;
		}
	}
	return all;
}
void show_date(int yty, int diy, int m, int y)/*yeartoyear,dayinyear*/
{
	int i;
	int ii;
	int days;
	int d_start;
	for (i = 0; i < 50; i++) { printf("*"); } printf("\n");
	switch (m)
	{
	case 1:case 3:case 5: case 7:case 8:case 10: case 12:days = 31; break;
	case 4:case 6: case 9: case 11:days = 30; break;
	case 2:if ((y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))) { days = 29; }
		   else days = 28;
	}
	d_start = ((yty + diy) % 7 + 5) % 7;
	printf("   SUN   MON   TUE   WED   THU   FRI   SAT\n");
	for (ii = 0; ii < d_start; ii++) { printf("      "); }
	for (i = 1; i <= days; i++) {
		if ((i + d_start-1) % 7 == 0)
			printf("\n");
		printf("%6d", i);

	}
	printf("\n");
}
int main()
{
	int y = 0, m = 0;
	char c = 'y';
	printf("Enter which year you want to display:");
	scanf("%d", &y);
	getchar();
	while (c != 'n')
	{
		printf("Enter month in %d to display calendar(1-12):", y);
		scanf("%d", &m);
		getchar();
		while (m <= 0 || m > 12) {
			printf("ERROR--Enter month in range of(1-12)!\n");
			printf("Enter month in %d to display calendar(1-12):",y);
			scanf("%d", &m);
			getchar();
		}
		show_date(all_days_yeartoyear(y), all_days_dayinyear(y, m), m, y);
		printf("Would you like to display another month(y/n):\n");
		//fflush(stdin);
		scanf("%c", &c);
		getchar();
	}
	return 0;
}
