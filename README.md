# Gobang Game (五子棋)

该项目实现了一个完整的五子棋游戏，支持以下功能：
- 人人对战模式（PVP）
- 人机对战模式（PVE）
- 智能AI对手
- 对局回放功能
- 游戏时长统计

## 功能亮点
✨ 基于评分模型的AI算法  
✨ 完整的对局记录和回放  
✨ 游戏状态管理  
✨ 实时胜负判断  

## 如何运行
1. 使用 Visual Studio 打开项目
2. 编译并运行 `main.cpp`
3. 选择游戏模式开始

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

## 技术细节
- AI算法：位置评分法（O(n²)时间复杂度）
- 图形库：EasyX（Windows）
- 数据结构：二维数组表示棋盘

> 开发环境：Visual Studio 2022 + C++11
