.NOLIST

;/*
;* VIRTUAL KEYS, STANDARD SET
;*/
    VK_LBUTTON                  EQU            01H
    VK_RBUTTON                  EQU            02H
    VK_CANCEL                   EQU            03H
    VK_MBUTTON                  EQU            04H    ;/* NOT CONTIGUOUS WITH L & RBUTTON */
    ;/*
    ;* VIRTUAL KEYS, STANDARD SET
    ;*/

    ;/* CONSTANTS FOR THE BICOMPRESSION FIELD */
    BI_RGB                      EQU              0
    BI_RLE8                     EQU              1
    BI_RLE4                     EQU              2
    BI_BITFIELDS                EQU              3
    BI_JPEG                     EQU              4
    BI_PNG                      EQU              5
    ;/* CONSTANTS FOR THE BICOMPRESSION FIELD */

    DIB_RGB_COLORS              EQU              0 ;/* COLOR TABLE IN RGBS */;
    SRCCOPY                     EQU      00CC0020H ;/* DEST = SOURCE                   */


    MEM_COMMIT                  EQU      00001000H  
    MEM_RESERVE                 EQU      00002000H  
    PAGE_NOACCESS               EQU            01H    
    PAGE_READONLY               EQU            02H    
    PAGE_READWRITE              EQU            04H    
    PAGE_WRITECOPY              EQU            08H    
    PAGE_EXECUTE                EQU            10H    
    PAGE_EXECUTE_READ           EQU            20H    
    PAGE_EXECUTE_READWRITE      EQU            40H    
    PAGE_EXECUTE_WRITECOPY      EQU            80H    

    MEM_DECOMMIT                EQU      00004000H
    MEM_RELEASE                 EQU      00008000H
    MEM_FREE                    EQU      00010000H


    ; Win32 Console handles
    STD_INPUT_HANDLE            EQU              -10
    STD_OUTPUT_HANDLE           EQU              -11		; predefined Win API constant
    STD_ERROR_HANDLE            EQU              -12

    ;  Input Mode flags (used by GetConsoleMode & SetConsoleMode):
    ENABLE_PROCESSED_INPUT      =                  1
    ENABLE_LINE_INPUT           =                  2
    ENABLE_ECHO_INPUT           =                  4
    ENABLE_WINDOW_INPUT         =                  8
    ENABLE_MOUSE_INPUT          =                 16

    ; Event constants
    KEY_EVENT                   =                  1
    MOUSE_EVENT                 =                  2
    WINDOW_BUFFER_SIZE_EVENT    =                  4          ; window change event record
    MENU_EVENT                  =                  8                   ; menu event record
    FOCUS_EVENT                 =                 16                  ; focus change

    ; ControlKeyState constants (used by ReadKey)
    KEY_MASKS  = 00011111b		; Mask if any Shift/Ctrl/Alt flag is set
    ALT_MASK   = 00000011b		; Left and right Alt key flags
    CTRL_MASK  = 00001100b		; Left and right Alt key flags
    SHIFT_MASK = 00010000b		; Left or right Shift key flag

    KBDOWN_FLAG = 00000001h		; Bit set for press, clear for release

    ;  Output mode flags  (used by GetConsoleMode & SetConsoleMode):
    ENABLE_PROCESSED_OUTPUT    = 1
    ENABLE_WRAP_AT_EOL_OUTPUT  = 2

    ; Constants found in WINNT.H
    FILE_SHARE_READ                 = 1
    FILE_SHARE_WRITE                = 2
    FILE_SHARE_DELETE               = 4

    FILE_ATTRIBUTE_READONLY         = 1
    FILE_ATTRIBUTE_HIDDEN           = 2
    FILE_ATTRIBUTE_SYSTEM           = 4
    FILE_ATTRIBUTE_DIRECTORY        = 10h
    FILE_ATTRIBUTE_ARCHIVE          = 20h
    FILE_ATTRIBUTE_DEVICE           = 40h
    FILE_ATTRIBUTE_NORMAL           = 80h
    FILE_ATTRIBUTE_TEMPORARY        = 100h
    FILE_ATTRIBUTE_SPARSE_FILE      = 200h
    FILE_ATTRIBUTE_REPARSE_POINT    = 400h
    FILE_ATTRIBUTE_COMPRESSED       = 800h
    FILE_ATTRIBUTE_OFFLINE          =    1000h
    FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 2000h
    FILE_ATTRIBUTE_ENCRYPTED           = 4000h

    FILE_READ_DATA = 1
    FILE_WRITE_DATA = 2
    FILE_APPEND_DATA = 4
    FILE_DELETE_CHILD = 40h

    GENERIC_READ     = 80000000h
    GENERIC_WRITE    = 40000000h
    GENERIC_EXECUTE  = 20000000h
    GENERIC_ALL      = 10000000h

    ; Memory allocation constants
    HEAP_NO_SERIALIZE              = 00000001h
    HEAP_GROWABLE                  = 00000002h
    HEAP_GENERATE_EXCEPTIONS       = 00000004h
    HEAP_ZERO_MEMORY               = 00000008h
    HEAP_REALLOC_IN_PLACE_ONLY     = 00000010h

    ; Error Handler Variables
    FORMAT_MESSAGE_ALLOCATE_BUFFER     = 100h
    FORMAT_MESSAGE_FROM_SYSTEM         = 1000h

    ;------------- Message Box Constants ---------------

    ; Icons:
    MB_ICONHAND            = 10h
    MB_ICONQUESTION        = 20h
    MB_ICONEXCLAMATION     = 30h
    MB_ICONASTERISK        = 40h
    MB_USERICON            = 80h
    MB_ICONWARNING         = MB_ICONEXCLAMATION
    MB_ICONERROR           = MB_ICONHAND
    MB_ICONINFORMATION     = MB_ICONASTERISK
    MB_ICONSTOP            = MB_ICONHAND

    ; Buttons:
    MB_OK         = 0
    MB_OKCANCEL   = 1
    MB_ABORTRETRYIGNORE = 2
    MB_YESNOCANCEL = 3
    MB_YESNO       = 4
    MB_RETRYCANCEL = 5
    MB_CANCELTRYCONTINUE = 6
    MB_HELP        =  4000h          ; does not close the window

    ; Select the default button:
    MB_DEFBUTTON1 = 0
    MB_DEFBUTTON2 = 100h
    MB_DEFBUTTON3 = 200h
    MB_DEFBUTTON4 = 300h

    ; Modal control buttons:
    MB_APPLMODAL     =  0
    MB_SYSTEMMODAL   =  1000h	; dialog floats above all windows
    MB_TASKMODAL     =  2000h

    ; Return values:
    IDOK               = 1
    IDCANCEL           = 2
    IDABORT            = 3
    IDRETRY            = 4
    IDIGNORE           = 5
    IDYES              = 6
    IDNO               = 7
    IDCLOSE            = 8
    IDHELP             = 9
    IDTRYAGAIN         = 10
    IDCONTINUE         = 11
    IDTIMEOUT          = 32000

    ;------------------ From winbase.h ----------------------------
    CREATE_NEW         = 1
    CREATE_ALWAYS      = 2
    OPEN_EXISTING      = 3
    OPEN_ALWAYS        = 4
    TRUNCATE_EXISTING  = 5

    FILE_BEGIN         =  0
    FILE_CURRENT       =  1
    FILE_END           =  2

    INVALID_HANDLE_VALUE = -1

    ;--------------------From wincon.h ---------------------------

    ; ControlKeyState flags

    RIGHT_ALT_PRESSED    = 0001h      ; the right alt key is pressed.
    LEFT_ALT_PRESSED     = 0002h      ; the left alt key is pressed.
    RIGHT_CTRL_PRESSED   = 0004h      ; the right ctrl key is pressed.
    LEFT_CTRL_PRESSED    = 0008h      ; the left ctrl key is pressed.
    SHIFT_PRESSED        = 0010h      ; the shift key is pressed.
    NUMLOCK_ON           = 0020h      ; the numlock light is on.
    SCROLLLOCK_ON        = 0040h      ; the scrolllock light is on.
    CAPSLOCK_ON          = 0080h      ; the capslock light is on.
    ENHANCED_KEY         = 0100h      ; the key is enhanced.

    ;---------------------- from WinUser.h -------------------------

    VK_NUMLOCK  =   90h
    VK_SCROLL   =   91h
    VK_LSHIFT   =   0A0h
    VK_RSHIFT   =   0A1h
    VK_LCONTROL =   0A2h
    VK_RCONTROL =   0A3h
    VK_LMENU    =   0A4h
    VK_RMENU    =   0A5h

    ;----------------------------------------------------------------

; RegisterClass Constants (from Winuser.h)
COLOR_WINDOW        = 5		; std window color
COLOR_BACKGROUND    = 2		; 2=blue F=gray
IDI_APPLICATION     = 32512		; application icon
IDC_ARROW           = 07f00h		; mouse cursor--arrow
CW_USEDEFAULT       = 80000000h		; default window size & position

;-----------------------------------------------------------------------------------------------------------------------
;                                                                                                                      -
; WINDOWS CONSTANTS.                                                                                                   -
;                                                                                                                      -
;-----------------------------------------------------------------------------------------------------------------------

;-----[A] --------------------------------------------------------------------------------------------------------------

;-----[B] --------------------------------------------------------------------------------------------------------------

;-----[C] --------------------------------------------------------------------------------------------------------------

    CS_VREDRAW                                       EQU                 00000001H
    CS_HREDRAW                                       EQU                 00000002H
    CS_DBLCLKS                                       EQU                 00000008H
    CS_OWNDC                                         EQU                 00000020H
    CS_CLASSDC                                       EQU                 00000040H
    CS_PARENTDC                                      EQU                 00000080H
    CS_NOCLOSE                                       EQU                 00000200H
    CS_SAVEBITS                                      EQU                 00000800H
    CS_BYTEALIGNCLIENT                               EQU                 00001000H
    CS_BYTEALIGNWINDOW                               EQU                 00002000H
    CS_GLOBALCLASS                                   EQU                 00004000H
    CS_IME                                           EQU                 00010000H
    CS_DROPSHADOW                                    EQU                 00020000H

;-----[T]---------------------------------------------------------------------------------------------------------------

;-----[U]---------------------------------------------------------------------------------------------------------------

;-----[V]---------------------------------------------------------------------------------------------------------------

;-----[W]---------------------------------------------------------------------------------------------------------------

    WM_ACTIVATE                                      EQU                 00000006H                                         ;
    WM_ACTIVATEAPP                                   EQU                 0000001CH                                         ;
    WM_AFXFIRST                                      EQU                 00000360H                                         ;
    WM_AFXLAST                                       EQU                 0000037FH                                         ;
    WM_APP                                           EQU                 00008000H                                         ;
    WM_ASKCBFORMATNAME                               EQU                 0000030CH                                         ;
    WM_CANCELJOURNAL                                 EQU                 0000004BH                                         ;
    WM_CANCELMODE                                    EQU                 0000001FH                                         ;
    WM_CAPTURECHANGED                                EQU                 00000025H                                         ;
    WM_CHANGECBCHAIN                                 EQU                 0000030DH                                         ;
    WM_CHAR                                          EQU                 00000102H                                         ;
    WM_CHARTOITEM                                    EQU                 0000002FH                                         ;
    WM_CHILDACTIVATE                                 EQU                 00000022H                                         ;
    WM_CLEAR                                         EQU                 00000303H                                         ;
    WM_CLOSE                                         EQU                 00000010H                                         ;
    WM_COMMAND                                       EQU                 00000111H                                         ;
    WM_COMMNOTIFY                                    EQU                 00000044H                                         ;
    WM_COMPACTING                                    EQU                 00000041H                                         ;
    WM_COMPAREITEM                                   EQU                 00000039H                                         ;
    WM_CONTEXTMENU                                   EQU                 0000007BH                                         ;
    WM_COPY                                          EQU                 00000301H                                         ;
    WM_COPYDATA                                      EQU                 0000004AH                                         ;
    WM_CREATE                                        EQU                 00000001H                                         ;
    WM_CTLCOLORBTN                                   EQU                 00000135H                                         ;
    WM_CTLCOLORDLG                                   EQU                 00000136H                                         ;
    WM_CTLCOLOREDIT                                  EQU                 00000133H                                         ;
    WM_CTLCOLORLISTBOX                               EQU                 00000134H                                         ;
    WM_CTLCOLORMSGBOX                                EQU                 00000132H                                         ;
    WM_CTLCOLORSCROLLBAR                             EQU                 00000137H                                         ;
    WM_CTLCOLORSTATIC                                EQU                 00000138H                                         ;
    WM_CUT                                           EQU                 00000300H                                         ;
    WM_DEADCHAR                                      EQU                 00000103H                                         ;
    WM_DELETEITEM                                    EQU                 0000002DH                                         ;
    WM_DESTROY                                       EQU                 00000002H                                         ;
    WM_DESTROYCLIPBOARD                              EQU                 00000307H                                         ;
    WM_DEVICECHANGE                                  EQU                 00000219H                                         ;
    WM_DEVMODECHANGE                                 EQU                 0000001BH                                         ;
    WM_DISPLAYCHANGE                                 EQU                 0000007EH                                         ;
    WM_DRAWCLIPBOARD                                 EQU                 00000308H                                         ;
    WM_DRAWITEM                                      EQU                 0000002BH                                         ;
    WM_DROPFILES                                     EQU                 00000233H                                         ;
    WM_ENABLE                                        EQU                 0000000AH                                         ;
    WM_ENDSESSION                                    EQU                 00000016H                                         ;
    WM_ENTERIDLE                                     EQU                 00000121H                                         ;
    WM_ENTERMENULOOP                                 EQU                 00000211H                                         ;
    WM_ENTERSIZEMOVE                                 EQU                 00000231H                                         ;
    WM_ERASEBKGND                                    EQU                 00000014H                                         ;
    WM_EXITMENULOOP                                  EQU                 00000212H                                         ;
    WM_EXITSIZEMOVE                                  EQU                 00000232H                                         ;
    WM_FONTCHANGE                                    EQU                 0000001DH                                         ;
    WM_GETDLGCODE                                    EQU                 00000087H                                         ;
    WM_GETFONT                                       EQU                 00000031H                                         ;
    WM_GETHOTKEY                                     EQU                 00000033H                                         ;
    WM_GETICON                                       EQU                 0000007FH                                         ;
    WM_GETMINMAXINFO                                 EQU                 00000024H                                         ;
    WM_GETTEXT                                       EQU                 0000000DH                                         ;
    WM_GETTEXTLENGTH                                 EQU                 0000000EH                                         ;
    WM_HANDHELDFIRST                                 EQU                 00000358H                                         ;
    WM_HANDHELDLAST                                  EQU                 0000035FH                                         ;
    WM_HELP                                          EQU                 00000053H                                         ;
    WM_HOTKEY                                        EQU                 00000312H                                         ;
    WM_HSCROLL                                       EQU                 00000114H                                         ;
    WM_HSCROLLCLIPBOARD                              EQU                 0000030EH                                         ;
    WM_ICONERASEBKGND                                EQU                 00000027H                                         ;
    WM_IME_CHAR                                      EQU                 00000286H                                         ;
    WM_IME_COMPOSITION                               EQU                 0000010FH                                         ;
    WM_IME_COMPOSITIONFULL                           EQU                 00000284H                                         ;
    WM_IME_CONTROL                                   EQU                 00000283H                                         ;
    WM_IME_ENDCOMPOSITION                            EQU                 0000010EH                                         ;
    WM_IME_KEYDOWN                                   EQU                 00000290H                                         ;
    WM_IME_KEYLAST                                   EQU                 0000010FH                                         ;
    WM_IME_KEYUP                                     EQU                 00000291H                                         ;
    WM_IME_NOTIFY                                    EQU                 00000282H                                         ;
    WM_IME_SELECT                                    EQU                 00000285H                                         ;
    WM_IME_SETCONTEXT                                EQU                 00000281H                                         ;
    WM_IME_STARTCOMPOSITION                          EQU                 0000010DH                                         ;
    WM_INITDIALOG                                    EQU                 00000110H                                         ;
    WM_INITMENU                                      EQU                 00000116H                                         ;
    WM_INITMENUPOPUP                                 EQU                 00000117H                                         ;
    WM_INPUT                                         EQU                 000000FFH                                         ;
    WM_INPUTLANGCHANGE                               EQU                 00000051H                                         ;
    WM_INPUTLANGCHANGER                              EQU                 00000050H                                         ;
    WM_KEYDOWN                                       EQU                 00000100H                                         ;
    WM_KEYFIRST                                      EQU                 00000100H                                         ;
    WM_KEYLAST                                       EQU                 00000108H                                         ;
    WM_KEYUP                                         EQU                 00000101H                                         ;
    WM_KILLFOCUS                                     EQU                 00000008H                                         ;
    WM_LBUTTONDBLCLK                                 EQU                 00000203H                                         ;
    WM_LBUTTONDOWN                                   EQU                 00000201H                                         ;
    WM_LBUTTONUP                                     EQU                 00000202H                                         ;
    WM_MBUTTONDBLCLK                                 EQU                 00000209H                                         ;
    WM_MBUTTONDOWN                                   EQU                 00000207H                                         ;
    WM_MBUTTONUP                                     EQU                 00000208H                                         ;
    WM_MDIACTIVATE                                   EQU                 00000222H                                         ;
    WM_MDICASCADE                                    EQU                 00000227H                                         ;
    WM_MDICREATE                                     EQU                 00000220H                                         ;
    WM_MDIDESTROY                                    EQU                 00000221H                                         ;
    WM_MDIGETACTIVE                                  EQU                 00000229H                                         ;
    WM_MDIICONARRANGE                                EQU                 00000228H                                         ;
    WM_MDIMAXIMIZE                                   EQU                 00000225H                                         ;
    WM_MDINEXT                                       EQU                 00000224H                                         ;
    WM_MDIREFRESHMENU                                EQU                 00000234H                                         ;
    WM_MDIRESTORE                                    EQU                 00000223H                                         ;
    WM_MDISETMENU                                    EQU                 00000230H                                         ;
    WM_MDITILE                                       EQU                 00000226H                                         ;
    WM_MEASUREITEM                                   EQU                 0000002CH                                         ;
    WM_MENUCHAR                                      EQU                 00000120H                                         ;
    WM_MENUCOMMAND                                   EQU                 00000126H                                         ;
    WM_MENUSELECT                                    EQU                 0000011FH                                         ;
    WM_MOUSEACTIVATE                                 EQU                 00000021H                                         ;
    WM_MOUSEENTER                                    EQU                 000002A2H                                         ;
    WM_MOUSEFIRST                                    EQU                 00000200H                                         ;
    WM_MOUSEHOVER                                    EQU                 000002A1H                                         ;
    WM_MOUSELAST                                     EQU                 00000209H                                         ;
    WM_MOUSEHWHEEL                                   EQU                 0000020EH                                         ;
    WM_MOUSEWHEEL                                    EQU                 0000020AH                                         ;
    WM_MOUSELEAVE                                    EQU                 000002A3H                                         ;
    WM_MOUSEMOVE                                     EQU                 00000200H                                         ;
    WM_MOVE                                          EQU                 00000003H                                         ;
    WM_MOVING                                        EQU                 00000216H                                         ;
    WM_NCACTIVATE                                    EQU                 00000086H                                         ;
    WM_NCCALCSIZE                                    EQU                 00000083H                                         ;
    WM_NCCREATE                                      EQU                 00000081H                                         ;
    WM_NCDESTROY                                     EQU                 00000082H                                         ;
    WM_NCHITTEST                                     EQU                 00000084H                                         ;
    WM_NCLBUTTONDBLCLK                               EQU                 000000A3H                                         ;
    WM_NCLBUTTONDOWN                                 EQU                 000000A1H                                         ;
    WM_NCLBUTTONUP                                   EQU                 000000A2H                                         ;
    WM_NCMBUTTONDBLCLK                               EQU                 000000A9H                                         ;
    WM_NCMBUTTONDOWN                                 EQU                 000000A7H                                         ;
    WM_NCMBUTTONUP                                   EQU                 000000A8H                                         ;
    WM_NCMOUSEHOVER                                  EQU                 000002A0H                                         ;
    WM_NCMOUSELEAVE                                  EQU                 000002A2H                                         ;
    WM_NCMOUSEMOVE                                   EQU                 000000A0H                                         ;
    WM_NCPAINT                                       EQU                 00000085H                                         ;
    WM_NCRBUTTONDBLCLK                               EQU                 000000A6H                                         ;
    WM_NCRBUTTONDOWN                                 EQU                 000000A4H                                         ;
    WM_NCRBUTTONUP                                   EQU                 000000A5H                                         ;
    WM_NCXBUTTONDBLCLK                               EQU                 000000ADH                                         ;
    WM_NCXBUTTONDOWN                                 EQU                 000000ABH                                         ;
    WM_NCXBUTTONUP                                   EQU                 000000ACH                                         ;
    WM_NEXTDLGCTL                                    EQU                 00000028H                                         ;
    WM_NEXTMENU                                      EQU                 00000213H                                         ;
    WM_NOTIFY                                        EQU                 0000004EH                                         ;
    WM_NOTIFYFORMAT                                  EQU                 00000055H                                         ;
    WM_NULL                                          EQU                 00000000H                                         ;
    WM_PAINT                                         EQU                 0000000FH                                         ;
    WM_PAINTCLIPBOARD                                EQU                 00000309H                                         ;
    WM_PAINTICON                                     EQU                 00000026H                                         ;
    WM_PALETTECHANGED                                EQU                 00000311H                                         ;
    WM_PALETTEISCHANGING                             EQU                 00000310H                                         ;
    WM_PARENTNOTIFY                                  EQU                 00000210H                                         ;
    WM_PASTE                                         EQU                 00000302H                                         ;
    WM_PENWINFIRST                                   EQU                 00000380H                                         ;
    WM_PENWINLAST                                    EQU                 0000038FH                                         ;
    WM_POWER                                         EQU                 00000048H                                         ;
    WM_POWERBROADCAST                                EQU                 00000218H                                         ;
    WM_PRINT                                         EQU                 00000317H                                         ;
    WM_PRINTCLIENT                                   EQU                 00000318H                                         ;
    WM_QUERYDRAGICON                                 EQU                 00000037H                                         ;
    WM_QUERYENDSESSION                               EQU                 00000011H                                         ;
    WM_QUERYNEWPALETTE                               EQU                 0000030FH                                         ;
    WM_QUERYOPEN                                     EQU                 00000013H                                         ;
    WM_QUEUESYNC                                     EQU                 00000023H                                         ;
    WM_QUIT                                          EQU                 00000012H                                         ;
    WM_RBUTTONDBLCLK                                 EQU                 00000206H                                         ;
    WM_RBUTTONDOWN                                   EQU                 00000204H                                         ;
    WM_RBUTTONUP                                     EQU                 00000205H                                         ;
    WM_RENDERALLFORMATS                              EQU                 00000306H                                         ;
    WM_RENDERFORMAT                                  EQU                 00000305H                                         ;
    WM_SETCURSOR                                     EQU                 00000020H                                         ;
    WM_SETFOCUS                                      EQU                 00000007H                                         ;
    WM_SETFONT                                       EQU                 00000030H                                         ;
    WM_SETHOTKEY                                     EQU                 00000032H                                         ;
    WM_SETICON                                       EQU                 00000080H                                         ;
    WM_SETREDRAW                                     EQU                 0000000BH                                         ;
    WM_SETTEXT                                       EQU                 0000000CH                                         ;
    WM_SETTINGCHANGE                                 EQU                 0000001AH                                         ;
    WM_SHOWWINDOW                                    EQU                 00000018H                                         ;
    WM_SIZE                                          EQU                 00000005H                                         ;
    WM_SIZECLIPBOARD                                 EQU                 0000030BH                                         ;
    WM_SIZING                                        EQU                 00000214H                                         ;
    WM_SPOOLERSTATUS                                 EQU                 0000002AH                                         ;
    WM_STYLECHANGED                                  EQU                 0000007DH                                         ;
    WM_STYLECHANGING                                 EQU                 0000007CH                                         ;
    WM_SYNCPAINT                                     EQU                 00000088H                                         ;
    WM_SYSCHAR                                       EQU                 00000106H                                         ;
    WM_SYSCOLORCHANGE                                EQU                 00000015H                                         ;
    WM_SYSCOMMAND                                    EQU                 00000112H                                         ;
    WM_SYSDEADCHAR                                   EQU                 00000107H                                         ;
    WM_SYSKEYDOWN                                    EQU                 00000104H                                         ;
    WM_SYSKEYUP                                      EQU                 00000105H                                         ;
    WM_TCARD                                         EQU                 00000052H                                         ;
    WM_THEMECHANGED                                  EQU                 0000031AH                                         ;
    WM_TIMECHANGE                                    EQU                 0000001EH                                         ;
    WM_TIMER                                         EQU                 00000113H                                         ;
    WM_UNDO                                          EQU                 00000304H                                         ;
    WM_USERCHANGED                                   EQU                 00000054H                                         ;
    WM_VKEYTOITEM                                    EQU                 0000002EH                                         ;
    WM_VSCROLL                                       EQU                 00000115H                                         ;
    WM_VSCROLLCLIPBOARD                              EQU                 0000030AH                                         ;
    WM_WINDOWPOSCHANGED                              EQU                 00000047H                                         ;
    WM_WINDOWPOSCHANGING                             EQU                 00000046H                                         ;
    WM_WININICHANGE                                  EQU                 0000001AH                                         ;
    WM_XBUTTONDBLCLK                                 EQU                 0000020DH                                         ;
    WM_XBUTTONDOWN                                   EQU                 0000020BH                                         ;
    WM_XBUTTONUP                                     EQU                 0000020CH                                         ;

    WS_BORDER                                        EQU                 00800000H                                         ;
    WS_CAPTION                                       EQU                 00C00000H                                         ;
    WS_CHILD                                         EQU                 40000000H                                         ;
    WS_CLIPCHILDREN                                  EQU                 02000000H                                         ;
    WS_CLIPSIBLINGS                                  EQU                 04000000H                                         ;
    WS_DISABLED                                      EQU                 08000000H                                         ;
    WS_DLGFRAME                                      EQU                 00400000H                                         ;
    WS_GROUP                                         EQU                 00020000H                                         ;
    WS_HSCROLL                                       EQU                 00100000H                                         ;
    WS_ICONIC                                        EQU                 20000000H                                         ;
    WS_MAXIMIZE                                      EQU                 01000000H                                         ;
    WS_MAXIMIZEBOX                                   EQU                 00010000H                                         ;
    WS_MINIMIZE                                      EQU                 20000000H                                         ;
    WS_MINIMIZEBOX                                   EQU                 00020000H                                         ;
    WS_OVERLAPPED                                    EQU                 00000000H                                         ;
    WS_POPUP                                         EQU                 80000000H                                         ;
    WS_SIZEBOX                                       EQU                 00040000H                                         ;
    WS_SYSMENU                                       EQU                 00080000H                                         ;
    WS_TABSTOP                                       EQU                 00010000H                                         ;
    WS_THICKFRAME                                    EQU                 00040000H                                         ;
    WS_TILED                                         EQU                 00000000H                                         ;
    WS_TILEDWINDOW                                   EQU                 00CF0000H                                         ;
    WS_VISIBLE                                       EQU                 10000000H                                         ;
    WS_VSCROLL                                       EQU                 00200000H                                         ;


WS_OVERLAPPEDWINDOW TEXTEQU <WS_OVERLAPPED     OR \
                             WS_CAPTION        OR \
                             WS_SYSMENU        OR \
                             WS_THICKFRAME     OR \
                             WS_MINIMIZEBOX    OR \
                             WS_MAXIMIZEBOX> 

; Window show constants
SW_SHOW             =     05h


; /*
;  * PeekMessage() Options  ; WinUser.h
;  */
; #define PM_NOREMOVE         0x0000
; #define PM_REMOVE           0x0001
; #define PM_NOYIELD          0x0002

PM_REMOVE   EQU 0001H