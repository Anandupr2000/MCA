set1 = set()
set2 = set()

print("\nEnter q to stop")
for i in range(2):
    while True:
        element = input(f"\nEnter element for set{i+1} : ")
        if(element=='q'): break
        if i == 0:
            set1.add(element)
        elif i==1:
            set2.add(element)

print(f"set1 is {set1}")
print(f"set2 is {set2}")
print(f"set1-set2 is {set1-set2}")