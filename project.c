#include <stdio.h>
#include <stdbool.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
	char val[100];
	double w,x, y,z;
	double distance;
}Point;
void bsortDesc(struct Point arr[], int s)
{
    int i, j;
    struct Point temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (arr[j].distance < arr[j + 1].distance)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
char * classifyAPoint(struct Point arr[], int n, int k,struct  Point p)
{
	int j;
	for (int i = 0; i < n; i++)
		arr[i].distance =
			sqrt((arr[i].x - p.x) * (arr[i].x - p.x) +
				(arr[i].y - p.y) * (arr[i].y - p.y)+(arr[i].w - p.w) * (arr[i].w - p.w) +
				(arr[i].z - p.z) * (arr[i].z - p.z));
	bsortDesc(arr, n);
	int n1 = 0;
	int n2 = 0;
	int n3=0;
	char max;
	char *a="Iris-setosa";
	char *b="Iris-versicolor";
	char *c="Iris-virginica";
	for (int i = n; i > (n-k-1); i--)
	{
		if (strcmp(arr[i].val,a) ==0 )
			n1++;
		else if (strcmp(arr[i].val,b) == 0)
			n2++;
		else if (strcmp(arr[i].val,c)==0)
             n3++;

	}
    max=(n1 > n2) ? (n1 > n3 ? n1 : n3 ): (n2 > n3 ? n2 : n3);
    if(n1==max)
        return a;
    else if (n2==max)
        return b;
    else
        return c;
}
const char* getfield(const char* line, int num)
{
    const char* tok;
    char nn[1024];
    strcpy(nn,line);
    for (tok = strtok(nn, ",");tok && *tok;tok = strtok(NULL, ",\n"))
    {

        if (!--num){
               free(nn);
            return tok;}
    }
   free(nn);
    return NULL;
}
int main()
{
    FILE* stream = fopen("iris.csv", "r");
    float a,b,c,d;
    char line[1024];
    int i=0,j=0;
    Point arr[1000];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        arr[i].w= atof(getfield(line, 1));
        arr[i].x= atof(getfield(line, 2));
        arr[i].y= atof(getfield(tmp, 3));
        arr[i].z= atof(getfield(tmp, 4));
        strcpy(arr[i].val,getfield(tmp, 5));
        free(tmp);
        i++;
    }
    struct Point p;
    printf("Enter data :");
    scanf("%f %f %f %f",&a,&b,&c,&d);
    p.w=a;
	p.x = b;
	p.y = c;
    p.z=d;
    int n = 150;
	int k = 5;
	printf ("The value classified to unknown point"
			" is %s.\n", classifyAPoint(arr, n, k, p));

}
