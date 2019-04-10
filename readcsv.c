#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
typedef struct Point
{
    char  val[100];	 // Group of point
	double w,x,y,z;	 // Co-ordinate of point
} Point ;
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

    char line[1024];
    int i=0;
    Point arr[1000];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        arr[i].w= atof(getfield(line, 1));
        arr[i].x= atof(getfield(line, 2));
        arr[i].y= atof(getfield(tmp, 3));
        arr[i].z= atof(getfield(tmp, 4));
        strcpy(arr[i].val,getfield(tmp, 5));

        printf("row %d would be %.2f %.2f %.2f %.2f %s  \n ",i+1,arr[i].w,arr[i].x,arr[i].y,arr[i].z,arr[i].val);
        free(tmp);
        i++;
    }

}
