import os
os.chdir("/home/pranshu/Haga/My_Files")
path ="/home/pranshu/Haga/My_Files"
files = os.listdir(path)
print("cd /home/pranshu/Haga/My_Files")
for filess in files:
    print("chmod 777 ",filess)