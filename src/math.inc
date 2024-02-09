.data
    sysTime SYSTEMTIME <>	     ; system time structure
.code
;--------------------------------------------------------------
Random32  PROC
;
; Generates an unsigned pseudo-random 32-bit integer
;   in the range 0 - FFFFFFFFh.
; Receives: nothing
; Returns: EAX = random integer
; Last update: 7/11/01
;--------------------------------------------------------------
.data

seed  DWORD 1
.code
	  push  rdx
	  mov   eax, 343FDh
	  imul  seed
	  add   eax, 269EC3h
	  mov   seed, eax    ; save the seed for the next call
	  ror   eax,8        ; rotate out the lowest digit (10/22/00)
	  pop   rdx

	  ret
Random32  ENDP


;--------------------------------------------------------------
RandomRange PROC
;
; Returns an unsigned pseudo-random 32-bit integer
; in EAX, between 0 and n-1. Input parameter:
; EAX = n.
; Last update: 09/06/2002
;--------------------------------------------------------------
	 push  rbx
	 push  rdx

	 mov   ebx,eax  ; maximum value
	 call  Random32 ; eax = random number
	 mov   edx,0
	 div   ebx      ; divide by max value
	 mov   eax,edx  ; return the remainder

	 pop   rdx
	 pop   rbx

	 ret
RandomRange ENDP


;--------------------------------------------------------
Randomize PROC
;
; Re-seeds the random number generator with the current time
; in seconds. Calls GetSystemTime, which is accurate to 10ms.
; Receives: nothing
; Returns: nothing
; Last update: 09/06/2002
;--------------------------------------------------------
	  local holder:QWORD
      Save_Registers


	  WinCall GetSystemTime, OFFSET sysTime
	  movzx eax,sysTime.wMilliseconds
	  mov   seed,eax

	  Restore_Registers
	  ret
Randomize ENDP