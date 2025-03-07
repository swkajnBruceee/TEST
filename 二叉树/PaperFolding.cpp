/*折纸问题
请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，压出折痕后展开。
此时折痕是凹下去的，即折痕突起的方向指向纸条的背面。
如果从纸条的下边向上方连续对折2次，压出折痕后展开，此时有三条折痕，
从上到下依次是下折痕、下折痕和上折痕。
给定一个输入参数N，代表纸条都从下边向上方连续对折N次。
请从上到下打印所有折痕的方向。
例如：N=1时，打印：down N=2时，打印：down down up
*/
#include<iostream>
using namespace std;


void printAllFolds(int N);
void printProcess(int i, int N, bool down);


int main()
{
    int N = 3;
    printAllFolds(N);
    return 0;
}


void printAllFolds(int N)
{
    printProcess(1, N, true);  // 从左子树开始
}

// 递归过程，来到了某一节点
// i是节点的层数，N是一共的层数， down == true -> 凹 ；down == false -> 凸
// 想象一个二叉树，左子树的头节点都是凹，右子树的头节点都是凸
void printProcess(int i, int N, bool down)
{
    if(i > N) return;
    printProcess(i + 1, N, true);   // 从左子树开始递归  
    cout<<(down ? "凹" : "凸");     //                  -> 这三行其实和中序遍历的逻辑一样
    printProcess(i + 1, N, false);  // 从右子树开始递归  
}





