#include "main.h"

int main(void)
{	
	PeriphInit();
	
	while(1)
	{
		key_brake();																										//����1������0�˳���ͣģʽ
		LED0=!LED0;																											//��ʾϵͳ��������	
		delay_ms(200);
	}
}

void PeriphInit(void)
{
	delay_init();	    	 																											//��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);														//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 																											//���ڳ�ʼ��Ϊ115200
	LED_Init();		  																													//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();																																//������ʼ��
	TIM1_Int_Init(4999,7199);	
	CAN_Mode_Init(CAN_SJW_1tq, CAN_BS2_8tq, CAN_BS1_9tq, 4, CAN_Mode_Normal);	//CAN��ʼ������ģʽ,������500Kbps  
}
 
