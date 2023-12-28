# Autocar
Arduino IDEとセンサーを組み合わせた自動運転車ロボットのArduinoファイル。

<img src="https://github.com/aozam3/Autocar/assets/65112280/260c5cf0-9750-49e1-ad4e-e98cb39c290b.png" width="600">

## Overview
Arduino IDEとセンサーを組み合わせて自動運転車ロボットを開発した。<br/>
超音波距離センサとモータを用いて、超音波距離センサが障害物を検知したら、モータを逆回転させ後ろに下がり、その障害物にぶつからないように曲がる。<br/>
また、このミニカーは、通常はブザーで音楽を流しながら走るが、障害物を検知すると警告音が鳴り、後退する。<br/>

### 構造
<img src="https://github.com/aozam3/Autocar/assets/65112280/5d0e5fc1-26b6-4c85-a95a-2da6b8bd7d6d.png" width="400">
<img src="https://github.com/aozam3/Autocar/assets/65112280/a6a74501-d537-4d57-be9a-3329f3604e7b.png" width="400">

使用した部品とその役割を以下に示す。


### 制作物の回路図
<img src="https://github.com/aozam3/Autocar/assets/65112280/7f5e73d3-7fc6-48ff-8960-01c69f6337d1.png" width="600">

回路は主にセンサー(HC-SR04)を制御する回路、左右のモータを制御する回路、ブザーを制御する回路、Arduinoに電源を供給する電池に分けられる。
