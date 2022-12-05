import math
from pathlib import Path
encodeOrDecode = input("encode or decode? e/d: ")
cypher = int((input("cypher key: ")))
alphabet = "abcdefghijklmnopqrstuvwxyz" * 10000
if encodeOrDecode == "e":
    fileOrText = input("from file? y/n: ")
    if fileOrText == "y":
        with open("toEncode.txt") as f:
            text = list(" ".join([l.rstrip() for l in f]))
    else:
        text = list(input("encode: "))
    code = text
    counter = 0
    while counter < len(code):
        if code[counter].isspace() == False:
            if math.fmod(counter, 3) == 0:
                code[counter] = alphabet[alphabet.find(code[counter]) + (counter * cypher)]
            elif math.fmod(counter, 3) == 1:
                code[counter] = alphabet[alphabet.find(code[counter]) + (counter + cypher)]
            else:
                code[counter] = alphabet[alphabet.find(code[counter]) + (counter - cypher)] 
        counter = counter + 1
    print(''.join(code))
elif encodeOrDecode == "d":
    fileOrText = input("from file? y/n: ")
    if fileOrText == "y":
        with open("toDecode.txt") as f:
            text = list(" ".join([l.rstrip() for l in f]))
    else:
        text = list(input("decode: "))
    code = text
    counter = 0
    while counter < len(code):
        if code[counter].isspace() == False:
            if math.fmod(counter, 3) == 0:
                code[counter] = alphabet[alphabet.find(code[counter]) - (counter * cypher)]
            elif math.fmod(counter, 3) == 1:
                code[counter] = alphabet[alphabet.find(code[counter]) - (counter + cypher)]
            else:
                code[counter] = alphabet[alphabet.find(code[counter]) - (counter - cypher)]
        counter = counter + 1
    print(''.join(code))
x = input("cya later")


    
