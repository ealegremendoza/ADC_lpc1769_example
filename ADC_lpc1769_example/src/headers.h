/*
 * headers.h
 *
 *  Created on: 19 mar. 2021
 *      Author: ealegremendoza
 */

#ifndef HEADERS_H_
#define HEADERS_H_


#include <cr_section_macros.h>
#include <stdio.h>
#include "Regs.h"
#include "Oscilador.h"
#include "GPIO.h"
#include "port.h"
#include "systick.h"
#include "ADC_lpc1769.h"

/* Comment for stand-alone mode */
#include "debug.h"

#ifndef DEBUG_H_
#define DEBUGOUT(a);
#else
#define DEBUGOUT(a);  printf(a);
#endif


#endif /* HEADERS_H_ */
