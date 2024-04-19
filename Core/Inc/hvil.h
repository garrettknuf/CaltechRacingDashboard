/*
 * @file hvil.h
 * @brief HVIL (High voltage inter-lock)
 *
 * @author Garrett Knuf
 * @date 4/19/2024
 */

#ifndef INC_HVIL_H_
#define INC_HVIL_H_

#include <stdbool.h>

void HVIL_Init(void);

bool HVIL_GetCurrent(void);

bool HVIL_GetFault(void);

#endif /* INC_HVIL_H_ */
