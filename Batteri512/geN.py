import os
import shutil

root = os.getcwd()

hfs = []
cfs = []

try:
    shutil.rmtree(root + r"\CSEC")
except:
    pass

try:
    shutil.rmtree(root + r"\CSEH")
except:
    pass

os.mkdir(root + r"\CSEC")
os.mkdir(root + r"\CSEH")

for sD, D, F in os.walk(root + r"\Code"):
    for f in F:
        if f[-2:] == ".h":
            shutil.copyfile(os.path.join(sD, f), os.path.join(root + r"\CSEH", f))
        if f[-2:] == ".c":
            shutil.copyfile(os.path.join(sD, f), os.path.join(root + r"\CSEC", f))
