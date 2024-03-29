/*
 * RfidReader.c
 *
 *  Created on: Mar 26, 2022
 *      Author: agn
 */

#include "RfidReader.h"
#include "usbd_cdc_if.h"
#include "MFRC522.h"

typedef struct RfidReader_ {
    SPI_HandleTypeDef *dev;
} RfidReader_;


RfidReader * rfidReaderInit(SPI_HandleTypeDef *spiDev)
{
    RfidReader* reader = malloc(sizeof(RfidReader_));
    reader->dev = spiDev;
    MFRC522_Init(spiDev);
    return reader;
}

void rfidReaderLoop(RfidReader *ctx)
{
    uint8_t version = Read_MFRC522(VersionReg);

    size_t len = 0;
    char str[120];

    uint8_t status, cardstr[MAX_LEN+1];
    memset(cardstr, 0, sizeof(cardstr));

    status = MFRC522_Request(PICC_REQIDL, cardstr);
    if (status == MI_OK)
    {
        len = snprintf(&str[len], sizeof(str), "Card:\r\n\tVersion: %x\r\n\tType: %x,%x,%x\r\n", version, cardstr[0], cardstr[1], cardstr[2]);
        status = MFRC522_Anticoll(cardstr);
        if(status == MI_OK)
        {
            uint32_t serial =  cardstr[0] + (cardstr[1] << 8) + (cardstr[2]<< 16) + (cardstr[3]<<24);
            len += snprintf(&str[len], sizeof(str) - len, "\tSerial: %lu\r\n", serial);
        }
    }

    if (len > 0)
        CDC_Transmit_FS((uint8_t*) str, len);
}
