#include<stdio.h>
#include<string.h>
#define N 5
int ranking(int a[], int x, int n);
int main()
{
	char name[N][10],ch[10];
	int score[N], t, i, j, k, score0, index;
	for (i = 0; i < N; i++)
	{
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
	}
	for (k = 1; k < N; k++)
	{
		for (i = 0; i < N - k; i++)
		{
			if (score[i] < score[i + 1])
			{
				t = score[i], score[i] = score[i + 1], score[i + 1] = t;//�������е���ֵ����
				strcpy(ch, name[i]), strcpy(name[i], name[i + 1]), strcpy(name[i + 1], ch);//����strcpy����ʹ�����ַ�������
			}
		}
	}
	for (i = 0; i < N; i++)
		printf("%s\t%d\n", name[i], score[i]);
	scanf("%d", &score0);
	index = ranking(score, score0, N);//�ö��ַ��ҳ���Ҫ�ɼ���iֵ
	if (index != -1) printf("%s\t%d\n", name[index], score[index]);
	else printf("not found!");
	return 0;
}
int ranking(int a[], int x, int n)
{
	int middle, front = 0, back = n - 1;
	middle = (front + back) / 2;
	for (; front <= back; middle = (front + back) / 2)
	{
		if (x == a[middle]) return middle;
		if (x > a[middle]) back = middle - 1;
		if (x < a[middle]) front = middle + 1;
	}
	return -1;
}