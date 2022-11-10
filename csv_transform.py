#!/usr/bin/env python3
# coding=utf-8

from ast import Num
import math
from re import S
import pandas as pd
import numpy as np
import csv


f_path = "BG_Huashang_dir90_L1_Xr0.006731_Yr0.004_C1728_R5000.csv"


list = np.arange(5184.0).reshape(1, 5184)

with open(f_path) as csv_f:
    reader = csv.reader(csv_f)
    count = 0
    rows = 0
    for row in reader:
        for i in range(3):   
            data = row[i]
            list[rows][count] = data
            #print(list[rows][count])
            count = count + 1

            if(count % 5184 == 0):
                rows = rows + 1
                count = 0
                list_add = np.arange(5184.0).reshape(1, 5184)
                list = np.r_[list, list_add]
        
    datas = pd.DataFrame(list)
    datas.to_csv('new_data.csv')

        
    


            




