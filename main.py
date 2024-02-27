import time

# get start time
start = time.time()

# quicksort function
def quick_sort(num_list, left, right):
    #stop recursion if partition contains 1 or 0 elements
    if right - left <= 1:
        return

    # the rightmost element as pivot
    pivot = num_list[right]
    # pointer for first bigger element
    bigger_ind = left

    # iterate through this partition and compare each element with pivot
    for j in range(left, right):
        if num_list[j] < pivot:
            # swap element at j with first bigger element
            num_list[bigger_ind], num_list[j] = num_list[j], num_list[bigger_ind]
            # increase pointer by 1 because the next element is either larger or the one we just swaped
            bigger_ind += 1

    # swap the pivot element with the first greater element
    num_list[bigger_ind], num_list[right] = num_list[right], num_list[bigger_ind]

    # recursive call on the left part
    quick_sort(num_list, left, bigger_ind-1)
    # recursive call on the right part, omitting pivot
    quick_sort(num_list, bigger_ind + 1, right)

# function for determining the median of set
def get_median(num_list):
    if len(num_list)%2:
        #if num_list has odd amount of numbers return middle num
        return num_list[len(num_list)//2]
    else:
        #if amount is even return half sum of central nums
        return (num_list[len(num_list)//2-1] + num_list[len(num_list)//2])/2

# function of finding the longest ascending and descending sequences
def find_sequences(num_list):
    # lists to store current sequences
    ascend_curr = [num_list[0]]
    descend_curr = [num_list[0]]

    # lists for the longest sequences
    ascend_max = []
    descend_max = []

    for i in num_list[1:]:
        # if sequnce go further, add current element to current seq list
        if i > ascend_curr[-1]:
            ascend_curr.append(i)
        # if element is smaller, compare length of current seq to previous longest seq
        # and if it is bigger remember it as longest ascend sequnce
        else:
            if len(ascend_curr) > len(ascend_max):
                ascend_max = ascend_curr
            # start new seq with current element
            ascend_curr = [i]

        # for descend seq logic is the same but check if seq is descending
        if i < descend_curr[-1]:
            descend_curr.append(i)
        else:
            if len(descend_curr) > len(descend_max):
                descend_max = descend_curr
            descend_curr = [i]
    return ascend_max, descend_max

# read a file and split by strings
file = open('10m.txt').read().splitlines()
# convert elements to integers
nums = [int(n) for n in file]

# find ascending and descending sequences
sequences = find_sequences(nums)

# sort list on place
quick_sort(nums, 0, len(nums)-1)

# show desired values
print(" Max is {} \n Min is {} \n Median is {} \n Ascending sequence: {} \n Descending sequence: {}".
      format(nums[-1], nums[0], get_median(nums), *sequences))
# show execution time
print(" • time of execution: {:.3f}s ".format(time.time()-start))


