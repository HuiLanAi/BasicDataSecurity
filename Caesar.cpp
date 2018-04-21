#include "iostream"
#include "fstream"
#include "string"
#include "cstdio"
#include "vector"
#include "time.h"
#include "stdlib.h"
using namespace std;

#define MAX_SIZE 10000//加密文件的最大容量
#define GROUP_SIZE 4 //一组的大小

void debug(int x)
{
    cout << x << endl;
}

void debug(string x)
{
    cout << x << endl;
}

int main()
{
    cout << "欢迎使用四个元素一组的周期换位加密！" << endl;
    cout << "copyright@温冬 计算机1507 20154312" << endl;
    cout << "请将要加密的文件(.txt)放入该程序同一文件夹目录内..." << endl;
    cout << "文件大小请不要超过10KB..." << endl;
    char fileName[80] = "";
    cout << "请输入文件名" << endl;
    cin >> fileName;

    FILE* fileToRead = fopen(fileName, "r");

    if(fileToRead == NULL)
    {
        cout << "文件名错误！" << endl;
        return 0;
    }

    cout << "生成随机组内变换顺序如下：" << endl;
    //生成随机数

    vector<int> raw, randProcess;
    raw.empty();
    randProcess.empty();

    for(int i = 1; i <= GROUP_SIZE; i ++) raw.push_back(i);

    srand((int) time(0));

    for(int i = GROUP_SIZE; i >= 1; i--)
    {
        int randNum = rand() % i;//根据当前raw内元素个数来确定随机数范围
        vector<int>:: iterator findIt = raw.begin();
        int num = raw.at(randNum);
        randProcess.push_back(num);
        raw.erase(findIt + randNum);
        cout << num << " ";
    }
    cout << endl;

    //生成随机组内变换顺序

    char content[MAX_SIZE] = {0};


    if(fgets(content, MAX_SIZE, fileToRead) != NULL);
    {
        fclose(fileToRead);
        int cur = 0;
        char temp[4] = {0};
        while (content[cur + 3] && content[cur + 2] && content[cur + 1] && content[cur])
        //如果组内都没有NULL
        {
            cout << "加密进度: "  << float(cur/100) << "%..." << endl;
            for (int i = 0; i < 4; i++)
            {
                temp[i] = content[cur + i];
            }
            //把原数组的值对应四个四个的copy

            content[cur] = temp[randProcess[0] - 1];
            content[cur + 1] = temp[randProcess[1] - 1];
            content[cur + 2] = temp[randProcess[2] - 1];
            content[cur + 3] = temp[randProcess[3] - 1];
            //变换 改变原数组的值

            cur += 4;
        }

        for (int i = 0; i < 3; i++)
        {
            temp[i] = content[cur + i];
        }
        //把原数组的值对应四个四个的copy
        content[cur] = temp[randProcess[0]];
        content[cur + 1] = temp[randProcess[1]];
        content[cur + 2] = temp[randProcess[2]];
        content[cur + 3] = temp[randProcess[3]];
        //最后一组四个的值 NULL必在其中里面 NULL后为任意但无效字符 此处一并一起处理

        cout << "加密完成" << endl;

        ofstream outFile;
        outFile.open("加密文件.txt", ios::trunc);
        if(!outFile.is_open()) { cout << "文件写入错误" << endl; return 0;}
        outFile << content;
        outFile.close();
        return 0;

    }
    // else
    // {
    //     cout << "发生文件读取错误" << endl;
    //     return 0;
    // }

    return 0;

}
