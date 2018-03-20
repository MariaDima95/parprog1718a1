#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <sys/time.h>


// compile like:  gcc -Wall -O2 -DNROWS=10000 matrix1.c -o matrix1


//-02 added in compiler options

#define NROWS 100000

#define NCOLS 100


void get_walltime(double *wct) {
  
	struct timeval tp;
  
	gettimeofday(&tp,NULL);
  		
	*wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);

}






int main() {

double *table;
int i, j;

double ts,te, macs, x;


  



table = (double *)malloc(NROWS*NCOLS*sizeof(double)); 
  
if (table==NULL) {
    
	printf("alloc error!\n");
    
	exit(1);
  
}


  // warmup


	
for (i=0;i<NROWS;i++) {
    	
	for (j=0;j<NCOLS;j++) {
      		
		table[i*NCOLS + j] = 0.0;
    	
	}
  	
 }

  


// get starting time (double, seconds) 
  
get_walltime(&ts);
  
  
// workload



 for (i=0;i<NROWS;i++) {
    	
	for (j=0;j<NCOLS;j++) {
      		
		x=sqrt(table[i*NCOLS + j] );
    	
	}

 }

 
 // get ending time
  get_walltime(&te);

  
// check results
  macs = (NROWS*NCOLS)/((te-ts)*1e6);

  
// print time elapsed and/or Maccesses/sec
  
printf("Time = %f\n",te-ts);
  
printf("Maccesses/sec = %f\n",macs);
  
  
  
  
free(table);

  
return 0;
}

