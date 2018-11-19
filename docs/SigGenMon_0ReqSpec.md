# Requirements



## 시작하는 질문

* Microcontroller를 배워보니 Digital 신호를 입출력 할 수 있고, Analog 신호도 입출력 할 수 있네.
* 그러면 실험실에서 보는 Function Generator 처럼 신호를 만들어 내고 Osciloscope 처럼 신호를 측정할 수도 있지 않을까?
* Microcontroller를 사용하면 신호 입출력은 가능한데, 사용자가 볼수 있는 장치와 사용자가 조정할 수 있는 스위치나 단추들이 없네(참고로 이것을 MMI: Man-Machine Interface 라고 함).  아 그것은 XMC의 uC/Probe를 사용하면 될 수 있겠다
* 나도 XMC와 uC/Probe를 사용해서 간단한 Function Generator 와 Oscilloscope를 만들어 보자!
* 이름도 지어주자 **Signal Generator & Monitor**




### System Overview

![System](./images/ReqSpec.svg)

* Digital 신호 2 Channel, Analog 신호 2 Channel을 입출력 한다.
* PC를 통해서 신호들을 확인하고 발생시킬 수 있다.


* Digital 신호
  * 최근의 동향을 반영하여 는 3.3V와 5V 신호를 모두 인터페이스 할 수 있다.
* Analog 입력
  * 0.1 ~ 10 의 증폭비를 갖도록 하고, 간단한 조작으로 증폭비를 조정할 수 있다.
  * 고주파 노이즈를 억제할 수 있는 필터를 장착하고, 간단한 조작으로 필터의 차단주파수를 조정할 수 있다.
* Analog 출력
  * 공급 전압에 따라 0~3.3V 혹은 0~5V의 전압을 출력할 수 있다.