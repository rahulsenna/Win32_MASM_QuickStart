
    OPTION casemap:none


    INCLUDE platform.inc
    INCLUDE macros.asm



.data
    EMPTY_ID     EQU 0
    SAND_ID      EQU 1
    WATER_ID     EQU 2
                           ;       BLACK        WHITE        BLUE
    Colors                  DWORD  000303030h,  0FFFFFFFFH,  0FFFF0000H

    GameBackBuffer qword ?

    gravity     real4 10.0
    one         real4 1.0
    zero        real4 0.0


.code





UpdateAndRender PROC


        

;-----[Display Grid]-------------------------------------------
    mov rdi, GameBackBuffer
    mov rax, BUF_WIDTH
    mov rbx, BUF_HEIGHT
    mul rbx
    mov rcx,rax
    mov rsi, GridMemory
    xor rax,rax
Paint:
    mov ebx,0FFFF0000h
    mov [rdi+rcx*4-4],ebx
ContinuePaint:
    loop Paint
    ; cld               ; this is important many  window's function will throw if this is not cleared

    mDrawCircle 100, 100, 200, GameBackBuffer



    ret
UpdateAndRender ENDP


END