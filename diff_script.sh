#!/bin/sh

diff ./TestCases/$1/stage1.txt stage1.txt
diff ./TestCases/$1/stage2.txt stage2.txt
diff ./TestCases/$1/stage3.txt stage3.txt
