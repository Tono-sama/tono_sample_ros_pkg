# tono_param
- rosparamとは...rosで簡単にパラメータ変更ができる機能
    - 再コンパイル不要なので楽！
- string型、int型、double型、bool型、リスト(配列)型が使える
    - リスト(配列)型はyamlでしか設定できないらしい(後述?)
- rosparamを使いたいノードでrosparamを読み込めるように記述
- 基本的にはlaunchファイルで
    1. yamlファイル(ROSのパラメータ設定ファイル)を読み込む方法
    2. node実行時にparamを渡す方法

## turtle_controller3_node
- rosparamを読み込んでturtleを動かすtopicを送るノード

## tono_param_turtlesim.launch
- launchファイルでyamlファイルを読み込み
- 実行コマンド:  
`roslaunch tono_param tono_param_turtlesim.launch`
- yamlを変更して亀の移動速度が変化すればok!