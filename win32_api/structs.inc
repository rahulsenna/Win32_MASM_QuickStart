.NOLIST
WNDCLASS STRUCT
  ALIGN DWORD
  style               UINT       ? ;
  ALIGN QWORD
  lpfnWndProc         WNDPROC    ? ;
  ALIGN DWORD
  cbClsExtra          INT32      ? ;
  cbWndExtra          INT32      ? ;
  ALIGN QWORD
  hInstance           HINSTANCE  ? ;
  hIcon               HICON      ? ;
  hCursor             HCURSOR    ? ;
  hbrBackground       HBRUSH     ? ;
  lpszMenuName        LPCSTR     ? ;
  lpszClassName       LPCSTR     ? ;
WNDCLASS ENDS

RECT STRUCT
  left                LONG       ? ;
  top                 LONG       ? ;
  right               LONG       ? ;
  bottom              LONG       ? ;
RECT ENDS

POINT STRUCT
  x                   LONG       ? ;
  y                   LONG       ? ;
POINT ENDS

 MSG STRUCT
  hwnd                HWND       ? ;
  message             UINT       ? ;
  wParam              WPARAM     ? ;
  lParam              LPARAM     ? ;
  time                DWORD      ? ;
  pt                  POINT     <> ;
  lPrivate            DWORD      ? ;
 MSG ENDS



;-----[BITMAP INFO]---------------------------------------------------------------------------------------------------------------


RGBQUAD STRUCT
    ALIGN BYTE
    rgbBlue     BYTE ?
    rgbGreen    BYTE ?
    rgbRed      BYTE ?
    rgbReserved BYTE ?
RGBQUAD ENDS

BITMAPINFOHEADER STRUCT
    ALIGN DWORD
    biSize              DWORD ?
    biWidth             SDWORD  ?
    biHeight            SDWORD  ?
    ALIGN WORD
    biPlanes            WORD  ?
    biBitCount          WORD  ?
    ALIGN DWORD
    biCompression       DWORD ?
    biSizeImage         DWORD ?
    biXPelsPerMeter     SDWORD  ?
    biYPelsPerMeter     SDWORD  ?
    biClrUsed           DWORD ?
    biClrImportant      DWORD ?
BITMAPINFOHEADER ENDS


BITMAPINFO STRUCT
    ALIGN DWORD
    bmiHeader BITMAPINFOHEADER <>
    bmiColors RGBQUAD 1 DUP (<>)
BITMAPINFO ENDS

SYSTEMTIME STRUCT
  ALIGN WORD
  wYear           WORD    ?        
  wMonth          WORD    ?         
  wDayOfWeek      WORD    ?             
  wDay            WORD    ?       
  wHour           WORD    ?        
  wMinute         WORD    ?          
  wSecond         WORD    ?          
  wMilliseconds   WORD    ?                
SYSTEMTIME ENDS