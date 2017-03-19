#include<iostream>
#include<bits/stdc++.h>
#include<vector>

   int DFS(std::vector<int>& nestedList, int depth)  
    {  
        int sum = 0;  
        for(auto val: nestedList)  
        {  
            if(val.isInteger())  
                sum += val.getInteger()*depth;  
            else sum += DFS(val.getList(), depth+1);  
        }  
        return sum;  
    }  
      
    int depthSum(std::vector<NestedInteger>& nestedList) {  
        return DFS(nestedList, 1);  
    }  

 int main() {
 	std::vector<int> l1, l2;
	l1.push_back(1);
	l1.push_back(1);
	l2.push_back(2);
	l1.push_back(l2);
	depthSum(l1);
}
