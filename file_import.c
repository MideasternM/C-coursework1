#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[10];
} FITNESS_DATA;

// Define any additional variables here

int i;
char data1[30];
char delimiter[10]={","};
char name[100];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FITNESS_DATA data;
    FILE *fp;
    printf("enter the name of the file which you want to read(including file extension):");
    scanf("%s",&name);
    fp=fopen(name,"r");
    for(i=1;i<=3;i++)
    {
        fgets(data1,30,(FILE*)fp);
        tokeniseRecord(data1,delimiter,data.date,data.time,data.steps);
        printf("%s/%s/%s",data.date,data.time,data.steps);
    }
}
