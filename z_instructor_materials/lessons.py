content = \
'''
Learning
--------



Challenges
----------
1)

2)

3)

*)
'''

names = ['math', 'if', 'if else', 'if else if else', 'sensors', 'while', 'for', 'arrays', 'actuators', 'functions']

num = 4

for name in names:
	name = name.replace(' ', '_')
	fname = '{:0>2}_{}.txt'.format(num, name)

	print(fname)
	with open(fname, 'w') as fp:
		fp.write(content)

	num += 1

