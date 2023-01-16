text = input("Text: ")

letters = 0
words = 1
sentences = 0

for i in text:
    if i.isalpha():
        letters += 1
    elif i == " ":
        words += 1
    elif i == "." or i == "?" or i == "!":
        sentences += 1

total = 0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8

index = round(total)

if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")