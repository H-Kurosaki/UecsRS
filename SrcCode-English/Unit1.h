//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include <DateUtils.hpp>
#include <IniFiles.hpp>
#include <process.h>
#include <stdio.h>
#include <ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <winsock2.h>


#define MAXHEATERS  10
#define BUFFERSIZE  8192


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TMemo *MemoLog;
        TMemo *MemoRecv;
        TEdit *EditFilterIP;
        TCheckBox *CheckBoxFilterEnabled;
        TButton *ButtonSend;
        TButton *ButtonAutoSend;
        TTimer *TimerAutoSend;
        TLabel *Label1;
        TLabel *Label2;
        TButton *ButtonAutoSendStop;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButtonSendTgt;
        TRadioButton *RadioButtonSendBcast;
        TEdit *EditSendIP;
        TCheckBox *CheckBoxRecvLogRefresh;
        TCheckBox *CheckBoxRecvStop1;
        TButton *ButtonLogClear;
        TEdit *EditSend;
        TCheckBox *CheckBoxCCMFilterEnabled;
        TEdit *EditCCM;
        TLabel *Label4;
        TTimer *Timer1;
        TLabel *Label5;
        TCSpinEdit *CSpinMaxLog;
        TLabel *Label6;
        TCheckBox *CheckBoxRecvStop2;
        TCheckBox *CheckBoxRecvStop3;
        TCheckBox *CheckIPIgnoreEnabled;
        TCheckBox *CheckBoxCCMIgnoreEnabled;
        TEdit *EditIgnoreIP;
        TEdit *EditIgnoreCCM;
        TCheckBox *CheckBoxWriteLog;
        TGroupBox *GroupBox2;
        TRadioButton *RadioSendDataPort;
        TRadioButton *RadioSendReqPort;
        TRadioButton *RadioSendScanPort;
        TGroupBox *GroupBox3;
        TButton *ButtonNodeScan;
        TButton *ButtonCCMScan;
        TButton *ButtonSrchCCM;
        TEdit *EditSrchCCM;
        TLabel *Label3;
        TCSpinEdit *CSpinScanPage;
        TLabel *Label7;
        TCheckBox *CheckScrollBar;
        TLabel *Label8;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall IdUDPServer1UDPRead(TObject *Sender,
          TStream *AData, TIdSocketHandle *ABinding);

        void __fastcall IdUDPServer2UDPRead(TObject *Sender,
          TStream *AData, TIdSocketHandle *ABinding);

        void __fastcall IdUDPServer3UDPRead(TObject *Sender,
          TStream *AData, TIdSocketHandle *ABinding);

        void __fastcall ButtonLogClearClick(TObject *Sender);
        void __fastcall ButtonAutoSendClick(TObject *Sender);
        void __fastcall ButtonAutoSendStopClick(TObject *Sender);
        void __fastcall TimerAutoSendTimer(TObject *Sender);
        void __fastcall ButtonSendClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ButtonNodeScanClick(TObject *Sender);
        void __fastcall ButtonSrchCCMClick(TObject *Sender);
        void __fastcall ButtonCCMScanClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall CheckScrollBarClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);



private:	// ユーザー宣言
       TIdUDPServer *UDPSrv01;
       TIdUDPServer *UDPSrv02;
       TIdUDPServer *UDPSrv03;
       void WriteDebugLOG(AnsiString mes);
       int recvSpeed;
       AnsiString RemoveReturnCode(AnsiString raw);
        int GetMyIpAddr();

        AnsiString myIpAddrList[64];
       int myNICCount;


public:		// ユーザー宣言
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
