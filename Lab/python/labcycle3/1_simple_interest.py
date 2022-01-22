def recalculateSI(person):
    for name in person.keys():
        if person[name]["age"]>60:
            salary = person[name]["salary"]
            person[name]["simpleInterest"] = (salary*12*1)//100
        else:
            person[name]["simpleInterest"] = (salary*10*1)//100
    return person

def display(person):
    for x in person.keys():
        print(f"\nname = {x}")
        print(f"Age = {person[x]['age']}")
        print(f"Salary = {person[x]['salary']}")
        print(f"Simple Interest = {person[x]['simpleInterest']}")
        print()
        
        
def main():
    person = {}

    print("\nEnter q to exit ")
    while True:
        name = input("Enter name : ")
        if name == "q":
            break
        else:
            person[name] = {}
            age = int(input("Enter age : "))
            person[name]["age"] = age
            salary = int(input("Enter salary : "))
            person[name]["salary"] = salary
            person[name]["simpleInterest"] = (salary*10*1)//100
            print()
    print(f"\nEntries : ")
    print(person.keys())
    display(person)       
    person = recalculateSI(person)
    print(f"\nAfter recalculating : ")
    display(person) 

main()