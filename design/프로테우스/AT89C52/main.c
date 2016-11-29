#include <reg51.h>
#include <stdio.h>
#include <string.h>


void upbit (unsigned char   led);
void downbit (unsigned char   led);
void delay (int del);
	sbit sw0=P1^0;
	sbit sw1=P1^1;
	sbit sw2=P1^2;
	sbit sw3=P1^3;
	sbit sw4=P3^2;
	sbit sw5=P3^3;
void main (void)
{
	unsigned char   led,a=0,b=0,c;
	unsigned char pattern1[12]={1,2,3,1,2,3,1,2,3,1,2,3};
	unsigned char pattern2[12];
 do{
	led = 0xf0;
	if(sw4==0)
	{
	 a=0;
     for(b=0;b<12;b++)
	 {
	 if(pattern1[b]==1)
	 {led=0xef;
		P1=led; }
		 if(pattern1[b]==2)
	 {led=0xdf;
		P1=led; }
		 if(pattern1[b]==3)
	 {led=0xbf;
		P1=led; }
		 if(pattern1[b]==4)
	 {led=0x7f;
		P1=led; }
	 delay(30000);
	 }
	 led=0xff;
	 P1=led;
	}	
	if(sw5==0)
	{  
		for(b=0;b<12;b++)
		{pattern2[b]=0;	}
	}
	
    if(sw0==0)
	{              	
		led=0xef;
		P1=led;
		pattern2[a]=1;a++;
		delay(30000);
		while(sw0==0){}
	}	 
		
	if(sw1==0)
      	{
		led=0xdf;
		P1=led;
		pattern2[a]=2;a++;
		delay(30000);
		while(sw1==0){}	
		}
		
	 if(sw2==0)
	  	{
		  led=0xbf;
		P1=led;
		pattern2[a]=3;a++;
		delay(30000);
		while(sw2==0){}
			}
	 
		
	  if(sw3==0)
          {
		 led=0x7f;
		P1=led;
		pattern2[a]=4; a++;
		delay(30000);
		while(sw3==0){}	 
		   }
	if(sw0==0|sw1==0|sw2==0|sw3==0)
	{
		if(pattern1[a]==pattern2[a])	   
	{
		if(a=11);
		{
			 led=0x0f;
			P1=led;
			delay(30000);
			delay(30000);
			delay(30000);
			delay(30000);
			delay(30000);
			delay(30000);
		}
		
	}
	else
	for(b=0;b<4;b++)
			   {
		 led=0x0f;
		P1=led;
		delay(30000);
		led=0xff;
		P1=led;
		delay(30000);
		a=0;	   
		   }
	   }	 
		   
 }while(1);		
}
			

void delay (int del)
{
    while(del--);
}