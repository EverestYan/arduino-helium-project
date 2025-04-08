# Arduino Helium Box Stability Experiment

## 项目目标
通过超声波传感器和氦气环境优化光悬浮实验的稳定性。

## 硬件需求
- Arduino Uno
- HC-SR04 超声波传感器
- 氦气箱组件

## 代码结构
- `src/main/main.ino`: 主程序（超声波测距）
- `src/test/ultrasonic_test.ino`: 传感器功能测试代码

## 快速开始
1. 克隆仓库：`git clone https://github.com/yourname/arduino-helium-project.git`
2. 使用 Arduino IDE 打开 `src/main/main.ino`
3. 上传到开发板并监视串口输出。

## 贡献指南
- 提交代码前运行测试。
- 使用 `dev` 分支开发，通过 PR 合并到 `main`。