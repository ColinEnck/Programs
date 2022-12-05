is_small = input("Is it small?")
is_green = input("Is it green?")
if is_small == "yes":
    small = True
elif is_small == "no":
    small = False
if is_green == "yes":
    green = True
elif is_green == "no":
    green = False
if small and green:
    print("pea")
elif small and not green:
    print("cherry")
elif not small and green:
    print("watermelon")
elif not small and not green:
    print("pumpkin")

