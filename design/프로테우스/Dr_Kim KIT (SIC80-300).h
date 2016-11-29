/*==================================================================
    File Name :  Dr_Kim KIT (SIC80-300).h
    Explanation
    Dr_Kim KIT (SIC80-300).h �� ����Ʈ ���
    C:\Keil\C51\INC\Atmel ������ �����Ѵ�.
==================================================================*/

#define COM_SELECT 	(*(unsigned char xdata *)0x8000)//7segment,DC Motor,Step Motor 
#define SEG_DATA 	(*(unsigned char xdata *)0x9000)//7segment Data �ܺθ޸� �ּ�
#define PPI_PA  	(*(unsigned char xdata *)0xA000)//green �ܺ� �޸� �ּ�
#define PPI_PB  	(*(unsigned char xdata *)0xA001)//red �ܺ� �޸� �ּ�
#define PPI_PC  	(*(unsigned char xdata *)0xA002)//Key, Sensor In �ܺ� �޸� �ּ�
#define PPI_CT  	(*(unsigned char xdata *)0xA003)//82C55 ��Ʈ�� ���� �ܺ� �޸� �ּ�
#define GLCD_CTRL   	(*(unsigned char xdata *)0xB000)//LCD ��Ʈ�Ѵ��� �ܺθ޸� �ּ�
#define GLCD_DATA   	(*(unsigned char xdata *)0xB001)//LCD-DATA�� �ܺ� �޸� �ּ�
#define GLCD_DATA_CS1   (*(unsigned char xdata *)0xB005)//LCD CS1 �ܺ� �޸� �ּ�
#define GLCD_DATA_CS2   (*(unsigned char xdata *)0xB003)//LCD CS2 �ܺ� �޸� �ּ�
#define DATA_OUT 	(*(unsigned char xdata *)0xC000)//Key, Sensor Out �ܺ� �޸� �ּ�
#define LINE_DATA 	(*(unsigned char xdata *)0xD000)//line�� �ܺ� �޸� �ּ�
#define M_DATA 		(*(unsigned char xdata *)0xe000)//Motor Data �ܺ� �޸� �ּ�
#define ADC_READ 	(*(unsigned char xdata *)0xF000)//ADC Read �ܺ� �޸� �ּ�
#define ADC_CH0 	(*(unsigned char xdata *)0xF000)//ADC 0 ü�� �ܺ� �޸� �ּ�
#define ADC_CH1 	(*(unsigned char xdata *)0xF001)//ADC 1 ü�� �ܺ� �޸� �ּ�
#define ADC_CH2 	(*(unsigned char xdata *)0xF002)//ADC 2 ü�� �ܺ� �޸� �ּ�
#define ADC_CH3 	(*(unsigned char xdata *)0xF003)//ADC 3 ü�� �ܺ� �޸� �ּ�
#define ADC_CH4 	(*(unsigned char xdata *)0xF004)//ADC 4 ü�� �ܺ� �޸� �ּ�

/*==================================================================
        Explanation : I/O PORT Initialize
==================================================================*/

void initialize_io(void)
{
    P1 = 0xff;	
    COM_SELECT = 0xff;
    SEG_DATA = 0xff;
    M_DATA = 0x00;
    }

/*==================================================================
        Explanation : LCD Function
==================================================================*/

void glcd_delay (char del)
{
    while(del--);
    }

void glcd_ctrl(unsigned char ctrl)
{
    GLCD_CTRL = ctrl;
    glcd_delay(1);
    }

void glcd_data(unsigned char select,unsigned char _data)
{
    switch(select){
        case 0: GLCD_DATA = _data;
                break;
        case 1: GLCD_DATA_CS1 = _data;
                break;
        case 2: GLCD_DATA_CS2 = _data;
                break;
        default:
                break;
        }
    glcd_delay(1);
    }

void initialize_graphic_lcd(void)
{
    unsigned char i, j, x, y;

    glcd_ctrl(0x3f);
    glcd_ctrl(0xc0);
    x = 0xB8;						 //X start address
    y = 0x40;						 //Y start address
    for(i=0; i<=7; i++){
        glcd_ctrl(x);
        glcd_ctrl(y);
        for(j = 0; j <= 63; j++)
            glcd_data(0,0x00);	     //clear CS1 and CS2
        x++;
        }
    }
