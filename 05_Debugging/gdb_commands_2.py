import gdb

f = open('test_2.txt', 'w')

gdb.execute('file ./range')
gdb.execute('b 32')
gdb.execute('run -100 100 3')

f.write(str(gdb.parse_and_eval('start')) + '\n')
f.write(str(gdb.parse_and_eval('stop')) + '\n')
f.write(str(gdb.parse_and_eval('step')) + '\n')

gdb.execute('c 26')
f.write(str(gdb.parse_and_eval('i')) + '\n')

for i in range(28, 35):
    gdb.execute('c')
    f.write(str(gdb.parse_and_eval('i')) + '\n')

gdb.execute('qquit')
