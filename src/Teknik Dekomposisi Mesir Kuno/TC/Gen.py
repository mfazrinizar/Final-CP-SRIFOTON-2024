import os
import subprocess

# Run the test case generator
# subprocess.run(["g++", "TC_Gen.cpp", "-o", "TC_Gen"], check=True)
# subprocess.run(["./TC_Gen"], check=True)

# Run the solution
# subprocess.run(["g++", "Sol3_Hard.cpp", "-o", "solution"], check=True)
# with open("output.txt", "w") as f:
#     subprocess.run(["./solution"], stdin=open("input.txt", "r"), stdout=f, check=True)


subprocess.run(["g++", "Sol.cpp", "-o", "solution"], check=True)

for i in range(1, 33):
    with open("output" + str(i) + ".txt", "w") as f:
        subprocess.run(["./solution"], stdin=open("input" + str(i) + ".txt", "r"), stdout=f, check=True)