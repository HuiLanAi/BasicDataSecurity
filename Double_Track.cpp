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
    cout << "欢迎使用Vigenère双轨加密！" << endl;
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


    char content[MAX_SIZE] = {0};


    if(fgets(content, MAX_SIZE, fileToRead) != NULL);
    {
        fclose(fileToRead);
        string odd = "", fair = "";
        for(int i = 0; content[i]; i += 2)
        {
            odd += content[i];
            if(content[i + 1]) fair += content[i + 1];
            else break;
        }

        odd += fair;
        int length = odd.size();

        for(int i = 0; i < MAX_SIZE; i ++)
        {
            if(i <= length) content[i] = odd[i];
            else content[i] = 0;
        }



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
