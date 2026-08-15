#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// To execute C++, please define "int main()"
// nums = {4, 0, 7, 4, 0, 9, 2, 9, 1}

// Tasks
// Find the largest element.
// Find the second largest distinct element.
// Move all zeros to the end while preserving the order of non-zero elements.
// Remove duplicate values while preserving the first occurrence.
// Reverse the resulting array.
// Return the final array.


int FindMax(std::vector<int> nums){
  int maximum; 
  maximum = *max_element(nums.begin(), nums.end());
  return maximum;
  }

int findSecondLargest(vector<int> nums){
  int maximum = FindMax(nums);
  nums.erase(remove(nums.begin(),nums.end(),maximum),nums.end());
  int secondmax = FindMax(nums);
  return secondmax;
}
vector <int> moveZeroEnd (vector<int> nums){
  vector <int> A, B;
  for(std::size_t i=0; i < nums.size(); i++){
    if(nums[i]==0){
      B.push_back(nums[i]);
    }else {
      A.push_back(nums[i]);
    }  
  }
    A.insert(A.end(), B.begin(), B.end());
  return A;
}
int main(){
   std::vector<int> nums = {4, 0, 7, 4, 0, 9, 2, 9, 3, 1};

  cout << "The max : " << FindMax(nums) << endl;
  cout << "The seecond : " << findSecondLargest(nums) << endl;
  vector <int> zeroEnd = moveZeroEnd(nums);
  cout << "All zeroes moved to the end: ";
  for(int i : zeroEnd){
    cout <<i;
  }
  return 0;
}



/*
- creat array A and B, 
- for loop: 
  -add to array A if non-zero element (use A.push_back(number) )
  -else if zero keep in array B
  -at the end, add array B to array A 
  A.insert(A.end(), B.begin(), B.end());
- O(n).
*/ 

