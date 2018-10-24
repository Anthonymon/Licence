#!/usr/bin/env python
import sys
import os

counter = 0 

def process_dot(dot, size):
    global counter
    counter += 1
    name = "temp_%s.dot"%counter
    out = "temp_%s.pdf"%counter
    with open(name, "w") as f:
        f.write("digraph {\n")
        for d in dot:
            f.write(d)
        f.write("}")

    os.system("dot -Tpdf %s -o %s"%(name, out))
    return "\\includegraphics[width=%s]{%s}"%(size, out)
    

def parse(lines):
    indot = False
    dot = []
    size = 0
    for l in lines:
        if l.startswith("~~~dot"):
            size = l.split()[1]
            dot = []
            indot = True
        elif l.startswith("~~~") and indot:
            indot = False
            print process_dot(dot,size)
        elif indot:
            dot.append(l)
        else:
            print l,

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print >>stderr, "usage: %s input.md"
        sys.exit()
    else:
        parse(file(sys.argv[1]).readlines())
