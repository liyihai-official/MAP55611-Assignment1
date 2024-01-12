import numpy as np 
import random
import pandas as pd


def create_vector(num):
    file_name = f"datafile/q3file_{num}.txt";
    
    list = []
    for i in range(num):
        list.append(i+1)     
    list = np.array(list)

    list = {num: list}
    list = pd.DataFrame(list)
    list.to_csv(file_name, sep='\n', index=False)


def main():
    create_vector(10000);

if __name__ == "__main__":
    main();