# tono_simple_communication
topic通信をしよう！

## simple_talker_node
- topic通信の送信側のノード
- 実行コマンド:  
`rosrun tono_simple_communication simple_talker_node`
- 端末にhelloworldが表示されることを確認できればok!

## simple_listener_node
- topic通信の受信側のノード
- 実行コマンド:  
`rosrun tono_simple_communication simple_listener_node`
- 端末にhelloworldが表示されることを確認できればok!

## turtle_controller_node
- turtlesimで遊ぶノード
- 実行コマンド:  
`rosrun turtlesim turtlesim_node`  
`rosrun tono_simple_communication turtle_controller_node`
- 亀が円を描いて移動すればok!