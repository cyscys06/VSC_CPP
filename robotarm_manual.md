# 시작
본 매뉴얼은 **ElephantRobotics사의 제품 MyCobot 320 pi와 F100 Force Gripper** 세팅을 위한 기본 가이드라인입니다.  
목표: 로봇암 및 그리퍼의 기본 세팅을 완료하고, ElephantRobotics사에서 기본적으로 제공하는 앱과 ROS2 및 ROS2 관련 툴(Rviz, Gazebo, Moveit 등)들을 사용하여 이를 제어합니다.  
매뉴얼 내용은 ElephantRobotics사의 공식 문서 및 여러 자료들을 참고하여 작성되었으며, 비정기적으로 업데이트될 수 있습니다.
궁금한 사항이 있다면 언제든지 댓글 남겨주세요.

# 주의할 점

## 1. 내장 PC에 대해
- MyCobot 320 pi 모델은 로봇 내부에 라즈베리파이 기반의 PC가 내장되어 있으며, 
  Ubuntu 또한 기본적으로 설치되어 있습니다.
- 따라서 외부 PC에 로봇을 연결할 필요가 없습니다.

**기본 OS: Ubuntu 20.04  
기본 ROS2 버전: Galactic(후에 다른 버전으로 변경합니다)**

- 모니터 / 키보드 / 마우스를 연결하여 로봇 내부 PC에서 직접 작업하며,  
  로봇 제어에 필요한 앱이나 툴 또한 이미 설치되어 있습니다.

## 2. 공식 문서를 항상 참고할 것
모르는 내용이 있으면 반드시 아래 공식 문서를 같이 확인해 주세요.  
영어로 나와있지만, 한국어로 번역하면 어느 정도 이해가 가능합니다.

**공식 문서:**  
[https://docs.elephantrobotics.com/docs/gitbook-en/](https://docs.elephantrobotics.com/docs/gitbook-en/)
- 모델 별로 상세 가이드가 나와있으므로, 이를 참고하면 큰 도움이 됩니다.

## 3. 로봇암 취급 주의사항
- 다음 주의사항을 꼭 읽어주세요:

1. 로봇암에 강제로 과한 힘을 가하지 마세요.
- 특히, 로봇암의 전원을 켠 후(로봇암이 고정된 상태)에 힘을 가하면 파손 및 고장의 원인이 될 수 있습니다.
- 관절부가 아닌 부분에도 강제로 과한 힘을 가하지 마세요. 제품이 파손될 수 있습니다.
- 또한, 관절부의 가동 범위 밖으로 로봇암을 강제로 움직이려 하지 마십시오. 제품이 파손될 수 있습니다.

2. 로봇암의 가동 범위를 잘 파악하세요.
- 가동 범위 안에 가급적 물체를 두지 마세요. 로봇암이 움직이는 데 방해가 될 수 있으며, 제품이 파손될 수 있습니다.
- 로봇암이 가동되다가 로봇암이 고정된 장소(ex: 책상)와 우연히 부딪힐 수 있습니다. 제품이 파손되지 않도록 주의하세요. 
- 충돌 위험이 있을 경우, 비상 정지 버튼을 눌러 로봇암의 가동을 강제로 종료할 수 있습니다.

3. 가급적이면 내장 PC의 전원을 먼저 끈 후, 로봇암의 전원을 꺼주세요.
- 아직 별다른 사항은 발견되지 않았지만, 강제 종료할 경우 데이터가 제대로 저장되지 않을 가능성도 있습니다.

# 로봇암, 그리퍼 세팅
**공식 문서**  
[https://docs.elephantrobotics.com/docs/gitbook-en/2-serialproduct/2.2-320/2.2.2-PI.html](https://docs.elephantrobotics.com/docs/gitbook-en/2-serialproduct/2.2-320/2.2.2-PI.html)
- MyCobot 320 pi 모델에 대한 가이드라인 항목입니다. 모르는 부분이 있다면 참고하세요.

## 케이블 연결
### 구성품 소개
[##_Image|kage@Mmwj4/dJMcaa5zIAJ/AAAAAAAAAAAAAAAAAAAAAF92OJ2jG1dm39pU2bYQSrYFqISnZDbRGrMN-LKKfNPv/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=fkhg9dwvDeYd6tphBGjWco3h8DM%3D|CDM|1.3|{"originWidth":4032,"originHeight":3024,"style":"alignCenter"}_##]
- 로봇 설치 과정에서 실제로 사용한 부품만 소개합니다.
- 내장 PC의 인터넷 연결을 위해, 랜선은 미리 준비해주세요(구성품에 포함되어 오지 않음).

### 1. 비상 정지 버튼
[##_Image|kage@bhS1lY/dJMcai3xTnc/AAAAAAAAAAAAAAAAAAAAAEctR1Mc6JEZ3K6gnpSF4EyHkmkq0uIbXRF61oqWlZQQ/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=JIgj3CvIVob8uNsApfdPZNjaiC0%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 로봇에 이상이 있거나, 관절부에 무리한 힘이 가해질 상황에 비상 정지 버튼을 눌러 강제 종료할 수 있습니다.

[##_Image|kage@cRFqUO/dJMcacbfudF/AAAAAAAAAAAAAAAAAAAAAF3vBj7EkYVQ_BlbR0aEb0UDTciGmsBfIlYbVA8o4q3c/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=zL1QrDC1H94T3GFxUJeNR97ZVYM%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 위의 포트에 연결합니다.

[##_Image|kage@b25HTe/dJMcaakcKqE/AAAAAAAAAAAAAAAAAAAAAN-T0ZkvSHK2QHqHUdgIPtrEFsD8-oLqrhNIgwyZD-FN/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=apzT%2Bp9nvmA%2FGoUAcibpXJwPFjA%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 연결한 후, 양쪽의 구멍 안에 있는 일자 볼트를 조여 고정할 수 있습니다(4-5. 일자드라이버 참조).

### 2. 전원 케이블
[##_Image|kage@clEHNL/dJMcac958fP/AAAAAAAAAAAAAAAAAAAAAL6GjpSoURABkPEWczSRjlBwm0LA3avig7-RIhgmI-6H/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=4F7hrnglo6nz%2FQuiNH51AZIoBn8%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 전원 포트에 연결하는 케이블입니다. 포트 구멍과 케이블의 요철의 위치가 같은 방향에 있는지 비교하면서 연결하세요.

[##_Image|kage@bx7jNG/dJMcabcjRY7/AAAAAAAAAAAAAAAAAAAAAH9p3z1Jxw_PKQK_QCnrFosxEqJamJra1eXZoGuj7S7k/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=K%2BIju1TOR94Adi6VP%2FpFHUXPyQY%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 연결된 사진입니다.

### 3. 모니터 케이블
[##_Image|kage@bwpFAd/dJMcadA9sV5/AAAAAAAAAAAAAAAAAAAAAO8CWXNTJ8aPsGbfca_l1t876xzhOw1d1gyz88ajIRcq/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=q4xyBUZAaKYKDNusf3txsQsB2v0%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 내장 PC의 화면을 모니터에 출력하게 해주는 케이블입니다.

[##_Image|kage@qAEMY/dJMcajg5RF4/AAAAAAAAAAAAAAAAAAAAAGQBt8hb8pslguZBrRrkv2VugLaOo8g4CzAzl2MiqEgw/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=IbwVN6cNHP7vnSsJGvD1R75%2BHVE%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- HDMI는 모니터의 HDMI 포트에, 반대쪽은 로봇암의 모니터 연결 포트에 연결해주세요(HDMI1, HDMI2가 있습니다).
- 모니터 화면이 출력되지 않는 경우, 로봇암에 연결된 케이블이 제대로 연결된 상태인지 확인해주세요(케이블이 로봇암에 눌려 제대로 연결되지 않은 상태일 수 있습니다).

[##_Image|kage@bCSKKk/dJMb99MkQI2/AAAAAAAAAAAAAAAAAAAAAOpzVDpg1RDQ291UaLjeNRv3jIRnWaN66WQF-tTdlBp_/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=P0hozH%2Fz7Ao386Q8V0Zyx1JFGUA%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 연결된 사진입니다.

[##_Image|kage@bqjftI/dJMcafy4EPa/AAAAAAAAAAAAAAAAAAAAAN-_EASh3ZHTdYj-dzZAqMw9a2-QQgSkJGJfhpf7K2vR/img.png|alignCenter|width="100%"|_##]
- 로봇암 전원이 켜져 있고 모니터 케이블이 모니터에 연결됐을 경우, 잠깐의 로딩 후 다음 바탕화면이 모니터에 출력됩니다.

### 4. 플랫폼, 볼트, 드라이버
[##_Image|kage@kX4hS/dJMcahDBvXe/AAAAAAAAAAAAAAAAAAAAAG_aysAbBkVRMl76G43VXrUhZ1e7oNcw-vv0bluo5MGm/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=tydt0ZPVL38B5OOoYl%2BiIwUVTM0%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 다음과 같은 구성품이 포함됩니다.

#### 4-1. 그리퍼 연결 플랫폼
[##_Image|kage@A6W9J/dJMcacPQ8SV/AAAAAAAAAAAAAAAAAAAAAOkSh5dvIeQmcX3BfegaDIXJXfV0RdYFfWtDEbwZzpOR/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=X9741rNEVnyVY6idWYyBYKlSILY%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 가운데 판에 구멍이 3개/4개인 플랫폼이 각각 존재합니다. 이 중 구멍이 3개인 플랫폼을 사용합니다.

[##_Image|kage@9vDDj/dJMcaaYNcGZ/AAAAAAAAAAAAAAAAAAAAAFEafwyJjwL2odNSPBsMYNlEsxHhr8TMNy5sttqO5lL5/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=11BRYm7zPZc7Te0v7vNt5%2Fx%2Bvvo%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 로봇암의 그리퍼 연결부에 있는 4개의 구멍 중 3개에 볼트를 조여 조립합니다.
- 구조상 그리퍼와 로봇암과의 수평이 맞지 않으며(영점 기준에서), 보정이 필요합니다.

#### 4-2. 큰 볼트
[##_Image|kage@ci66nv/dJMcagraWtJ/AAAAAAAAAAAAAAAAAAAAAGh1i3E4j3N7tA_6-1lRKdOkpy_zCqQIUYFiuCkeO4SH/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=5R56VFTdV1KiqG8FzZrABc7U4lM%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 플랫폼의 큰 구멍과 로봇암의 그리퍼 연결부의 큰 구멍 사이에 넣어 조립합니다.

#### 4-3. 작은 볼트
[##_Image|kage@cZPccV/dJMcaduoGTN/AAAAAAAAAAAAAAAAAAAAALSe4iaXjMc8bhPeCmKvcDKxOqdf_To94ksvTuzZCTMs/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=rYBS9sqVH%2Bzht4cx3ZpfQ55z3r0%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 플랫폼의 작은 구멍과 그리퍼의 작은 구멍 사이에 넣어 조립합니다.

[##_Image|kage@ccXzR4/dJMcajg5RR4/AAAAAAAAAAAAAAAAAAAAAFxJ3LkqNQ8-KHMUpF9UIjLskEJXUp4G6fM-FZBW_c0P/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=UR8ujqToyAjq9H8OGbZN%2BI2Z8UU%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 플랫폼과 그리퍼 사이의 조립 방식은 다음과 같습니다.

#### 4-4. 육각렌치
[##_Image|kage@KkOME/dJMcaaEwwDm/AAAAAAAAAAAAAAAAAAAAAKlS2AgwTXoVFBZurzxgoJdBHQR5qOL4KCJyrGFYIiXA/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=uVknsaWhb%2FZQYkbQ22BZS3KIpAI%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 가장 큰 렌치가 큰 볼트용. 중간 크기 렌치가 작은 볼트용 입니다.

#### 4-5. 일자드라이버
[##_Image|kage@cj5xzW/dJMcad2e1XO/AAAAAAAAAAAAAAAAAAAAAGuNF3I71C2tdKw7TcwF1MuMAJ5rVfrAyjfN_PBQCl0e/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=3MhyAohd%2Bh8N3djlt%2BhFi7GPh8M%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- '1. 비상 정지 버튼' 단계에서 연결 케이블의 일자 나사를 조일 때 사용합니다.

### 5. 그리퍼
[##_Image|kage@DKe4L/dJMcajuEcfh/AAAAAAAAAAAAAAAAAAAAAIhDxnTAs8Y-ykKC9c7fLa1z7NKGGN57EbExj87t2ets/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=zTTY4iLtQfKt5AOxXl3EPbI9Ljk%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 앞
- 그리퍼 연결 케이블 포트가 있는 방향입니다.

[##_Image|kage@bbxGm8/dJMcaiCvL3U/AAAAAAAAAAAAAAAAAAAAANmR84qC_g1Qk8oGVbP6cafZBNyE_ObxnnT_KM4zGVgq/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=JsfIoNevlOpMpRIKNVcZsAJgve0%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 뒤1

[##_Image|kage@b3iang/dJMcaaxKmF2/AAAAAAAAAAAAAAAAAAAAAIG4sCSC4Jbq1KkmVmWffghEuGlrStW7hvJH9fBHj-x3/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=mLGEyz8GfmLD0OVcMM0BKyP%2FNxM%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 뒤2

### 6. 그리퍼 연결 케이블
[##_Image|kage@bxrAmc/dJMb99MkQR2/AAAAAAAAAAAAAAAAAAAAAG7b_KwPcu-thQC2Qsc5A5E28vvefatsIROmqVgOx_Jn/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=92NLsD4xIWJRMYOR0sKSw1Swgok%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- 그리퍼와 로봇암의 ATOM을 연결하는 케이블입니다.

[##_Image|kage@dDVzvo/dJMb99MkQSe/AAAAAAAAAAAAAAAAAAAAAJshFn_W1KKt-8bxgaxJUPq-u8dTlUzcQE6BY2vbmQVG/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=3jpN7ZjQZ1fVa40OUduh6sGsy%2BQ%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- ATOM에서 그리퍼 연결 케이블을 연결하는 포트입니다.

[##_Image|kage@B6kfr/dJMcafMBCEZ/AAAAAAAAAAAAAAAAAAAAAC9-uDVxtOhXnlAr82-l1_4JYjTNXNTbPgUOCMSbvFzu/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=lLcci6NItLxI%2BFObafF9FD4vxDk%3D|CDM|1.3|{"originWidth":4032,"originHeight":3024,"style":"alignCenter"}_##]
- 그리퍼 조립 완료된 사진입니다.

### 7. 펌웨어 업데이트용 케이블
[##_Image|kage@tIU5V/dJMb99MkQSn/AAAAAAAAAAAAAAAAAAAAAKGQYKEz8S3qrs89ozjlqyZZmMuLmMZM746tD79Ozltm/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=%2FrWU9U5LebE068Ttu5FTMSmrGdQ%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- base와 ATOM의 펌웨어를 업데이트할 때 사용하는 케이블입니다.
- USB는 USB 포트에, c타입은 base/ATOM의 c타입 포트에 연결합니다.
- 만약 길이가 짧다면, 길이가 긴 데이터 전송용 USB-C 케이블로 대체 가능합니다.

[##_Image|kage@bRBfQF/dJMcaaYNc0b/AAAAAAAAAAAAAAAAAAAAAFn0yBIME-co2v8CT3-Hz0Tovg1c_ldKKblnIL3wC5-Y/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=i68ToDEoe4ifopJvNsrAlqPWjD4%3D|CDM|1.3|{"originWidth":3024,"originHeight":4032,"style":"alignCenter"}_##]
- ATOM에 연결하는 c타입 포트 위치입니다(**주의**: 케이블 연결 과정에서 로봇암에 과도한 힘을 주지 마세요. 제품이 파손될 수 있습니다).
- base에 연결하는 c타입 포트는 '3. 모니터 케이블' 단계의 포트 사진에서 혼자 있는 c타입 포트 위치와 같습니다.

# 기본 제공 앱(MyStudio, MyBlockly) 사용법
## MyStudio 사용법
- ElephantRobotics사 제품들의 펌웨어 업데이트를 돕는 앱입니다.
- 이미 MyCobot 320 pi 내장 PC에 앱이 설치돼 있으므로 별도의 다운로드는 필요 없습니다.

[##_Image|kage@ctVJwy/dJMcacPRY72/AAAAAAAAAAAAAAAAAAAAABHknznAS0wYGYsurToPlGfjH79K0w77FzqxsWU1s0-v/img.png|alignCenter|width="100%"|_##]
- 다음 아이콘을 클릭하여 MyStudio 앱을 실행합니다.

[##_Image|kage@b0OIts/dJMcaflwC6b/AAAAAAAAAAAAAAAAAAAAAAT0eYYbnL2BpMI7PB-krppbuO5mwUrbExYGme3EPppL/img.png|alignCenter|width="100%"|_##]
- 시작 화면입니다.
- ATOM과 base 중 ATOM 먼저 펌웨어를 플래시 합니다.

### ATOM 펌웨어 업데이트
[##_Image|kage@1Jzoh/dJMcagdF5Rz/AAAAAAAAAAAAAAAAAAAAAGR8cNPd4GxBqBUoIhO1AhvtPYndITJZBoZFwds7E2wn/img.jpg|alignCenter|width="100%"|_##]
- PC와 ATOM을 연결합니다.

[##_Image|kage@NYqp1/dJMb99ZWbBZ/AAAAAAAAAAAAAAAAAAAAAImF8znNMnr9Yl9cxJwDJvLasZDNueeecNvV9l9oSK1K/img.png|alignCenter|width="100%"|_##]
- 제품에 맞는 옵션으로 설정 후, 로그인합니다.
- USB Port의 경우, ATOM에 케이블을 연결하면 자동으로 옵션이 'M5 Stack-atom'으로 변경됩니다.

[##_Image|kage@rQNMp/dJMcajg6JlR/AAAAAAAAAAAAAAAAAAAAAL_CC0u0pAQ-U_B9kOyrcsug07J0QhzBdSqfDGgLyEIW/img.png|alignCenter|width="100%"|_##]
- 로그인 화면입니다.
- 왼쪽 설정 중 'Basic'으로 이동합니다.

[##_Image|kage@5yeGl/dJMcabKdLNb/AAAAAAAAAAAAAAAAAAAAAHYEA5V4wxESN1UrtYFMnXPrCmueAi3fYq89WLeEAjKj/img.png|alignCenter|width="100%"|_##]
- 존재하는 펌웨어 버전 중 가장 최신 버전으로 업데이트 합니다(2026년 3월 기준으로 가장 최신 버전은 v5.2 입니다).
- 처음 플래시하는 경우, Flash 버튼이 아닌 Download 버전이 있을 것입니다. 다운로드가 완료되면 Flash 버튼으로 바뀝니다.

[##_Image|kage@b38zD1/dJMcajuE4wH/AAAAAAAAAAAAAAAAAAAAAA555B1lev53tPgucfEmL6F6hsC5QGUPHoTw9TWg1LUJ/img.png|alignCenter|width="100%"|_##]
- ATOM 펌웨어 업데이트 완료
- 완료됐다는 메세지가 나올 때까지 기다리시면 됩니다.

### Base 펌웨어 업데이트
[##_Image|kage@5yjec/dJMcajalrqg/AAAAAAAAAAAAAAAAAAAAAP5UScZlVeysDgCDwTlTAD_7ryv-Q0tnUEE6Cv-JKIOr/img.jpg|alignCenter|width="100%"|_##]
- PC와 Base를 연결합니다.

[##_Image|kage@5p1jf/dJMcagkpMyu/AAAAAAAAAAAAAAAAAAAAAJ16n3uBBgwLI6ioseCs6PHCZGeZqSIIU9u_i91InIC2/img.png|alignCenter|width="100%"|_##]
- 제품에 맞는 옵션으로 설정 후, 로그인합니다.
- USB Port의 경우, ATOM에 케이블을 연결하면 자동으로 옵션이 'M5 Stack-basic'으로 변경됩니다.
- Base의 경우, basic으로 표기됩니다.

[##_Image|kage@QkkdI/dJMcacbgjdn/AAAAAAAAAAAAAAAAAAAAAD0jI9tGA_DMpMMvl1iN1nX76RsrqPMvGCC2Sev4IMHK/img.png|alignCenter|width="100%"|_##]
- 로그인 화면입니다.
- 왼쪽 설정 중 'Basic'으로 이동합니다.

[##_Image|kage@uENA4/dJMcadBaiYs/AAAAAAAAAAAAAAAAAAAAAAzF-ujl7qZw3lhd2ZDnNrJstOc08IBFy-qXV3NmfT5J/img.png|alignCenter|width="100%"|_##]
- 존재하는 펌웨어 버전 중 가장 최신 버전으로 업데이트 합니다(2026년 3월 기준으로 가장 최신 버전은 v1.5 입니다).
- 처음 플래시하는 경우, Flash 버튼이 아닌 Download 버전이 있을 것입니다. 다운로드가 완료되면 Flash 버튼으로 바뀝니다.

[##_Image|kage@WWlis/dJMcajuE4D4/AAAAAAAAAAAAAAAAAAAAAAp_CLBIIH6uTZ6xegdrWU13NJshy9-Pem4iNdF6ypPx/img.png|alignCenter|width="100%"|_##]
- Base 펌웨어 업데이트 완료
- 업데이트 중간에 시리얼 포트가 tty/ACM0에서 tty/AMA0으로 변경되었다는 메세지가 뜰 것입니다.
  (tty/ACM0, tty/AMA0 등은 라즈베리파이 계열에서 시리얼 포트로 사용되는 장치 파일의 이름을 말합니다.) 
- 완료됐다는 메세지가 나올 때까지 기다리시면 됩니다. Base의 경우, 업데이트가 완료된 후 재부팅을 해야 합니다.

## MyBlockly 사용법
- 간단한 블록코딩 또는 관절 별 각도 조정을 통해 제품을 제어할 수 있도록 하는 앱입니다.
- 이미 MyCobot 320 pi 내장 PC에 앱이 설치돼 있으므로 별도의 다운로드는 필요 없습니다.
- **주의: 필자가 제품 제어에서 사용했던 기능만 설명합니다.**

### 옵션 세팅
[##_Image|kage@CZZKs/dJMcacI7zSc/AAAAAAAAAAAAAAAAAAAAAEl3M22EyZSNoaHewbcct8z4bnRQryr9DvFiS8Mc-ol2/img.png|alignCenter|width="100%"|_##]
- 다음 아이콘을 클릭하여 MyBlockly 앱을 실행합니다.

[##_Image|kage@tHiqE/dJMcai3yMop/AAAAAAAAAAAAAAAAAAAAAGxcHbW-7v_Sj5qh7f_3jJNMhaU9uzIZrbGI93zPjxNG/img.png|alignCenter|width="100%"|_##]
- MyBlockly 메인 화면입니다.
- 왼쪽은 블록 코드들, 가운데는 블록 코드를 작성하는 공간입니다.

[##_Image|kage@bgfWY0/dJMcaiWOmoD/AAAAAAAAAAAAAAAAAAAAACc-oOAs3foJ-mLPdbnKBnGJUy-nVYubTYks10P4uBug/img.png|alignCenter|width="100%"|_##]
- init 블록의 설정을 다음과 같이 세팅합니다.
- Baud(Baudrate): 시리얼 통신에서 1초당 몇 개의 신호가 전달되는지를 나타내는 수치입니다.

### 로봇 제어 - 블록코딩
[##_Image|kage@cGTAfk/dJMcadnFv2G/AAAAAAAAAAAAAAAAAAAAAJqgrddssP-36wf2vpTX8_Ty9FP1UCUER8OQ8R05kqGa/img.png|alignCenter|width="100%"|_##]
- 간단한 테스트 코드를 작성하여 로봇암 제어를 테스트할 수 있습니다.
  (참고: set joint 블록을 한번에 여러 개 사용할 때, 블록 사이사이에 Sleep 블록을 넣어주어야 로봇암이 제대로 가동됩니다.)
- 우측 상단의 초록색 Run 버튼을 클릭하여 작성한 코드를 실행할 수 있습니다.

[##_File|kage@NrrYw/dJMcajalrR7/AAAAAAAAAAAAAAAAAAAAALFJC9v0V6AHxxJxdtjSOSz3Y5ly03voNhS7q1P4uSQh/tfile.mp4|filename="테스트코드 작동 영상.mp4" size="5.5 MB"|_##]
- 테스트 코드 작동 영상입니다.

### 로봇 제어 - 관절 각도 조정
[##_Image|kage@cUbMk6/dJMcaa5AAw4/AAAAAAAAAAAAAAAAAAAAAGyfRixYyux8Lv2lirfi5mHqiQgxwienv3sKgpDbFk-B/img.png|alignCenter|width="100%"|_##]
- 우측 상단의 빨간색 버튼을 클릭합니다.

[##_Image|kage@bxsAh0/dJMb99S8ksl/AAAAAAAAAAAAAAAAAAAAADv1sM4qn4Hu1S3iZOBGwTTZ4SKhwLt9Fry0GQZ6VKjs/img.png|alignCenter|width="100%"|_##]
- Close 되어있는 버튼을 클릭하여 Open으로 전환할 수 있습니다, Open/Close 모드는 마음대로 변경 가능합니다.
- Close 모드일때는 블록 코드를 실행하여 로봇암을 제어할 수 있지만, 로봇암의 관절 세부 각도 조정 및 조회는 불가능합니다. 
- Open 모드일때는 관절 세부 각도를 조정 및 조회할 수 있지만, 블록 코드를 실행할 수 없습니다.

[##_Image|kage@b5mdFe/dJMcadBajp8/AAAAAAAAAAAAAAAAAAAAANUrPegzvQlco-4SC7LITwQ-h2S9E5giXRAtNrdSjtrj/img.png|alignCenter|width="100%"|_##]
- 로봇암의 관절별 각도를 세부 조정할 수 있는 인터페이스입니다.
- 로봇암의 맨 밑 관절부터 맨 위 관절까지, 차례대로 J1~6입니다.

### 기타 기능
[##_Image|kage@c7HSbC/dJMcahp7buw/AAAAAAAAAAAAAAAAAAAAAHnxVYa3EP2F_kSAUtmiJf97AEzGDfp1nBut4pAbIKXw/img.png|alignCenter|width="100%"|_##]
- 우측 상단에 있는 파란색 버튼의 기능에 대해 설명합니다.

1. Save
- 작성한 블록코드를 저장할 수 있습니다.
- 블록코드 파일은 json 형태로 저장됩니다.

2. Load
- 저장해놓은 블록코드를 불러올 수 있습니다.
- init 블록에 세팅됐었던 설정까지 불러와지진 않으므로 init 블록은 MyBlockly 앱을 실행할 때마다 설정을 세팅해줘야 합니다.

3. Settings
- 언어 설정이 가능합니다(중국어, 영어만 있습니다).
- 라이트모드/다크모드 설정이 가능합니다.
- MyBlockly와 pymycobot의 버전을 확인할 수 있습니다.

# 우분투 기본 설정(나중에 오류 모음으로 이름 바꾸고 순서 맨밑으로 내릴수도 있음)
## 시스템 업데이트
```
sudo apt update
```
- 해당 명령어를 입력하려 하면 오류가 발생하면서 업데이트가 되지 않을 것입니다.
- ROS 공개 키가 만료되었기 때문에 업데이트가 차단되어 발생하는 오류입니다.
- 최신 버전의 공개 키를 다시 다운로드하여 keyring 파일을 재설정하는 것으로 문제를 해결할 수 있습니다.

### 해결
1. Universe 저장소 활성화
```
sudo apt install software-properties-common 
sudo add-apt-repository universe
```

2. curl 설치
```
sudo apt install curl -y
```
- curl: 인터넷에서 파일을 다운로드할 수 있게 해주는 툴

3. ROS 공개 키 다시 다운로드
```
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

4. ROS 저장소 항목 재등록
```
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

5.  다시 업데이트 시도
```
sudo apt update 
sudo apt upgrade
```
- 정상적으로 해결된 경우, 문제 없이 업데이트 됩니다.

## 비밀번호 변경
- 기본적으로, ElephantRobotics사에서 공개하고 있는 초기 비밀번호는 Elephant 혹은 elephant입니다.
- 만약 해당 비밀번호를 입력해도 틀리는 경우(필자도 같은 현상을 겪었습니다), root 권한을 통해 비밀번호를 변경할 수 있습니다.

### 해결
- 다음 명령어를 통해 root 권한에 접속합니다:
```
sudo su
```

- root 계정의 비밀번호를 변경합니다:
```
passwd
# 이후 변경할 비밀번호 입력/재입력
```

- root/터미널 접속을 종료하려면:
```
exit
```

# ROS2 버전 변경(Galactic -> Foxy)
- MyCobot 320 pi 모델의 내장 PC에 기본적으로 설치된 ROS2 버전은 Galactic 버전입니다.
- Galactic 버전은 실험용 버전이므로, ROS2 학습 및 연구에는 부적절하다고 판단하였습니다.
- 따라서 같은 우분투 20.04버전 상에서 호환 가능한 Foxy버전으로 변경합니다.

1. 현재 ROS 버전 확인
```
printenv | grep ROS which ros2
```

2. 기존 워크스페이스 백업
```
cp -r ~/mycobot_ws ~/mycobot_ws_backup
```
- 기존 버전에서의 워크스페이스가 충돌을 일으킬 수 있으므로 미리 백업합니다.

3. 기존 버전 패키지 제거
```
sudo apt remove '~nros-galactic-*' 
sudo apt autoremove
```

4. 남아있을 수 있는 설정 제거
```
nano ~/.bashrc
```

- .bashrc 파일로 이동 후, 다음 코드가 있으면 삭제합니다:
```
source /opt/ros/galactic/setup.bash 
source ~/mycobot_ws/install/setup.bash 
# 기존 버전의 설정 파일들을 적용하는 명령어들
```
- 없으면 그대로 진행합니다.

- 현재 설정을 적용:
```
source ~/.bashrc
```

5. 새로운 버전에서 사용할 리포지토리 새로 생성
```
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository universe
```
- universe: ROS 의존성 패키지 설치에 필요한 리포지토리 이름입니다.

6. 새로운 리포지토리에 공개 키를 다시 등록
```
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```
- 위에서 했던 공개 키 등록은 오류 해결을 위한 등록이었습니다.
- 현재는 버전 변경을 위해 리포지토리를 새로 생성했으므로, 공개 키를 다시 등록해줍니다.

7. ROS2 리포지토리 추가
```
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

8. Foxy 버전 설치
```
sudo apt update 
sudo apt install ros-foxy-desktop python3-argcomplete -y
```

9. 환경변수 등록
```
echo "source /opt/ros/foxy/setup.bash" >> ~/.bashrc 
source ~/.bashrc
```
- 현재 버전의 .bashrc 파일 안에, foxy 버전의 셋업 파일을 적용해주는 명령어를 추가합니다.
- 이후 `source ~/.bashrc` 명령어를 실행할 때마다, .bashrc 파일 안에 있는 명령어가 자동으로 같이 실행됩니다.
  (**참고: .bashrc 파일은 로봇암을 켤 때마다 터미널에서 항상 설정을 source 해줘야 합니다.**)

10. 변경 확인
```
printenv | grep ROS 
ros2 doctor --report 
ros2 pkg list | head
```  
- `ROS_DISTRO=foxy` 이면 정상입니다.
- `ros2 doctor` 명령어로 전체 환경 점검을 할 수 있습니다.

11. 기존 워크스페이스를 현재 버전으로 다시 빌드
```
cd ~/mycobot_ws
source /opt/ros/foxy/setup.bash
colcon build
```    

- 빌드 후 설정 다시 적용:
```
source ~/mycobot_ws/install/setup.bash
```

- '9. 환경변수 등록' 단계처럼, .bashrc 파일에 명령어를 추가하여 
`source ~/.bashrc` 명령어만 입력하여도 모든 설정이 한번에 적용되도록 할 수도 있습니다:
```
echo "source ~/mycobot_ws/install/setup.bash" >> ~/.bashrc
```