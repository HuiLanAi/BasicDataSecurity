#include "iostream"
using namespace std;

class Return_Values
{
    public:
    int synA;
    int A;

    Return_Values(int x, int y)
    {
        synA = x;
        synB = y;
    }
};

Return_Values compute(int previous, int back);

int main()
{
    cout << "求m关于模n的乘法逆元" << endl;
    cout << "请输入m" << endl;
    int m = 0;
    cin >> m;
    cout << "请输入n" << endl;
    int n = 0;
    cin >> n;
    int origin_n = n;

    while(n < m) n += n;

    Return_Values value = compute(m, n);
    while(value.synA < 0) value.synA += origin_n;
    cout << "该乘法逆元为： " << value.synA << endl;

}

Return_Values compute(int previous, int back)
{
    int left_c = back % previous;
    int synk = (back - left_c) / previous;
    cout << synk << " " << left_c << endl;
    if(left_c == 1)
    {
        Return_Values value(synk, 1);
        return (value);
    }

    Return_Values sub_value = compute(left_c, previous);

    int ret_A = sub_value.synA + sub_value.synB * synk;
    int ret_B = synk + sub_value.synB;
    cout << ret_A << " " << ret_B << endl;

    Return_Values ret(ret_A, sub_value.synB);
    return (ret);
}

// 14 = 5*2 + 4
// 5 = 4*1 + 1 rt 1, 1

// 1 = 5 - 4*1
// 1 = 5 - 1*(14 - 5 * 2)
