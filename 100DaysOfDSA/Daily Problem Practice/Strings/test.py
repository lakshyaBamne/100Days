def valid_palindrome(s):
    letter_list = list(map(str, s.split(' ')))

    # list comprehension to remove all the spaces in the given list
    letter_list = [item for item in letter_list if len(item)!=0]

    trimmed_string = ""

    for word in letter_list:
        trimmed_string = trimmed_string + word

    final_string = ""

    # we also need to remove all the non-alpha numerical characters
    # this can be achieved using ASCII codes

    CAPITAL_LETTERS = [num for num in range(65, 91)]
    SMALL_LETTERS = [num for num in range(97, 123)]
    NUMBERS = [num for num in range(48, 58)]

    ALL_ASCII = CAPITAL_LETTERS + SMALL_LETTERS + NUMBERS

    # CAPITAL LETTERS -> 65-90
    # small leters -> 97-122
    # numbers -> 48-57
    for letter in trimmed_string:
        ascii_val = ord(letter)
        if ascii_val in ALL_ASCII:
            final_string = final_string + letter

    final_string = final_string.casefold()

    print(final_string)

    return final_string == final_string[::-1]


print(valid_palindrome("9,8"))



