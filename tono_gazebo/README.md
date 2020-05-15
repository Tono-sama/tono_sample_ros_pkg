# tono_gazebo
gazeboで遊ぼう!

## (多分)依存パッケージ
- インストールコマンド(ワイルドカード使ってるので雑):  
`sudo apt-get install ros-melodic-gazebo*`  
`sudo apt-get install ros-melodic-velodyne*`  

## tono_gazebo.launch
- 実行コマンド:  
`roslaunch tono_gazebo tono_gazebo.launch`
  - rviz上でgazeboの障害物が映っていればok!
- おまけ(速度指令)  
`rostopic pub -r 10 /tono_robot/diff_drive_controller/cmd_vel geometry_msgs/Twist -- '[1.0, 0.0, 0.0]' '[0.0, 0.0, 0.5]'`
  - ロボットが回転すればok!
