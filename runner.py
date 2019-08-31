#!/usr/bin/env python3
import sys
import os.path
import subprocess

args = sys.argv
if len(args) == 1:
	print('set program')
	quit()
src = args[1]
if len(args) == 3:
	test_file = args[2]
base, ext = os.path.splitext(src)
exe = base + '.out'
compile_cmd=['g++',src,'-std=c++14','-o',exe]
res = subprocess.call(compile_cmd)

if res==0:
	print('Compile success')
	if len(args) == 3:
		print('test '+test_file)
		test_data = open(test_file, "r")
		lines = test_data.readlines()
		test_cmd = './' + exe + '<< EOS\n'
		test_counter = 1
		inout = True # True is input False is output
		for line in lines:
			if line == '[input]\n':
				inout = True
				print('------test' + str(test_counter)+'------')
				test_counter+=1
			elif line == '[output]\n':
				inout = False
				test_cmd += 'EOS'
				print(test_cmd)
				res = subprocess.call(test_cmd,shell=True)
				test_cmd = './' + exe + '<< EOS\n'
			else:
				if inout:
					test_cmd += line
				else:
					print('Correct Answer ' + line)
		test_data.close()
else:
	res = subprocess.check_output(compile_cmd)
	print(res)
