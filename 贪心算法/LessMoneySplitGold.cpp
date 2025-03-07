// 实质上是哈夫曼编码问题

/*
  一块金条切成两半，是需要花费和长度数值一样的铜板的。比如长度为20的金条，不管切成长度多大的两半，都要花费20个铜板。
  一群人想整分整块金条，怎么分最省铜板？
  例如，给定数组｛10，20,30｝，代表一共三个人，整块金条长度为10+20+30=60。
  金条要分成10.20，30三个部分。如果先把长度60的金条分成10和50，花费60；
  再把长度50的金条分成20和30，花费50；一共花费110铜板。
  但是如果先把长度60的金条分成30和30，花费60；再把长度30金条分成10和20，花费30；一共花费90铜板。
  输入一个数组，返回分割的最小代价。(LeeetCode_1547)
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int lessMoney(vector<int>& arr)
{
    // 准备一个小根堆
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < (int)arr.size(); i++)
    {
        q.push(arr[i]);
    }
    int sum = 0;  // 最终总花费
    int cur = 0;
    while(q.size() > 1)
    {
        // 小根堆弹出两个数相加,再将结果加到小根堆里去
        cur = q.top();
        q.pop();
        cur = cur + q.top();
        q.pop();

        sum += cur;
        q.push(cur);
    }
    return sum;
}


int main()
{
    vector<int> arr = {1,1,5,1,1,1};
    cout<<lessMoney(arr);
    return 0;
}




         


