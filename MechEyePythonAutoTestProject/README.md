

#  MechEyeAPI自动化测试工程(python2.2.0)

***


## 目录
* [功能介绍](#功能介绍)
* [使用须知](#使用须知)
* [使用方法](#使用方法)
* [适用相机](#适用相机)
  * [Camera](#Camera)
  * [Profiler](#Profiler)
* [目录结构](#目录结构及描述)
  * [目录结构](#目录结构)
  * [目录描述](#目录描述)
* [测试项](#测试项)
  * [Camera](#Camera)
  * [Profiler](#Profiler)
---


## 功能介绍

>[1]&nbsp; 本测试脚本基于python unittest 框架编写，旨在遍历测试 `220 版本python API` 。
>
>[2]&nbsp; 工程可根据实际情况生成对应的`测试报告`。
>
&nbsp;

---

## 使用须知

1）使用前 **务必** 安装对应平台（Linux/Windows）MechEye-viewer SDK 安装包.

2）使用前 **务必** 安装MechEye-2.2.0 版本MechEyeAPI Python库.
``` python
pip install MechEyeAPI
```

3）使用前请执行如下命令安装 Python 依赖.
``` python
pip install -r requirements.txt
```


4）测试使用的环境为windows10/11, Linux-X64(Ubuntu20) 其他场景未经验证.

---

## 使用方法

> 第一步：安装必须的三方库，可终端执行如下：
``` bash
pip install -r requirements.txt
```

`注意`：

1）windows确保已正确配置环境变量。

2）Linux确保对应的python3版本已安装pip。

3）Linux下通常使用pip3 install xxxxxx



> 第二步： 启动测试脚本，进行测试参数测试，并生成html格式的测试报告

启动命令语法：
``` bash
python [启动文件] [相机IP]
```

示例：

``` bash
python .\main.py 192.168.20.214
```

`注意`： Linux下通常使用python3启动代替python


---

## 适用相机

### Camera

| 相机型号                       | 是否验证 |
|----------------------------|--|
| Mech-Eye Laser L           | √ |
| Mech-Eye LSR L             | √ |
| Mech-Eye Log M             | √ |
| Mech-Eye Deep              | √ |
| Mech-Eye NANO              | √ |
| Mech-Eye PRO M             | √ |
| Mech-Eye PRO XS            | √ |
| Mech-Eye UHP               | √ |
| Mech-Eye Laser L  Enhanced | √ |
| Mech-Eye Pro L Enhanced    | √ |
| Mech-Eye Pro M Enhanced    | √ |
| Mech-Eye Pro S Enhanced    | √ |
| Mech-Eye DEEP              | √ |
| Mech-Eye Log s             | √ |
| Mech-Eye LSR S             | √ |

### Profiler
| 相机型号                       | 是否验证 |
|----------------------------|--|
| Mech-Eye LNX 8080          | √ |
| Mech-Eye LNX 8030          | √ |
| Mech-Eye LNX 8300          | √ |


---

## 目录结构及描述

### 目录结构

```markdown
APITestPy
├─area
│  ├─capture
│  │    ├─test_case_frame_2d.py
│  │    ├─test_case_frame_3d.py	
│  │    ├─test_case_frame_2d_3d.py
│  │    └─__init.py__
│  │
│  ├─parameter
│  │   ├─test_case_2d.py
│  │   ├─test_case_3d.py
│  │   ├─test_case_uhp.py
│  │   ├─test_case_laser.py
│  │   ├─test_case_projector.py
│  │   ├─test_case_point_cloud.py
│  │   └─__init.py__
│  │
│  ├─test_case_message.py
│  ├─test_case_user_sets.py
│  └─test_case_camera_event.py
│
├─profiler
│  ├─capture
│  │    ├─test_case_capture_batch_acquire.py
│  │    ├─test_case_capture_call_back.py
│  │    └─__init.py__
│  │
│  ├─parameter
│  │   ├─test_case_profile_extraction.py
│  │   ├─test_case_profile_processing.py
│  │   ├─test_case_raw_image.py
│  │   ├─test_case_scan.py
│  │   └─__init.py__
│  │
│  ├─test_case_message.py
│  ├─test_case_trigger.py
│  ├─test_case_profiler_user_sets.py
│  └─test_case_profiler_event.py
├─files
├─report
├─config.json
├─common.py
├─base_test_case.py
├─main.py
├─requirements.txt
└─README.md
```
### 目录描述

`camera`: 结构光相机测试用例

`profiler`: 线激光轮廓仪测试用例

`files`: 存储自动化执行过程中生成的中间文件

`report`: 测试报告的存放位置

---
## 6.测试项

### Camera

| 测试项 | 描述                       |
|--|--------------------------|
| Parameter 2d  | 2D 参数所有测试用例              |
| Parameter 3d  | 3D 参数所有测试用例              |
| Parameter uhp  | UHP 相机参数所有测试用例           |
| Parameter laser  | Laser 相机参数所有测试用例         |
| Parameter projector  | projector 参数所有测试用例       |
| Parameter pointcloud  | 点云相关测试用例                 |
| Camera message  | 相机状态/信息/分辨率/温度所有测试用例     |
| Camera usersets  | 参数组管理及加载/保存文件测试用例        |
| Camera event  | 相机事件测试用例                 |
| Frame2d  | 采集2D图及Frame 2D测试用例       |
| Frame3d  | 采集3D图及Frame 3D测试用例       |
| frame2dAnd3D  | 采集2D/3D图及Frame 2D 3D测试用例 |

### Profiler
| 测试项                  | 描述                 |
|----------------------|--------------------|
| Parameter extraction | extraction 参数所有测试用例 |
| Parameter processing | processing 参数所有测试用例 |
| Parameter raw image  | raw 参数所有测试用例       |
| Parameter scan       | scan 参数所有测试用例      |
| Profiler message     | 相机状态/信息/测试用例       |
| Profiler usersets    | 参数组管理及加载/保存文件测试用例  |
| Profiler event       | 相机事件测试用例           |
| Profiler trigger     | 流状态测试用例            |
| Call back capture    | 回调方式取图测试用例         |
| acquire capture      | 轮询方式取图测试用例         |