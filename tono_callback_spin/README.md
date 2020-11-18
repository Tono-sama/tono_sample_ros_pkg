# tono_callback_spin
ROSのcallback関数とspinについて

## callbackとspinの使い方
### 参考サイト
- http://wiki.ros.org/roscpp/Overview/Callbacks%20and%20Spinning
- https://qiita.com/srs/items/36511930b6ffae9bc87a

### callback関数とは
- 条件が満たされたときに呼び出したい関数(実際に呼び出されるタイミングはspinとはを参照)
- 主に使用される条件はtopicの受信(Subscriber)とtimerで指定した時間が経過したとき(Timer) (他にはserviceとか)

### spinとは
- callback関数を呼び出したい条件が満たされていたら実際にcallback関数を実行するっていう関数
- singleスレッドかmultiスレッドかで関数や書き方が異なる(後述)

### spinによるcallback関数の呼び出し(ノードが single threadの場合(通常の場合))
- `ros::spin();`
	- callback関数の処理のみがノードの機能の場合によく使われる
	- この関数より下の行は(ROSがシャットダウンされるまでは)処理されない
	- callback関数の処理が即時される(これが最速)
- `ros::spinOnce();`
	- callback関数以外に処理があるノードで使われる
	- callback関数の処理が終了したら次の行の処理に進む

### spinによるcallback関数の呼び出し(ノードが multi threadの場合)
- `ros::AsyncSpinner spinner(4);`  
`spinner.start();`  
`ros::waitForShutdown();`
	- マルチスレッドでcallback関数の処理を行うときの書き方(callbac関数が非同期で処理される)
	- 1行目の引数でcallback関数を処理するスレッドの数を指定(0を指定するとCPUのコア数がスレッドの数になる)
	- start()関数でマルチスレッドの処理開始、stop()関数で停止
	- ros::waitForShutdown();関数より下の行は(ROSがシャットダウンされるまでは)処理されない