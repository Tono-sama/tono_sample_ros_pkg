# tono_sample_ros_pkg
ROSの基本的な機能の確認

1. ROSの導入
- ROS環境構築コマンド:  
`source ros_melodic_install.sh`
- 便利aliases
  1. .bash_aliases_tonoをホームディレクトリにコピペ
  2. ~/.bashrcに以下を追記(bash_aliasesを追加するコマンドが既にあると思うのでその直下当たりに書くのが美しい)  
  `if [ -f ~/.bash_aliases_tono ]; then`  
  `  . ~/.bash_aliases_tono`  
  `fi`
  - 中身
    - catm ... catkin_wsへのcdとcatkin_make
    - bagp ... rosbag play するときによく使うオプション付きの rosbag play 
      - 使用例: bagp hoge.bag

2. hello, world  
tono_helloworld

3. topic通信  
tono_simple_communication

4. loopの使い方  
tono_loop

5. マルチスレッド処理  
tono_callback_spin

6. launchファイル  
tono_launch

7. rviz  
tono_turtlesim

8. gazebo  
tono_gazebo

9. rosparam  
tono_param

10. TF  
tono_tf

11. cppでROSっぽく書く書き方みたいな  
tono_cpp_test

12. CUDA

## 追加メモ
- 拡張子でROSの機能を知る
- launch
  - 端末での実行時にarg指定
- TF
  - lookuptf
- rosbag
  - pythonでrosbag内容を読み込み
- Time
  - ros::Time vs ros::WallTime
