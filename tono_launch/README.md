# tono_launch
- launchファイルの使い方
    - 複数のノードをまとめて実行できて便利!(roscoreも不要)
- launchファイルの置き場はパッケージフォルダの中のlaunchフォルダの中
- launchファイルの書き方はXMLと同じ

## tono_launch001.launch
- 基本的なlaunchファイルの書き方
- nodeタグ...ノードの実行
    - pkg属性...実行したいノードのパッケージ名
    - type属性...実行したいノードのノード名
    - name属性...実行するときのノード名(ROSで認識されるノード名、同一のノード名のノードが実行されようとすると既に存在していた方が強制終了させられる)
    - output属性...screen or log を記述(screenにすると端末にコメントアウト表示される、デフォルト値はlog)
    - required属性...true or false を記述(trueにするとこのノードがkillされたとき他のノードもkillされる、デフォルト値はfalse)
- 実行コマンド:  
`roslaunch tono_launch tono_launch001.launch`
    - subscriberのコメントアウトが表示されればok!

## tono_launch002.launch
- includeタグ...他のlaunchファイルの実行
    - file属性...実行するlaunchファイル名($(find (パッケージ名))でパッケージのパスが得られる)
- remapタグ...topic名の置き換え(publisherとsubscriberの両方に適応可能)
    - from属性...置換前のtopic名
    - to属性...置換後のtopic名
- argタグ...launchファイルにおける変数の設定($(arg (変数名))で変数の値を取得できる)
    - name属性...変数名
    - default属性...デフォルトの値
- groupタグ...条件を満たしていればタグで囲まれた内容を実行 (ifはtrueのとき実行 unlessはfalseのとき実行 evalを使うと文字列比較も可能)
- 実行コマンド:  
`roslaunch tono_launch tono_launch002.launch`
    - rqt_graphのウィンドウで...node0, ...node1, ...node2の3組とremapしたtopic名が反映されていればok!

## tono_launch003.launch
- argを指定してlaunchファイルを実行
- includeタグ
    - argタグ(記述されなかったargタグの変数にはデフォルトの値が代入される)
        - name属性...変数名
        - value属性...値
- 実行コマンド:  
`roslaunch tono_launch tono_launch003.launch`
    - rqt_graphのウィンドウで...node0, ...node1, ...node3の3組とremapしたtopic名が反映されていればok!