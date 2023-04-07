def main():
    # create global vars
    name_dict = {}

    with open('./names-data.txt', 'r') as file:
    # # Read the contents of the file
        for eachLine in file:
            eachList = eachLine.split()
            eachKeyDict = eachList[0]
            name_dict[eachKeyDict] = eachList

    print(name_dict)

if __name__ == '__main__':
    main()
