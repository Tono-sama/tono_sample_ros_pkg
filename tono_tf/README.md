# tono_tf
ROSの座標管理

## tfとは
- ROS上で座標系の管理をしてくれる機能
    - frame_1から見たframe_2の座標とframe_2から見たframe3の座標が与えられているときにframe_1から見たframe_3の座標を計算してくれる(しかもタイムスタンプを考慮して座標系の補間もしてくれる)
    - (例) ロボットの移動開始位置から現在のロボット基準位置と、ロボット基準位置とLiDARの相対位置を教えると、ロボットの移動開始位置から見たLiDARの点群が描画できる
- broadcasterを使って登録する方法が一般的みたいだけど、topicとしてpublishすることでtfを登録することもできる(個人的にはtopicの方が分かりやすい気がする...)
- tf vs. tf_static
- urdfによるtf_staticの登録
    - ロボット内部のtfはurdfで登録するのが一般的(楽)
- tf2はtfの完全上位互換らしい
    - tfでできることはそのままtf2でもできるらしいので置換して良さそう

## tf_publisher_1.launch
- 実行コマンド:  
`roslaunch tono_tf tf_publisher_1.launch`
    - value="0.0"のところを変えてから実行しなおして、変更が反映されるか確認しよう！

## robot_tf.launch
- 実行コマンド:  
`roslaunch tono_gazebo robot_tf.launch`
    - robotのtfが表示されることを確認できたらok！

## tf_test.launch
- 動作確認用
- frame_1_1から見たframe_1_2と、frame_2_1から見たframe_2_2が登録されているときにframe_1_2から見たframe_2_2を登録すると、frame_2_1が表示されない(仕様？)