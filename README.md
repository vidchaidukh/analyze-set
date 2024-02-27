## **Solution description**

Looking at the given set of numbers, I noticed that the range of number generation should be about 5-10 times larger than the amount of numbers in the set, so there shouldn't be many repeating elements. Therefore, I decided to sort it with the quick sort algorithm.  
  
Sorting is of course necessary to find the median, and it also allows you to quickly find the minimum and maximum numbers. To find the longest ascending and descending sequences, I wrote a simple algorithm with temporarily arrays to store current sequences. And to find the arithmetic mean, the sum of all numbers is calculated and divided by their amount.
  
At first, I implemented the solution in Python, but I didn't like how long it took to sort, so I decided to rewrite it in C++ and the time decreased by almost 10 times, to 5 seconds. The results are shown below.
## Python results
 1. Max is 49999978  
 2. Min is -49999996  
 3. Median is 25216  
 4. Arithmetic mean is 7364.418442641844  
 5. Ascending sequence: [-48190694, -47725447, -43038241, -20190291, -17190728, -6172572, 8475960, 25205909, 48332507, 48676185]  
 6. Descending sequence: [47689379, 42381213, 30043880, 12102356, -4774057, -5157723, -11217378, -23005285, -23016933, -39209115, -49148762]  
 • time of execution: 41.320s

### Execution time with the time command on WSL2:
real    0m49.175s  
user    0m48.152s  
sys     0m0.852s  

 ---
## C++ results
 1. Max: 49999978  
 2. Min: -49999996  
 3. Median: 25216  
 4. Arithmetic mean: 7364.418442641844  
 5. Ascending sequence: -48190694 -47725447 -43038241 -20190291 -17190728 -6172572 8475960 25205909 48332507 48676185  
 6. Descending sequence: 47689379 42381213 30043880 12102356 -4774057 -5157723 -11217378 -23005285 -23016933 -39209115 -49148762  
 • time of execution: 7.903s  
### Execution time with the time command on WSL2:
real    0m5.036s  
user    0m0.007s  
sys     0m0.001s

---