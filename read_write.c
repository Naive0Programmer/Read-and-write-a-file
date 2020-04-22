#include <stdio.h>

int main(int argc, char*argv[]){
    //usage: marks [file in] [file out]

    FILE * f_read = fopen(argv[1], "r");//r read, w write, a append
    FILE * f_write = fopen(argv[2], "w");

    if(f_read==NULL || f_write==NULL){
        printf("File is null.");
        return 0;
    }
    float avg = 0;
    int grade1 = 0, grade2 = 0;
    char first_name[20];
    char last_name[20];

    while(fscanf(f_read,"%s %s %d %d", first_name, last_name, &grade1, &grade2) != EOF){
        avg = (float) (grade1 + grade2) / 2;
        fprintf(f_write, "%s %s %d %d %.1f\n", first_name, last_name, grade1, grade2, avg);
    }
    fclose(f_read);
    fclose(f_write);
    return 0;
}