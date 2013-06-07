/* source for http://uva.onlinejudge.org/external/1/100.pdf */
/* vinay raghavan k s */

#include <stdio.h>
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#define MAXSZ 50001 

static unsigned short tbl[MAXSZ];

int getcyclength(unsigned long n) {
	return ((n<MAXSZ && tbl[n]) ?	tbl[n] : computecyclength(n));
}	

int computecyclength(unsigned long n){
  if (n&1){ /* is odd */
		if(n<MAXSZ) 
			tbl[n]=2+getcyclength((3*n+1)>>1);
		else
			return 2+getcyclength((3*n+1)>>1);
    }
  else{
		if(n<MAXSZ) 
	    tbl[n]=1+getcyclength(n>>1);
		else
	    return 1+getcyclength(n>>1);
    }
  return tbl[n];
} 

int main(int argc, char* argv[]) {

    tbl[1] = 1; /* need to count 1 too */
    unsigned long currl=0,maxl,n,i,j;

    i=atol(argv[1]); j=atol(argv[2]);

    printf ("%lu %lu ",i,j);

		if(j<i) 
			{ SWAP (j,i); }
		
		maxl=0;
		for(n=i;n<=j;n++) {
			currl=getcyclength(n);
			maxl=(currl>maxl)?currl:maxl;
		}
    
		printf ("%lu\n",maxl);
	return 0;

}
