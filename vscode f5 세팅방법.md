## VSCODE에서 F5로 빌드, 실행, 디버그하는 기능 세팅하기
- c_cpp_properties.json, launch.json, task.json 파일을 .vscode 폴더 안에 생성해야 함

### 1. c_cpp_properties.json
1. F1누르고 검색창에 'Edit Configurations (JSON)' 검색
2. .vscode 폴더에 생성된 c_cpp_properties.json파일에 다음 내용 복붙
```
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:\\msys64\\ucrt64\\bin\\g++.exe",
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```

### 2. launch.json
1. 왼쪽 위 툴바 중 한국어면 '실행', 영어면 'Run' 선택(오른쪽 점 3개 누르면 옵션 더 있음)
2. 한국어면 '구성 추가', 영어면 'Add Configurations'선택
3. .vscode 폴더 안에 생성된 launch.json파일에 다음 내용 복붙
```
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++.exe - 활성 파일 빌드 및 디버그",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\msys64\\ucrt64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "gdb에 자동 서식 지정 사용",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++.exe 활성 파일 빌드"
        }
    ]
}
```

### 3. task.json
1. F1누르고 검색창에 Tasks: Configure Task 입력
2. 구성할 작업 선택에서 한국어면 '템플릿에서 json파일 만들기', 영어면 'Create tasks.json file from template' 선택
3. 옵션에서 'Others' 선택
4. .vscode 폴더 안에 생성된 task.json파일에 다음 내용 복붙
```
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 활성 파일 빌드",
            "command": "C:\\msys64\\ucrt64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "디버거에서 생성된 작업입니다."
        }
    ],
    "version": "2.0.0"
}
```