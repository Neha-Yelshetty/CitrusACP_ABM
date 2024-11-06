import json
import os
from pickle import FALSE
import psycopg2
import multiprocessing as mp
import tqdm
import random
import string
import math
import datetime
import copy 

econConfig = None 
with open("configs/econConfig.json", "r") as read_file:
    econConfig = json.load(read_file)

bioconfig_file = None 
with open("configs/bioConfig.json", "r") as read_file:
    bioconfig_file = json.load(read_file)

#List to hold all of our triples
masterConfigList = []
setid_dict = {}
cluster_name = "TESTER"

def loadDataFile(cnx, path, tbl):
    fQuery = f"copy {tbl} FROM \'{path}\' DELIMITER \',\' csv header;"
    cursor = cnx.cursor()
    cursor.execute(fQuery)
    cnx.commit()

def runInstance(config):
    biofileName = config[1]["fileName"][:-4]
    econFileName = config[0]["outputFilename"][:-4]
    print("biofileName :{}".format(biofileName))
    print("econFileName :{}".format(econFileName))
    os.makedirs(f'configs/{cluster_name}/{config[2]}', exist_ok=True)
    os.makedirs(f'output/{cluster_name}/{config[2]}', exist_ok=True)
    config[0]["outputFilename"] = f"output/{cluster_name}/{config[2]}/{econFileName}.csv"
    config[1]["fileName"] = f"output/{cluster_name}/{config[2]}/{biofileName}.csv"
    config[0]["experimentID"] = expid
    with open(f"configs/{cluster_name}/{config[2]}/{biofileName}.json", "w") as write_file:
        json.dump(config[1], write_file)
    with open(f"configs/{cluster_name}/{config[2]}/{econFileName}.json", "w") as write_file:
        json.dump(config[0], write_file) 
    os.system(f"./serial.out \"configs/{cluster_name}/{config[2]}/{econFileName}.json\" \"configs/{cluster_name}/{config[2]}/{biofileName}.json\"")


def runInstance(config):
    biofileName = config[1]["fileName"][:-4]
    econFileName = config[0]["outputFilename"][:-4]
    print("biofileName :{}".format(biofileName))
    print("econFileName :{}".format(econFileName))
    os.makedirs(f'configs/{cluster_name}/{config[2]}', exist_ok=True)
    os.makedirs(f'output/{cluster_name}/{config[2]}', exist_ok=True)
    config[0]["outputFilename"] = f"output/{cluster_name}/{config[2]}/{econFileName}.csv"
    config[1]["fileName"] = f"output/{cluster_name}/{config[2]}/{biofileName}.csv"
    config[0]["experimentID"] = expid
    with open(f"configs/{cluster_name}/{config[2]}/{biofileName}.json", "w") as write_file:
        json.dump(config[1], write_file)
    with open(f"configs/{cluster_name}/{config[2]}/{econFileName}.json", "w") as write_file:
        json.dump(config[0], write_file) 
    os.system(f"./serial.out \"configs/{cluster_name}/{config[2]}/{econFileName}.json\" \"configs/{cluster_name}/{config[2]}/{biofileName}.json\"")


def appendMasterTriples(cnx, econ, biocons, folder, master, numSets=0, nameSuffix="",noofiteration = -1):
    if numSets==0:
        #rndBio = random.randint(0, len(biocons)-1)
        bio_copy = copy.deepcopy(biocons)
        econ_copy = copy.deepcopy(econ) 
        rndmid = id_generator()
        if noofiteration != -1:
            rndmid = noofiteration
        elif len(nameSuffix) == 0:
            rndmid = nameSuffix + rndmid
        econ_copy["outputFilename"] = f"{rndmid}_econ.csv"
        bio_copy["fileName"] = f"{rndmid}_bio.csv"
        master.append([econ_copy, bio_copy, folder])
    else: 
        cursor = cnx.cursor()
        setid = createSet(cnx, cursor, folder, cluster_id)
        setid_dict[folder] = setid
        for ns in range(numSets):
            for bio in biocons:
                econ_copy = copy.deepcopy(econ)
                bio_copy = copy.deepcopy(bio)
                rndmid = id_generator()
                if noofiteration != -1:
                    rndmid = noofiteration
                elif len(nameSuffix) == 0:
                  rndmid = nameSuffix + rndmid
                econ_copy["outputFilename"] = f"{rndmid}_econ.csv"
                bio_copy["fileName"] = f"{rndmid}_bio.csv"
                master.append([econ_copy, bio_copy, folder])


for x in range(0,2):
    econ_copy = copy.deepcopy(econConfig)
    econ_copy["strategyFlags"] = "0,0,0,0"
    econ_copy["strategyParameters"] = f"0,0,0,0,0,0,0,0"
    econ_copy["noactionread_file_no"] = x

    bio_copy = copy.deepcopy(config_file)
    invasionDays_lst = ["81"]
    bio_copy["invasionDays"] = ','.join([x for x in invasionDays_lst])
    invasionModality_lst = random.choices(range(1,7),k=len(invasionDays_lst))
    invasionModalities = ','.join([str(x) for x in invasionModality_lst])
    bio_copy["invasionModalities"] =  invasionModalities
    appendMasterTriples(cnx_a, econ_copy, bio_copy, f"noAction_baseCase",  masterConfigList, numSets=0,noofiteration = x)



basePath = f"/home/instr1/repo/test/output/{cluster_name}"
print("Starting data loading...")

pool = mp.Pool(mp.cpu_count())

for _ in tqdm.tqdm(pool.imap_unordered(runInstance, masterConfigList), total=len(masterConfigList)):
    pass 
pool.close()



