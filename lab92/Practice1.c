#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 20
#define MAX_LEN 1000
int main() {
    float sales[MAX_LINES][MAX_LEN];
    FILE *file;
    file = fopen("test.txt", "r");
    int line = 0;
    while (!feof(file) && !ferror(file))
        if (fgets(sales[line], MAX_LEN, file) != NULL)
            line++;
    fclose(file);
/*
Next is the function for the sales report
*/
    printf("Monthly sales report for 2022:\n");
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", NULL};
    int i = 0;
    while (months[i]) {
        printf("%-10s: ", months[i]);
        printf("$%-10s", sales[i]);
        i++;
    }
/*
Next is the function for the sales summary
*/
    printf("\nSales Summary:\n");
    int j = 0;
    float min = atof(sales[j]);
    int tempmonth = 0;
    while (months[j]) {
        if(atof(sales[j]) < min)
            min = atof(sales[j]);
            tempmonth = j;
        j++;
    }
    printf("Minimum Sales: $%.2f\n", min);
    int k = 0;
    float max = atof(sales[k]);
    int tempmonth2=0;
    while (months[k]) {
        if(atof(sales[k]) > max)
            max = atof(sales[k]);
            tempmonth2 = k;
        k++;
    }
    printf("Maximum Sales: $%.2f\n", max);
    int w = 0;
    float o = 12.00;
    float avg = 0;
    float total = 0;
    while (months[w]) {
        total = total + atof(sales[w]);
        w++;
    }
    avg = total/o;
    printf("Average Sales: $%.2f\n",avg);
/*
Next is the functino for the moving average
*/
    printf("\nSix-Month Moving Average Report:\n");
    int m = 6;
    int v = 0;
    int monthtrack1=0;
    int monthtrack2=5;
    int start = 0;
    while(m != 13) {
        float total2 = 0;
        float avg2 = 0;
        v = start;
        while(v<m) {
            total2 = total2 + atof(sales[v]);
            v++;
        }
        avg2 = total2/6;
        printf("%-10s - %-10s  ",months[monthtrack1],months[monthtrack2]);
        printf("$%.2f\n", avg2);
        m = m + 1;
        start = start + 1;
        monthtrack1++;
        monthtrack2++;
    }
    
/*
Next is the function for the highest to lowest
*/
    printf("\nSales Report (Highest to Lowest)\n");
    int c;
    int b;
    int holder = 12;
    float tempval;
    float array[12];
    for(c=0;c<12;c++){
        array[c] = atof(sales[c]);
    }
    c = 0;
    char tempmonth4;
    for(c = 0;c < holder; c++){
        for(b = c+1;b<holder;b++){
            if(array[c] < array[b]){
                tempval = array[c];
                array[c] = array[b];
                array[b] = tempval;
            }
    }
    }
    printf("    Sales\n");
    for(b=0;b<12;b++) {
        printf("    $%.2f\n", array[b]);
        }
    return 0;
}