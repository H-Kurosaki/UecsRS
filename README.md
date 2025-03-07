# UecsRS
昔作ったUECS用パケットの表示と送信を行えるWindows用ツールのソースコードです。

このリポジトリのフォルダ構成

bin/  コンパイル済みのWindows用実行ファイルです(簡易マニュアル付き)

普通に使うだけならbinフォルダのファイルをダウンロードして使うだけで問題なく使えます

SrcCode-Japanese/  日本語版のソースコードです

SrcCode-English/  英語版のソースコードです

ソースコードはBorland C++ Builder 6というかなり古い開発環境を使用しています。

現在では入手困難なモジュールを使用しているため開発環境の再構築は難しいと思われますが、

このツールは使われることが多かったため、公開することにします。

(作者は2024年現在でもWindows7でこの開発環境を維持していますがいつまで保つか分かりません)

# ライセンス

これまで明確なライセンスを付与していませんでしたが、MITライセンスとします。

Copyright © 2019 Kurosaki Hideto

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.



# 説明書

##################################################

UECS パケット送受信支援ツール Ver2.2

2019.8.9 Kurosaki Hideto

##################################################

●動作環境
Windows2000,WindowsXP,Windows7,Windows8.1,Windows10で動作確認済みです。
WindowsXP以降では初回起動時にネットワークの使用に関する警告が
出ることがありますが通信を許可して下さい。
本ツールと同様のUDP受信機能を持つソフトウェアとは競合するため
同時に起動できないことがあります。

●UDP受信
UECSで多用されるUDP通信の状態をモニターすることができます。
機能は単純で16520,16521,16529ポートから何か受信次第表示します。
ブロードキャストされるパケットはサブネットが一致していなくても受信可能です。
そのため、PCに接続されたノードが動作していれば何らかの文字列が表示されます。
(http通信はサブネットを一致させないとアクセスできないのでご注意下さい)
なお、ブロードキャストパケットと、PCのIPアドレスに対して送られる以外のパケットは受信できません。
注意：本ツールで扱えるパケットの受信速度は最大で秒間200パケットまでです。

●UDP送信
送信文の欄に書かれた文字列をUDP送信します。
IPアドレスを指定しての送信、あるいはブロードキャストすることができます。
自動送信ボタンを押すと1秒間隔で自動送信されます。

もし、PCに複数のLANポートがある場合、ブロードキャストは一番優先度の高い
１つのLANポートにのみ行われます。
このような条件でパケットがUECSノードに到達しない場合、IP指定送信を行って下さい。
(意図したポートにブロードキャストしたい場合、それ以外のポートはケーブルを抜いて下さい)

●スキャンコマンド送信
３種類のコマンドを送信できます。
・ノードスキャン
LAN内に接続されたUECSノードに応答を求めます

・CCMスキャン(通信子スキャン)
ノードの持つ、発信可能なCCMのリストを要求します。
パケットサイズに収まらない場合、複数のページに分割されることがありますので
ページ番号を指定して要求を出します。

・CCM提供者サーチ
特定のCCMを持つノードを探索します。
探索CCM欄に探したいCCMのtypeを入力してください。

注意：UARDECSはスキャンコマンドには対応していません(UARDECS_MEGA,UARDECS_PICOは対応済み)

●CCM受信速度のカウント
Ver2.2以降からは１分あたりのパケットの流通量を表示できるようになりました。
この値が表示されるにはソフトウェアを起動してから１分以上の時間がかかります。
12000packet/分以上の流通量を計測する場合はPCの表示速度が追いつかなくなります。
もし、12000packet/分以上のパケット流通量を計測したい場合は"データポート(16520)受信停止"
のチェックを入れて表示を停止して下さい。
表示が停止していてもパケット流通量だけは計測できます。

●ログのファイル出力
この項目をチェックすると、このツールの実行ファイルのあるフォルダに"receive.txt"
というファイルが生成されて受信した文字列が逐次書き出されます。

●注意事項
このツールを利用したことによって生じたいかなる結果についても開発者が責任を負うことはありませんので自己責任の上で使用して下さい。


######################################################

UECS Packet sending and receiving support tool Ver2.2E

2019.8.9 Kurosaki Hideto

######################################################

●Operating environment
This software has already been confirmed with Windows 2000, Windows XP, Windows 7, Windows 8.1, Windows 10.
In Windows XP or later, you may be warned about using the network the first time you start up, so please allow communication.
Since this software conflicts with software with same kinds of UDP communication function, it can not start at the same time.

●UDP reception
This software can display the status of UDP communication used by UECS and display the character string received from the 16520, 16521, 16529 port.

Broadcast packets can be received even if the subnet does not match.
Therefore, if a UECS node connected to the PC is running, some character string will be displayed.
(Please be aware that http communication can not be accessed unless subnets are matched)
Broadcast packets and packets other than sent to the IP address of the PC can not be received.
Note: The maximum packet reception speed handled by this tool is up to 200 packets per second.

●UDP transmission
UDP transmission of the character string written in the "Send string to UDP" field.
You can select broadcast or unicast.
When you press the "send once" button, it will be sent only once.
When you press the "send every second" button, it will be sent automatically at 1 second intervals.

If there are multiple LAN ports on the PC, broadcasting will only be done on one LAN port with the highest priority.
If the packet does not arrive at the UECS node under such conditions, please perform to specify IP address and unicast transmission.
(If you want to broadcast to the intended LAN port, please unplug the other LAN ports)

●Send scaning command
Three kinds of commands can be sent.
· Node scan
Ask the UECS node connected in the LAN to respond.

· CCM scan
Request a list of CCMs that the node can send out.
If it over the packet size limit, it may be divided into multiple pages, so please specify the page number.

Note: UARDECS does not support scan commands (UARDECS_MEGA and UARDECS_PICO already support these)

· CCM sender search
Search nodes with a specific CCM.
Please enter the CCM type you want to search in the request CCM column.

● Counting CCM traffic
From Ver2.2 onwards, you can display the packet traffic per minute.
It takes more than one minute for the value to be displayed after starting the software.
When measuring the traffic over 12000 packet / min, the display speed of the PC cannot keep up.
If you want to measure the packet flow rate of 12000 packets / min or more, check "Stop data port(UDP16520)" and stop the display.
Even if the display is stopped, only the packet distribution volume can be measured.


●"Output log to file" option
When this item is checked, a file called "receive.txt" is generated in the folder containing the executable file of this tool, and the received character string is written out sequentially.

●Notes
The developer of this tool is not responsible for any outcome caused by the use of this tool by the user.
