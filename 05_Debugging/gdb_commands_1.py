import gdb

f = open('test_1.txt', 'w')

gdb.execute('file ./range')
gdb.execute('b 32')
gdb.execute('run 1 12')

f.write(str(gdb.parse_and_eval('start')) + '\n')
f.write(str(gdb.parse_and_eval('stop')) + '\n')
f.write(str(gdb.parse_and_eval('step')) + '\n')

gdb.execute('c 4')
f.write(str(gdb.parse_and_eval('i')) + '\n')

gdb.execute('c 5')
f.write(str(gdb.parse_and_eval('i')) + '\n')

gdb.execute('qquit')
