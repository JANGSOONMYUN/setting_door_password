
#line 1 "..\AT89C52\main.c" /0
  
#line 1 "C:\Keil\C51\BIN\..\INC\Atmel\reg51.h" /0






 
 
 
 
 
 
 sfr P0   = 0x80;
 sfr P1   = 0x90;
 sfr P2   = 0xA0;
 sfr P3   = 0xB0;
 sfr PSW  = 0xD0;
 sfr ACC  = 0xE0;
 sfr B    = 0xF0;
 sfr SP   = 0x81;
 sfr DPL  = 0x82;
 sfr DPH  = 0x83;
 sfr PCON = 0x87;
 sfr TCON = 0x88;
 sfr TMOD = 0x89;
 sfr TL0  = 0x8A;
 sfr TL1  = 0x8B;
 sfr TH0  = 0x8C;
 sfr TH1  = 0x8D;
 sfr IE   = 0xA8;
 sfr IP   = 0xB8;
 sfr SCON = 0x98;
 sfr SBUF = 0x99;
 
 
 
 
 sbit CY   = 0xD7;
 sbit AC   = 0xD6;
 sbit F0   = 0xD5;
 sbit RS1  = 0xD4;
 sbit RS0  = 0xD3;
 sbit OV   = 0xD2;
 sbit P    = 0xD0;
 
 
 sbit TF1  = 0x8F;
 sbit TR1  = 0x8E;
 sbit TF0  = 0x8D;
 sbit TR0  = 0x8C;
 sbit IE1  = 0x8B;
 sbit IT1  = 0x8A;
 sbit IE0  = 0x89;
 sbit IT0  = 0x88;
 
 
 sbit EA   = 0xAF;
 sbit ES   = 0xAC;
 sbit ET1  = 0xAB;
 sbit EX1  = 0xAA;
 sbit ET0  = 0xA9;
 sbit EX0  = 0xA8;
 
 
 sbit PS   = 0xBC;
 sbit PT1  = 0xBB;
 sbit PX1  = 0xBA;
 sbit PT0  = 0xB9;
 sbit PX0  = 0xB8;
 
 
 sbit RD   = 0xB7;
 sbit WR   = 0xB6;
 sbit T1   = 0xB5;
 sbit T0   = 0xB4;
 sbit INT1 = 0xB3;
 sbit INT0 = 0xB2;
 sbit TXD  = 0xB1;
 sbit RXD  = 0xB0;
 
 
 sbit SM0  = 0x9F;
 sbit SM1  = 0x9E;
 sbit SM2  = 0x9D;
 sbit REN  = 0x9C;
 sbit TB8  = 0x9B;
 sbit RB8  = 0x9A;
 sbit TI   = 0x99;
 sbit RI   = 0x98;
 
 
#line 1 "..\AT89C52\main.c" /0
 
  
#line 1 "C:\Keil\C51\BIN\..\INC\stdio.h" /0






 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef unsigned int size_t;
 
 
 #pragma SAVE
 #pragma REGPARMS
 extern char _getkey (void);
 extern char getchar (void);
 extern char ungetchar (char);
 extern char putchar (char);
 extern int printf   (const char *, ...);
 extern int sprintf  (char *, const char *, ...);
 extern int vprintf  (const char *, char *);
 extern int vsprintf (char *, const char *, char *);
 extern char *gets (char *, int n);
 extern int scanf (const char *, ...);
 extern int sscanf (char *, const char *, ...);
 extern int puts (const char *);
 
 #pragma RESTORE
 
 
 
#line 2 "..\AT89C52\main.c" /0
 
  
#line 1 "C:\Keil\C51\BIN\..\INC\string.h" /0






 
 
 
 
 
 
#line 13 "C:\Keil\C51\BIN\..\INC\string.h" /1
  
 
 
#line 16 "C:\Keil\C51\BIN\..\INC\string.h" /0
 
 
#line 18 "C:\Keil\C51\BIN\..\INC\string.h" /1
  
 
#line 20 "C:\Keil\C51\BIN\..\INC\string.h" /0
 
 #pragma SAVE
 #pragma REGPARMS
 extern char *strcat (char *s1, char *s2);
 extern char *strncat (char *s1, char *s2, int n);
 
 extern char strcmp (char *s1, char *s2);
 extern char strncmp (char *s1, char *s2, int n);
 
 extern char *strcpy (char *s1, char *s2);
 extern char *strncpy (char *s1, char *s2, int n);
 
 extern int strlen (char *);
 
 extern char *strchr (const char *s, char c);
 extern int strpos (const char *s, char c);
 extern char *strrchr (const char *s, char c);
 extern int strrpos (const char *s, char c);
 
 extern int strspn (char *s, char *set);
 extern int strcspn (char *s, char *set);
 extern char *strpbrk (char *s, char *set);
 extern char *strrpbrk (char *s, char *set);
 extern char *strstr  (char *s, char *sub);
 extern char *strtok  (char *str, const char *set);
 
 extern char memcmp (void *s1, void *s2, int n);
 extern void *memcpy (void *s1, void *s2, int n);
 extern void *memchr (void *s, char val, int n);
 extern void *memccpy (void *s1, void *s2, char val, int n);
 extern void *memmove (void *s1, void *s2, int n);
 extern void *memset  (void *s, char val, int n);
 #pragma RESTORE
 
 
#line 3 "..\AT89C52\main.c" /0
 
 
 
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
