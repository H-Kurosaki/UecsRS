//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;

char recbuf01[65536];
char recbuf02[65536];
char recbuf03[65536];

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
//起動時に実行される関数
void __fastcall TForm1::FormCreate(TObject *Sender)
{
try
{
//UDP受信部分の設定(通常受信)
UDPSrv01= new TIdUDPServer(Form1);
UDPSrv01->DefaultPort=16520;
UDPSrv01->BufferSize=BUFFERSIZE;
UDPSrv01->OnUDPRead=IdUDPServer1UDPRead; //データ受信時に呼び出される関数の設定
UDPSrv01->BroadcastEnabled=true;
UDPSrv01->Active=true;

//UDP受信部分の設定(問い合わせ)
UDPSrv02= new TIdUDPServer(Form1);
UDPSrv02->DefaultPort=16521;
UDPSrv02->BufferSize=BUFFERSIZE;
UDPSrv02->OnUDPRead=IdUDPServer2UDPRead; //データ受信時に呼び出される関数の設定
UDPSrv02->BroadcastEnabled=true;
UDPSrv02->Active=true;

//UDP受信部分の設定(返信)
UDPSrv03= new TIdUDPServer(Form1);
UDPSrv03->DefaultPort=16529;
UDPSrv03->BufferSize=BUFFERSIZE;
UDPSrv03->OnUDPRead=IdUDPServer3UDPRead; //データ受信時に呼び出される関数の設定
UDPSrv03->BroadcastEnabled=true;
UDPSrv03->Active=true;
}
catch(...)
{
Application->MessageBox("The port is occupied by another application or there is no connection to the LAN.", "Error!", MB_OK);
exit(0);
}


}
//------------------------------------------------------
//-----------------------
void TForm1::WriteDebugLOG(AnsiString mes)
{
AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());
MemoLog->Lines->Add(nowDate+mes);

//ログが溜まったらメモ消去
while(MemoLog->Lines->Count>9)
        {MemoLog->Lines->Delete(0);}

}

//---------------------受信処理(データ受信時に呼び出される関数)
void __fastcall TForm1::IdUDPServer1UDPRead(TObject *Sender,
      TStream *AData, TIdSocketHandle *ABinding)
{
recvSpeed++;
//受信停止がONの時は何もしないで戻る
if(CheckBoxRecvStop1->Checked)
        {return;}

//-------------------------------

AnsiString fromIP;
AnsiString rawdata;
//送信元IPを得る
fromIP=ABinding->PeerIP;
//IPフィルタが有効な場合IPフィルタにかける
 if(CheckBoxFilterEnabled->Checked&&
    fromIP!=EditFilterIP->Text)
        {return;}
//受信文を得る
//念のためバッファを消去する
 ZeroMemory(recbuf01,BUFFERSIZE);
 AData->Read(recbuf01,AData->Size);
 rawdata=recbuf01;
//CCMフィルタが有効な場合CCMフィルタにかける
 if(CheckBoxCCMFilterEnabled->Checked&&
    rawdata.AnsiPos(EditCCM->Text)==0)
        {return;}
//IP無視が有効な場合
  if(CheckIPIgnoreEnabled->Checked&&
    fromIP==EditIgnoreIP->Text)
        {return;}
//CCM無視が有効な場合
 if(CheckBoxCCMIgnoreEnabled->Checked&&
    rawdata.AnsiPos(EditIgnoreCCM->Text)!=0)
        {return;}

//改行を抜く
rawdata=RemoveReturnCode(rawdata);

//ログのリフレッシュが有効な場合、過去のログを消去する
 if(CheckBoxRecvLogRefresh->Checked)
        {MemoRecv->Lines->Clear();}
//現在の時刻を得て文字列に変換する
AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());


//ログが溜まったらメモ消去
if(CSpinMaxLog->Value<MemoRecv->Lines->Count&&CSpinMaxLog->Value>0)
        {
        MemoRecv->Lines->Clear();

        }


//現在の時刻と送信元をログに書き込む
 MemoRecv->Lines->Add(nowDate+"\tFrom:"+fromIP+"\tPort:16520");
//受信文を書き込む
 MemoRecv->Lines->Add(rawdata);

//ログのファイル出力
if(CheckBoxWriteLog->Checked)
{
out=fopen("receive.txt","a");
if(out!=NULL)
        {
        fprintf(out,"%s%s\t16520\t%s\n",nowDate.c_str(),fromIP.c_str(),rawdata);
        }
fclose(out);
}


}
//---------------------受信処理(データ受信時に呼び出される関数)
void __fastcall TForm1::IdUDPServer2UDPRead(TObject *Sender,
      TStream *AData, TIdSocketHandle *ABinding)
{
recvSpeed++;
//受信停止がONの時は何もしないで戻る
if(CheckBoxRecvStop2->Checked)
        {return;}

//-------------------------------

AnsiString fromIP;
AnsiString rawdata;
//送信元IPを得る
fromIP=ABinding->PeerIP;
//IPフィルタが有効な場合IPフィルタにかける
 if(CheckBoxFilterEnabled->Checked&&
    fromIP!=EditFilterIP->Text)
        {return;}
//受信文を得る
//念のためバッファを消去する
 ZeroMemory(recbuf02,BUFFERSIZE);
 AData->Read(recbuf02,AData->Size);

 rawdata=recbuf02;
//CCMフィルタが有効な場合CCMフィルタにかける
 if(CheckBoxCCMFilterEnabled->Checked&&
    rawdata.AnsiPos(EditCCM->Text)==0)
        {return;}
//IP無視が有効な場合
  if(CheckIPIgnoreEnabled->Checked&&
    fromIP==EditIgnoreIP->Text)
        {return;}
//CCM無視が有効な場合
 if(CheckBoxCCMIgnoreEnabled->Checked&&
    rawdata.AnsiPos(EditIgnoreCCM->Text)!=0)
        {return;}

//改行を抜く
rawdata=RemoveReturnCode(rawdata);

//ログのリフレッシュが有効な場合、過去のログを消去する
 if(CheckBoxRecvLogRefresh->Checked)
        {MemoRecv->Lines->Clear();}
//現在の時刻を得て文字列に変換する
AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());

//ログが溜まったらメモ消去
if(CSpinMaxLog->Value<MemoRecv->Lines->Count&&CSpinMaxLog->Value>0)
        {
        MemoRecv->Lines->Clear();

        }

//現在の時刻と送信元をログに書き込む
 MemoRecv->Lines->Add(nowDate+"\tFrom:"+fromIP+"\tPort:16521");
//受信文を書き込む
 MemoRecv->Lines->Add(rawdata);

//ログのファイル出力
if(CheckBoxWriteLog->Checked)
{
out=fopen("receive.txt","a");
if(out!=NULL)
        {
        fprintf(out,"%s%s\t16521\t%s\n",nowDate.c_str(),fromIP.c_str(),rawdata);
        }
fclose(out);
}



}
//---------------------受信処理(データ受信時に呼び出される関数)
void __fastcall TForm1::IdUDPServer3UDPRead(TObject *Sender,
      TStream *AData, TIdSocketHandle *ABinding)
{
recvSpeed++;
if(CheckBoxRecvStop3->Checked)
        {return;}

//受信停止がONの時は何もしないで戻る


//-------------------------------

AnsiString fromIP;
AnsiString rawdata;
//送信元IPを得る
fromIP=ABinding->PeerIP;
//IPフィルタが有効な場合IPフィルタにかける
 if(CheckBoxFilterEnabled->Checked&&
    fromIP!=EditFilterIP->Text)
        {return;}
//受信文を得る
//念のためバッファを消去する
 ZeroMemory(recbuf03,BUFFERSIZE);
 AData->Read(recbuf03,AData->Size);
 rawdata=recbuf03;
//CCMフィルタが有効な場合CCMフィルタにかける
 if(CheckBoxCCMFilterEnabled->Checked&&
    rawdata.AnsiPos(EditCCM->Text)==0)
        {return;}
//IP無視が有効な場合
  if(CheckIPIgnoreEnabled->Checked&&
    fromIP==EditIgnoreIP->Text)
        {return;}
//CCM無視が有効な場合
 if(CheckBoxCCMIgnoreEnabled->Checked&&
    rawdata.AnsiPos(EditIgnoreCCM->Text)!=0)
        {return;}

 //改行を抜く
rawdata=RemoveReturnCode(rawdata);

//ログのリフレッシュが有効な場合、過去のログを消去する
 if(CheckBoxRecvLogRefresh->Checked)
        {MemoRecv->Lines->Clear();}
//現在の時刻を得て文字列に変換する
AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());

//ログが溜まったらメモ消去
if(CSpinMaxLog->Value<MemoRecv->Lines->Count&&CSpinMaxLog->Value>0)
        {
        MemoRecv->Lines->Clear();
        }

//現在の時刻と送信元をログに書き込む
 MemoRecv->Lines->Add(nowDate+"\tFrom:"+fromIP+"\tPort:16529");
//受信文を書き込む
 MemoRecv->Lines->Add(rawdata);


//ログのファイル出力
if(CheckBoxWriteLog->Checked)
{
out=fopen("receive.txt","a");
if(out!=NULL)
        {
        fprintf(out,"%s%s\t16529\t%s\n",nowDate.c_str(),fromIP.c_str(),rawdata);
        }
fclose(out);
}

}

//---------------------------------------------------------------------------
//ログの消去
void __fastcall TForm1::ButtonLogClearClick(TObject *Sender)
{
MemoRecv->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAutoSendClick(TObject *Sender)
{
//自動送信の開始
ButtonAutoSendStop->Enabled=true;
ButtonAutoSend->Enabled=false;
ButtonSend->Enabled=false;
EditSend->Enabled=false;
TimerAutoSend->Enabled=true;//タイマーON
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAutoSendStopClick(TObject *Sender)
{
//自動送信の停止
ButtonAutoSendStop->Enabled=false;
ButtonAutoSend->Enabled=true;
ButtonSend->Enabled=true;
EditSend->Enabled=true;
TimerAutoSend->Enabled=false;//タイマーOFF
}
//---------------------------------------------------------------------------
//自動送信時に呼ばれる関数
void __fastcall TForm1::TimerAutoSendTimer(TObject *Sender)
{


ButtonSendClick(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
//１回だけ送信
if(RadioButtonSendTgt->Checked)
        {
        //送信先を指定する場合
        WriteDebugLOG("Sending");
        if(RadioSendDataPort->Checked)
                {UDPSrv01->Send(EditSendIP->Text,16520,EditSend->Text);}
        if(RadioSendReqPort->Checked)
                {UDPSrv01->Send(EditSendIP->Text,16521,EditSend->Text);}
        if(RadioSendScanPort->Checked)
                {UDPSrv01->Send(EditSendIP->Text,16529,EditSend->Text);}

        }

if(RadioButtonSendBcast->Checked)
        {
        //ブロードキャストする場合
        WriteDebugLOG("Sending(Broadcast)");
        if(RadioSendDataPort->Checked)
                {UDPSrv01->Broadcast(EditSend->Text,16520);}
        if(RadioSendReqPort->Checked)
                {UDPSrv01->Broadcast(EditSend->Text,16521);}
        if(RadioSendScanPort->Checked)
                {UDPSrv01->Broadcast(EditSend->Text,16529);}

        }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
static int recvSpeedHist[60];
static int count=0;
static bool startFlag=false;
recvSpeedHist[count]=recvSpeed;
count++;
if(count==60){count=0;startFlag=true;}

int recvSpeedMin=0;
for(int i=0;i<60;i++)
{recvSpeedMin+=recvSpeedHist[i];}
if(startFlag)
{Label8->Caption=IntToStr(recvSpeedMin)+"packet/min";}
else
{Label8->Caption="????packet/min";}



Label5->Caption=IntToStr(recvSpeed)+"packet/sec";
recvSpeed=0;


AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNodeScanClick(TObject *Sender)
{
if(RadioButtonSendBcast->Checked)
{WriteDebugLOG("Node scan sending:16529(Broadcast)");UDPSrv02->Broadcast("<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><NODESCAN/></UECS>",16529);}
else
{WriteDebugLOG("Node scan sending:16529");UDPSrv02->Send(EditSendIP->Text,16529,"<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><NODESCAN/></UECS>");}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCCMScanClick(TObject *Sender)
{
if(CSpinScanPage->Value==0)
{
if(RadioButtonSendBcast->Checked)
{WriteDebugLOG("CCM scan sending:16529(Broadcast)");UDPSrv02->Broadcast("<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><CCMSCAN/></UECS>",16529);}
else
{WriteDebugLOG("CCM scan sending:16529");UDPSrv02->Send(EditSendIP->Text,16529,"<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><CCMSCAN/></UECS>");}
}
else
{
if(RadioButtonSendBcast->Checked)
{WriteDebugLOG("CCM scan sending:16529(Broadcast)");UDPSrv02->Broadcast("<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><CCMSCAN page=\""+IntToStr(CSpinScanPage->Value)+"\"/></UECS>",16529);}
else
{WriteDebugLOG("CCM scan sending:16529");UDPSrv02->Send(EditSendIP->Text,16529,"<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><CCMSCAN page=\""+IntToStr(CSpinScanPage->Value)+"\"/></UECS>");}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSrchCCMClick(TObject *Sender)
{
if(RadioButtonSendBcast->Checked)
{WriteDebugLOG("CCM sender search:16521(Broadcast)");UDPSrv02->Broadcast("<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><SEARCH type=\""+EditSrchCCM->Text+"\" room=\"0\" region=\"0\" order=\"0\"/></UECS>",16521);}
else
{WriteDebugLOG("CCM sender search:16521");UDPSrv02->Send(EditSendIP->Text,16521,"<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><SEARCH type=\""+EditSrchCCM->Text+"\" room=\"0\" region=\"0\" order=\"0\"/></UECS>");}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
UDPSrv01->Active=false;
UDPSrv02->Active=false;
UDPSrv03->Active=false;

}
//---------------------------------------------------------------------------
AnsiString TForm1::RemoveReturnCode(AnsiString raw)
{

while(1)
  {
  if(raw.AnsiPos("\n")==0){break;}
  raw=raw.Delete(raw.AnsiPos("\n"),1);
  }
while(1)
  {
  if(raw.AnsiPos("\r")==0){break;}
  raw=raw.Delete(raw.AnsiPos("\r"),1);
  }

return raw;
}
//-------------------------------------------------------------------


int TForm1::GetMyIpAddr()
{
try{
  int niccount=0;
  for(niccount=0;niccount<64;niccount++){myIpAddrList[niccount]="127.0.0.1";}

  WSADATA wsadata;
  if (WSAStartup(MAKEWORD(1, 1), &wsadata) != 0) {
    return 0;
  }

  //ホスト名を取得する
  char hostname[256];
  if (gethostname(hostname, sizeof(hostname)) != 0) {
    return 0;
  }
  puts(hostname);

  //ホスト名からIPアドレスを取得する
  HOSTENT* hostend = gethostbyname(hostname);
  if (hostend == NULL) {
    return 0;
  }
  IN_ADDR inaddr;
  char ip[256];
  niccount=0;
  int iCount;
  for(iCount = 0 ; hostend->h_addr_list[iCount] ; iCount++)
  {
  memcpy(&inaddr, hostend->h_addr_list[iCount], 4);
  strcpy(ip, inet_ntoa(inaddr));
  if(niccount>64){break;}
  myIpAddrList[niccount]=ip;
  niccount++;
  }
  WSACleanup();
  if(myNICCount!=niccount){
                        for(int i=0;i<niccount;i++)
                                {MemoLog->Lines->Add("My IP address:"+myIpAddrList[i]);}
                        }
  myNICCount=niccount;



  return niccount;
  }
catch(...)
        {
    return 0;
        }

}



void __fastcall TForm1::FormShow(TObject *Sender)
{
   int niccount=GetMyIpAddr();
    EditSend->Text="<?xml version=\"1.0\"?><UECS ver=\"1.00-E10\"><DATA type=\"InAirTemp\" room=\"0\" region=\"0\" order=\"0\" priority=\"30\">20.0</DATA><IP>"+myIpAddrList[0]+"</IP></UECS>";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckScrollBarClick(TObject *Sender)
{
if(CheckScrollBar->Checked){MemoRecv->ScrollBars=ssVertical;}
else {MemoRecv->ScrollBars=ssBoth;}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
//--------------------
       if(Form1->Width<520)
       {
         MemoRecv->Width=520-32;
         EditSend->Width=520-32;
         MemoLog->Width=520-490;
                }
       else
       {
       MemoRecv->Width=Form1->Width-32;
       EditSend->Width=Form1->Width-32;
       MemoLog->Width=Form1->Width-490;
       }

}
//---------------------------------------------------------------------------

