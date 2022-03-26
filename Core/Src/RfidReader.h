/*
 * RfidReader.h
 *
 *  Created on: Mar 26, 2022
 *      Author: agn
 */

#ifndef INC_RFIDREADER_H_
#define INC_RFIDREADER_H_

void EXTI4_IRQHandler(void);

typedef struct RfidReader_ RfidReader;

RfidReader * rfidReaderInit();
void rfidReaderLoop(RfidReader* ctx);

#endif /* INC_RFIDREADER_H_ */
