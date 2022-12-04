#!/bin/bash

cppcheck --language=c --std=c99 -v -I. --xml . 2>cppcheck-out.xml
