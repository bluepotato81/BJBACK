import random

ad=[]
bd=[]

for i in range(10000):
    ad.append(0)
    bd.append(0)


while True:
    a=random.randint(1,10000)

    if ad[a-1]==1:
        continue
    
    ad[a-1]=1
    
    print("? A", a, flush=True)
    
    r=int(input())

    if r==1:
        while True:
            b=random.randint(1,10000)

            if bd[b-1]==1:
                continue

            bd[b-1]=1
            
            print("? B", b, flush=True)

            r=int(input())

            if r==1:
                print("!",a+b)
                break
        break


