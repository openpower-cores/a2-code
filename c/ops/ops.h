// © IBM Corp. 2020
// Licensed under and subject to the terms of the CC-BY 4.0
// license (https://creativecommons.org/licenses/by/4.0/legalcode). 
// Additional rights, including the right to physically implement a softcore 
// that is compliant with the required sections of the Power ISA 
// Specification, will be available at no cost via the OpenPOWER Foundation. 
// This README will be updated with additional information when OpenPOWER's 
// license is available.

#pragma once

#include "a2lib.h"
#include "printf.h"

void init(void);
char *me(void);
void start_time(void);
void stop_time(void);
uint32_t get_time(void);
uint32_t time_in_secs(uint32_t ticks);
double ftime_in_secs(uint32_t ticks);

