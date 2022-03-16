#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from select import select
import sys
import angr


def main(targetPath):
    prog = angr.Project(targetPath)
    sm = prog.factory.simgr(prog.factory.entry_state())

    sm.run()

    #Collect all outputs
    outputSet = set()
    opts = []
    count = 0

    if len(sm.unconstrained) > 0:
        sm.move(from_stash='unconstrained', to_stash='deadended')

    for i in sm.deadended:
        outputSet.add(i.posix.dumps(1))

    for s in outputSet:
        opts.append(s)
        print(count," ", s)
        count += 1

    print("Please select a target output: ", end="")

    selection = int(input())

    print("you selected ", selection, " ", opts[selection])

    sm.move(from_stash= 'deadended', to_stash='authed', filter_func=lambda s:  opts[selection] == s.posix.dumps(1))

    print("Possible input:")

    for res in sm.authed:
        print(res.posix.dumps(0))




if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("Please input the target file path and retry again.")
    else:
        main(sys.argv[1])