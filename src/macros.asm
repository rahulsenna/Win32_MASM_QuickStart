
;***** AInclude ********************************************************************************************************
AInclude  MACRO               filename                                  ; Declare macro

  ;***** [Process] ******************************************************

  align               qword                                             ; Set qword alignment
  include             filename                                          ; Restore entry RBX

  ;***** [End macro] ****************************************************

  ENDM                                                                  ; End macro declaration


;
;***** LoopN ***********************************************************************************************************
LoopN MACRO               destination                                   ; Declare macro

  ;***** [Process] ******************************************************

  dec                 rcx                                               ; Decrement the loop counter
  jnz                 destination                                       ; Return to top of loop

  ;***** [End macro] ****************************************************

  ENDM                                                                  ; End macro declaration


;***** Restore_Registers ***********************************************************************************************
Restore_Registers MACRO                                                   ; Declare macro

    ;***** [Process] ******************************************************

    pop                 r15                                               ; Restore entry R15
    pop                 r14                                               ; Restore entry R14
    pop                 r13                                               ; Restore entry R13
    pop                 r12                                               ; Restore entry R12
    pop                 r11                                               ; Restore entry R11
    pop                 r10                                               ; Restore entry R10
    pop                 r9                                                ; Restore entry R9
    pop                 r8                                                ; Restore entry R8
    pop                 rdi                                               ; Restore entry RDI
    pop                 rsi                                               ; Restore entry RSI
    pop                 rdx                                               ; Restore entry RDX
    pop                 rcx                                               ; Restore entry RCX
    pop                 rbx                                               ; Restore entry RBX

    ;***** [End macro] ****************************************************

    ENDM                                                                  ; End macro declaration


;***** Save_Registers **************************************************************************************************
Save_Registers  MACRO                                                     ; Declare macro

    ;***** [Process] ******************************************************

    push                rbx                                               ; Save entry RBX
    push                rcx                                               ; Save entry RCX
    push                rdx                                               ; Save entry RDX
    push                rsi                                               ; Save entry RSI
    push                rdi                                               ; Save entry RDI
    push                r8                                                ; Save entry r8
    push                r9                                                ; Save entry r9
    push                r10                                               ; Save entry r10
    push                r11                                               ; Save entry r11
    push                r12                                               ; Save entry r12
    push                r13                                               ; Save entry r13
    push                r14                                               ; Save entry r14
    push                r15                                               ; Save entry r15

    ;***** [End macro] ****************************************************

    ENDM                                                                  ; End macro declaration

;***** WinCall *********************************************************************************************************
;
; Every function invoking this macro MUST have a local "holder" variable declared.
WinCall  MACRO  call_dest:REQ, argnames:VARARG                          ; Declare macro
  LOCAL               jump_1, lpointer, numArgs                         ; Declare local labels

  ;***** [Process] ******************************************************

  numArgs             = 0                                               ; Initialize # arguments passed

  FOR                 argname, <argnames>                               ; Loop through each argument passed
    numArgs           = numArgs + 1                                     ; Increment local # arguments count
  ENDM                                                                  ; End of FOR looop

  IF numArgs LT 4                                                       ; If # arguments passed < 4
    numArgs = 4                                                         ; Set count to 4
  ENDIF                                                                 ; End IF

  mov                 holder, rsp                                       ; Save the entry RSP value

  sub                 rsp, numArgs * 8                                  ; Back up RSP 1 qword for each parameter passed
  and                 rsp, 0FFFFFFFFFFFFFFF0h                           ; Clear low 4 bits for para alignment
jump_1:
  lPointer            = 0                                               ; Initialize shadow area @ RSP + 0

  FOR                 argname, <argnames>                               ; Loop through arguments
    IF                lPointer GT 24                                    ; If not on argument 0, 1, 2, 3
      mov             rax, argname                                      ; Move argument into RAX
      mov             [ rsp + lPointer ], rax                           ; Shadow the next parameter on the stack
    ELSEIF            lPointer EQ 0                                     ; If on argument 0
      mov             rcx, argname                                      ; Argument 0 -> RCX
    ELSEIF            lPointer EQ 8                                     ; If on argument 1
      mov             rdx, argname                                      ; Argument 1 -> RDX
    ELSEIF            lPointer EQ 16                                    ; If on argument 2
      mov             r8, argname                                       ; Argument 2 -> R8
    ELSEIF            lPointer EQ 24                                    ; If on argument 3
      mov             r9, argname                                       ; Argument 3 -> R9
    ENDIF                                                               ; End IF
    lPointer          = lPointer + 8                                    ; Advance the local pointer by 1 qword
  ENDM                                                                  ; End FOR looop

  call                call_dest                                         ; Execute call to destination function

  mov                 rsp, holder                                       ; Reset the entry RSP value

  ;***** [End macro] ****************************************************

ENDM                                                                    ; End macro declaration




mDrawCircle  MACRO X:req, Y:req,radius:req, VideoMemory:req
              local r1,c1,ct
        ;-----[Draw Circle]-------------------------------------------

            mov r8,X+radius        ; ox    
            mov r9,Y+radius        ; oy

            mov rcx,radius*2       ; diameter
            mov rsi,Y
        r1:
            push rcx
            mov rdi,X              ; x
            mov rcx,radius*2       ; diameter
        c1:

            mov rax,rdi
            sub rax,r8
            mul rax
            mov r10,rax
            
            mov rax,rsi
            sub rax,r9
            mul rax
            add rax,r10
            cmp rax,radius*radius  ; radius = 40
            jg ct


            mov rax,BUF_WIDTH*4
            ; xor rdx,rdx
            mul rsi                            ; Y
            mov rbx,VideoMemory
            add rbx,rax
            mov rax,rdi                        ; X
            shl rax,2   ; *4 , 4 BytesPerPixel
            add rbx,rax

            mov dword ptr [rbx], 0FFFFFFFFh
        ct:
            add rdi,1

            loop c1
            pop rcx
            add rsi,1  ; y
            loop r1

ENDM