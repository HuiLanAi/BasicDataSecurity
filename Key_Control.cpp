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
    cout << "欢迎使用钥控加密！" << endl;
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

    string key = "WENDONG";
    //            7251643

    cout << "加密秘钥为：" << endl;
    cout << key << endl;


    char content[MAX_SIZE] = {0};


    if(fgets(content, MAX_SIZE, fileToRead) != NULL);
    {
        fclose(fileToRead);

        string subline_1 = "";
        string subline_2 = "";
        string subline_3 = "";
        string subline_4 = "";
        string subline_5 = "";
        string subline_6 = "";
        string subline_7 = "";

        int cur = 0;

        // while(content[cur] && content[cur + 1] && content[cur + 2])
        // {
        //     if(!(content[cur + 3] && content[cur + 4] && content[cur + 5] && content[cur + 6])) break;
        //     //对当前组进行非空检查
        //     subline_1 += content[cur++];
        //     subline_2 += content[cur++];
        //     subline_3 += content[cur++];
        //     subline_4 += content[cur++];
        //     subline_5 += content[cur++];
        //     subline_6 += content[cur++];
        //     subline_7 += content[cur++];
            
        // }

        while(content[cur])
        {
            subline_1 += content[cur++];
            if(!content[cur]) break;
            subline_2 += content[cur++];
            if(!content[cur]) break;
            subline_3 += content[cur++];
            if(!content[cur]) break;
            subline_4 += content[cur++];
            if(!content[cur]) break;
            subline_5 += content[cur++];
            if(!content[cur]) break;
            subline_6 += content[cur++];
        }
        
        subline_1 += subline_2 + subline_3 + subline_4 + subline_5 + subline_6 + subline_7;

        int length = subline_1.size();

        for(int i = 0; i < length; i ++)
        {
            content[i] = subline_1[i];
        }
        content[length] = 0;

        cout << "加密完成" << endl;

        ofstream outFile;
        outFile.open("加密文件.txt", ios::trunc);
        if(!outFile.is_open()) { cout << "文件写入错误" << endl; return 0;}
        outFile << content;
        outFile.close();
        return 0;

    }

    cout << "文件读写发生错误！" << endl;

    return 0;

}
