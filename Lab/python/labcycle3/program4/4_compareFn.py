def compare(str1,str2,limit):
    if str1[:limit]==str2[:limit]:
        return True
    else:
        return False
def main():
    string1 = input("\nEnter string: ")
    string2 = input("\nEnter string: ")
    l = int(input("\nEnter limit for compare: "))
    if(compare(string1,string2,l)):
        print(f"{l} character is same in {string1} and {string2}")
    else:
        print("No similarity found")
        
main()