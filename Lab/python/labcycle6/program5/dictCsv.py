cars = {
        "slno":[1,2,3,4],
        "Name":["Datsun","Hornet","Duster","Mercedes Benz"],
        "Model":["710","Sportabout","360","240D"]
        }

try:
    fileobj2 = open("dict.csv","r")
except FileNotFoundError:
    # preparing csv files
    fileobj2 = open("dict.csv","w")
    # Entering key as column heading
    keys = cars.keys() # keys_dicts type is not subcriptable
    keys = list(keys)
    for s in keys:
        fileobj2.write(s)
        if(s!=keys[len(keys)-1]):
            fileobj2.write(", ")
        else:
            fileobj2.write("\n")  
    
    # entering values       
    values = cars.values() # not subscriptable   
    values = list(values) #converting to list
    for i in range(len(values[0])): #execute loop untill column end
        for s in values:
            # print(s[i],end="")
            fileobj2.write(str(s[i]))
            if (s!=values[len(keys)-1]):
                # print(",",end=" ")
                fileobj2.write(", ")
            else:
                # print()
                fileobj2.write("\n")
finally:
    fileobj2 = open("dict.csv","r")
    print(fileobj2.read())
    fileobj2.close()
