import os
import sys
import glob
import shutil

cwd = os.getcwd()
path_cse = cwd + r"\BatteriUKF\work\codegen\AEKF_ert_rtw"

path_dst_c = cwd + r"\CSEC"
path_dst_h = cwd + r"\CSEH"

try:
    shutil.rmtree(path_dst_c)
    shutil.rmtree(path_dst_h)
except:
    pass
os.mkdir(path_dst_c)
os.mkdir(path_dst_h)

for path_src in [ path_cse ]:
    os.chdir(path_src)
    for cfile in glob.glob("*.c"):
        src = f"{path_src}\\{cfile}"
        dst = f"{path_dst_c}\\{cfile}"
        shutil.copy(src, dst)

    for hfile in glob.glob("*.h"):
        src = f"{path_src}\\{hfile}"
        dst = f"{path_dst_h}\\{hfile}"
        shutil.copy(src, dst)

