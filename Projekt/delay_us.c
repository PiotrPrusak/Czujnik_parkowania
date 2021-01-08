#include "delay_us.h"
void delay_us( int n) {
volatile int i;
volatile int j;
							for( i = 0 ; i < n; i++)
							for(j = 0; j < 4; j++) {}
}
