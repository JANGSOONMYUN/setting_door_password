/*==================================================================
    File Name :  Dr_Kim KIT (SIC80-300).h
    Explanation
    Dr_Kim KIT (SIC80-300).h 를 디폴트 경로
    C:\Keil\C51\INC\Atmel 폴더에 복사한다.
==================================================================*/

#define COM_SELECT 	(*(unsigned char xdata *)0x8000)//7segment,DC Motor,Step Motor 
#define SEG_DATA 	(*(unsigned char xdata *)0x9000)//7segment Data 외부메모리 주소
#define PPI_PA  	(*(unsigned char xdata *)0xA000)//green 외부 메모리 주소
#define PPI_PB  	(*(unsigned char xdata *)0xA001)//red 외부 메모리 주소
#define PPI_PC  	(*(unsigned char xdata *)0xA002)//Key, Sensor In 외부 메모리 주소
#define PPI_CT  	(*(unsigned char xdata *)0xA003)//82C55 컨트롤 단자 외부 메모리 주소
#define GLCD_CTRL   	(*(unsigned char xdata *)0xB000)//LCD 컨트롤단자 외부메모리 주소
#define GLCD_DATA   	(*(unsigned char xdata *)0xB001)//LCD-DATA의 외부 메모리 주소
#define GLCD_DATA_CS1   (*(unsigned char xdata *)0xB005)//LCD CS1 외부 메모리 주소
#define GLCD_DATA_CS2   (*(unsigned char xdata *)0xB003)//LCD CS2 외부 메모리 주소
#define DATA_OUT 	(*(unsigned char xdata *)0xC000)//Key, Sensor Out 외부 메모리 주소
#define LINE_DATA 	(*(unsigned char xdata *)0xD000)//line의 외부 메모리 주소
#define M_DATA 		(*(unsigned char xdata *)0xe000)//Motor Data 외부 메모리 주소
#define ADC_READ 	(*(unsigned char xdata *)0xF000)//ADC Read 외부 메모리 주소
#define ADC_CH0 	(*(unsigned char xdata *)0xF000)//ADC 0 체널 외부 메모리 주소
#define ADC_CH1 	(*(unsigned char xdata *)0xF001)//ADC 1 체널 외부 메모리 주소
#define ADC_CH2 	(*(unsigned char xdata *)0xF002)//ADC 2 체널 외부 메모리 주소
#define ADC_CH3 	(*(unsigned char xdata *)0xF003)//ADC 3 체널 외부 메모리 주소
#define ADC_CH4 	(*(unsigned char xdata *)0xF004)//ADC 4 체널 외부 메모리 주소

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
