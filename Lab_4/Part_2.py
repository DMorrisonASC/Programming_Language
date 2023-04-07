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
    startSearching()

def startSearching():
    while True:
        # Get user input
        choice = input("Enter a choice: 1) Search 2) Popularity over time 3) Top ten: 4) Quit\n")

        # Check if the user entered "a"
        if choice == "1":
            substring = input("Enter a enter name to search for: \n")
            matching_names = searchNames(substring)

            if matching_names:
                print("Names containing '{}' as a substring:".format(substring))
                for name in matching_names:
                    print(name)
            else:
                print("No names found containing '{}' as a substring.".format(substring))


        # Check if the user entered "b"
        elif choice == "b":
            print("You chose option B")

        # Check if the user entered "c"
        elif choice == "c":
            print("You chose option C")

        # Check if the user entered "q"
        elif choice == "q":
            print("Quitting...")
            break

        # If the user entered an invalid choice
        else:
            print("Invalid choice. Please try again.")

def searchNames(substring):
    matching_names = []
    for line in name_dict:
        if substring in name:
            matching_names.append(name)
    return matching_names

def findYear(index):
    indexInt = int(index)
    year = 0
    if (indexInt == 1):
        year = "1900"
    elif (indexInt == 2):
        year = "1910"
    elif (indexInt == 3):
        year = "1910"
    elif (indexInt == 4):
        year = "1910"
    elif (indexInt == 5):
        year = "1910"
    elif (indexInt == 6):
        year = "1910"
    elif (indexInt == 2):
        year = "1910"
    elif (indexInt == 2):
        year = "1910"


if __name__ == '__main__':
    main()
