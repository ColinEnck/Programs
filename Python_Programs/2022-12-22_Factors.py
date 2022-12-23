def main():
	num = input("Input a number: ")
	num = int(num)	
	factors_of_num = factors(num)
	for i in factors_of_num:
		print(i)

def factors(num):
	list_of_factors = []
	for i in range(2, num):
		if num % i == 0:
			list_of_factors.append(i)

	return list_of_factors

main()