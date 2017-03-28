; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFTPView
LastTemplate=CListBox
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FTP.h"
LastPage=0

ClassCount=9
Class1=CFTPApp
Class2=CFTPDoc
Class3=CFTPView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_FTP
Resource3=IDR_FTPTYPE
Class5=CChildFrame
Class6=CAboutDlg
Class7=CServerListBox
Resource4=IDD_ABOUTBOX
Class8=CInputDialog
Class9=CLocalListBox
Resource5=IDD_INPUT

[CLS:CFTPApp]
Type=0
HeaderFile=FTP.h
ImplementationFile=FTP.cpp
Filter=N

[CLS:CFTPDoc]
Type=0
HeaderFile=FTPDoc.h
ImplementationFile=FTPDoc.cpp
Filter=N
LastObject=CFTPDoc

[CLS:CFTPView]
Type=0
HeaderFile=FTPView.h
ImplementationFile=FTPView.cpp
Filter=D
LastObject=CFTPView
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_NEW


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=FTP.cpp
ImplementationFile=FTP.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_FTPTYPE]
Type=1
Class=CFTPView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_FTP]
Type=1
Class=CFTPView
ControlCount=14
Control1=IDC_ADDRESS_STATIC,static,1342312448
Control2=IDC_ADDRESS_COMBOBOX,combobox,1344340226
Control3=IDC_USER_STATIC,static,1342312448
Control4=IDC_NAME_COMBOBOX,combobox,1344340226
Control5=IDC_STATIC,static,1342312448
Control6=IDC_PASSWORD_EDIT,edit,1350631584
Control7=IDC_CONNECT_BUTTON,button,1342242817
Control8=IDC_FILE_LIST_STATIC,static,1342312448
Control9=IDC_FILELIST_LISTBOX,listbox,1352729857
Control10=IDC_UPLOAD_BUTTON,button,1342242816
Control11=IDC_LOCALLIST_STATIC,static,1342312448
Control12=IDC_LOCALLIST_LISTBOX,listbox,1352729857
Control13=IDC_DOWNLOAD_BUTTON,button,1342242816
Control14=IDC_MANAGEADDRESS_LIST,listbox,1352728835

[DLG:IDD_INPUT]
Type=1
Class=CInputDialog
ControlCount=4
Control1=IDC_INPUTNAME_STATIC,static,1342308352
Control2=IDC_INPUTNAME_EDIT,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CInputDialog]
Type=0
HeaderFile=InputDialog.h
ImplementationFile=InputDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_INPUTNAME_EDIT
VirtualFilter=dWC

[CLS:CLocalListBox]
Type=0
HeaderFile=mylistbox.h
ImplementationFile=mylistbox.cpp
BaseClass=CListBox
LastObject=CLocalListBox
Filter=W
VirtualFilter=bWC

[CLS:CServerListBox]
Type=0
HeaderFile=mylistbox.h
ImplementationFile=mylistbox.cpp
BaseClass=CListBox
LastObject=CServerListBox
Filter=W
VirtualFilter=bWC

