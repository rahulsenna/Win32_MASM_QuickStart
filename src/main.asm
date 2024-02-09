
    OPTION casemap:none

    INCLUDE platform.inc

    WinProc PROTO
    Win32ResizeDIBSection PROTO

.DATA

;----- [Data file includes] -------------------------------------------------------------------------------

    INCLUDE            macros.asm        ; Macros first for subsequent ainclude defs
    ALIGN QWORD
    AInclude           windows.inc

win32_offscreen_buffer STRUCT
    ALIGN DWORD
    Info            BITMAPINFO <>
    Widths          DWORD ?
    Height          DWORD ?
    BytesPerPixel   DWORD ?
    Pitch           DWORD ?
    ALIGN QWORD
    Memory          QWORD ?
win32_offscreen_buffer ENDS


;------ [String constants] ---------------------------------------------------------------------------------
    
    AppLoadMsgTitle        BYTE              "Application Loaded",0
    AppLoadMsgText         BYTE              "This window displays when the WM_CREATE "
                           BYTE              "message is received",0
    PopupTitle             BYTE              "Popup Window",0
    PopupText              BYTE              "This window was activated by a "
                           BYTE              "WM_LBUTTONDOWN message",0
    GreetTitle             BYTE              "Main Window Active",0
    GreetText              BYTE              "This window is shown immediately after "
                           BYTE              "CreateWindow and UpdateWindow are called.",0
    CloseMsg               BYTE              "WM_CLOSE message received",0
    ErrorTitle             BYTE              "Error",0
    WindowName             BYTE              "ASM Windows App",0
    className              BYTE              "ASMWin",0

;------ [Window class structure] ----------------------------------------------------------------------------
    ALIGN QWORD
    MainWin                 WNDCLASS <NULL,WinProc,NULL,NULL,NULL,NULL,NULL,NULL,NULL,className>
   
    hMainWnd                QWORD ?
    hInstance               QWORD ?

    msg                     MSG    <>        ;   
    winRect                 RECT   <>
    DeviceContext           QWORD  ?

    MouseP                  POINT  <>
;------ [Global Variables] ----------------------------------------------------------------------------
    ALIGN QWORD
    ExternDef GlobalBackBuffer:win32_offscreen_buffer
    GlobalBackBuffer        win32_offscreen_buffer <> ;
    ALIGN QWORD
    
    
    GridMemory              QWORD ?
    Velocities              QWORD ?

    ALIGN DWORD
    BitmapMemorySize        DWORD ? 




    KeyState                DWORD 0

    LBUTTON_U    EQU  01111111111111111111111111111111b
    MBUTTON_U    EQU  10111111111111111111111111111111b
    RBUTTON_U    EQU  11011111111111111111111111111111b

    LBUTTON      EQU  10000000000000000000000000000000b
    MBUTTON      EQU  01000000000000000000000000000000b
    RBUTTON      EQU  00100000000000000000000000000000b




    WinDim  RECT <0,0,WIN_WIDTH,WIN_HEIGHT>


    deltaTime  REAL4 ?
    QPC_Begin  REAL8 ?
    QPC_End    REAL8 ?

    QPF        REAL8 ?
ALIGN QWORD


extern UpdateAndRender:PROC
; UpdateAndRender PROTO


;------ [Code] -----------------------------------------------------------------------------------------

.CODE

    AInclude           math.inc



Startup     PROC 
    LOCAL   holder:QWORD,
    h:QWORD,w:QWORD


    call Win32ResizeDIBSection
    ; mov rax, size BITMAPINFOHEADER

    WinCall GetModuleHandle,0
    mov hInstance,rax
    mov MainWin.hInstance, rax
    

    WinCall LoadIcon, NULL, IDI_APPLICATION
    mov MainWin.hIcon, rax
    WinCall LoadCursor, NULL, IDC_ARROW
    mov MainWin.hCursor, rax

    WinCall RegisterClass, OFFSET MainWin 

    
;-----[AdjustWindow]--------------------------------------------------
    WinCall AdjustWindowRectEx, OFFSET WinDim, WS_CAPTION or WS_SYSMENU or WS_MINIMIZEBOX, 0, 0 

    xor rax,rax
    mov eax,WinDim.right
    sub eax,WinDim.left
    mov w,rax
    mov eax,WinDim.bottom
    sub eax,WinDim.top
    mov h,rax

;-----[CreateWindow]--------------------------------------------------
    WinCall CreateWindowEx, 0, OFFSET className, OFFSET WindowName,WS_OVERLAPPEDWINDOW, \
                                800,100,w,h, \
                                NULL,NULL,hInstance,NULL

    mov hMainWnd,rax
    WinCall ShowWindow, rax, SW_SHOW
    WinCall GetDC, hMainWnd
    mov DeviceContext, rax

    WinCall QueryPerformanceFrequency, OFFSET QPF
    mDrawCircle 100, 100, 200, GameBackBuffer

;-----[Main Loop]--------------------------------------------------
Message_Loop:
    WinCall QueryPerformanceCounter, OFFSET QPC_Begin    ; BeginTime


    WinCall PeekMessage, OFFSET msg, NULL,NULL,NULL,PM_REMOVE    
    cmp rax, 0
    je $PostDispatch
    WinCall DispatchMessage, OFFSET msg
    cmp msg.message, WM_QUIT
    je ExitMain
    jmp Message_Loop
$PostDispatch:

    test KeyState,LBUTTON or RBUTTON or MBUTTON
    jz NoMouseClick
    call HandleMouse
NoMouseClick:
; Continue_Message_Loop:

    call UpdateAndRender

    WinCall StretchDIBits, DeviceContext,0,0,WIN_WIDTH,WIN_HEIGHT,0,0,BUF_WIDTH,BUF_HEIGHT,GlobalBackBuffer.Memory, OFFSET GlobalBackBuffer.Info, DIB_RGB_COLORS, SRCCOPY
    
    ;-----[deltaTime Calc]-----------------------------------------------------------------
    WinCall QueryPerformanceCounter, OFFSET QPC_End   ; EndTime
    mov rax,QPC_End
    sub rax,QPC_Begin

    cvtsi2ss xmm0, qword ptr [QPF]     ; TODO:(optimize) try to not load this everytime
    cvtsi2ss xmm1,rax
    divss xmm1,xmm0
    movss real4 ptr [deltaTime], xmm1
    ;-----[deltaTime Calc END]-----------------------------------------------------------------


    cmp msg.message,WM_QUIT
    jne Message_Loop
ExitMain:
    WinCall ExitProcess,69
    ret
Startup     ENDP







;-----[HandleMouse]--------------------------------------------------

HandleMouse PROC
    LOCAL holder:QWORD   

            WinCall GetActiveWindow
            cmp rax,hMainWnd
            jne Continue_Message_Loop

            WinCall GetCursorPos, OFFSET MouseP
            WinCall ScreenToClient, hMainWnd, OFFSET MouseP

        ;-----[Mouse Left Button Clicked ?]-------------------------------------------
            test KeyState,LBUTTON
            jz NotSand  ; if rax == 08000h (1 << 15) ; zero flag will be cleared
            nop
        NotSand:
            test KeyState,RBUTTON
            jz NotWater
            nop
        NotWater:
        ;-----[Is mouse pointer inside the window ?]-------------------------------------------
            cmp MouseP.y,WIN_HEIGHT-1
            jg Continue_Message_Loop
            cmp MouseP.x,WIN_WIDTH-1
            jg Continue_Message_Loop

            cmp MouseP.y,0
            jl Continue_Message_Loop
            cmp MouseP.x,0
            jl Continue_Message_Loop

        ;-----[PutPixel in Grid]-------------------------------------------
        ;  Cicular Pattern for Spawning elements
    .data
        PI    DWORD 3.1415926535897932
        PIx2  DWORD 6.2831853071795864
        ZeroPointZeroOne dword 0.01
        Theta  dword ?
        Cos  dword ?
        Sin  dword ?
        R equ 25          ; Radius constant
        rx dword ?
        ry dword ?
        RandRadius dword ?
    .code
                
                xor r10,r10
                xor r9,r9
                mov rsi, GameBackBuffer
                mov r8, BUF_WIDTH
                xor rbx,rbx
                mov r9d, MouseP.y
                shr r9d,WIN_HEIGHT/BUF_HEIGHT-1         ; scale height for mouse pointer;
                mov r10d,MouseP.x
                shr r10d,WIN_WIDTH/BUF_WIDTH-1           ; scale width for mouse pointer


                mov rax, 20           ; amt of elements per click
                call RandomRange
                mov rcx, rax

                movss xmm4, [ZeroPointZeroOne]


        PutElem:

                mov eax, 100 
                call RandomRange
                cvtsi2ss xmm0,eax
                movss xmm1, xmm4
                mulss xmm0,xmm1
                
                movss xmm2, dword ptr [PIx2]
                mulss xmm0,xmm2
                movss dword ptr [Theta], xmm0

                fld dword ptr [Theta]
                fsincos
                fstp dword ptr [Cos]
                fstp dword ptr [Sin]

                ; RandRadius
                mov eax, 100 
                call RandomRange
                cvtsi2ss xmm0,eax
                movss xmm1, xmm4
                mulss xmm0,xmm1
                sqrtss xmm0,xmm0
                mov eax,R
                cvtsi2ss xmm1,eax
                mulss xmm0,xmm1
                ; movss dword ptr [RandRadius],xmm0

                ; Rx Ry
                movss xmm1, [Cos]
                mulss xmm1,xmm0
                cvtss2si eax,xmm1
                mov r11, rax       ; rx
                movss xmm2, [Sin]
                mulss xmm2,xmm0
                cvtss2si eax,xmm2
                ; mov ry, eax
                mov r12, rax       ; ry


                
                mov rax,r8         ; r8 = BufferWidth
                mov rbx,r9         ; r9 = Y
                add ebx,r12d       ; Y+ry
                mul rbx
                
        
                add rax,r10        ; r10 = X
                add eax,r11d       ; X+rx

                nop
                mov  DWORD PTR [rsi+rax*4-4], 0FFFF0000h  ;


    ; Loop PutElem
    dec rcx
    cmp rcx,0
    jg PutElem




Continue_Message_Loop:
    ret
HandleMouse ENDP




;-----[Main Loop]--------------------------------------------------

WinProc PROC
    LOCAL   holder:QWORD
    
    cmp edx,WM_LBUTTONDOWN
    jne NoLeftButtonDown
    or KeyState,LBUTTON
NoLeftButtonDown:
cmp edx,WM_LBUTTONUP
    jne NoLeftButtonUp
    and KeyState,LBUTTON_U
NoLeftButtonUp:


    cmp edx,WM_RBUTTONDOWN
    jne NoRightButtonDown
    or KeyState,RBUTTON
NoRightButtonDown:
cmp edx,WM_RBUTTONUP
    jne NoRightButtonUp
    and KeyState,RBUTTON_U
NoRightButtonUp:



    ; cmp edx,WM_PAINT
    ; jne NoPaint
    ; WinCall StretchDIBits, DeviceContext,0,0,WIN_WIDTH,WIN_HEIGHT,0,0,BUF_WIDTH,BUF_HEIGHT,GlobalBackBuffer.Memory, OFFSET GlobalBackBuffer.Info, DIB_RGB_COLORS, SRCCOPY
NoPaint:


    cmp edx,WM_DESTROY
    jne EndWinProc
    WinCall PostQuitMessage,0    
EndWinProc:
    WinCall DefWindowProc
    ret
WinProc ENDP







;-----[Win32ResizeDIBSection]--------------------------------------------------
Win32ResizeDIBSection PROC
    LOCAL holder:QWORD

    cmp GlobalBackBuffer.Memory,0
    jne SkipVirtualFree
    WinCall VirtualFree, OFFSET GlobalBackBuffer.Memory, 0, MEM_RELEASE 
SkipVirtualFree:
;-----[Setting Bitmap]--------------------------------------------------
    mov GlobalBackBuffer.Widths,BUF_WIDTH
    mov GlobalBackBuffer.Height,BUF_HEIGHT
    mov GlobalBackBuffer.BytesPerPixel,4
    mov GlobalBackBuffer.Pitch, BUF_WIDTH
    shl GlobalBackBuffer.Pitch,2 ; GlobalBackBuffer.Pitch*4

    mov GlobalBackBuffer.Info.bmiHeader.biSize, sizeof GlobalBackBuffer.Info.bmiHeader
    mov GlobalBackBuffer.Info.bmiHeader.biWidth, BUF_WIDTH
    mov GlobalBackBuffer.Info.bmiHeader.biHeight, -BUF_HEIGHT;
    mov GlobalBackBuffer.Info.bmiHeader.biPlanes,1;
    mov GlobalBackBuffer.Info.bmiHeader.biBitCount,32;
    mov GlobalBackBuffer.Info.bmiHeader.biCompression, BI_RGB;
;--[VirtualAlloc]------------------
;----------------[VideoMemory]------------------

    mov rax, BUF_WIDTH
    mov rbx, BUF_HEIGHT
    mul rbx
    shl rax,2 ; w*h*4
    mov BitmapMemorySize,eax

    WinCall VirtualAlloc, 0,rax,MEM_COMMIT,PAGE_READWRITE
    mov GlobalBackBuffer.Memory,rax
    mov GameBackBuffer,rax


;----------------[GridMemory]------------------
    mov rax, BUF_WIDTH
    mov rbx, BUF_HEIGHT
    mul rbx

    WinCall VirtualAlloc, 0,rax,MEM_COMMIT,PAGE_READWRITE
    mov GridMemory,rax

    mov rax, BUF_WIDTH
    mov rbx, BUF_HEIGHT
    mul rbx
    mov rbx, 8          ; 2*real4
    mul rbx
    WinCall VirtualAlloc, 0,rax,MEM_COMMIT,PAGE_READWRITE
    mov Velocities,rax

    ret
Win32ResizeDIBSection ENDP












END        ; End module
