def removeNonAlphabets (str1):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    newStr = ""

    for c in str1.lower():
        if c in alphabet:
            newStr = newStr + c
    return newStr


def isPalindrome(str1):
    newStr = removeNonAlphabets(str1)

    if newStr == newStr[::-1]:
        return True
    else:
        return False

input = input("Enter a skibidi gooner diddy gyat: ")
print(isPalindrome(input))

