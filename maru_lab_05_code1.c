//Jal Maru EECS 348 Lab 05 Code 1 Sales
#include <stdio.h>
#include <math.h>

// array o9f months
const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// declare array of doubles for sales and six month 
double sales[12];
double sixMonthAverages[7];

//sorts high to low
int main(void) {
    char filename[100];
    printf("Enter your file: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    // error if empty
    if (file == NULL) {
        printf("Unable to open sales file\n");
        return 1;
    }

    // read data from file
    int i;
    for (i = 0; i < 12; i++) {
        // This is reading the sales data from the file and storing it in the array of sales.
        fscanf(file, "%lf", &sales[i]);
    }
    // required
    fclose(file);
    // sales report
    printf("\nMonthly Sales Report\n");
    printf("--------------------------\n");
    printf("Month\tSales\n");
    printf("--------------------------\n");
    //pritning month and sale data
    for (i = 0; i < 12; i++) {
        printf("%s\t$%.2lf\n", months[i], sales[i]);
    }
    printf("-------------------\n");

    // declare and initialize needed variables to find vals
    double total = 0;
    double min = sales[0];
    double max = sales[0];
    int minHelp = 0;
    int maxHelp = 0;
    for (i = 0; i < 12; i++) {
        total += sales[i];
        // finds min by comparing to previous min
        if (sales[i] < min) {
            min = sales[i];
            minHelp = i;
        }
        //finds max in same way as min, compares val to previous max
        if (sales[i] > max) {
            max = sales[i];
            maxHelp = i;
        }
    }
    // get average
    double average = total / 12;
    printf("Sales Summary\n");
    printf("--------------------------\n");
    printf("Month with lowest sales: %s ($%.2lf)\n", months[minIndex], min);
    printf("Month with highest sales: %s ($%.2lf)\n", months[maxIndex], max);
    printf("Average sales: $%.2lf\n", average);
    printf("-------------------------\n");
    // sixmonthAverages
    sixMonthAverages[0] = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5]) / 6;
    sixMonthAverages[1] = (sales[1] + sales[2] + sales[3] + sales[4] + sales[5] + sales[6]) / 6;
    sixMonthAverages[2] = (sales[2] + sales[3] + sales[4] + sales[5] + sales[6] + sales[7]) / 6;
    sixMonthAverages[3] = (sales[3] + sales[4] + sales[5] + sales[6] + sales[7] + sales[8]) / 6;
    sixMonthAverages[4] = (sales[4] + sales[5] + sales[6] + sales[7] + sales[8] + sales[9]) / 6;
    sixMonthAverages[5] = (sales[5] + sales[6] + sales[7] + sales[8] + sales[9] + sales[10]) / 6;
    sixMonthAverages[6] = (sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 6;
    // printing with correct syntax
    printf("Six-Month Averages\n");
    printf("----------------------------\n");
    printf("January - June\t$%.2lf\n", sixMonthAverages[0]);
    printf("February - July\t$%.2lf\n", sixMonthAverages[1]);
    printf("March - August\t$%.2lf\n", sixMonthAverages[2]);
    printf("April - September\t$%.2lf\n", sixMonthAverages[3]);
    printf("May - October\t$%.2lf\n", sixMonthAverages[4]);
    printf("June - November\t$%.2lf\n", sixMonthAverages[5]);
    printf("July - December\t$%.2lf\n", sixMonthAverages[6]);
    printf("-------------------------\n");
    // Print the months and sales from the highest to lowest
  printf("Months and Sales from the Highest to Lowest:\n");
  printf("--------------------------\n");
  printf("Month\tSales\n");
  printf("--------------------------\n");
    // sorting sales from highest to lowest
  int k, j;
  // This is a for loop that is used to iterate through the array of sales.
  for (k = 0; k < 12 - 1; k++) {
    for (j = k + 1; j < 12; j++) {
      // swap down if lower val than next month
      if (sales[k] < sales[j]) {
        // store in temp to swap j to k and temp to j, switching order of vals
        double temp = sales[k];
        sales[k] = sales[j];
        sales[j] = temp;
        //do same for the month values for k and j
=        const char* tempMonth = months[k];
        months[k] = months[j];
        months[j] = tempMonth;
      }
    }
  }

  // Printing the sorted data
  // This is a for loop that is used to iterate through the array of sales.
  for (i = 0; i < 12; i++) {
    printf("%s\t$%.2lf\n", months[i], sales[i]);
  }

  return 0;
}