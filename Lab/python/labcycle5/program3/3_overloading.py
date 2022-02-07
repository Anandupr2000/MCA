class Time:
    def __init__(self,hour,minute,second):
        #assigning values to private variables
        self.__hour = hour # "__" is used to declare private variables, "_"for protected
        self.__minute = minute
        self.__second = second
    def getHour(self):
        return self.__hour
    def getMinute(self):
        return self.__minute
    def getSecond(self):
        return self.__second
    
    def showTime(self):
        print(f"Time = {self.__hour}:{self.__minute}:{self.__second}")
        
    def __add__(self,time):
        second = self.__second + time.getSecond()
        minute = self.__minute + time.getMinute()
        hour = self.__hour + time.getHour()
        if second>60:
            minute+=1
            second-=60
        if minute>60:
            hour+=1
            minute-=60
        if hour>24:
            hour-=24
        self.__hour = hour
        self.__minute = minute
        self.__second = second
        return self
    
        
def main():
    print("\nEnter first time")
    hour = int(input("\nEnter hour : "))
    minute = int(input("\nEnter minute : "))
    second = int(input("\nEnter second : "))
    t1 = Time(hour, minute, second) # setting first time
    
    print("\nEnter second time")
    hour = int(input("\nEnter hour : "))
    minute = int(input("\nEnter minute : "))
    second = int(input("\nEnter second : "))
    t2 = Time(hour, minute, second) # setting second time
    
    t3 = t1 + t2 #summing time
    
    t3.showTime()
    
    
main()