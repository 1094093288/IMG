flag=''
m=[0xc8,0xf4,0xf5,0xc7,0xc5,0xc3,0xf9,0xc6,0xf7,0xcb,0xc8,0xc7,0xca,0xf8,0xc3,0xc4]
for i in m:
            flag+=chr((i+109)&0xff)
print (flag)
str2 = '81a41a650bd2e906'

for i in range(0,len(str2),4):
    flag += str2[2+i]
    flag += str2[1+i]
    flag += str2[0+i]
    flag += str2[3+i]
print ('bmzctf{'+flag+'}')