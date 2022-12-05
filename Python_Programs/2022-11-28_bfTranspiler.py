import os

# this is where I'm organizing the function calls
def main():
	code = openingLines()
	transpiler(code)

# opening lines and input of the BF code
def openingLines():
	startingText = ("All characters other than <>+-.,[] will be ignored,"
	" but a newline will quit the input")
	print(startingText)
	code = input("Type here your bf code\n")
	return code	

# writes to file "bf.c" based on list "code"
# pob -> passed opening brackets
# pcb -> passed closing brackets
def transpiler(code):
	pob = 0
	pcb = 0
	with open("bf.c", 'w') as file:
		file.write("#include <stdio.h>\n#include <stdlib.h>\n\n")
		file.write("int main(){\n")
		file.write("\tchar array[30000] = {0};\n")
		file.write("\tchar *p_array = array;\n")
		for i in range(len(code)):
			match code[i]:
				case '<':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("\t--p_array;\n")
				case '>':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("\t++p_array;\n")
				case '+':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("\t++*p_array;\n")
				case '-':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("\t--*p_array;\n")
				case '.':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("\tputchar(*p_array);\n")
				case ',':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("\t*p_array = getchar();\n")
				case '[':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("\twhile (*p_array){\n")
					pob += 1
				case ']':
					for i in range(pob - pcb):
						file.write("\t")
					file.write("}\n")
					pcb += 1
		file.write("}")
	os.system('cmd /c "gcc bf.c -o bf.exe"')

# runs the program
main()