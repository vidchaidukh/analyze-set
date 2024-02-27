#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h> 
#include <chrono>

using namespace std;

// functions for execution time measurement 
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;

// function for swapping two nums by addreses
void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

// quick sort function
int quickSort(vector<int> &num_vector, int left, int right){
    // stop recursion if partition contains 1 or 0 elements
    if(right - left <= 1){
        return 1;
    }

    // the rightmost element as pivot
    int pivot = num_vector[right];
    // pointer for first bigger element
    int bigger_ind = left;

    // iterate through this partition and compare each element with pivot
    for(int j=left; j<right; j++){
        if (num_vector[j] < pivot){
            // swap element at j with first bigger element
            swap(num_vector[bigger_ind], num_vector[j]);
            // increase pointer by 1 because the next element is either larger or the one we just swaped
            bigger_ind++;
        }
    }

    // swap the pivot element with the first greater element
    swap(num_vector[bigger_ind], num_vector[right]);

    // recursive call on the left part
    quickSort(num_vector, left, bigger_ind-1);
    // recursive call on the right part, omitting pivot
    quickSort(num_vector, bigger_ind + 1, right);

    return 1;
}

// function to find ascending and descending sequences
tuple<vector<int>, vector<int>> findSequences(vector<int> vec){
    // vectors to store current sequences
    vector<int> ascend_curr{vec[0]};
    vector<int> descend_curr{vec[0]};

    // remove first element
    vec.erase(vec.begin());

    // vectors for the longest sequences
    vector<int> ascend_max;
    vector<int> descend_max;

    // iterate through the vector bypassing the first element
    for (int i:vec){
        // if sequnce go further, add current element to current sequence vector
        if (i > ascend_curr.back()){
            ascend_curr.push_back(i);
        }
        // if element is smaller, compare length of current seq to previous longest seq
        // and if it is bigger remember it as longest ascend sequnce
        else{
            if (size(ascend_curr) > size(ascend_max)){
                ascend_max = ascend_curr;
            }
            // start new seq with current element
            ascend_curr.clear();
            ascend_curr.push_back(i);
            
        }

        // for descend seq logic is the same but check if seq is descending
        if (i < descend_curr.back()){
            descend_curr.push_back(i);
        }
        else{
            // if current seq is bigger rewrite the biggest seq vector
            if (size(descend_curr) > size(descend_max)){
                descend_max = descend_curr;
            }
            // start new seq with current element
            descend_curr.clear();
            descend_curr.push_back(i);
        }
    }
    return {ascend_max, descend_max};
}

// function for calculating arithmetic mean
long double getMean(vector<int> vec, int vec_size){
    // long long int for storing sum
    long long int vec_sum = 0;
    for (int i:vec){
        vec_sum += i;
    }

    return vec_sum/double(vec_size);
}
// function for determening the median of array
double getMedian(vector<int> &vec, int vec_size){
    // if num_list has odd amount of numbers return middle num
    if(vec_size%2){
        return vec[vec_size/2];
    }else{
        // if amount is even return half sum of central nums
        return (vec[vec_size/2]+vec[vec_size/2+1])/2.0;
    }
}

// function for displaying vector 
void printVector(vector<int> &vec){
    for (int i:vec){
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    // get start time
    auto st_time = high_resolution_clock::now();

    // read file and convert to vector of integers
    ifstream file;
    file.open("10m.txt");
    vector<int> numbers;
    int i;
    while (file >> i) {
        numbers.push_back(i);
    }
    int numbers_size = size(numbers);

    // find the longest ascending and descending sequences in original list
    auto [longest_ascending, longest_descending] = findSequences(numbers); 

    // calculate arithmetic mean
    long double arithmetic_mean = getMean(numbers, numbers_size);

    // sort vector in place
    quickSort(numbers, 0, numbers_size-1);

    // display desired values
    cout << " 1. Max: " << numbers.back() << endl;
    cout << " 2. Min: " << numbers.front() << endl;
    cout << " 3. Median: " << getMedian(numbers, numbers_size) << endl;
    cout << " 4. Arithmetic mean: " << fixed << setprecision(12) << arithmetic_mean << endl;
    cout << " 5. Ascending sequence: ";
    printVector(longest_ascending);
    cout << " 6. Descending sequence: ";
    printVector(longest_descending);
    
    // get end time 
    auto end_time = high_resolution_clock::now();
    
    // calculate and display time taken by program
    auto f_secs = duration_cast<duration<float>>(end_time-st_time);
    cout << " • time of execution: " << fixed << setprecision(3) << f_secs.count() << "s\n";
}