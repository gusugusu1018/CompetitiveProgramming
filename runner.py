#!/usr/bin/env python3
import sys
import os.path
import subprocess
import time
import argparse

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Local debug tool for competitive programing.')
	parser.add_argument('src', help='Sourcecode file')
	parser.add_argument('-t','--test',help='Test file. default file = src.test')
	parser.add_argument('-d','--debug', action='store_true', help='set debug mode')
	parser.add_argument('-v','--verbose', action='store_true', help='Activate print function')
	args = parser.parse_args()

	base, ext = os.path.splitext(args.src)
	exe = base + '.out'
	compile_cmd=['g++',args.src,'-std=c++14','-o',exe]
	res = subprocess.call(compile_cmd)

	if args.test == None:
		test_file = base + '.test'
		if os.path.exists(test_file):
			args.test = test_file

	if res==0:
		print('Compile success')
		if args.test != None:
			test_data = open(args.test, "r")
			lines = test_data.readlines()
			test_cmd = './' + exe + '<< EOS\n'
			test_counter = 0
			correct_counter = 0
			average_time = 0.0
			inout = True # True is input False is output
			for line in lines:
				if line == '[input]\n':
					inout = True
					test_counter+=1
					if args.verbose or args.debug:
						print('------test' + str(test_counter)+'------')
				elif line == '[output]\n':
					inout = False
					test_cmd += 'EOS'
					if args.verbose or args.debug:
						print(test_cmd)
					start = time.time()
					ret = subprocess.check_output(test_cmd,shell=True)
					elapsed_time = time.time() - start
					average_time += elapsed_time
					test_cmd = './' + exe + '<< EOS\n'
				else:
					if inout:
						test_cmd += line
					else:
						if args.verbose or args.debug:
							print('Correct Answer : ' + line + 'Program output : ' + ret.decode('utf-8'))
						if not args.debug :
							if line == ret.decode('utf-8'):
								if args.verbose:
									print('Ding ding ding! Correct!')
								correct_counter+=1
							else:
								if args.verbose:
									print('Wrong!')
							if args.verbose:
								print('elapsed_time:{0}'.format(elapsed_time) + '[sec]')
			test_data.close()
			if not args.debug:
				print('------Result------\n')
				print('Accuracy rate : ' + str(correct_counter/test_counter*100) + '%')
				print('Average time  : ' + str(average_time/(test_counter)) + '[sec]')
	else:
		res = subprocess.check_output(compile_cmd)
		print(res)
