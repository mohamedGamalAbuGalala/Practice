/*************************************************************************
	> File Name: main.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sun Jan  4 19:51:21 2015
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
#include<unordered_map>
#include<climits>
#include<unordered_set>
#include<map>
#include<set>
#include<stack>

#include "p_queue.h"

int main()
{
    int A[10] = {10,9,8,7,6,5,4,3,2,1};
    p_queue q1(A, 10);

    std::cout << q1.maximum() << std::endl;
    q1.insert(20);
    std::cout << q1.maximum() << std::endl;
    q1.extract_max();
    std::cout << q1.maximum() << std::endl;
    return 0;
}

