###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = AT89C52
COMPILER = "Keil for 8051"
TARGET = Debug
SHELL = C:\Windows\system32\cmd.exe

## Tools general options
CCFLAGS=ROM(SMALL) BROWSE DEBUG CODE OBJECTEXTEND PREPRINT

## Processing Tools
CC=C51.exe
LD=BL51.exe
ASM=A51.exe
#  C:/Users/JANG-SM/Desktop/프로테우스/Debug/Debug.OMF: TOOL=LD
#     C:/Users/JANG-SM/Desktop/프로테우스/Debug/main.OBJ: TOOL=CC
#        C:/Users/JANG-SM/Desktop/프로테우스/AT89C52/main.c

# Build tree:
all:	Debug

Debug:	Debug.OMF

Debug.OMF:	main.OBJ 
	"..\..\..\..\..\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\VSM Studio\Tools\RunTool.exe" --good-exits=0,1 --executable=$(LD) "main.OBJ" TO "Debug.OMF" $(LDFLAGS) 

main.OBJ:	../AT89C52/main.c 
	"..\..\..\..\..\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\VSM Studio\Tools\RunTool.exe" --good-exits=0,1 --executable=$(CC) "..\AT89C52\main.c" $(CCFLAGS)  OBJECT("main.OBJ")

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Debug.M51
	rm -rf ./main.lst
	rm -rf ./main.I

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.OMF
	rm -rf main.OBJ

