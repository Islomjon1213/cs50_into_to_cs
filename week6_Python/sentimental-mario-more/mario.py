# run while loop to check if input greater than 0 and less than 9
while True:
    height = int(input("Height: "))
    if height >= 1 or height <= 8:
        break

# run a for loop to print space and hash mark
for i in range(1, height + 1):

    # make a variable called space to add space before hashes
    space = " " * (height - i)

    # make a variable called hashes to print hash mark after space
    hashes = "#" * i

    # after that print space and hashes with using above variables
    print(f"{space}{hashes} {hashes}")