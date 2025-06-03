# Gobang Game (五子棋)

该项目实现了一个完整的五子棋游戏，支持以下功能：
- 人人对战模式（PVP）
- 人机对战模式（PVE）
- 智能AI对手
- 对局回放功能
- 游戏时长统计
  
## 功能亮点
- 基于评分模型的AI算法  
- 完整的对局记录和回放  
- 游戏状态管理 
- 实时胜负判断
- setup软件发布
  
## 技术细节
- AI算法：位置评分法
- 图形库：EasyX（Windows）
- 数据结构：二维数组表示棋盘

## 项目结构
```
Gobang-Game/
├── src/
│   ├── gobang.cpp
│   └── gobang.h
├── resources/
│   └── 01.jpg
├── records/
│   ├── pvp.txt
│   └── pve.txt
├── README.md
└── .gitignore
```

> 开发环境：Visual Studio 2022 + C++11
