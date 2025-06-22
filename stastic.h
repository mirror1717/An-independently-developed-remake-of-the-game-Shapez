#ifndef STASTIC_H
#define STASTIC_H


#define WIN_PATH ":/picture/win.png"    // win图案
/******************游戏界面背景*******************/
#define GAME_WIDTH 780 // 可放置物体区域宽度
#define GAME_HEIGHT 520 // 可放置物体区域高度
#define WIDTH 26        // 可放置物体区域横向网格数
#define HEIGHT 14       // 可放置物体区域纵向网格数
#define BIANCHANG 30     // 每个格子的边长

/******************矿地资源*******************/
#define CYCLE_MINE ":/picture/cycle_mine.png" // 圆形矿地
#define RECT_MINE ":/picture/rect_mine.png"   // 方形矿地
#define BARRIER_ ":/picture/barrier.png"        // 障碍物
/*********************按钮***********************/
#define BUTTON_SIZE 70                              // 选择工具区域的工具按钮大小
#define MINER_BUTTON_PATH ":/picture/miner_button.png"   // 采矿机
#define BELT_BUTTON_PATH ":/picture/belt_button.png"     // 传送带
#define CUTTER_BUTTON_PATH ":/picture/cutter_button.png" // 切割机
#define TRASH_BUTTON_PATH ":/picture/trash_button.png"    // 垃圾桶
/****************不同大小的交付中心******************/
#define HUB_SMALL_PATH ":/picture/hub_small.png" // 小交付中心
#define HUB_BIG_PATH ":/picture/hub_big.png"     // 大交付中心
/****************不同方向的采矿机******************/
#define MINER_A_PATH ":/picture/miner_A.png" // 朝左
#define MINER_D_PATH ":/picture/miner_D.png" // 朝右
#define MINER_S_PATH ":/picture/miner_S.png" // 朝下
#define MINER_W_PATH ":/picture/miner_W.png" // 朝上
/****************不同方向的传送带******************/
#define BELT_A_PATH ":/picture/belt_A.png"
#define BELT_A_S_PATH ":/picture/belt_A_S.png"
#define BELT_A_W_PATH ":/picture/belt_A_W.png"
#define BELT_D_PATH ":/picture/belt_D.png"
#define BELT_D_S_PATH ":/picture/belt_D_S.png"
#define BELT_D_W_PATH ":/picture/belt_D_W.png"
#define BELT_S_PATH ":/picture/belt_S.png"
#define BELT_S_A_PATH ":/picture/belt_S_A.png"
#define BELT_S_D_PATH ":/picture/belt_S_D.png"
#define BELT_W_PATH ":/picture/belt_W.png"
#define BELT_W_A_PATH ":/picture/belt_W_A.png"
#define BELT_W_D_PATH ":/picture/belt_W_D.png"
/****************不同方向的切割机******************/
#define CUTTER_A_PATH ":/picture/cutter_A.png" // 朝左
#define CUTTER_D_PATH ":/picture/cutter_D.png" // 朝右
#define CUTTER_S_PATH ":/picture/cutter_S.png" // 朝下
#define CUTTER_W_PATH ":/picture/cutter_W.png" // 朝上
/****************不同方向的垃圾桶******************/
#define TRASH_A_PATH ":/picture/trash_A.png" // 朝左
#define TRASH_D_PATH ":/picture/trash_D.png" // 朝右
#define TRASH_S_PATH ":/picture/trash_S.png" // 朝下
#define TRASH_W_PATH ":/picture/trash_W.png" // 朝上
/******************物品*******************/
#define CYCLE_PATH ":/picture/cycle.png"             // 圆形物品
#define RECT_PATH ":/picture/rect.png"               // 方形物品
#define LEFT_CYCLE_PATH ":/picture/left_cycle.png"   // 左圆形物品
#define RIGHT_CYCLE_PATH ":/picture/right_cycle.png" // 右圆形物品
/******************名字宏*******************/
#define NONE 0
// 物品
#define CYCLE 1
#define RECT 2
#define LEFT_CYCLE 3
#define RIGHT_CYCLE 4
#define BARRIER 5
// 建筑
#define HUB 21
#define MINER_W 22
#define MINER_A 23
#define MINER_S 24
#define MINER_D 25
#define CUTTER_W_R 26
#define CUTTER_A_R 27
#define CUTTER_S_R 28
#define CUTTER_D_R 29
#define CUTTER_W_L 30
#define CUTTER_A_L 31
#define CUTTER_S_L 32
#define CUTTER_D_L 33
#define TRASH_W 34
#define TRASH_A 35
#define TRASH_S 36
#define TRASH_D 37
#define BELT_A 38
#define BELT_A_S 39
#define BELT_A_W 40
#define BELT_D 41
#define BELT_D_S 42
#define BELT_D_W 43
#define BELT_S 44
#define BELT_S_A 45
#define BELT_S_D 46
#define BELT_W 47
#define BELT_W_A 48
#define BELT_W_D 49
#define BELT 50
#define CUTTER 51
#define TRASH 52
#define MINER 53

#endif // STASTIC_H
