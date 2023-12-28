# Autocar
Arduino IDEとセンサーを組み合わせた自動運転車ロボットのArduinoファイル。

<img src="https://github.com/aozam3/Autocar/assets/65112280/260c5cf0-9750-49e1-ad4e-e98cb39c290b.png" width="500">

## Overview
Arduino IDEとセンサーを組み合わせて自動運転車ロボットを開発した。<br/>
超音波距離センサとモータを用いて、超音波距離センサが障害物を検知したら、モータを逆回転させ後ろに下がり、その障害物にぶつからないように曲がる。<br/>
また、このミニカーは、通常はブザーで音楽を流しながら走るが、障害物を検知すると警告音が鳴り、後退する。<br/>

### 機構
<img src="https://github.com/aozam3/Autocar/assets/65112280/5d0e5fc1-26b6-4c85-a95a-2da6b8bd7d6d.png" width="400">
<img src="https://github.com/aozam3/Autocar/assets/65112280/a6a74501-d537-4d57-be9a-3329f3604e7b.png" width="400">

ユニバーサルプレートにボールキャスター、モータ、ギアーボックスをそれぞれ2つずつ付けることで四輪車を実現できた。モータは直径55mmと一体化しており、これによりミニカーが前後左右に動く。ユニバーサルプレート上にはブレッドボード、Arduino本体、Arduino・モーターへの電源、パッシブブザー、電源モジュールがある。なお、超音波距離センサは車体の前面に取り付け、重量のあるArduino本体、Arduino・モーターへの電源、ブレッドボードは車体にテープで固定した。モータ、ギアーボックスはユニバーサルプレートの裏側に固定されている。また、モータのリード線が短かったため、ブレッドボードと付属のリード線を利用し、L293Dに接続できるようにした。

以下に示す。

| 使用した部品 | 個数 | 役割 |
| ---- | ---- | ---- |
| Uno R3 | 1 | プログラムで要求された挙動を実現する |
| ブレッドボード	 | 1 | ハンダ付け無しで素早く回路を制作する |
| 超音波センサ | 1 | 障害物を検知する |
| パッシブブザー | 1 | 音楽・警告音を鳴らす |
| 電源モジュール | 1 | モータに供給する電源を制御する |
| 電池 | 2 | Arduino Unoとモーターに電源を供給する |
| リード線 | 適当 | それぞれの部品をつなぐ |
| L293D | 1 | モータを制御する |
| モータ | 1 | タイヤを動かす |
| ギヤーボックス | 2 | モータの回転を遅くする |
| ボールキャスター | 2 | ロボットの動きを柔軟にする |
| ユニバーサルプレート | 2 | ロボットの基盤になる |
| タイヤ | 2 | ロボットを走らす |

### 制作物の回路図
<img src="https://github.com/aozam3/Autocar/assets/65112280/7f5e73d3-7fc6-48ff-8960-01c69f6337d1.png" width="500">

回路は主にセンサー(HC-SR04)を制御する回路、左右のモータを制御する回路、ブザーを制御する回路、Arduinoに電源を供給する電池に分けられる。
