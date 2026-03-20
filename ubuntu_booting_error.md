우분투 설치 후 재부팅하는 과정에서 로딩이 멈추는 현상이 발생했습니다.  
계속 재부팅을 시도해도 동일한 문제가 발생하여, 이에 대한 해결 방법을 정리했습니다.  
  

문제 원인의 대부분은 GPU와 그래픽 드라이버 사이의 충돌 때문입니다.  
문제 해결을 위해 먼저 그래픽 드라이버 없이 PC를 부팅한 다음, GPU와 호환되는 그래픽 드라이버를 재설치하여 문제를 해결했습니다.

# 드라이버 없이 부팅(Dell 데스크탑)
## 1. 컴퓨터 부팅 후, Dell 로고 보이자마자 Esc 입력
- 우분투 로고 아닙니다. PC 켜자마자 처음 보이는 로딩화면이 Dell 로딩화면입니다.

## 2. 이후 Dell 로고 및 파란 바 로딩 끝나자 마자 Esc 한번 더 입력
**주의: Esc를 반복적으로 입력하지 마세요. Grub 창에서 벗어나 다른 창으로 이동할 수 있습니다. 위에 나온대로만 하면 됩니다.**
[##_Image|kage@dAQ0Av/dJMcaf6Xic0/AAAAAAAAAAAAAAAAAAAAAHhcdQZXCasMr3h31UY9RMSEDALloVcrgE1HqPqr8tPM/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=Zz6WkwLYGRK%2Ff5RUbh6Ay1UwoWU%3D|CDM|1.3|{"originWidth":4032,"originHeight":3024,"style":"alignCenter","width":null}_##]
- 다음과 같은 창이 뜰 것입니다.

## 3. 'Ubuntu' 탭에서 'e' 키를 입력
- 'Ubuntu' 탭은 Grub 진입하자마자 선택되어있는 상태입니다.  
[##_Image|kage@cvhdvS/dJMb99Mp4K6/AAAAAAAAAAAAAAAAAAAAAF2m9uf7RKQUVpX3ReE1t5McvpQuLfJdS_MxXkv805j3/img.jpg?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1774969199&amp;allow_ip=&amp;allow_referer=&amp;signature=4S1Lv2v18pcuG7ZOR7LJUQ2298o%3D|CDM|1.3|{"originWidth":4032,"originHeight":3024,"style":"alignCenter","width":null}_##]
- 진입 시 다음과 같은 창이 뜹니다.

## 4. 목록 중 'linux /boot/vmlinuz...' 와 같이 되어있는 코드를 확인
- 찾았다면 해당 코드의 뒷부분 중:
```
ro  quiet splash 
```
혹은:
```
ro  quiet splash $vt_handoff
```
-   이와 같은 부분이 있을 것입니다.


-   해당 부분에서 'quiet splash' 바로 뒤에 'nomodeset' 이라는 문구를 추가하세요:
```
ro quiet splash nomodeset
```
혹은
```
ro quiet splash nomodeset $vt_handoff
```
- 다음과 같이 변경되면 됩니다.


- ctrl + x 또는 F10을 누르세요. 자동으로 변경사항이 저장된 후 재부팅됩니다.
- 정상적이라면 우분투 화면이 출력될 것입니다.

# GPU와 호환되는 그래픽 드라이버 재설치
## 1. sudo apt update를 위한 기본 설정 변경
- 우분투가 처음 설치된 경우, 시간 설정이 제대로 되어 있지 않을 확률이 높습니다.
- 시간 설정이 이상할 경우 우분투 업데이트가 되지 않으므로 현지 시간으로 시간을 설정 후 업데이트 합니다.


- 터미널에서 다음 명령어 입력:
```
timedatectl list-timezones | grep Seoul
```
- 입력 결과로 'Asia/Seoul'이 나올 것입니다.


- 타임존을 'Asia/Seoul'로 변경:
```
sudo timedatectl set-timezone Asia/Seoul
``` 
- 이후 바탕화면 위쪽의 시간을 보고 설정이 제대로 적용됐는지 확인합니다.


- 제대로 적용됐다면, 우분투를 업데이트합니다:
```
sudo apt update
```

## 2. 터미널에서 현재 GPU 버전과 호환되는 드라이버 버전 확인
- GPU 버전 조회:
```
sudo update-pciids lspci | grep -i vga
```
- 이 명령어를 실행하면 RTX 4070Ti, 3070 Ti 등의 그래픽카드 버전이 나올 것입니다.


- 이후 해당 버전을 인터넷에 검색하여 맞는 드라이버 버전을 찾을 수도 있고, 다음 명령어를 실행해서 recommended되는 드라이버를 설치할 수도 있습니다:
```
ubuntu-drivers devices
```
- 여러 드라이버 버전 리스트 중, 맨 끝에 'recommended'라고 적혀 있는 드라이버를 찾아 설치합니다.


- 해당 드라이버 설치:
```
sudo apt install [드라이버 이름(ex: nvidia-driver-580 등의 이름)]
```


- 설치 완료 후, 재부팅하여 로딩 멈춤 오류 없는지 확인:
```
sudo reboot
```

## 기타
- 만약 드라이버 버전을 변경하고 싶은 경우, 기존에 설치한 드라이버를 삭제하고 다른 버전 드라이버를 다시 설치할 수 있습니다.
**주의: 기존에 남아있던 드라이버 관련 파일이 제대로 삭제되지 않고 남을 경우, 새로 설치할 드라이버와 충돌할 가능성이 있습니다.**

- 문제를 사전에 방지하기 위해, 드라이버 관련 파일을 전부 삭제 후 재설치합니다.


- 기존 드라이버 삭제:
```
sudo apt-get remove --purge '^nvidia-.*'
```
- 삭제 후, 남아있을 수 있는 잔여 파일까지 제거


- 잔여 드라이버 파일 조회:
```
sudo dpkg -l | grep nvidia
```


- 잔여 드라이버 파일 삭제:
```
sudo purge [위 코드에서 나온 이름]
```


- 잔여 파일 자동 삭제:
```
sudo apt-get autoremove
```


이 글에 나오지 않은 오류 또는 잘못된 내용이 있을 시 말씀주시면 감사하겠습니다.  
감사합니다.