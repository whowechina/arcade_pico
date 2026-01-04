# Arcade Pico - 街机按钮的替代开关灯座
[Click here for the English version of this guide](README.md)

<img src="doc/main.jpg" width="90%">

本项目是我之前 sanwa_opt 项目的继任者。通过这个项目，你可以在街机按钮上使用普通的键盘矮轴，甚至是光电开关。

## 特性
* 兼容老款和新款三和，韩国三鸭以及常见的国产街机按钮；
* 支持机械键盘轴，光电开关和磁（霍尔）轴（需要 IO 板）；
* 机械轴支持热插拔（凯华 Choc 插座）；
* 手感轴和触发轴可以分离；
* 幻彩RGB LED 支持（需要 IO 板）；
* 非常适合 FDM 3D 打印。
* 多种连接选项以适应不同的系统。

## 感谢
感谢许多尊敬的爱好者和公司将他们的工具或材料免费或开源（KiCad，OnShape，InkScape，Raspberry 相关工具, 嘉立创等）。

特别感谢社区项目和开发者的帮助，还有如下项目：
* RP_Silicon_KiCad: https://github.com/HeadBoffin/RP_Silicon_KiCad

## 其他项目
你也可以查看我其他的酷炫项目。

<img src="https://github.com/whowechina/popn_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/iidx_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/iidx_teeny/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/chu_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/mai_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/diva_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/aic_pico/raw/main/doc/main.gif" height="100px"> <img src="https://github.com/whowechina/groove_pico/raw/main/doc/main.gif" height="100px">  <img src="https://github.com/whowechina/geki_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/musec_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/ju_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/bishi_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/nos_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/voltex_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/chord_pico/raw/main/doc/main.jpg" height="100px"> <img src="https://github.com/whowechina/arcade_pico/raw/main/doc/main.jpg" height="100px">

* Popn Pico: https://github.com/whowechina/popn_pico
* IIDX Pico: https://github.com/whowechina/iidx_pico
* IIDX Teeny: https://github.com/whowechina/iidx_teeny
* Chu Pico: https://github.com/whowechina/chu_pico
* Mai Pico: https://github.com/whowechina/mai_pico
* Diva Pico: https://github.com/whowechina/diva_pico
* AIC Pico: https://github.com/whowechina/aic_pico
* Groove Pico: https://github.com/whowechina/groove_pico
* Geki Pico: https://github.com/whowechina/geki_pico
* Musec Pico: https://github.com/whowechina/musec_pico
* Ju Pico: https://github.com/whowechina/ju_pico
* Bishi Pico: https://github.com/whowechina/bishi_pico
* Nos Pico: https://github.com/whowechina/nos_pico
* Voltex Pico: https://github.com/whowechina/voltex_pico
* Chord Pico: https://github.com/whowechina/chord_pico
* Arcade Pico: https://github.com/whowechina/arcade_pico

## **声明** ##
我在个人时间内制作了这个项目，没有任何经济利益或赞助。我将继续改进这个项目。我已尽我所能确保所有内容的准确性和功能性，但总有可能出现错误。如果你因使用这个开源项目而造成时间或金钱的损失，我不能负责。感谢你的理解。

## 关于许可证
它是 CC-NC 授权。所以你只能给自己和你的朋友 DIY，不能利用这个项目赚钱，比如收费的代做，出售整机等，连源作者都不敢提的抄袭，或者稍微改改换个名字来打擦边球，这些都是不允许的。注意团购和拼单订购原始元器件是合理的，非盈利的方式卖掉剩余的元器件也是可以接受的。

如果希望找我购买成品或者获取商用授权，请联系我（Discord，QQ 群，闲鱼）。
* Discord 服务器邀请：https://discord.gg/M8f2PPQFEA
* QQ 群：854535476
* 闲鱼：whowe12345

## 使用场景
### 先对齐术语
* **`按钮板`** - 包含开关轴和 LED 子板的 PCB。它是 Arcade Pico 项目的主要部分。
* **`IO 板`** - 可选的 PCB，将磁轴信号转换为数字信号，并将常规 LED 信号桥接到 WS2812B RGB LED 数据信号。它也是 Arcade Pico 项目的一部分。
* **`主板`** - 你的手台或者街机系统的原始主控板或 IO 板。
* **`灯座`** - 准确说是灯和开关轴共同的底座，习惯上都简称为灯座。

### 场景：不使用 `IO 板` 的情况下替换灯座/开关座
这是最常见也最简单的使用场景。你只需要将你的 `主板` 上的开关和灯的信号接线到 `按钮板` 上对应的连接器即可。
你可以使用机械轴或者光电传感器，但不能使用磁轴或 RGB 灯。

#### 连线方式
* `按钮板` 的 **SW Out** (SH1.0 3P) → `主板` 的 **按钮输入**
* `按钮板` 的 **LED In** (SH1.0 3P) ← `主板` 的 **灯输出**

### 场景：使用 `IO 板` 享受磁轴或 RGB 幻彩灯
使用磁轴的话，你可以定义触发和复位距离。使用幻彩灯，你可以定义按钮灯颜色和效果。这个场景下，需要 `IO 板` 来驱动磁轴和幻彩灯。

#### 连线方式
* 磁轴信号
  * `按钮板` 的 **SW Out** (SH1.0 3P) → `IO 板` 的 **Hall In** (SH1.0 3P)
  * `IO 板` 的 **Out** (XH2.5 2P) → `主板` 的 **按钮输入**

* 幻彩灯信号
  * `主板` 的 **灯输出** → `IO 板` 的 **Lamp In** (XH2.5 2P)
  * `IO 板` 的 **LED Out** (SH1.0 3P) → `按钮板` 的 **LED In** (SH1.0 3P)
  * `按钮板` 的 **LED Out** (SH1.0 3P) → 下一个 `按钮板` 的 **LED In** (SH1.0 3P)（如果有的话）
  * 最后一个 `按钮板` 的 **LED Out** (SH1.0 3P) → `IO 板` 的 **LED End**，用作灯光供电备份。

* 你可以通过 JST 2P 从 `主板` 的 5V 电源为 `IO 板` 供电，或者直接通过 Type-C 接口（USB 或电源适配器）供电。

#### 当 `IO 板` 通过 Type-C 连接到主机电脑时：
  * `IO 板` 作为 HID 设备工作。  
    所以如果你不介意这根额外的 USB 线，你也许可以省去 `IO 板` 和 `主板` 之间的连线。但是，有些游戏要求控制器是单一设备，所以这个方式对这类游戏没用。
  * CLI（命令行界面）运行在 USB CDC（串口）。
  * Type-C 接口可以用于固件更新。

### 幻想的场景：与 DJDao PhoenixWAN 对接
这只是一个理论上的场景，可能不会被实现。如果实现了，`IO 板` 和 `主板` 之间所有那些复杂的连线都将被消除 - 它们将通过 UART 通信。

希望这一天能到来。

# 如何制作
## 按钮板
### 通用部分
* PCB 的 Gerber 文件在 `Production/PCB/"arcade_pico_button_*.zip"`。文件名带有 `socket` 的版本是热插拔版（适用于 Choc V1 和 V2）。我总是使用嘉立创（https://www.jlcpcb.com）和 捷配（https://www.jiepei.com），你也可以使用你喜欢的 PCB 制造商。他们可能会问你是否需要为 `按钮板` 制作半孔焊盘，只需回答“否”，没必要浪费钱在这个用不上的工艺上。
* 2X 3P SH1.0 水平贴片插座，分别焊接在 “SW” 和 “LED In” 焊盘上。
* 1X 3P SH1.0 水平贴片插座，焊接在 “LED Out” 焊盘上，仅当使用幻彩灯时才需要。

* 连接 LED 的方法:
  * “LED In” 连接器（+, -）用于连接来自你现有 `主板` 的常规单色 LED 信号。
  * 当使用 WS2812B RGB 幻彩 LED 子板时，“LED In” 和 “LED Out” 连接器用于串联连接。

### 机械轴
* 使用 SW1 或 SW2 焊盘以安装 Kailh Choc V1/V2 机械轴。
* 如果选择热插拔 PCB 版本，请使用 Kailh Choc 矮轴热插拔插座。  
  https://kailhswitch.net/products/kailh-mechnical-keyboard-switches-hot-swap-pcb-socket-diy-for-1350-choc-low-profile-keyboard-switches
* 短接对应的跳线（sw1 或 sw2）来启用该轴。
* 你可以焊接另一个轴，但它只是为了手感，所以不要短接对应跳线。

* 连接到 `主板` 的方法：
  * “SW” 连接器（Out，GND）用于开关信号；

* 这个例子展示了 SW1 作为触发开关，可选的 SW2 仅提供手感。  
  <img src="doc/choc_pcb1.png" width="38%"/> <img src="doc/choc_pcb2.png" width="40%"/>

  
### 光学传感器 (红外对管)
* 焊接红外二极管（IR908-7C）和光电三极管（PT908-7C）并调节到合适的高度；
* 焊接 R3（3.3V 供电时为 500 ohm，5V 供电时为 1k ohm）；
* 电阻：R4、R5；跳线：c、e；齐纳二极管：Z1。
  * 低有效逻辑（大多数系统都是）：R4（0-10 ohm），R5（2k ohm），通过焊接跳线 e 来短接。
  * 高有效逻辑：R4（2k ohm），R5（0-10 ohm），短接跳线 c。
  * 当电源为 5V 但目标系统 IO 为 3.3V 时，焊接 Z1（3.3V SOD-123F 齐纳二极管）来保护 IO 管脚。
* 你可以在 SW1 焊盘上焊接一个机械轴以增加手感，但不要短接跳线 sw1。
* 在大部分系统上，LED 的正极线是恒定的 5V 或 3.3V 电源供应，你可以借用它来为光学传感器供电 - 只需短接跳线"LEDP-V"。

* 连接到 `主板` 的方法：
  * "SW" 连接器（V、Out、GND）用于开关信号；

* 这个例子展示了低有效逻辑配置，5V 从 LED 正极线借用，SW1 上的可选 Choc V1 仅用于手感。  
  <img src="doc/opt_pcb1.png" width="41%"/> <img src="doc/opt_pcb2.png" width="38%"/>

### 磁轴（霍尔传感器）
* 磁轴安装在 SW1 焊盘上。
* 焊接 U1（SS49E SOT23-3）和 C1（0.1uF 0603）。
* 你可以在 SW2 焊盘上安装一个机械轴以增加手感，但不要短路对应跳线。
* 如果磁轴安装不够紧，你可能需要使用一些 RTV 硅胶粘合剂来固定它。

* 这个例子里，SW1 上的是磁轴，SW2 上的可选的 Choc V1 仅用于手感。  
  <img src="doc/he_pcb1.png" width="43%"/> <img src="doc/he_pcb2.png" width="37%"/>

* 连接到 `主板` 的方法：
* "SW" 连接器（V、Out、G）连接到 **Arcade Pico IO** 板。然后 `IO 板` 连接到 `主板`。

* 注意：这套配置需要 Arcade Pico `IO 板`。

## LED 子板
* 它需要从 **Arcade Pico 按钮** 板分离，切断或者掰断都行。有两个 LED 子板：单色 LED 和 WS2812B RGB LED。你可以根据需要选择其中一个。
* 焊接元件后，从上侧垂直将 LED 子板插入按钮 PCB。注意先只焊接一个焊盘，这样你就有机会调整高度。
* 如果太低或太高，你将无法获得均匀的照明。你可以测量你的旧灯座的对应高度。根据我对三和按钮的经验，从 LED 顶部到 PCB 表面的距离约为 37mm。
* 完成高度调整后，焊接所有剩下的焊盘以固定连接。  
<img src="doc/assembly_1.jpg" width="30%"/> <img src="doc/assembly_2.jpg" width="49%"/>

### 单色 LED 板
* 使用高亮度侧发光的 LED 型号。焊盘兼容各种封装，例如贴片的 4008、4020、3014，甚至直插型（带凹透镜的更好）。
* 如果使用贴片 LED，装两颗，两面各一颗，以获得更好的光分布。
* 它们的工作电流一般是 20mA。通常 5V 供电使用 100-220 ohm限流电阻（R1 和 R2），3.3V 供电则使用 50-100 ohm。
* 焊接后的样子。  
  <img src="doc/led_pcb1.png" width="30%"/> <img src="doc/led_pcb2.png" width="36%"/> <img src="doc/led_pcb3.png" width="13%"/>
* 如果 LED 焊盘的极性与你的 LED 不匹配，只需在**两侧** "x" 标记处切断铜箔走线，并相应短接跳线。这样极性就反过来了。  
  <img src="doc/led_pcb4.png" width="30%"/>

### WS2812B RGB LED 板
* **需要用到 Arcade Pico `IO 板`。**
* 使用 WS2812B 4020 侧发光 RGB LED。装两颗，两面各一颗，以获得更好的光分布。
* 强烈建议在 C2 焊盘上使用 0.1uF 0805 或 0603 电容。
* 焊接后的样子。  
  <img src="doc/rgb_pcb1.png" width="34%"/> <img src="doc/rgb_pcb2.png" width="36%"/> <img src="doc/rgb_pcb3.png" width="12%"/>

## `IO 板`
* `IO 板` 可以将磁轴的模拟信号转换为数字信号供你的主控板使用。它还可以将传统 LED 灯信号桥接为 WS2812B RGB LED 数据信号。
* 如果你不需要其中一个或两个功能，只需跳过对应的元件。

<img src="doc/io_pcb1.png" width="40%"/> <img src="doc/io_pcb2.png" width="41%"/>

### 通用部分
* 1x 树莓派 Pico。  
  https://www.raspberrypi.com/products/raspberry-pi-pico
* 2x 2P JST XH2.54 或 XH2.5 直插连接器，用于 5V 电源输入。
* 1x 3P JST XH2.54 或 XH2.5 直插连接器用于 UART，供未来使用。

### 磁轴部分的元件
* 1x ADG708BRUZ，8 转 1 模拟选路开关，TSSOP-16 封装（U3）。
* 1x LP5907MFX-4.5 或 TPS7A2042PDBVR LDO，SOT23-5 封装（U2），见下一行。
* 1x LM4040 分流参考电压源，SOT23-3 封装（Z2），2.0~2.1V（用于 4.2V LDO）或 2.2~2.5V（用于 4.5V LDO）。
* 1x 3.3V 齐纳二极管，SOD-123 或 SOD-123F 封装，例如 BZT52H-C3V3（Z1）。
* 3x 0.1uF 0603 电容（CC1、CC2、CC3）。
* 8x 3P SH1.0 水平贴片连接器（In1~In8），用于连接最多 8 个磁轴 `按钮板`。
* 8x 2P JST XH2.54 或 XH2.5 竖直连接器（Out1~Out8），用于连接到主控板。

### RGB LED 的元件
* 8x 220 ohm 0603 电阻（R1~R8），用于光耦隔离器限流。如果你的灯是 12V，使用 1k ohm 0805 电阻。
* 8x 1N4148 SOD-323 二极管（D1~D8），用于保护反向电压，仅在 12V 灯输入时需要。
* 2x PC847 或兼容的四路光耦隔离器（U4、U5），SOP-16 封装。
* 2x 0805 x 4 5.1K 8P4R 电阻阵列（RN1、RN2），如果不可用，使用 8x 单独的 5.1K 0603 电阻代替。
* 2x 3P SH1.0 水平贴片连接器（LED Out 和 LED End），用于连接配备 WS2812B RGB LED 子板的 `按钮板`。
* 8x 2P JST XH2.54 或 XH2.5 竖直连接器（Lamp In 1~8），用于连接到主控板的 LED 信号。

## PCB 和电路说明
### 可能**需要**调整的东西
* 这是计算 LED 限流电阻的方法，也适用于光耦隔离器的红外发光二极管：
  * R = (V_supply - V_F) / I
  * 单色 LED 的 V_F 通常约为 3V，红外发光二极管的 V_F 通常约为 1.3V。
  * 单色 LED 的 I 通常为 10-20mA，红外发光二极管的 I 实际为 1-10mA。
* 这是计算光电三极管的上拉或下拉电阻的方法（`按钮板` 上的和光耦隔离器内部的）：
  * R >= V_supply / I_C
  * 很难估计光电三极管的 I_C（集电极电流），所以假设它约为 1mA。
  * 所以在 3.3V 电源供应下，R >= 3.3V / 1mA = 3.3K ohm，你可以使用 3.3K 或 3.9K ohm电阻。
  * 你可能需要根据实际设置调整电阻值。

### 可能**想**调整的东西
* 对于"手感轴"，选择有点击感的，Choc V1 和 Choc V2 都有一些点击选项。如果你找到其他适合焊盘的低轮廓机械轴，你也可以尝试。
* 当同时安装了磁轴和"手感"轴时，弹簧力会叠加，你可能想为两个开关都使用较轻的弹簧。你可以选择轻力开关，或者你可以改变其内部的弹簧。

## 灯座体
* 使用任何 FDM 打印机来打印。
  * 材料：PLA、PETG、ABS，随你选择。
  * 层高：推荐 0.2mm。
  * 填充：20% 就足够了。
  * 墙：2-4 层。
  * 支撑：是的，树形支撑。

* 文件在 "Production/3DPrint" 文件夹中。
  * `Sanwa_push.stl` - 老款三和灯座（推按式）。
  * `Sanwa_twist.stl` - 新款三和灯座（旋转锁定式）。
  * `Samducksa.stl` - Samducksa 灯座。
  * `Chinese.stl` - 常见的国产街机按钮灯座。

* 使用 M2\*6mm 螺钉将 PCB 固定在按钮上。
