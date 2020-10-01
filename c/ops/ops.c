// © IBM Corp. 2020
// Licensed under and subject to the terms of the CC-BY 4.0
// license (https://creativecommons.org/licenses/by/4.0/legalcode). 
// Additional rights, including the right to physically implement a softcore 
// that is compliant with the required sections of the Power ISA 
// Specification, will be available at no cost via the OpenPOWER Foundation. 
// This README will be updated with additional information when OpenPOWER's 
// license is available.

// test some a2lib calls

#include "ops.h"

uint64_t tick_start[4];
uint64_t tick_stop[4];
uint32_t ticks_per_sec;

#define LOOPS   1000000
#define MSGFREQ  250000

int main(uint32_t t) {

   int i = 0;
   int j = 1;
   uint32_t timer;

   init();
   printf("[%010u] %sThread: parm says:%i   whoami() says:%i\n", tick(), me(), t, whoami());  
   ticks_per_sec = tickspersec() * 1000000;
   printf("[%010u] %sKernel reports frequency=%u\n", tick(), me(), ticks_per_sec);    
 
   start_time();   
   while (i < LOOPS) {
      i++;
      j *= i;
      if (j == 0) {
         j = 1;
      }
      if ((i % MSGFREQ) == 0) {
         printf("[%010u] %s   Iterations=%i\n", tick(), me(), i); 
      }
   }
   
   stop_time();
   timer = get_time();
   printf("\n[%010u] %sLoop done. Iterations=%i Res=%u Ticks=%u (%.6lf seconds).\n", tick(), me(), LOOPS, j, timer, ftime_in_secs(timer));
   
   j = 0;   // rc=0 is 'pass'
   printf("[%010u] T%i done. rc=%i\n", tick(), t, j);
   return j;
}

 char *me(void) {
   char *id[] = {
      "T0 [Inky].....",
      "T1 [Blinky]...",
      "T2 [Pinky]....",
      "T3 [Darrell].."
   };
   return id[whoami()];
}

void init(void) {
   char *msg[] = {
      "kickstart my heart!",
      "poetry in motion...",
      "bring me to life...",
      "walk..............."
   };
   uint32_t t = whoami();
   
   printf("[%010u] %s%s\n", tick(), me(), "You shouldn't see this!!!");    
   printf_reset();
   
   printf("[%010u] %s%s\n", tick(), me(), msg[t]);    
}

void start_time(void) {
   tick_start[whoami()] = tick();
}

void stop_time(void) {  
   tick_stop[whoami()] = tick();   
}

uint32_t get_time(void) {
   uint32_t id = whoami();
	return tick_stop[id] - tick_start[id];
}

uint32_t time_in_secs(uint32_t ticks) {
   uint32_t retval=((uint32_t)ticks) / (uint32_t)ticks_per_sec;
	return retval;
}

double ftime_in_secs(uint32_t ticks) {
   double retval=((double)ticks) / (double)ticks_per_sec;
	return retval;
}

