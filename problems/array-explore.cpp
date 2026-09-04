#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// nums = {4, 0, 7, 4, 0, 9, 2, 9, 1}

// Tasks
// Find the largest element.
// Find the second largest distinct element.
// Move all zeros to the end while preserving the order of non-zero elements.
// Remove duplicate values while preserving the first occurrence.
// Reverse the resulting array.
// Return the final array.




// The findMax function is for finding the maximum element of an array
// By just calling the max_element Function
int FindMax(std::vector<int> nums){
  int maximum; 
  maximum = *max_element(nums.begin(), nums.end());
  return maximum;  
}

//This function finds the second largest by ereasing the first maximum element 
//and again calling the findMax function
int findSecondLargest(vector<int> nums){
  int maximum = FindMax(nums);
  nums.erase(remove(nums.begin(),nums.end(),maximum),nums.end());
  int secondmax = FindMax(nums);
  return secondmax;
}


//This function is used to move all zeroes inside the array to the end and 
//preserves the other elements order 
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


//This function is for delating duplicated element 
vector<int> deleteDuplicated(vector<int> nums) {
    vector<int> temp;

    for (int i : nums) {
        auto it = find(temp.begin(), temp.end(), i);
        // find() returns the target if find. if not found, return temp.end() = False
        if (it == temp.end()) {
          // if not found push to temp array
            temp.push_back(i);
        }
    }
    return temp;
}

//Reversing a vector without uinsg revers() function
vector<int> reverseVector(vector<int> nums){
  // reverse(nums.begin(),nums.end());   //we are not allow to using this function
  vector<int> temp;
  int j = nums.size()-1;
  for(int i=0; i<nums.size(); i++){
    temp.push_back(nums[j]);
    j--;
  }
  return temp;
}


//This is second version of reversing and a bit simpller than first version 
//using just one integer and looping from reverse
vector<int> reverseVectorV2(vector<int> nums){
  vector<int> temp;
  for(int i=nums.size(); i>0; i--){
    temp.push_back(nums[i-1]);
  }
  return temp;
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

  cout <<endl;
  vector<int> A = deleteDuplicated(nums);
  cout<<"all duplicated elements delated = ";
  for(size_t i=0; i<A.size(); i++){
  cout<<" "<< A[i];
  }
  cout<<endl;

  vector<int> reversedV = reverseVectorV2(nums);
  cout << "The reversed Vector = ";
  for(int i:reversedV){
    cout << i << " ";
  }
  return 0;
}



/* For move zeroes to the end 
- creat array A and B, 
- for loop: 
  -add to array A if non-zero element (use A.push_back(number) )
  -else if zero keep in array B
  -at the end, add array B to array A 
  A.insert(A.end(), B.begin(), B.end());
- O(n).
*/ 

/* For delated duplicated elements 
- Define a new vector A 
- For loop over elements,
- if element not in A, append to A
- else skip
if (std::find(my_list.begin(), my_list.end(), x) != my_list.end()) {
    // x is in the list
}
*/

// Reverse the resulting array.
/* 
1.creating a temp array
2.for loop that save the last element of 
  given array to the temp array 
but simply we can use reverse(bigan of array, end of array) to reverse and 
array and vector
*/
