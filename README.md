# hello_pwm
Raspberry Pi PicoでPWM生成　ブラシレスモータやサーボを動作させて検証できます。

## ビルド手順

念の為

`export PICO_SDK_PATH=../../pico-sdk


pico-sdkディレクトリがある場所で

```
git clone https://github.com/kouhei1970/hello_pwm.git
cd hello_pwm
mkdir build
cd build
cmake ..
make
```

## 接続

- GP2:Dutyが周期的変化
- GP3：Duty固定
