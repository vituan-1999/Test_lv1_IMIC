#include<stdio.h>
#include<stdint.h>

typedef struct
{
	int8_t LSB;
	int8_t MSB;
}_8bit_t;

typedef union
{
	int16_t _16bit;
	_8bit_t _8bit;
}_16bit_t;
int main()
{
	_16bit_t So = { 0 };
	So._16bit = 0x04D2;
	printf("\n\tSo: 0x%X, duoc chia thanh MSB: 0x%0.2X va LSB: 0x%0.2X\n\n", 
		So, So._8bit.MSB, So._8bit.LSB);
	return 0;
}
