#include "delay.h"
void delay_ms( int n) {
volatile int i;
volatile int j;
							for( i = 0 ; i < n; i++)
							for(j = 0; j < 3500; j++) {}
}
