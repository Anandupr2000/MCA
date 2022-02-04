class publisher:
    def __init__(self,publisherId,publisherName):
        self.publisherId = publisherId
        self.publisherName = publisherName
    def show1(self):
        print(f"Publisher is {self.publisherName}")
        
class book(publisher):
    def __init__(self,publisherId,publisherName,title,author):
        publisher.__init__(self,publisherId,publisherName)
        self.title = title
        self.author = author
        
    def display(self):
        print(f"Boot title is {self.title} and author is {self.author}")
        
class python(book):
    def __init__(self,publisherId,publisherName,title,author,price,no_of_pages):
        book.__init__(self, publisherId,publisherName,title, author)
        self.price = price
        self.no_of_pages = no_of_pages
        
    def display(self):
        # print(f"Book name : {super().title}")
        # print(f"Book author : {super().author}")
        # print(f"Book publisher : {super().publisherName}")
        print(f"Book price : {self.price}")    
        print(f"Book total pages : {self.no_of_pages}")
        
    
def main():
    while True:
        print("======== Menu ========")
        print(" 1 - Create new book")
        print(" 2 - Display book")
        print(" 0 - Exit")
        choice = int(input("Enter your choice: "))
        if choice== 0: break
        elif choice ==1:
            print("Ente book details")
            title = input("Name: ")
            author = input("Author: ")
            publisherId = input("Publisher id: ")
            publisherName = input("Publisher name: ")
            price  = input("Price: ")
            no_of_pages = input("No of pages : ")
            python1 = python(publisherId, publisherName, title, author, price, no_of_pages)
    
        elif choice==2:
            python1.display()
            python1.show1()      
    

main()