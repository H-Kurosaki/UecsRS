object Form1: TForm1
  Left = 577
  Top = 151
  Width = 781
  Height = 661
  Caption = 'UECS Packet sending and receiving support tool'#12288'Ver 2.2E'
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 8
    Top = 112
    Width = 60
    Height = 12
    Caption = 'Receive log'
  end
  object Label2: TLabel
    Left = 8
    Top = 376
    Width = 99
    Height = 12
    Caption = 'Send string to UDP'
  end
  object Label4: TLabel
    Left = 608
    Top = 88
    Width = 65
    Height = 12
    BiDiMode = bdLeftToRight
    Caption = 'Receive rate'
    ParentBiDiMode = False
  end
  object Label5: TLabel
    Left = 680
    Top = 88
    Width = 78
    Height = 12
    Caption = '????packet/sec'
  end
  object Label6: TLabel
    Left = 657
    Top = 37
    Width = 109
    Height = 12
    Caption = 'Maximum lines of log'
  end
  object Label8: TLabel
    Left = 656
    Top = 104
    Width = 78
    Height = 12
    Caption = '????packet/sec'
  end
  object MemoLog: TMemo
    Left = 464
    Top = 416
    Width = 297
    Height = 193
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object MemoRecv: TMemo
    Left = 8
    Top = 128
    Width = 753
    Height = 241
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object EditFilterIP: TEdit
    Left = 136
    Top = 8
    Width = 121
    Height = 20
    TabOrder = 2
    Text = '192.168.1.7'
  end
  object CheckBoxFilterEnabled: TCheckBox
    Left = 8
    Top = 8
    Width = 121
    Height = 17
    Caption = 'Restrict receive IP'
    TabOrder = 3
  end
  object ButtonSend: TButton
    Left = 352
    Top = 424
    Width = 105
    Height = 25
    Caption = 'Send once'
    TabOrder = 4
    OnClick = ButtonSendClick
  end
  object ButtonAutoSend: TButton
    Left = 352
    Top = 456
    Width = 105
    Height = 25
    Caption = 'Send every second'
    TabOrder = 5
    OnClick = ButtonAutoSendClick
  end
  object ButtonAutoSendStop: TButton
    Left = 352
    Top = 488
    Width = 105
    Height = 25
    Caption = 'Stop sending'
    Enabled = False
    TabOrder = 6
    OnClick = ButtonAutoSendStopClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 424
    Width = 169
    Height = 89
    Caption = 'Destination'
    TabOrder = 7
    object RadioButtonSendTgt: TRadioButton
      Left = 8
      Top = 16
      Width = 65
      Height = 17
      Caption = 'Unicast'
      TabOrder = 0
    end
    object RadioButtonSendBcast: TRadioButton
      Left = 8
      Top = 56
      Width = 113
      Height = 17
      Caption = 'Broadcast'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object EditSendIP: TEdit
      Left = 80
      Top = 16
      Width = 81
      Height = 20
      TabOrder = 2
      Text = '192.168.1.7'
    end
  end
  object CheckBoxRecvLogRefresh: TCheckBox
    Left = 512
    Top = 8
    Width = 137
    Height = 17
    Caption = 'Display 1 line of log'
    TabOrder = 8
  end
  object CheckBoxRecvStop1: TCheckBox
    Left = 312
    Top = 8
    Width = 185
    Height = 17
    Caption = 'Stop data port(UDP16520)'
    TabOrder = 9
  end
  object ButtonLogClear: TButton
    Left = 504
    Top = 88
    Width = 97
    Height = 33
    Caption = 'Clear log'
    TabOrder = 10
    OnClick = ButtonLogClearClick
  end
  object EditSend: TEdit
    Left = 8
    Top = 392
    Width = 753
    Height = 20
    TabOrder = 11
    Text = 
      '<?xml version="1.0"?><UECS ver="1.00-E10"><DATA type="InAirTemp"' +
      ' room="0" region="0" order="0" priority="30">20.0</DATA><IP>192.' +
      '168.1.1</IP></UECS>'
  end
  object CheckBoxCCMFilterEnabled: TCheckBox
    Left = 8
    Top = 64
    Width = 153
    Height = 17
    Caption = 'Receive specified string'
    TabOrder = 12
  end
  object EditCCM: TEdit
    Left = 168
    Top = 64
    Width = 121
    Height = 20
    TabOrder = 13
    Text = 'InAirHumid'
  end
  object CSpinMaxLog: TCSpinEdit
    Left = 664
    Top = 56
    Width = 57
    Height = 21
    MaxValue = 1000
    TabOrder = 14
    Value = 300
  end
  object CheckBoxRecvStop2: TCheckBox
    Left = 312
    Top = 40
    Width = 209
    Height = 25
    Caption = 'Stop inquiry port(UDP16521)'
    TabOrder = 15
  end
  object CheckBoxRecvStop3: TCheckBox
    Left = 312
    Top = 80
    Width = 185
    Height = 17
    Caption = 'Stop scanning port(UDP16529)'
    TabOrder = 16
  end
  object CheckIPIgnoreEnabled: TCheckBox
    Left = 8
    Top = 32
    Width = 97
    Height = 17
    Caption = 'Ignore IP'
    TabOrder = 17
  end
  object CheckBoxCCMIgnoreEnabled: TCheckBox
    Left = 8
    Top = 88
    Width = 145
    Height = 17
    Caption = 'Ignore specified string'
    TabOrder = 18
  end
  object EditIgnoreIP: TEdit
    Left = 136
    Top = 32
    Width = 121
    Height = 20
    TabOrder = 19
    Text = '192.168.1.7'
  end
  object EditIgnoreCCM: TEdit
    Left = 168
    Top = 88
    Width = 121
    Height = 20
    TabOrder = 20
    Text = 'InAirHumid'
  end
  object CheckBoxWriteLog: TCheckBox
    Left = 512
    Top = 32
    Width = 129
    Height = 17
    Caption = 'Output log to file'
    TabOrder = 21
  end
  object GroupBox2: TGroupBox
    Left = 184
    Top = 424
    Width = 161
    Height = 89
    Caption = 'Specify send port'
    TabOrder = 22
    object RadioSendDataPort: TRadioButton
      Left = 8
      Top = 16
      Width = 145
      Height = 17
      Caption = 'Data port(UDP16520)'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioSendReqPort: TRadioButton
      Left = 8
      Top = 40
      Width = 145
      Height = 17
      Caption = 'Inquiry port(UDP16521)'
      TabOrder = 1
    end
    object RadioSendScanPort: TRadioButton
      Left = 8
      Top = 64
      Width = 145
      Height = 17
      Caption = 'Scanning port(UDP16529)'
      TabOrder = 2
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 520
    Width = 449
    Height = 97
    Caption = 'Send scanning command'
    TabOrder = 23
    object Label3: TLabel
      Left = 312
      Top = 47
      Width = 97
      Height = 12
      Caption = 'Request CCM type'
    end
    object Label7: TLabel
      Left = 166
      Top = 46
      Width = 111
      Height = 12
      Caption = 'Request page number'
    end
    object ButtonNodeScan: TButton
      Left = 24
      Top = 16
      Width = 105
      Height = 25
      Caption = 'Node scan'
      TabOrder = 0
      OnClick = ButtonNodeScanClick
    end
    object ButtonCCMScan: TButton
      Left = 168
      Top = 16
      Width = 113
      Height = 25
      Caption = 'CCM scan'
      TabOrder = 1
      OnClick = ButtonCCMScanClick
    end
    object ButtonSrchCCM: TButton
      Left = 312
      Top = 16
      Width = 129
      Height = 25
      Caption = 'CCM sender search'
      TabOrder = 2
      OnClick = ButtonSrchCCMClick
    end
    object EditSrchCCM: TEdit
      Left = 367
      Top = 66
      Width = 73
      Height = 20
      TabOrder = 3
      Text = 'Time'
    end
    object CSpinScanPage: TCSpinEdit
      Left = 224
      Top = 64
      Width = 57
      Height = 21
      MaxValue = 99
      TabOrder = 4
      Value = 1
    end
  end
  object CheckScrollBar: TCheckBox
    Left = 512
    Top = 56
    Width = 121
    Height = 17
    Caption = 'Wrap log string'
    TabOrder = 24
    OnClick = CheckScrollBarClick
  end
  object TimerAutoSend: TTimer
    Enabled = False
    OnTimer = TimerAutoSendTimer
    Left = 752
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 720
  end
end
