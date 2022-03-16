#!/usr/bin/python3
# -*- coding: utf-8 -*-

import random
import string

seed = input("Please input your username: ").upper()

random.seed(seed)

def modifyTarget(num, context):
    ftIn = open("./src/problem"+num+".c",'r')
    ftOut = open("problem"+num+".c",'w')
    s = ftIn.readlines()
    ftIn.close()
    for l in s:
        for (v,t) in context:
            l = l.replace(v,t)
        ftOut.write(l)
    ftOut.close()



p1_pwd = "PWD_P1"
p1_val = ''.join(random.sample(string.ascii_letters + string.digits, 8))

p2_pwd = "PWD_P2"
p2_val = ''.join(random.sample(string.ascii_lowercase, 8))


modifyTarget("1",[(p1_pwd,p1_val)])
modifyTarget("2",[(p2_pwd,p2_val)])
