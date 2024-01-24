pipeline {
    agent any

        environment {

        CAM_IP = '192.168.20.107'   // camera
        LNX_IP = '192.168.20.232'   // profiler
        OTHER_IP = '192.168.20.159'    // profiler virtual
        DEB_PACKAGE = 'Mech-Eye_API_2.3.0_amd64.deb'  // cpp package
        WHEEL_PACKAGE = 'MechEyeAPI-2.3.0-cp38-cp38-manylinux_2_27_x86_64.whl'  // wheel python3.8

        WORKSPACE = 'MMIND_TEST_CI_main'
        REPO_URL = 'https://github.com/changlelian/MechMindAPICI.git'
        PIP_MIRRORS = 'https://pypi.tuna.tsinghua.edu.cn/simple'
    }
    stages {
        stage('Clone test code'){
            steps{
                //sh 'sudo rm -rf /var/lib/jenkins/workspace/MMIND_TEST_CI_main*'
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: '2c5b2149-4914-4b15-bd7a-af703dddf0da', url: 'https://github.com/changlelian/MechMindAPICI.git']])
            }
        }

        // stage('Update mecheye device firmware') {
        //     steps {
        //         script {
        //             sh 'sudo dpkg -P Mecheyeapi'
        //             sh 'sudo dpkg -i /var/lib/jenkins/workspace/${DEB_PACKAGE}'
        //             sh 'sudo mkdir -p /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             sh 'sudo cmake -S /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/ -B /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             sh 'sudo make -C /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             sh '/var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build/UpgradeFirmwareUbuntu ${CAM_IP} ${LNX_IP} ${OTHER_IP}'
        //         }
        //     }
        // }

        // stage('Parallel Execute Cpp Stages') {
        //     parallel {
        //         stage('Build cpp amd64 samples') {
        //             steps {
        //                 script {
        //                     sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APIBuildTest mecheyeenvimage'
        //                     sh 'sudo docker start APIBuildTest'
        //                     sh 'sudo docker exec APIBuildTest sh /home/MMIND_TEST_CI_main/MechEyeCppBuildAmd/ubuntu_build.sh'
        //                 }
        //             }
        //         }

        //         stage('Test cpp camera interface in linux') {
        //             steps {
        //                 script {
        //                     sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestCameraInterface mecheyeenvimage'
        //                     sh 'sudo docker start APITestCameraInterface'
        //                     sh 'sudo docker exec APITestCameraInterface dpkg -i /home/${DebianPackage}'
        //                     sh 'sudo docker exec APITestCameraInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestCameraInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestCameraInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestCameraInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Camera* --ip=${CAM_IP}'
        //                 }
        //             }
        //         }


        //         stage('Test cpp profiler interface in linux') {
        //             steps {
        //                 script {
        //                     sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestProfilerInterface mecheyeenvimage'
        //                     sh 'sudo docker start APITestProfilerInterface'
        //                     sh 'sudo docker exec APITestProfilerInterface dpkg -i /home/${DebianPackage}'
        //                     sh 'sudo docker exec APITestProfilerInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestProfilerInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestProfilerInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestProfilerInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Profiler* --ip=${LNX_IP}'
        //                 }
        //             }
        //         }
                

        //         stage('Test cpp virtual profiler interface in linux') {
        //             steps {
        //                 script {
        //                     sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestVirtualProfilerInterface mecheyeenvimage'
        //                     sh 'sudo docker start APITestVirtualProfilerInterface'
        //                     sh 'sudo docker exec APITestVirtualProfilerInterface dpkg -i /home/${DebianPackage}'
        //                     sh 'sudo docker exec APITestVirtualProfilerInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestVirtualProfilerInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestVirtualProfilerInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
        //                     sh 'sudo docker exec APITestVirtualProfilerInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*ProVirtual* --ip=${IP3}'
        //                 }
        //             }
        //         }
        //     }
        // }

        stage('Parallel Execute Python Stages') {
            parallel {
                stage('Test python camera interface in linux') {
                    steps {
                        script {
                            // sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestPythonCameraInterface mecheyeenvimage'
                            // sh 'sudo docker start APITestPythonCameraInterface'
                            // sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install --upgrade pip -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            
                            // sh 'sudo docker exec APITestPythonCameraInterface dpkg -i /home/${DebianPackage}'
                            // sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install ${WheelPackage} -i https://pypi.tuna.tsinghua.edu.cn/simple'

                            // sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install -r /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            // sh 'sudo docker exec APITestPythonCameraInterface python3 /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/main.py ${CAM_IP}'

                            dockerRunAndExec('APITestPythonProfilerInterface', 'mecheyeenvimage', [
                                    "python3 -m pip install --upgrade pip -i ${PIP_MIRRORS}",
                                    "dpkg -i /home/${DEB_PACKAGE}",
                                    "python3 -m pip install /home/${WHEEL_PACKAGE} -i ${PIP_MIRRORS}",
                                    "python3 -m pip install -r /home/${WORKSPACE}/MechEyePythonAutoTestProject/requirements.txt -i ${PIP_MIRRORS}",
                                    "python3 /home/${WORKSPACE}/MechEyePythonAutoTestProject/main.py ${CAM_IP}"
                                ])
                        }
                    }
                }

                stage('Test python profiler interface in linux') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestPythonProfilerInterface mecheyeenvimage'
                            // sh 'sudo docker start APITestPythonProfilerInterface'
                            // sh 'sudo docker exec APITestPythonProfilerInterface python3 -m pip install --upgrade pip -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            
                            // sh 'sudo docker exec APITestPythonProfilerInterface dpkg -i /home/${DebianPackage}'
                            // sh 'sudo docker exec APITestPythonProfilerInterface python3 -m pip install ${WheelPackage} -i https://pypi.tuna.tsinghua.edu.cn/simple'

                            // sh 'sudo docker exec APITestPythonProfilerInterface python3 -m pip install -r /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            // sh 'sudo docker exec APITestPythonProfilerInterface python3 /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/main.py ${LNX_IP}'
                        
                            dockerRunAndExec('APITestPythonProfilerInterface', 'mecheyeenvimage', [
                                    "python3 -m pip install --upgrade pip -i ${PIP_MIRRORS}",
                                    "dpkg -i /home/${DEB_PACKAGE}",
                                    "python3 -m pip install /home/${WHEEL_PACKAGE} -i ${PIP_MIRRORS}",
                                    "python3 -m pip install -r /home/${WORKSPACE}/MechEyePythonAutoTestProject/requirements.txt -i ${PIP_MIRRORS}",
                                    "python3 /home/${WORKSPACE}/MechEyePythonAutoTestProject/main.py ${LNX_IP}"
                                ])
                        }
                    }
                }

                stage('Test python virtual profiler interface in linux') {
                    steps {
                        script {
                            dockerRunAndExec('APITestPythonVirtualProfilerInterface', 'mecheyeenvimage', [
                                "python3 -m pip install --upgrade pip -i ${PIP_MIRRORS}",
                                "dpkg -i /home/${DEB_PACKAGE}",
                                "python3 -m pip install /home/${WHEEL_PACKAGE} -i ${PIP_MIRRORS}",
                                "python3 -m pip install -r /home/${WORKSPACE}/MechEyePythonAutoTestProject/requirements.txt -i ${PIP_MIRRORS}",
                                "python3 /home/${WORKSPACE}/MechEyePythonAutoTestProject/main.py 127.0.0.1"
                            ])
                        }
                    }
                }
            }
        }


    }

    post {
        always {
            cleanDocker()
            moveReportWorkSpace()
            generateAllureReport()
        }
    }
}



def dockerRunAndExec(containerName, imageName, commands) {
    sh "sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name ${containerName} ${imageName}"
    sh "sudo docker start ${containerName}"
    commands.each { command ->
        sh "sudo docker exec ${containerName} ${command}"
    }
}

def cleanDocker(){
    sh 'sudo docker stop $(sudo docker ps -q) && sudo docker rm -f $(sudo docker ps -aq)'
}

def moveReportWorkSpace(){
    // sh 'sudo rm -rf /var/lib/jenkins/workspace/MMIND_main/allure-results/'
    // 将测试报告文件移动到jenkins默认的工作路径下
    sh 'mkdir -p allure-results && find /var/lib/jenkins/workspace/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/report/ -name "*.json" -print0 | xargs -0 cp -t /var/lib/jenkins/workspace/MMIND_TEST_CI_main/allure-results/'

}

def generateAllureReport(){
        allure([
        includeProperties: false,
        jdk: '',
        properties: [],
        reportBuildPolicy: 'ALWAYS',
        results: [[path: 'allure-results']]
    ])
}

