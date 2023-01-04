def main():

    # equalise the new cents variable to get_cents() function
    cents = get_cents()

    #calculate quarter coins
    quarters = calculate_quarters(cents)
    cents = cents - (quarters * 25)

    #calculate dimes coins
    dimes = calculate_dimes(cents)
    cents = cents - (dimes * 10)

    #calculate nickles coins
    nickels = calculate_nickels(cents)
    cents = cents - (nickels * 5)

    #calculate pennies coins
    pennies = calculate_pennies(cents)
    cents = cents - (pennies * 1)

    #calculate and print total coins
    total = quarters + dimes + nickels + pennies
    print(f"Total is {total}")

# take input from the user and check if it is greater than 0 with using while loop
def get_cents():
    while True:
        sum = float(input("Enter any value you want: "))
        if (sum >= 0):
            break
    return sum * 100

#function for calculate quarters
def calculate_quarters(cents):
    coins = 0
    while (cents >= 25):
        cents -= 25
        coins += 1
    return coins

#function for calculate dimes
def calculate_dimes(cents):
    coins = 0
    while (cents >= 10):
        cents -= 10
        coins += 1
    return coins

#function for calculate nickles
def calculate_nickels(cents):
    coins = 0
    while (cents >= 5):
        cents -= 5
        coins += 1
    return coins

#function for calculate pennies
def calculate_pennies(cents):
    coins = 0
    while (cents >= 1):
        cents -= 1
        coins += 1
    return coins

if __name__ == "__main__":
    main()