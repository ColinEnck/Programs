import os

def main():
	os.system("cls")
	nums = []
	print('Type the numbers to be sorted (an "x" will start sorting):')
	while True:
		entry = input(">> ")
		if entry == 'x':
			break
		else:
			entry = int(entry)
			nums.append(entry)

	bubble(nums)
	print(nums)

def bubble(nums):
	for i in range(len(nums)):
		for j in range(len(nums) - 1):
			if nums[j] < nums[j + 1]:
				temp = nums[j]
				nums[j] = nums[j + 1]
				nums[j + 1] = temp

main()