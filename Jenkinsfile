pipeline {
    agent any

        environment {
        IP1 = '192.168.20.39'   // camera
        IP2 = '192.168.20.8'   // profiler
        IP3 = '192.168.20.147'    // profiler virtual
        DebianPackage = '/home/Mech-Eye_API_2.3.0_amd64.deb'  // cpp package
        WheelPackage = '/home/MechEyeAPI-2.3.0-cp38-cp38-manylinux_2_27_x86_64.whl'  // wheel python3.8
    }
    stages {
        stage('Clone test code'){
            steps{
                sh 'sudo rm -rf MMIND_TEST_CI_main'
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: '2c5b2149-4914-4b15-bd7a-af703dddf0da', url: 'https://github.com/changlelian/MechMindAPICI.git']])
            }
        }

        // stage('Update mecheye device firmware') {
        //     steps {
        //         script {
        //             // sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name FirmwareUpgradeTest mecheyeenvimage'
        //             // sh 'sudo docker start FirmwareUpgradeTest'

        //             // sh 'sudo docker exec FirmwareUpgradeTest dpkg -i ${DebianPackage}'
        //             // sh 'sudo docker exec FirmwareUpgradeTest mkdir -p /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             // sh 'sudo docker exec FirmwareUpgradeTest cmake -S /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/ -B /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             // sh 'sudo docker exec FirmwareUpgradeTest make -C /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             // sh 'sudo docker exec FirmwareUpgradeTest /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build/UpgradeFirmwareUbuntu ${IP1} ${IP2} ${IP3}'
        //             sh 'sudo dpkg -P Mecheyeapi'
        //             sh 'sudo dpkg -i /var/lib/jenkins/workspace/Mech-Eye_API_2.3.0_amd64.deb'
        //             sh 'sudo mkdir -p /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             sh 'sudo cmake -S /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/ -B /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             sh 'sudo make -C /var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
        //             sh '/var/lib/jenkins/workspace/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build/UpgradeFirmwareUbuntu ${IP1} ${IP2} ${IP3}'
        //         }
        //     }
        // }

        stage('Parallel Execute Cpp Stages') {
            parallel {
                stage('Build cpp amd64 samples') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APIBuildTest mecheyeenvimage'
                            sh 'sudo docker start APIBuildTest'
                            sh 'sudo docker exec APIBuildTest sh /home/MMIND_TEST_CI_main/MechEyeCppBuildAmd/ubuntu_build.sh'
                        }
                    }
                }

                // stage('Test cpp camera interface in linux') {
                //     steps {
                //         script {
                //             sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestCameraInterface mecheyeenvimage'
                //             sh 'sudo docker start APITestCameraInterface'
                //             sh 'sudo docker exec APITestCameraInterface dpkg -i /home/Mech-Eye_API_2.3.0_amd64.deb'
                //             sh 'sudo docker exec APITestCameraInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestCameraInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestCameraInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestCameraInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Camera* --ip=${IP1}'
                //         }
                //     }
                // }


                // stage('Test cpp profiler interface in linux') {
                //     steps {
                //         script {
                //             sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestProfilerInterface mecheyeenvimage'
                //             sh 'sudo docker start APITestProfilerInterface'
                //             sh 'sudo docker exec APITestProfilerInterface dpkg -i /home/Mech-Eye_API_2.3.0_amd64.deb'
                //             sh 'sudo docker exec APITestProfilerInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestProfilerInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestProfilerInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestProfilerInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Profiler* --ip=${IP2}'
                //         }
                //     }
                // }
                

                // stage('Test cpp virtual profiler interface in linux') {
                //     steps {
                //         script {
                //             sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestVirtualProfilerInterface mecheyeenvimage'
                //             sh 'sudo docker start APITestVirtualProfilerInterface'
                //             sh 'sudo docker exec APITestVirtualProfilerInterface dpkg -i /home/Mech-Eye_API_2.3.0_amd64.deb'
                //             sh 'sudo docker exec APITestVirtualProfilerInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestVirtualProfilerInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestVirtualProfilerInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                //             sh 'sudo docker exec APITestVirtualProfilerInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*ProVirtual* --ip=${IP3}'
                //         }
                //     }
                // }
            }
        }

        stage('Parallel Execute Python Stages') {
            parallel {
                stage('Test python camera interface in linux') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestPythonCameraInterface mecheyeenvimage'
                            sh 'sudo docker start APITestPythonCameraInterface'
                            sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install --upgrade pip -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            
                            sh 'sudo docker exec APITestPythonCameraInterface dpkg -i ${DebianPackage}'
                            sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install ${WheelPackage} -i https://pypi.tuna.tsinghua.edu.cn/simple'

                            sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install -r /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            sh 'sudo docker exec APITestPythonCameraInterface python3 /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/main.py ${IP1}'

                        }
                    }
                }

                stage('Test python profiler interface in linux') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestPythonProfilerInterface mecheyeenvimage'
                            sh 'sudo docker start APITestPythonProfilerInterface'
                            sh 'sudo docker exec APITestPythonProfilerInterface python3 -m pip install --upgrade pip -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            
                            sh 'sudo docker exec APITestPythonProfilerInterface dpkg -i ${DebianPackage}'
                            sh 'sudo docker exec APITestPythonProfilerInterface python3 -m pip install ${WheelPackage} -i https://pypi.tuna.tsinghua.edu.cn/simple'

                            sh 'sudo docker exec APITestPythonProfilerInterface python3 -m pip install -r /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple'
                            sh 'sudo docker exec APITestPythonProfilerInterface python3 /home/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/main.py ${IP2}'
                        }
                    }
                }
            }
        }


    }

    post {
        always {
            sh 'sudo docker stop $(sudo docker ps -q) && sudo docker rm -f $(sudo docker ps -aq)'
            sh 'sudo rm -rf /var/lib/jenkins/workspace/MMIND_main/allure-results/'

            // 将测试报告文件移动到jenkins默认的工作路径下
            sh 'mkdir -p allure-results && cp /var/lib/jenkins/workspace/MMIND_TEST_CI_main/MechEyePythonAutoTestProject/report/*.json /var/lib/jenkins/workspace/MMIND_TEST_CI_main/allure-results/'

            //Allure report
            allure([
                includeProperties: false,
                jdk: '',
                properties: [],
                reportBuildPolicy: 'ALWAYS',
                results: [[path: 'allure-results']]
            ])

        }
    }
}