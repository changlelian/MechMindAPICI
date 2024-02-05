pipeline {
    // agent any
    agent {
        label 'mm_amd64'
    }
    
    // triggers {
    //     cron('H 1,7,23 * * *')
    // }

    environment {

        CAM_IP = '192.168.20.139'   // camera
        LNX_IP = '192.168.20.13'   // profiler
        // OTHER_IP = '192.168.20.159'    // profiler virtual
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

        stage('Update mecheye device firmware') {
            steps {
                script {
                    sh 'sudo dpkg -P mecheyeapi'
                    sh 'sudo rm -rf /opt/mech-mind'
                    sh "sudo dpkg -i /var/lib/jenkins/workspace/${DEB_PACKAGE}"
                    sh "sudo mkdir -p /var/lib/jenkins/workspace/${WORKSPACE}/UpgradeFirmwareLinux/build"
                    sh "sudo cmake -S /var/lib/jenkins/workspace/${WORKSPACE}/UpgradeFirmwareLinux/ -B /var/lib/jenkins/workspace/${WORKSPACE}/UpgradeFirmwareLinux/build"
                    sh "sudo make -C /var/lib/jenkins/workspace/${WORKSPACE}/UpgradeFirmwareLinux/build"
                    sh "/var/lib/jenkins/workspace/${WORKSPACE}/UpgradeFirmwareLinux/build/UpgradeFirmwareUbuntu ${CAM_IP} ${LNX_IP}"
                }
            }
        }

        stage('Parallel build Cpp Stages') {
            parallel {
                stage('Build cpp amd64 samples') {
                    steps {
                        script {
                            dockerRunAndExec('APISamplesBuildTest', 'mecheyeenvimage', [
                                "sh /home/${WORKSPACE}/MechEyeCppBuildAmd/ubuntu_build.sh"
                            ])
                        }
                    }
                }

                stage('Build cpp amd64 test case') {
                    steps {
                        script {
                            dockerRunAndExec('APITestCaseBuildTest', 'mecheyeenvimage', [
                                    "dpkg -i /home/${DEB_PACKAGE}",
                                    "mkdir -p /home/${WORKSPACE}/MechEyeCppAutoTestProject/src/build",
                                    "cmake -S /home/${WORKSPACE}/MechEyeCppAutoTestProject/src -B /home/${WORKSPACE}/MechEyeCppAutoTestProject/src/build",
                                    "make -C /home/${WORKSPACE}/MechEyeCppAutoTestProject/src/build"
                            ])
                        }
                    }
                }
            }
        }

        stage('Parallel Execute Cpp Stages') {
            parallel {
                stage('Test cpp camera interface in linux') {
                    steps {
                        catchError(buildResult: 'SUCCESS', stageResult: 'FAILURE') {
                            script {
                                dockerRunAndExec('APITestCameraInterface', 'mecheyeenvimage', [
                                    "dpkg -i /home/${DEB_PACKAGE}",
                                    "/home/${WORKSPACE}/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Camera* --ip=${CAM_IP}"
                                ])
                            }
                        }
                    }
                }


                stage('Test cpp profiler interface in linux') {
                    steps {
                        catchError(buildResult: 'SUCCESS', stageResult: 'FAILURE') {
                            script {      
                                dockerRunAndExec('APITestProfilerInterface', 'mecheyeenvimage', [
                                    "dpkg -i /home/${DEB_PACKAGE}",
                                    "/home/${WORKSPACE}/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Profiler* --ip=${LNX_IP}"
                                ])
                            }
                        }
                    }
                }
                

                stage('Test cpp virtual profiler interface in linux') {
                    steps {
                        catchError(buildResult: 'SUCCESS', stageResult: 'FAILURE') {
                            script {
                                dockerRunAndExec('APITestVirtualProfilerInterface', 'mecheyeenvimage', [
                                    "dpkg -i /home/${DEB_PACKAGE}",
                                    "/home/${WORKSPACE}/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*ProVirtual* --ip=127.0.0.1"
                                ])
                            }
                        }
                    }
                }
            }
        }

        stage('Parallel Execute Python Stages') {
            parallel {
                stage('Test python camera interface in linux') {
                    steps {
                        script {
                            dockerRunAndExec('APITestPythonCameraInterface', 'mecheyeenvimage', [
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

