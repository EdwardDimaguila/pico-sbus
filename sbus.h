#ifndef __SBUS_H__

#include <stdint.h>
#include <stdbool.h>



#define SBUS_UART_ID uart1
// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 4
#define UART_RX_PIN 5

#define SBUS_BAUD_RATE 100000
#define SBUS_DATA_BITS 8
#define SBUS_PARITY    UART_PARITY_EVEN
#define SBUS_STOP_BITS 2


#define SBUS_STARTBYTE	0x0F
#define SBUS_ENDBYTE	0X00
#define SBUS_MESSAGE_MAX_SIZE 25

#define SBUS_FIFO_SIZE	4

typedef struct {
    uint16_t ch1;
    uint16_t ch2;
    uint16_t ch3;
    uint16_t ch4;
    uint16_t ch5;
    uint16_t ch6;
    uint16_t ch7;
    uint16_t ch8;
    uint16_t ch9;
    uint16_t ch10;
    uint16_t ch11;
    uint16_t ch12;
    uint16_t ch13;
    uint16_t ch14;
    uint16_t ch15;
    uint16_t ch16;
    bool dch17;
    bool dch18;
    bool framelost;
    bool failsafe;
} sbus_state_t;

bool hasSbusData();

void readSbusData(uint8_t *data);

void sbus_on_uart_rx();

void decode_sbus_data(const uint8_t *data, sbus_state_t *decoded);

#endif