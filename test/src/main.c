# include <mcs51/8051.h>

void Delay(unsigned int);

void main(void) {
	while(1) {
		P2_0 = 0;
		Delay(1000);
		p2_0 = 1;
		Delay(1000);
	}
}

void Delay(unsigned int x){
	unsigned int a,b;
	for(a = x; a > 0; a--)
		for(b = 100; b > 0; b--);
}
