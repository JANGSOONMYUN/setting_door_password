;====================================================================
; Main.asm file generated by New Project wizard
;
; Created:   �� 5 19 2013
; Processor: PIC10F200
; Compiler:  MPASM (Proteus)
;====================================================================

;====================================================================
; DEFINITIONS
;====================================================================

#include p10f200.inc                ; Include register definition file

;====================================================================
; VARIABLES
;====================================================================

;====================================================================
; RESET and INTERRUPT VECTORS
;====================================================================

      ; Reset Vector
RST   code  0x0 
      goto  Start

;====================================================================
; CODE SEGMENT
;====================================================================

PGM   code
Start
      ; Write your code here
Loop  
      goto  Loop

;====================================================================
      END
