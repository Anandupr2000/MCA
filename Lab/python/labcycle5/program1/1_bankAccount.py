class customer:
    def __init__(self,name,accType):
        self.userName = name
        self.accType = accType
        self.accNo = id(self)
        self.balance = 0
            
    def showDetails(self):
        print(f"Account holder name = {self.userName}")
        print(f"Account number = {self.accNo}")
        print(f"Account type = {self.accType}")
        print(f"Account balance = {self.balance}")
        
    def deposit(self,amount):
        self.balance = self.balance + int(amount)
        return self.balance
        
    def withdraw(self,amount):
        if(self.balance==0):
            print("Please deposit cash before withdrawal...")
        
        else:
            if self.balance<amount:
                print("Not enough balance to withdraw...")
            else:
                self.balance = self.balance - int(amount)
                print(f"After withdrawal, balance = {self.balance}") 
                   
def main():
    while True:
        print("======= Menu =======")
        print("1 - New Customer")
        print("2 - Deposit")
        print("3 - Withdrawal")
        print("4 - Display")
        print("5 - Exit")
        choice = int(input("Enter your choice: "))
        if choice==5:
            break
        else:
            if choice==1:
                name = input("Enter name for new customer: ")
                accType = input("Enter account type: ")
                bankAcc = customer(name, accType)
            elif choice==2:
                amount = int(input("Enter amount to deposit : "))
                print(f"Balance = {bankAcc.deposit(amount)}")
            elif choice==3:
                amount = int(input("Enter amount for withdrawal :"))
                bankAcc.withdraw(amount)
            elif choice==4:
                bankAcc.showDetails()
               
main()
