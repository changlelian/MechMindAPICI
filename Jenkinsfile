pipeline {
    agent any

        environment {
        IP1 = '192.168.20.242'   // camera
        IP2 = '192.168.20.254'   // profiler
        IP3 = '192.168.20.14'    // profiler virtual
    }
    stages {
        stage('Clone test code'){
            steps{
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: '2c5b2149-4914-4b15-bd7a-af703dddf0da', url: 'https://github.com/changlelian/MechMindAPICI.git']])

            }
        }

        stage('Update mecheye device firmware') {
            steps {
                script {
                    sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name FirmwareUpgradeTest mecheyeenvimage'
                    sh 'sudo docker start FirmwareUpgradeTest'

                    sh 'sudo docker exec FirmwareUpgradeTest dpkg -i /home/Mech-Eye_API_2.3.0_amd64.deb'
                    sh 'sudo docker exec FirmwareUpgradeTest mkdir -p /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
                    sh 'sudo docker exec FirmwareUpgradeTest cmake -S /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/ -B /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
                    sh 'sudo docker exec FirmwareUpgradeTest make -C /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build'
                    sh 'sudo docker exec FirmwareUpgradeTest /home/MMIND_TEST_CI_main/UpgradeFirmwareLinux/build/UpgradeFirmwareUbuntu ${IP1} ${IP2} ${IP3}'
                }
            }
        }

        stage('Parallel execute Stages') {
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

            stage('Test cpp camera interface in linux') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestCameraInterface mecheyeenvimage'
                            sh 'sudo docker start APITestCameraInterface'
                            sh 'sudo docker exec APITestCameraInterface dpkg -i /home/Mech-Eye_API_2.3.0_amd64.deb'
                            sh 'sudo docker exec APITestCameraInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestCameraInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestCameraInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestCameraInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Camera* --ip=${IP1}'
                        }
                    }
                }

            stage('Test cpp profiler interface in linux') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestProfilerInterface mecheyeenvimage'
                            sh 'sudo docker start APITestProfilerInterface'
                            sh 'sudo docker exec APITestProfilerInterface dpkg -i /home/Mech-Eye_API_2.3.0_amd64.deb'
                            sh 'sudo docker exec APITestProfilerInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestProfilerInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestProfilerInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestProfilerInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*Profiler* --ip=${IP2}'
                        }
                    }
                }
            
                stage('Test cpp virtual profiler interface in linux') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APITestVirtualProfilerInterface mecheyeenvimage'
                            sh 'sudo docker start APITestVirtualProfilerInterface'
                            sh 'sudo docker exec APITestVirtualProfilerInterface dpkg -i /home/Mech-Eye_API_2.3.0_amd64.deb'
                            sh 'sudo docker exec APITestVirtualProfilerInterface mkdir -p /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestVirtualProfilerInterface cmake -S /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src -B /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestVirtualProfilerInterface make -C /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build'
                            sh 'sudo docker exec APITestVirtualProfilerInterface /home/MMIND_TEST_CI_main/MechEyeCppAutoTestProject/src/build/MechEyeCppAutoTestProject --gtest_filter=*ProVirtual* --ip=${IP3}'
                        }
                    }
                }

        }
        }   
    }

    post {
        always {
            sh 'sudo docker stop $(sudo docker ps -q) && sudo docker rm -f $(sudo docker ps -aq)'
            //sh 'sudo rm -rf /var/lib/jenkins/workspace/MMIND_main/allure-results/'
            // 将测试报告文件移动到jenkins默认的工作路径下
            //sh 'mkdir -p allure-results && cp /home/mech_mind_sdk/MechMindSDK/GithubTestCode/APITestPy/report/*.json /var/lib/jenkins/workspace/MMIND_main/allure-results/'

            // Allure 报告的生成命令
            // allure([
            //     includeProperties: false,
            //     jdk: '',
            //     properties: [],
            //     reportBuildPolicy: 'ALWAYS',
            //     results: [[path: '/home/mech_mind_sdk/MechMindSDK/GithubTestCode/APITestPy/report']]
            // ])
            
            // sh 'sudo docker stop APITestCameraInterface && sudo docker rm APITestCameraInterface'
            // sh 'sudo docker stop APITestPythonCameraInterface && sudo docker rm APITestPythonCameraInterface'

        }
    }
}