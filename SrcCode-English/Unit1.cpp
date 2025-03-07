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
//�N�����Ɏ��s�����֐�
void __fastcall TForm1::FormCreate(TObject *Sender)
{
try
{
//UDP��M�����̐ݒ�(�ʏ��M)
UDPSrv01= new TIdUDPServer(Form1);
UDPSrv01->DefaultPort=16520;
UDPSrv01->BufferSize=BUFFERSIZE;
UDPSrv01->OnUDPRead=IdUDPServer1UDPRead; //�f�[�^��M���ɌĂяo�����֐��̐ݒ�
UDPSrv01->BroadcastEnabled=true;
UDPSrv01->Active=true;

//UDP��M�����̐ݒ�(�₢���킹)
UDPSrv02= new TIdUDPServer(Form1);
UDPSrv02->DefaultPort=16521;
UDPSrv02->BufferSize=BUFFERSIZE;
UDPSrv02->OnUDPRead=IdUDPServer2UDPRead; //�f�[�^��M���ɌĂяo�����֐��̐ݒ�
UDPSrv02->BroadcastEnabled=true;
UDPSrv02->Active=true;

//UDP��M�����̐ݒ�(�ԐM)
UDPSrv03= new TIdUDPServer(Form1);
UDPSrv03->DefaultPort=16529;
UDPSrv03->BufferSize=BUFFERSIZE;
UDPSrv03->OnUDPRead=IdUDPServer3UDPRead; //�f�[�^��M���ɌĂяo�����֐��̐ݒ�
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

//���O�����܂����烁������
while(MemoLog->Lines->Count>9)
        {MemoLog->Lines->Delete(0);}

}

//---------------------��M����(�f�[�^��M���ɌĂяo�����֐�)
void __fastcall TForm1::IdUDPServer1UDPRead(TObject *Sender,
      TStream *AData, TIdSocketHandle *ABinding)
{
recvSpeed++;
//��M��~��ON�̎��͉������Ȃ��Ŗ߂�
if(CheckBoxRecvStop1->Checked)
        {return;}

//-------------------------------

AnsiString fromIP;
AnsiString rawdata;
//���M��IP�𓾂�
fromIP=ABinding->PeerIP;
//IP�t�B���^���L���ȏꍇIP�t�B���^�ɂ�����
 if(CheckBoxFilterEnabled->Checked&&
    fromIP!=EditFilterIP->Text)
        {return;}
//��M���𓾂�
//�O�̂��߃o�b�t�@����������
 ZeroMemory(recbuf01,BUFFERSIZE);
 AData->Read(recbuf01,AData->Size);
 rawdata=recbuf01;
//CCM�t�B���^���L���ȏꍇCCM�t�B���^�ɂ�����
 if(CheckBoxCCMFilterEnabled->Checked&&
    rawdata.AnsiPos(EditCCM->Text)==0)
        {return;}
//IP�������L���ȏꍇ
  if(CheckIPIgnoreEnabled->Checked&&
    fromIP==EditIgnoreIP->Text)
        {return;}
//CCM�������L���ȏꍇ
 if(CheckBoxCCMIgnoreEnabled->Checked&&
    rawdata.AnsiPos(EditIgnoreCCM->Text)!=0)
        {return;}

//���s�𔲂�
rawdata=RemoveReturnCode(rawdata);

//���O�̃��t���b�V�����L���ȏꍇ�A�ߋ��̃��O����������
 if(CheckBoxRecvLogRefresh->Checked)
        {MemoRecv->Lines->Clear();}
//���݂̎����𓾂ĕ�����ɕϊ�����
AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());


//���O�����܂����烁������
if(CSpinMaxLog->Value<MemoRecv->Lines->Count&&CSpinMaxLog->Value>0)
        {
        MemoRecv->Lines->Clear();

        }


//���݂̎����Ƒ��M�������O�ɏ�������
 MemoRecv->Lines->Add(nowDate+"\tFrom:"+fromIP+"\tPort:16520");
//��M������������
 MemoRecv->Lines->Add(rawdata);

//���O�̃t�@�C���o��
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
//---------------------��M����(�f�[�^��M���ɌĂяo�����֐�)
void __fastcall TForm1::IdUDPServer2UDPRead(TObject *Sender,
      TStream *AData, TIdSocketHandle *ABinding)
{
recvSpeed++;
//��M��~��ON�̎��͉������Ȃ��Ŗ߂�
if(CheckBoxRecvStop2->Checked)
        {return;}

//-------------------------------

AnsiString fromIP;
AnsiString rawdata;
//���M��IP�𓾂�
fromIP=ABinding->PeerIP;
//IP�t�B���^���L���ȏꍇIP�t�B���^�ɂ�����
 if(CheckBoxFilterEnabled->Checked&&
    fromIP!=EditFilterIP->Text)
        {return;}
//��M���𓾂�
//�O�̂��߃o�b�t�@����������
 ZeroMemory(recbuf02,BUFFERSIZE);
 AData->Read(recbuf02,AData->Size);

 rawdata=recbuf02;
//CCM�t�B���^���L���ȏꍇCCM�t�B���^�ɂ�����
 if(CheckBoxCCMFilterEnabled->Checked&&
    rawdata.AnsiPos(EditCCM->Text)==0)
        {return;}
//IP�������L���ȏꍇ
  if(CheckIPIgnoreEnabled->Checked&&
    fromIP==EditIgnoreIP->Text)
        {return;}
//CCM�������L���ȏꍇ
 if(CheckBoxCCMIgnoreEnabled->Checked&&
    rawdata.AnsiPos(EditIgnoreCCM->Text)!=0)
        {return;}

//���s�𔲂�
rawdata=RemoveReturnCode(rawdata);

//���O�̃��t���b�V�����L���ȏꍇ�A�ߋ��̃��O����������
 if(CheckBoxRecvLogRefresh->Checked)
        {MemoRecv->Lines->Clear();}
//���݂̎����𓾂ĕ�����ɕϊ�����
AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());

//���O�����܂����烁������
if(CSpinMaxLog->Value<MemoRecv->Lines->Count&&CSpinMaxLog->Value>0)
        {
        MemoRecv->Lines->Clear();

        }

//���݂̎����Ƒ��M�������O�ɏ�������
 MemoRecv->Lines->Add(nowDate+"\tFrom:"+fromIP+"\tPort:16521");
//��M������������
 MemoRecv->Lines->Add(rawdata);

//���O�̃t�@�C���o��
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
//---------------------��M����(�f�[�^��M���ɌĂяo�����֐�)
void __fastcall TForm1::IdUDPServer3UDPRead(TObject *Sender,
      TStream *AData, TIdSocketHandle *ABinding)
{
recvSpeed++;
if(CheckBoxRecvStop3->Checked)
        {return;}

//��M��~��ON�̎��͉������Ȃ��Ŗ߂�


//-------------------------------

AnsiString fromIP;
AnsiString rawdata;
//���M��IP�𓾂�
fromIP=ABinding->PeerIP;
//IP�t�B���^���L���ȏꍇIP�t�B���^�ɂ�����
 if(CheckBoxFilterEnabled->Checked&&
    fromIP!=EditFilterIP->Text)
        {return;}
//��M���𓾂�
//�O�̂��߃o�b�t�@����������
 ZeroMemory(recbuf03,BUFFERSIZE);
 AData->Read(recbuf03,AData->Size);
 rawdata=recbuf03;
//CCM�t�B���^���L���ȏꍇCCM�t�B���^�ɂ�����
 if(CheckBoxCCMFilterEnabled->Checked&&
    rawdata.AnsiPos(EditCCM->Text)==0)
        {return;}
//IP�������L���ȏꍇ
  if(CheckIPIgnoreEnabled->Checked&&
    fromIP==EditIgnoreIP->Text)
        {return;}
//CCM�������L���ȏꍇ
 if(CheckBoxCCMIgnoreEnabled->Checked&&
    rawdata.AnsiPos(EditIgnoreCCM->Text)!=0)
        {return;}

 //���s�𔲂�
rawdata=RemoveReturnCode(rawdata);

//���O�̃��t���b�V�����L���ȏꍇ�A�ߋ��̃��O����������
 if(CheckBoxRecvLogRefresh->Checked)
        {MemoRecv->Lines->Clear();}
//���݂̎����𓾂ĕ�����ɕϊ�����
AnsiString nowDate;
FILE *out;
DateTimeToString(nowDate,"yyyy/mm/dd hh:nn:ss\t",Now());

//���O�����܂����烁������
if(CSpinMaxLog->Value<MemoRecv->Lines->Count&&CSpinMaxLog->Value>0)
        {
        MemoRecv->Lines->Clear();
        }

//���݂̎����Ƒ��M�������O�ɏ�������
 MemoRecv->Lines->Add(nowDate+"\tFrom:"+fromIP+"\tPort:16529");
//��M������������
 MemoRecv->Lines->Add(rawdata);


//���O�̃t�@�C���o��
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
//���O�̏���
void __fastcall TForm1::ButtonLogClearClick(TObject *Sender)
{
MemoRecv->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAutoSendClick(TObject *Sender)
{
//�������M�̊J�n
ButtonAutoSendStop->Enabled=true;
ButtonAutoSend->Enabled=false;
ButtonSend->Enabled=false;
EditSend->Enabled=false;
TimerAutoSend->Enabled=true;//�^�C�}�[ON
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAutoSendStopClick(TObject *Sender)
{
//�������M�̒�~
ButtonAutoSendStop->Enabled=false;
ButtonAutoSend->Enabled=true;
ButtonSend->Enabled=true;
EditSend->Enabled=true;
TimerAutoSend->Enabled=false;//�^�C�}�[OFF
}
//---------------------------------------------------------------------------
//�������M���ɌĂ΂��֐�
void __fastcall TForm1::TimerAutoSendTimer(TObject *Sender)
{


ButtonSendClick(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
//�P�񂾂����M
if(RadioButtonSendTgt->Checked)
        {
        //���M����w�肷��ꍇ
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
        //�u���[�h�L���X�g����ꍇ
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

  //�z�X�g�����擾����
  char hostname[256];
  if (gethostname(hostname, sizeof(hostname)) != 0) {
    return 0;
  }
  puts(hostname);

  //�z�X�g������IP�A�h���X���擾����
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

