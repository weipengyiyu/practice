#include "main.h"

static int recv_total = 0;
static int flag = 1;

//�յ����� ͳ����Ϣ����ʱ����ͳ�ư����ʹ�ӡ��
void recv_heart(u8 *buf)
{	
	//int i;
	recv_total++;
	
	//�򴮿ڷ�����Ϣ
#if 0
	for(i=0;i<8;i++)
	{
		USART_SendData(USART1, buf[i]);		//�򴮿�1��������
	}
#endif
	
	printf("%d ", recv_total);					//�����������ͣ����ڷ��͵��ַ���ʾû�µ��Ժ�
}

void urgency_stop(void)
{
	int temp = 0;
	u8 msg[8] = {0};
	
	//��伱ɲ����ɲ����0~255��
	msg[5] = 255 & 0xff;
	msg[6] = (255>>8) & 0xff;
	msg[7] = 2;
	
	if(flag)
	{
		//����ֵ:0,�ɹ�;����,ʧ��;
		temp = Can_Send_Msg(msg,8);
		if(temp)
		{
			printf("  stop Failed  temp=%d  ", temp);		
		}
		else
		{
			printf("  stop OK  temp=%d  ", temp);
		}
	}
}

void key_brake(void)
{
	u8 key;
	key=KEY_Scan(0);
	if(key == KEY0_PRES)										//KEY0_PRES����
	{
		flag = 0;															//��֤�˳���ͣģʽ�����ٽ���urgency_stop
		
		printf("  exit OK    ");
	}
	else if(key == KEY1_PRES)										//KEY1_PRES����
	{
		flag = 1;															//
		
		printf("  start OK  ");
	}
}



