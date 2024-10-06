/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

//initialize types of num and points
typedef struct {
	int num;
	int pts;
}
// prints output of all possible scoring scenarios
void print_output(scoring td2p, scoring tdfg, scoring td, scoring fg, scoring safety) {
	printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2p.num, tdfg.num, td.num, fg.num, safety.num);
}
scoring;

int main() {
	// Initialize the number and points of each type of scoring
	scoring td2p = {0, 8};
	scoring tdfg = {0, 7};
	scoring td = {0, 6};
	scoring fg = {0, 3};
	scoring safety = {0, 2};

	// Initialize the total number of points scored
	int total_pts = 0;

	// Keep the program running until the user inputs 0 or 1
	while (1) {
		printf("(0 or 1 to stop) Enter the NFL score: ");
		scanf("%d", &total_pts);

		// break if 0 or 1
		if (total_pts == 0 || total_pts == 1) {
			break;
		}

		for (td2p.num = 0; td2p.num <= total_pts / td2p.pts; td2p.num++) {
			for (tdfg.num = 0; tdfg.num <= total_pts / tdfg.pts; tdfg.num++) {
				for (td.num = 0; td.num <= total_pts / td.pts; td.num++) {
					for (fg.num = 0; fg.num <= total_pts / fg.pts; fg.num++) {
						for (safety.num = 0; safety.num <= total_pts / safety.pts; safety.num++) {
							if ((td2p.pts * td2p.num + tdfg.pts * tdfg.num + td.pts * td.num + fg.pts * fg.num + safety.pts * safety.num) == total_pts) {
							    print_output(td2p, tdfg, td, fg, safety);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
