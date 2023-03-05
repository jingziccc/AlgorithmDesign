#include <iostream>
using namespace std;

int Cij(int i, int j) // 计算排列组合数量
{
    if (i == 1)
        return j;
    return i * Cij(i - 1, j - 1) / j;
}

// 计算走法
int way_of_moves(int step, int calories)
{
    // 先只走一步，然后再逐渐增加一次走两步的数量
    int one_step = step;
    int ways = 0;
    int consume = step; // 走一步消耗一卡
    while (consume <= calories)
    {
        ways += Cij(one_step, step);
        step--; // step代表走的次数
        consume++;
        if (one_step > 1)
            one_step -= 2;
        else
            break;
    }
    return ways;
}

bool input_check(int &steps, int &calories)
{
    cin >> steps >> calories;
    if (cin.fail()) // 如果输入错误，直接退出程序
    {
        cout << "Input error" << endl;
        exit(-1);
    }
    if (steps >= calories)
        return true;
    else
    {
        cout << 0;
        return false;
    }
}

int main()
{
    int m, n;
    cout << "Please input m(steps) and n(calories):";
    if (input_check(m, n))
        cout << "Ways:" << way_of_moves(m, n);
    return 0;
}