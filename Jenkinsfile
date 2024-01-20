pipeline {
    agent any
    stages {
        stage('Clone test code'){
            steps{
                docker stop $(docker ps -q) && docker stop $(docker ps -q)
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: '2c5b2149-4914-4b15-bd7a-af703dddf0da', url: 'https://github.com/changlelian/MechMindAPICI.git']])
            }
        }

        stage('Parallel execute Stages') {
        parallel {
            stage('Build cpp amd64 samples') {
                steps {
                    script {
                        sh 'sudo docker run -d -t -v /var/lib/jenkins/workspace:/home --name APIBuildTest mecheyeenvimage'
                        sh 'sudo docker start APIBuildTest'
                        // sh 'sudo docker exec APIBuildTest sh /home/GithubTestCode/ubuntu_build.sh'
                        // sh 'sudo docker stop APIBuildTest'
                        // sh 'sudo docker rm APIBuildTest'
                    }
                }
            }
        }
        }   
    }
}

    //     stage('Parallel execute Stages') {
    //         parallel {
    //             stage('Build cpp amd64 samples') {
    //                 steps {
    //                     script {
    //                         sh 'sudo docker run -d -t -v /home/mech_mind_sdk/MechMindSDK:/home --name APIBuildTest mecheyeenvimage'
    //                         sh 'sudo docker start APIBuildTest'
    //                         sh 'sudo docker exec APIBuildTest sh /home/GithubTestCode/ubuntu_build.sh'
    //                         sh 'sudo docker stop APIBuildTest'
    //                         sh 'sudo docker rm APIBuildTest'
    //                     }
    //                 }
    //             }

    //             stage('Test cpp camera interface in linux') {
    //                 steps {
    //                     script {
    //                         sh 'sudo docker run -d -t -v /home/mech_mind_sdk/MechMindSDK:/home --name APITestCameraInterface mecheyeenvimage'
    //                         sh 'sudo docker start APITestCameraInterface'
    //                         sh 'sudo docker exec APITestCameraInterface sh /home/GithubTestCode/APITest/installer.sh'
    //                         sh 'sudo docker exec APITestCameraInterface mkdir -p /home/GithubTestCode/APITest/build'
    //                         sh 'sudo docker exec APITestCameraInterface cmake -S /home/GithubTestCode/APITest -B /home/GithubTestCode/APITest/build'
    //                         sh 'sudo docker exec APITestCameraInterface make -C /home/GithubTestCode/APITest/build'
    //                         sh 'sudo docker exec APITestCameraInterface /home/GithubTestCode/APITest/build/TestMechMindSDK --gtest_filter=*Camera* --ip=192.168.20.173'

    //                         sh 'sudo docker stop APITestCameraInterface'
    //                         sh 'sudo docker rm APITestCameraInterface'
    //                     }
    //                 }
    //             }

    //             stage('Test cpp profiler interface in linux') {
    //                 steps {
    //                     script {
    //                         sh 'sudo docker run -d -t -v /home/mech_mind_sdk/MechMindSDK:/home --name APITestProfilerInterface mecheyeenvimage'
    //                         sh 'sudo docker start APITestProfilerInterface'
    //                         sh 'sudo docker exec APITestProfilerInterface sh /home/GithubTestCode/APITest/installer.sh'
    //                         sh 'sudo docker exec APITestProfilerInterface mkdir -p /home/GithubTestCode/APITest/build'
    //                         sh 'sudo docker exec APITestProfilerInterface cmake -S /home/GithubTestCode/APITest -B /home/GithubTestCode/APITest/build'
    //                         sh 'sudo docker exec APITestProfilerInterface make -C /home/GithubTestCode/APITest/build'
    //                         sh 'sudo docker exec APITestProfilerInterface /home/GithubTestCode/APITest/build/TestMechMindSDK --gtest_filter=*Profiler* --ip=192.168.20.217'

    //                         sh 'sudo docker stop APITestProfilerInterface'
    //                         sh 'sudo docker rm APITestProfilerInterface'
    //                     }
    //                 }
    //             }

    //             stage('Test python camera interface in linux') {
    //                 steps {
    //                     script {
    //                         sh 'sudo docker run -d -t -v /home/mech_mind_sdk/MechMindSDK:/home --name APITestPythonCameraInterface mecheyeenvimage'
    //                         sh 'sudo docker start APITestPythonCameraInterface'
    //                         sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install --upgrade pip -i https://pypi.tuna.tsinghua.edu.cn/simple'

    //                         sh 'sudo docker exec APITestPythonCameraInterface sh /home/GithubTestCode/APITestPy/installer.sh'
    //                         // sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install /home/*38*.whl -i https://pypi.tuna.tsinghua.edu.cn/simple'
    //                         sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install -r /home/GithubTestCode/APITestPy/requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple'
    //                         sh 'sudo docker exec APITestPythonCameraInterface python3 /home/GithubTestCode/APITestPy/main.py 192.168.20.118'

    //                         sh 'sudo docker stop APITestPythonCameraInterface'
    //                         sh 'sudo docker rm APITestPythonCameraInterface'
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    // post {
    //     always {
    //         sh 'sudo rm -rf /var/lib/jenkins/workspace/MMIND_main/allure-results/'
    //         // 将测试报告文件移动到jenkins默认的工作路径下
    //         sh 'mkdir -p allure-results && cp /home/mech_mind_sdk/MechMindSDK/GithubTestCode/APITestPy/report/*.json /var/lib/jenkins/workspace/MMIND_main/allure-results/'

    //         // Allure 报告的生成命令
    //         allure([
    //             includeProperties: false,
    //             jdk: '',
    //             properties: [],
    //             reportBuildPolicy: 'ALWAYS',
    //             results: [[path: '/home/mech_mind_sdk/MechMindSDK/GithubTestCode/APITestPy/report']]
    //         ])
            
    //         sh 'sudo docker stop APITestCameraInterface && sudo docker rm APITestCameraInterface'
    //         sh 'sudo docker stop APITestPythonCameraInterface && sudo docker rm APITestPythonCameraInterface'

    //     }
    // }
