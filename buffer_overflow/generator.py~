#!/usr/bin/python3
# -*- coding: utf-8 -*-

import random


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



p1_buffer = "BUFFER_P1"
p1_val = str(100*random.randrange(1,5))

p2_num_1 = "STRUCT_BYNS_P2"
p2_val_1 = str(2**random.randrange(1,5))
p2_num_2 = "MAX_STRUCT_P2"
p2_val_2 = str(512+random.randrange(2,512))


modifyTarget("1",[(p1_buffer,p1_val)])
modifyTarget("2",[(p2_num_1,p2_val_1), (p2_num_2,p2_val_2)])
