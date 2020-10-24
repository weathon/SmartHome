import datetime
import serial
Arduino = serial.Serial("/dev/ttyACM0",9600)

template='''{
    "humidity":%s,
    "temp":%s,
    "HIC":%s,
    "light":%s
}'''

def serializer(data):
    mylist=data.split(",")
    # print(tuple(mylist))
    if mylist[0]=="Failed to read from DHT sensor!":
        # mylist[0]=mylist[1]=mylist[2]=-999
        mylist[0]=-999
        mylist.insert(1,-999)
        mylist.insert(2,-999)      
        # 优化
    
    # for i in range(4):
    #     mylist[i]=int(mylist[i])
        #qiang zhi ge shi zhuan huan, ru guo chu cuo 999,  di yige wen jian she qi?
    return template % tuple(mylist) # not data here

atbegining=True

while 1:
    # 多个文件怎么合并？数据库？
    with open("jsons/index.json","r") as f:
        fileindex=int(f.read())
    
    with open("jsons/index.json","w") as f:
        f.write(str(fileindex+1))

    f=open("jsons/"+str(fileindex)+".json","a")
    f.write("""
    {'date':"%s",
      'dataset': [ """ % str(datetime.datetime.now()))
    for i in range(60): #Every 2 min a file

        try:
            f.write(serializer(Arduino.readline().decode()[:-2]))
            atbegining = True
        except KeyboardInterrupt:
            raise
        except:
            # if atbegining == False:
            f.write(serializer("-999,-999,-999,-999")) # 优化 hysm houqi tian bu yong zhi qian de shu zhi
        f.write(",")
    f.write("]}")
    f.close()