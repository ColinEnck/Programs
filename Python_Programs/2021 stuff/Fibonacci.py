amount = int(input("How long?"))
search = int(input("What are we looking for?"))
x = y = z = 1
print(1)
while x < amount:
    print(y)
    z = z + y
    x = x + 1
    if str(y).find(str(search)) != -1:
        print("entry numer: ", x)
        x = amount
    print(z)
    y = y + z
    x = x + 1
    if str(z).find(str(search)) != -1:
        print("entry numer: ", x)
        x = amount
goodbye = input("Goodbye!")

    
