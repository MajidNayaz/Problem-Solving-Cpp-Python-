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


int analyzeArray(std::vector<int> nums){
  int maximum; 
  maximum = *max_element(nums.begin(), nums.end());
  cout <<"max is: " <<  maximum << endl;
  return maximum;
  }

void findSecondLargest(vector<int> nums, int maximum){
  
  nums.erase(remove(nums.begin(),nums.end(),maximum),nums.end());
  cout << "the second "<< analyzeArray(nums)<< "\n";
  for(int i=0; i<nums.size(); i++){
    cout<< nums[i] <<" ";
  }
  
}

int main(){
   std::vector<int> nums = {4, 0, 7, 4, 0, 9, 2, 3, 1};

  int maximum = analyzeArray(nums);
  findSecondLargest(nums, maximum);


  return 0;
}

