# make a do while loop to ask if height is less 1 and greater 8
while True:
    height = int(input("Height: "))
    # if height greater or equal to 1 and less or equal to 8
    if height >= 1 and height <= 8:
        break

# run a for loop to print space and # mark
for i in range(1, height+1):

    # make a variable as a space which is put before hash mark
    space = " " * (height-i)

    # make a variable called hashes which are put hash after spaces
    hashes = "#" * i

     #after that print them variables with using f inside print function
    print(f'{space}{hashes}')