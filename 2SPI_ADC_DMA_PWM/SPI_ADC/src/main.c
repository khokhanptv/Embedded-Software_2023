#include "stm32f4xx.h"                  // Device header
#define SPI1_NSS 		GPIO_Pin_4
#define SPI1_SCK 		GPIO_Pin_5
#define SPI1_MISO 	GPIO_Pin_6
#define SPI1_MOSI 	GPIO_Pin_7
#define SPI1_GPIO 	GPIOA
void RCC_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1|RCC_APB2Periph_SPI1,ENABLE);
}
void GPIO_config(){
	// adc config
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	// spi config
	GPIO_InitStruct.GPIO_Pin =SPI1_NSS|SPI1_SCK|SPI1_MISO|SPI1_MOSI;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(SPI1_GPIO,&GPIO_InitStruct); 
	//
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
}
void SPI_Config(){
	SPI_InitTypeDef SPI_InitStruct;
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_16b;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 10;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &SPI_InitStruct);
	SPI_Cmd(SPI1,ENABLE);
}
void ADC_config(){
	ADC_InitTypeDef ADC_InitStructure;
	ADC_StructInit(&ADC_InitStructure);
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b; // Ð? phân gi?i ADC
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 1;
  ADC_Init(ADC1, &ADC_InitStructure);
  ADC_Cmd(ADC1, ENABLE);
}

void TIM_Config(){

	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	TIM_InitStruct.TIM_ClockDivision = 0;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStruct.TIM_Period = 0xFFFF-1;
	TIM_InitStruct.TIM_Prescaler = 167;
	TIM_TimeBaseInit(TIM1, &TIM_InitStruct);
	TIM_Cmd(TIM1,ENABLE);
	ADC_SoftwareStartConv(ADC1);

}

void delay_us(uint32_t time){
	TIM_SetCounter(TIM1,0);
	while(TIM_GetCounter(TIM1) < time);

}
void SPI_Trans(uint16_t arr ){
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	SPI_I2S_SendData(SPI1,arr);
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE)==0);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}
uint16_t ADC_ReadData(){
	uint16_t sum = 0;
	uint16_t val = 0;
		for(int i=0; i<10; i++){
		ADC_SoftwareStartConv(ADC1);
			while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)){};
				val= ADC_GetConversionValue(ADC1);
			delay_us(10);
			sum+=val;
		}
		 return sum/10;
}
uint16_t data;
int main(){
	RCC_Config();
	TIM_Config();
	GPIO_config();
	ADC_config();
	SPI_Config();
	while(1){
		
		data = ADC_ReadData();
		SPI_Trans(data);
		delay_us(3000);
	}

}