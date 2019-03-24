#include <stdio.h>
#define N 7
struct Student
{
	char surnames[20];
	char groop[15];
	int Mark[5];
	float averageScore;
};

void prints(struct Student a) {
	printf("%s, %s  %d,%d,%d,%d,%d   sr-%.1f\n",a.surnames,a.groop,a.Mark[0], a.Mark[1], a.Mark[2], a.Mark[3], a.Mark[4], a.averageScore);
}

float AverageScore(int mark[5]) {
	float s=0; int i;
	for (i = 0; i < 5; i++)
	{
		s += mark[i];
	}
	return s / 5;
}
void Sort(struct Student avarage[N]) {

	int i,j;
	struct Student tmp;
	float mark[N];

	for (i = N-1; i >=0; i--) {
		for (j = 0; j < i; j++) {
			if (avarage[j].averageScore < avarage[j + 1].averageScore) {
				tmp = avarage[j];
				avarage[j] = avarage[j + 1];
				avarage[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		prints(avarage[i]);
	}
}

int main()
{
	printf("Execute function:\n1) sorting\n2) conclusion only good students\n\n\n");
	int input;

	struct Student arr[N] = {{"Abramson","mkn-181",{5,2,5,4,5}},
	                        {"Hancock","mkn-181",{3,3,3,4,3}},
							{"Gilson","mkn-181",{2,2,3,4,3}},
							{"Finch","mkn-181",{5,5,5,5,5}},
							{"Donovan","mkn-181",{4,3,3,4,5}},
							{"Charlson","mkn-181",{4,4,3,4,4}},
							{"Coleman","mkn-181",{2,2,3,4,2}}};
	int i;
	for (i = 0; i < N; i++)
	{
		arr[i].averageScore = AverageScore(arr[i].Mark);
	}

	for (i = 0; i < N; i++)
	{
		prints(arr[i]);
	}
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		printf("\n");
		Sort(arr);
		break;
	case 2:
		printf("\n");
		for (i = 0; i < N; i++)
		{
			if (arr[i].averageScore>3.9f)
			prints(arr[i]);
		}
		break;

	default:
		break;
	}

	return 0;

}

