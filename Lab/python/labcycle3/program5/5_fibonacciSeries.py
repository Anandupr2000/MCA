def fibo(f1,f2,num):
    s = f1+f2
    if(s>=num):
        # print(f" {s}",end="")
        return
    # swapping variable's values
    f1 = f2
    f2 = s
    # printing value of each variable
    print(f" {s}",end="")
    # calling itself with updated argument values
    fibo(f1, f2, num)
    
def main():
    num = int(input("Enter a number : "))
    print("Series : ",end="")
    fibo(-1,1,num)
    
main()
    