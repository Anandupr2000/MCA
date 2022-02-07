'''
    this program demonstrate variable length arguments
    add fn receives argument as tuple
'''
def add(*var):
    print(f"Sum of {var} is {sum(var)}")
    
def main():
    add(10,20,60,5)

main()