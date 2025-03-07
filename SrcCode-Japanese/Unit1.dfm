object Form1: TForm1
  Left = 275
  Top = 167
  Width = 781
  Height = 661
  Caption = 'UECS '#12497#12465#12483#12488#36865#21463#20449#25903#25588#12484#12540#12523#12288'Ver2.2'
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
    Width = 36
    Height = 12
    Caption = #21463#20449#25991
  end
  object Label2: TLabel
    Left = 8
    Top = 376
    Width = 36
    Height = 12
    Caption = #36865#20449#25991
  end
  object Label4: TLabel
    Left = 608
    Top = 88
    Width = 48
    Height = 12
    Caption = #21463#20449#36895#24230
  end
  object Label5: TLabel
    Left = 664
    Top = 88
    Width = 72
    Height = 12
    Caption = '????packet/'#31186
  end
  object Label6: TLabel
    Left = 649
    Top = 37
    Width = 81
    Height = 12
    Caption = #12525#12464#12398#26368#22823#34892#25968
  end
  object Label8: TLabel
    Left = 660
    Top = 104
    Width = 72
    Height = 12
    Caption = '????packet/'#20998
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
    Left = 120
    Top = 8
    Width = 121
    Height = 20
    TabOrder = 2
    Text = '192.168.1.7'
  end
  object CheckBoxFilterEnabled: TCheckBox
    Left = 8
    Top = 8
    Width = 105
    Height = 17
    Caption = #25351#23450'IP'#12398#12415#21463#20449
    TabOrder = 3
  end
  object ButtonSend: TButton
    Left = 352
    Top = 432
    Width = 105
    Height = 25
    Caption = #65297#22238#36865#20449
    TabOrder = 4
    OnClick = ButtonSendClick
  end
  object ButtonAutoSend: TButton
    Left = 352
    Top = 464
    Width = 105
    Height = 25
    Caption = #33258#21205#36865#20449#65288'1'#31186#38291#38548#65289
    TabOrder = 5
    OnClick = ButtonAutoSendClick
  end
  object ButtonAutoSendStop: TButton
    Left = 352
    Top = 496
    Width = 105
    Height = 25
    Caption = #33258#21205#36865#20449#20572#27490
    Enabled = False
    TabOrder = 6
    OnClick = ButtonAutoSendStopClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 424
    Width = 169
    Height = 89
    Caption = #36865#20449#20808
    TabOrder = 7
    object RadioButtonSendTgt: TRadioButton
      Left = 8
      Top = 16
      Width = 65
      Height = 17
      Caption = 'IP'#25351#23450
      TabOrder = 0
    end
    object RadioButtonSendBcast: TRadioButton
      Left = 8
      Top = 56
      Width = 113
      Height = 17
      Caption = #12502#12525#12540#12489#12461#12515#12473#12488
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object EditSendIP: TEdit
      Left = 72
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
    Width = 193
    Height = 17
    Caption = #65297#25991#21463#20449#12372#12392#12395#12525#12464#12434#12522#12501#12524#12483#12471#12517
    TabOrder = 8
  end
  object CheckBoxRecvStop1: TCheckBox
    Left = 312
    Top = 8
    Width = 185
    Height = 17
    Caption = #12487#12540#12479#12509#12540#12488'(16520)'#21463#20449#20572#27490
    TabOrder = 9
  end
  object ButtonLogClear: TButton
    Left = 504
    Top = 88
    Width = 97
    Height = 33
    Caption = #12525#12464#28040#21435
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
    Width = 161
    Height = 17
    Caption = #25991#23383#21015#12434#21547#12416#12497#12465#12483#12488#21463#20449
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
    Caption = #21839#12356#21512#12431#12379#12509#12540#12488'(16521)'#21463#20449#20572#27490
    TabOrder = 15
  end
  object CheckBoxRecvStop3: TCheckBox
    Left = 312
    Top = 80
    Width = 185
    Height = 17
    Caption = #12473#12461#12515#12531#12509#12540#12488'(16529)'#21463#20449#20572#27490
    TabOrder = 16
  end
  object CheckIPIgnoreEnabled: TCheckBox
    Left = 8
    Top = 32
    Width = 97
    Height = 17
    Caption = #25351#23450'IP'#12434#28961#35222
    TabOrder = 17
  end
  object CheckBoxCCMIgnoreEnabled: TCheckBox
    Left = 8
    Top = 88
    Width = 153
    Height = 17
    Caption = #25991#23383#21015#12434#21547#12416#12497#12465#12483#12488#28961#35222
    TabOrder = 18
  end
  object EditIgnoreIP: TEdit
    Left = 120
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
    Caption = #12525#12464#12398#12501#12449#12452#12523#20986#21147
    TabOrder = 21
  end
  object GroupBox2: TGroupBox
    Left = 184
    Top = 424
    Width = 161
    Height = 89
    Caption = #36865#20449#12509#12540#12488
    TabOrder = 22
    object RadioSendDataPort: TRadioButton
      Left = 8
      Top = 16
      Width = 145
      Height = 17
      Caption = #12487#12540#12479#12509#12540#12488'(16520)'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioSendReqPort: TRadioButton
      Left = 8
      Top = 40
      Width = 145
      Height = 17
      Caption = #21839#12356#21512#12431#12379#12509#12540#12488'(16521)'
      TabOrder = 1
    end
    object RadioSendScanPort: TRadioButton
      Left = 8
      Top = 64
      Width = 145
      Height = 17
      Caption = #12473#12461#12515#12531#12509#12540#12488'(16529)'
      TabOrder = 2
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 528
    Width = 393
    Height = 81
    Caption = #12473#12461#12515#12531#12467#12510#12531#12489#36865#20449
    TabOrder = 23
    object Label3: TLabel
      Left = 256
      Top = 55
      Width = 49
      Height = 12
      Caption = #25506#32034'CCM'
    end
    object Label7: TLabel
      Left = 134
      Top = 54
      Width = 58
      Height = 12
      Caption = #35201#27714#12506#12540#12472
    end
    object ButtonNodeScan: TButton
      Left = 8
      Top = 16
      Width = 105
      Height = 25
      Caption = #12494#12540#12489#12473#12461#12515#12531
      TabOrder = 0
      OnClick = ButtonNodeScanClick
    end
    object ButtonCCMScan: TButton
      Left = 128
      Top = 16
      Width = 113
      Height = 25
      Caption = 'CCM'#12473#12461#12515#12531
      TabOrder = 1
      OnClick = ButtonCCMScanClick
    end
    object ButtonSrchCCM: TButton
      Left = 256
      Top = 16
      Width = 129
      Height = 25
      Caption = 'CCM'#25552#20379#32773#12469#12540#12481
      TabOrder = 2
      OnClick = ButtonSrchCCMClick
    end
    object EditSrchCCM: TEdit
      Left = 311
      Top = 50
      Width = 73
      Height = 20
      TabOrder = 3
      Text = 'Time'
    end
    object CSpinScanPage: TCSpinEdit
      Left = 200
      Top = 48
      Width = 41
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
    Caption = #25240#12426#36820#12375#12390#34920#31034#12377#12427
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
    Top = 8
  end
end
