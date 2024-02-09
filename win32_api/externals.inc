
.NOLIST
;                                                                                                                      -;
; External function declarations.                                                                                      -;
;                                                                                                                      -;




extrn                                            __imp_AdjustWindowRect:QWORD                                          ;;





extrn                                            __imp_CreateWindowExA:QWORD                                           ;;



extrn                                            __imp_DefWindowProcA:QWORD                                            ;;
extrn                                            __imp_DestroyWindow:QWORD                                             ;;
extrn                                            __imp_DispatchMessageA:QWORD                                          ;;
; extrn                                            __imp_D3D11CreateDeviceAndSwapChain:QWORD                             ;;
; extrn                                            __imp_D3DX11CompileFromFileA:QWORD                                    ;;



extrn                                            __imp_EnumDesktopWindows:QWORD                                        ;;
extrn                                            __imp_ExitProcess:QWORD                                               ;;





extrn                                            __imp_GetClientRect:QWORD                                             ;;
extrn                                            __imp_GetCurrentThreadId:QWORD                                        ;;
extrn                                            __imp_GetLastError:QWORD                                              ;;
extrn                                            __imp_GetModuleHandleA:QWORD                                          ;;
extrn                                            __imp_GetParent:QWORD                                                 ;;
extrn                                            __imp_GetThreadDesktop:QWORD                                          ;;
extrn                                            __imp_GetWindowTextA:QWORD                                            ;;











extrn                                            __imp_LoadImageA:QWORD                                                ;;



extrn                                            __imp_MoveWindow:QWORD                                                ;;







extrn                                            __imp_PeekMessageA:QWORD                                              ;;
extrn                                            __imp_PostQuitMessage:QWORD                                           ;;





extrn                                            __imp_RegisterClassExA:QWORD                                          ;;



extrn                                            __imp_SendMessageA:QWORD                                              ;;
extrn                                            __imp_ShowWindow:QWORD                                                ;;
extrn                                            __imp_SystemParametersInfoA:QWORD                                     ;;



extrn                                            __imp_TranslateMessage:QWORD                                          ;;



extrn                                            __imp_UnregisterClassA:QWORD                                          ;;



extrn                                            __imp_ValidateRect:QWORD                                              ;;









AdjustWindowRect                                 TEXTEQU             <__imp_AdjustWindowRect>                          ;;




; HWND CreateWindowExA(
;   [in]           DWORD     dwExStyle,
;   [in, optional] LPCSTR    lpClassName,
;   [in, optional] LPCSTR    lpWindowName,
;   [in]           DWORD     dwStyle,
;   [in]           int       X,
;   [in]           int       Y,
;   [in]           int       nWidth,
;   [in]           int       nHeight,
;   [in, optional] HWND      hWndParent,
;   [in, optional] HMENU     hMenu,
;   [in, optional] HINSTANCE hInstance,
;   [in, optional] LPVOID    lpParam
; );
CreateWindowEx                                   TEXTEQU             <__imp_CreateWindowExA>                           ;;



D3D11CreateDeviceAndSwapChain                    TEXTEQU             <__imp_D3D11CreateDeviceAndSwapChain>             ;;
D3DX11CompileFromFile                            TEXTEQU             <__imp_D3DX11CompileFromFileA>                    ;;
DefWindowProc                                    TEXTEQU             <__imp_DefWindowProcA>                            ;;
DestroyWindow                                    TEXTEQU             <__imp_DestroyWindow>                             ;;
DispatchMessage                                  TEXTEQU             <__imp_DispatchMessageA>                          ;;



EnumDesktopWindows                               TEXTEQU             <__imp_EnumDesktopWindows>                        ;;
ExitProcess                                      TEXTEQU             <__imp_ExitProcess>                               ;;





GetClientRect                                    TEXTEQU             <__imp_GetClientRect>                             ;;
GetCurrentThreadId                               TEXTEQU             <__imp_GetCurrentThreadId>                        ;;
GetLastError                                     TEXTEQU             <__imp_GetLastError>                              ;;
GetModuleHandle                                  TEXTEQU             <__imp_GetModuleHandleA>                          ;;
GetParent                                        TEXTEQU             <__imp_GetParent>                                 ;;
GetThreadDesktop                                 TEXTEQU             <__imp_GetThreadDesktop>                          ;;
GetWindowText                                    TEXTEQU             <__imp_GetWindowTextA>                            ;;











LoadImage                                        TEXTEQU             <__imp_LoadImageA>                                ;;



MoveWindow                                       TEXTEQU             <__imp_MoveWindow>                                ;;







PeekMessage                                      TEXTEQU             <__imp_PeekMessageA>                              ;;
PostQuitMessage                                  TEXTEQU             <__imp_PostQuitMessage>                           ;;




RegisterClassEx                                  TEXTEQU             <__imp_RegisterClassExA>                          ;;
    



SendMessage                                      TEXTEQU             <__imp_SendMessageA>                              ;;
ShowWindow                                       TEXTEQU             <__imp_ShowWindow>                                ;;
SystemParametersInfo                             TEXTEQU             <__imp_SystemParametersInfoA>                     ;;


TranslateMessage                                 TEXTEQU             <__imp_TranslateMessage>                          ;;


UnregisterClass                                  TEXTEQU             <__imp_UnregisterClassA>                          ;;


ValidateRect                                     TEXTEQU             <__imp_ValidateRect>                              ;;




    extern                                    __imp_MessageBoxA:QWORD
;   int MessageBox(
;   [in, optional] HWND    hWnd,
;   [in, optional] LPCTSTR lpText,
;   [in, optional] LPCTSTR lpCaption,
;   [in]           UINT    uType
; );
MessageBox                  TEXTEQU      <__imp_MessageBoxA>


    extrn                                     __imp_Sleep:QWORD
    Sleep                       TEXTEQU      <__imp_Sleep>


    extrn                                     __imp_GetKeyState:QWORD
    GetKeyState                 TEXTEQU      <__imp_GetKeyState>


    extrn                                     __imp_ScreenToClient:QWORD
    ScreenToClient              TEXTEQU      <__imp_ScreenToClient>
    
    extrn                                     __imp_GetCursorPos:QWORD
    GetCursorPos                TEXTEQU      <__imp_GetCursorPos>

    extrn                                     __imp_GetActiveWindow:QWORD
    GetActiveWindow             TEXTEQU      <__imp_GetActiveWindow>

    extrn                                     __imp_BeginPaint:QWORD
    BeginPaint                  TEXTEQU      <__imp_BeginPaint>

    extrn                                     __imp_FillRect:QWORD
    FillRect                    TEXTEQU      <__imp_FillRect>

    extrn                                     __imp_EndPaint:QWORD
    EndPaint                    TEXTEQU      <__imp_EndPaint>


;-------------------------------------------------------------------------
    extrn                                     __imp_VirtualAlloc:QWORD
;LPVOID VirtualAlloc(
;   [in, optional] LPVOID lpAddress,
;   [in]           SIZE_T dwSize,
;   [in]           DWORD  flAllocationType,
;   [in]           DWORD  flProtect
; );
VirtualAlloc                TEXTEQU      <__imp_VirtualAlloc>
;-------------------------------------------------------------------------

;-------------------------------------------------------------------------
    extrn                                     __imp_VirtualFree:QWORD
;LPVOID VirtualFree
VirtualFree                TEXTEQU      <__imp_VirtualFree>
;-------------------------------------------------------------------------



;-------------------------------------------------------------------------
    extrn                                     __imp_StretchDIBits:QWORD
; int StretchDIBits(
;   [in] HDC              hdc,
;   [in] int              xDest,
;   [in] int              yDest,
;   [in] int              DestWidth,
;   [in] int              DestHeight,
;   [in] int              xSrc,
;   [in] int              ySrc,
;   [in] int              SrcWidth,
;   [in] int              SrcHeight,
;   [in] const VOID       *lpBits,
;   [in] const BITMAPINFO *lpbmi,
;   [in] UINT             iUsage,
;   [in] DWORD            rop
; );
StretchDIBits               TEXTEQU      <__imp_StretchDIBits>
;-------------------------------------------------------------------------


    extrn                                     __imp_GetDC:QWORD
    GetDC                       TEXTEQU      <__imp_GetDC>




;-------------------------------------------------------------------------
    extern __imp_RegisterClassA:QWORD
; ATOM RegisterClassA(
;   [in] const WNDCLASSA *lpWndClass
; );
RegisterClass                                  TEXTEQU             <__imp_RegisterClassA>
;-------------------------------------------------------------------------
    extern __imp_LoadIconA:QWORD
    LoadIcon                                  TEXTEQU             <__imp_LoadIconA>
    extern __imp_LoadCursorA:QWORD
    LoadCursor     TEXTEQU             <__imp_LoadCursorA>

extern __imp_DefWindowProcA:QWORD
DefWindowProc     TEXTEQU             <__imp_DefWindowProcA>


;-------------------------------------------------------------------------
    extern        __imp_GetMessageA:QWORD
; BOOL GetMessage(
;   [out]          LPMSG lpMsg,
;   [in, optional] HWND  hWnd,
;   [in]           UINT  wMsgFilterMin,
;   [in]           UINT  wMsgFilterMax
; );
GetMessage        TEXTEQU             <__imp_GetMessageA>
;-------------------------------------------------------------------------


    extern __imp_AdjustWindowRectEx:QWORD
    AdjustWindowRectEx TEXTEQU <__imp_AdjustWindowRectEx>



extern __imp_GetSystemTime:QWORD
GetSystemTime        TEXTEQU          <__imp_GetSystemTime>



extern __imp_QueryPerformanceCounter:QWORD
QueryPerformanceCounter        TEXTEQU          <__imp_QueryPerformanceCounter>
extern __imp_QueryPerformanceFrequency:QWORD
QueryPerformanceFrequency        TEXTEQU          <__imp_QueryPerformanceFrequency>

