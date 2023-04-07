def main():
    # create global vars
    name_dict = {}

    with open('./names-data.txt', 'r') as file:
    # # Read the contents of the file
        for eachLine in file:
            eachList = eachLine.split()
            eachKeyDict = eachList[0]
            name_dict[eachKeyDict] = eachList

    # print(name_dict)
    startSearching(name_dict)

def startSearching(allNames_Dict):
    while True:
        # Get user input
        choice = input("Enter a choice: 1) Search 2) Popularity over time 3) Top ten: 4) Quit\n")

        # Check if the user entered "a"
        if choice == "1":
            substring = input("Enter a enter name to search for: \n")
            matching_names = searchNames(substring, allNames_Dict)

            if matching_names:
                print("Names containing '{}' as a substring:".format(substring))
                for name in matching_names:
                    print(name)
            else:
                print("No names found. Try again!".format(substring))


        # Check if the user entered "b"
        elif choice == "2":
            string = input("Enter a enter name to find yearly rankings: \n")
            matching_name = findRankings(string, allNames_Dict)

            if matching_name:
                print("'{}'s yearly ranking from 1900-2010:\n ".format(string))
                print("1900 1910 1920 1930 1940 1950 1960 1970 1980 1990 2000 2010")
                print("----------------------------------------------------------------")
                for i in range(1, len(matching_name)):
                    whitespace = ' '
                    print(matching_name[i], end='  ')
                    # print(whitespace * (4 % len(matching_name[i])), end='')
            else:
                print("No names found containing '{}' as a substring.\n".format(string))

        # Check if the user entered "c"
        elif choice == "3":
            print("You chose option C")

        # Check if the user entered "q"
        elif choice == "4":
            print("Ending program...")
            break

        # If the user entered an invalid choice
        else:
            print("Invalid choice. Please try again.")

def searchNames(substring, name_dict):
    matching_names = []
    for key in name_dict:
        eachList = name_dict[key]
        # print(eachName)
        if substring.lower() in eachList[0].lower():
            name_and_year = findBiggestYear(eachList)
            matching_names.append(name_and_year)
    return matching_names

def findBiggestYear(nameList):
    biggestNum_index = 1  # Skip first value(the name)
    year = 0

    # Find index of biggest number
    for i in range(2, len(nameList)):
        if nameList[i] > nameList[biggestNum_index]:
            biggestNum_index = i
    # State year based on the largest index
    if (biggestNum_index == 1):
        year = "1900"
    elif (biggestNum_index == 2):
        year = "1910"
    elif (biggestNum_index == 3):
        year = "1920"
    elif (biggestNum_index == 4):
        year = "1930"
    elif (biggestNum_index == 5):
        year = "1940"
    elif (biggestNum_index == 6):
        year = "1950"
    elif (biggestNum_index == 7):
        year = "1960"
    elif (biggestNum_index == 8):
        year = "1970"
    elif (biggestNum_index == 9):
        year = "1980"
    elif (biggestNum_index == 10):
        year = "1990"
    elif (biggestNum_index == 11):
        year = "2000"
    elif (biggestNum_index == 12):
        year = "2010"
    
    return nameList[0], year

def findRankings(string, name_dict):
    for key in name_dict:
        eachList = name_dict[key]

        if string.lower() == eachList[0].lower():
            return eachList


if __name__ == '__main__':
    main()
